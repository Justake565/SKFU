#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Customer {
    string name;           // Фамилия и инициалы покупателя
    string purchaseDate;   // Дата покупки
    double totalFirstHalf;      // Общая стоимость за первое полугодие
    double totalSecondHalf;     // Общая стоимость за второе полугодие
    double discountPercentage;   // Начальный процент скидки
};

// Функция для записи данных в бинарный файл
void writeToFile(const string& filename, const vector<Customer>& customers) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }
    for (const auto& customer : customers) {
        size_t nameLength = customer.name.size();
        outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        outFile.write(customer.name.c_str(), nameLength);
        outFile.write(customer.purchaseDate.c_str(), 10); // Предполагаем, что дата в формате "ДД.ММ.ГГГГ"
        outFile.write(reinterpret_cast<const char*>(&customer.totalFirstHalf), sizeof(customer.totalFirstHalf));
        outFile.write(reinterpret_cast<const char*>(&customer.totalSecondHalf), sizeof(customer.totalSecondHalf));
        outFile.write(reinterpret_cast<const char*>(&customer.discountPercentage), sizeof(customer.discountPercentage));
    }
    outFile.close();
}

// Функция для чтения данных из бинарного файла
vector<Customer> readFromFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return {};
    }

    vector<Customer> customers;
    while (inFile.peek() != EOF) {
        Customer customer;

        size_t nameLength;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

        customer.name.resize(nameLength);
        inFile.read(&customer.name[0], nameLength);

        customer.purchaseDate.resize(10); // Предполагаем, что дата в формате "ДД.ММ.ГГГГ"
        inFile.read(&customer.purchaseDate[0], 10);

        inFile.read(reinterpret_cast<char*>(&customer.totalFirstHalf), sizeof(customer.totalFirstHalf));
        inFile.read(reinterpret_cast<char*>(&customer.totalSecondHalf), sizeof(customer.totalSecondHalf));
        inFile.read(reinterpret_cast<char*>(&customer.discountPercentage), sizeof(customer.discountPercentage));

        customers.push_back(customer);
    }

    inFile.close();
    return customers;
}

// Функция для обновления скидки
void updateDiscounts(vector<Customer>& customers) {
    for (auto& customer : customers) {
        if (customer.totalFirstHalf >= 10000 && customer.totalSecondHalf >= 10000) {
            customer.discountPercentage += 7.0; // Увеличиваем скидку на 7%
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string filename = "customers.dat";

    vector<Customer> customers = {
        {"Осипчук А.И.", "01.01.2025", 12000.0, 13000.0, 5.0},
        {"Гриднев А.П.", "15.02.2025", 5000.0, 9000.0, 5.0},
        {"Романов Р.С.", "20.03.2025", 8000.0, 19000.0, 5.0}
    };

    // Запись данных в бинарный файл
    writeToFile(filename, customers);

    // Чтение данных из файла
    auto readCustomers = readFromFile(filename);

    // Вывод данных до изменения скидки
    cout << "Данные до изменения скидки:\n";
    for (const auto& customer : readCustomers) {
        cout << "ФИО: " << customer.name
            << ", Дата: " << customer.purchaseDate
            << ", Общая стоимость 1 полугодие: " << customer.totalFirstHalf
            << ", Общая стоимость 2 полугодие: " << customer.totalSecondHalf
            << ", Скидка: " << customer.discountPercentage << "%\n";
    }

    // Обновление скидок
    updateDiscounts(readCustomers);

    // Запись измененных данных обратно в файл
    writeToFile(filename, readCustomers);

    // Чтение данных из файла после изменения
    auto modifiedCustomers = readFromFile(filename);

    // Вывод данных после изменения скидки
    cout << "\nДанные после изменения скидки:\n";
    for (const auto& customer : modifiedCustomers) {
        cout << "ФИО: " << customer.name
            << ", Дата: " << customer.purchaseDate
            << ", Общая стоимость 1 полугодие: " << customer.totalFirstHalf
            << ", Общая стоимость 2 полугодие: " << customer.totalSecondHalf
            << ", Скидка: " << customer.discountPercentage << "%\n";
    }

    return 0;
}

