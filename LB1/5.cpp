#include <iostream>
#include <fstream> //для работы с файлами.
#include <sstream> //для работы со строками как с потоками.
#include <vector> // для использования динамического массива.
#include <string>
using namespace std;
struct Owner {
    string lastName; // информация о водителях 
    string firstName;
    string patronymic;
    string phoneNumber;
    string address; // Полный адрес
    string carBrand;
    string carNumber;
    string techPassportNumber; //технический паспорт 
};

void createFile(const string& filename) { // для создания файла
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    // Пример данных о владельцах автомобилей
    outFile << "Василий;Иван;Иванович;127890;3456, Россия, Московская область, Москва, Октябрьская, 1, 1;Ваз;А1BC;1256\n";
    outFile << "Осипчук;Петр;Петрович;098321;6321, Россия, Санкт-Петербург, Питер, Смоленского, 2, 2;Toyota;B456CD;6321\n";
    outFile << "Краснов;Сидор;Сидорович;1124455;9012, Россия, Ставропольский край, Романова, Ленина, 3, 3;Ваз;CEF;7012\n";

    outFile.close();
}

vector<Owner> readFile(const string& filename) { //  для использования динамического массива и сохраняет обекты в owner
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return {};
    }

    vector<Owner> owners;
    string line;

    while (getline(inFile, line)) {
        istringstream ss(line);
        Owner owner;
        string token;

        // Чтение данных из строки
        getline(ss, owner.lastName, ';');
        getline(ss, owner.firstName, ';');
        getline(ss, owner.patronymic, ';');
        getline(ss, owner.phoneNumber, ';');
        getline(ss, owner.address, ';');
        getline(ss, owner.carBrand, ';');
        getline(ss, owner.carNumber, ';');
        getline(ss, owner.techPassportNumber);

        owners.push_back(owner);
    }

    inFile.close();
    return owners;
}

void writeFilteredData(const vector<Owner>& owners, const string& outputFilename) { // принимает вектор владельцев и имя выходного файла.
    ofstream outFile(outputFilename); // т.е для отбора
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << outputFilename << endl;
        return;
    }

    for (const auto& owner : owners) {
        if (owner.carBrand == "Ваз") {
            outFile << owner.lastName << ";"
                << owner.firstName << ";"
                << owner.patronymic << ";"
                << owner.phoneNumber << ";"
                << owner.address << ";"
                << owner.carBrand << ";"
                << owner.carNumber << ";"
                << owner.techPassportNumber << "\n";
        }
    }

    outFile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string inputFilename = "owners.txt"; //Определяются имена входного и выходного файлов.
    const string outputFilename = "filtered_owners.txt";

    // Создаем файл с данными
    createFile(inputFilename);

    // Читаем данные из файла
    auto owners = readFile(inputFilename);

    // Записываем отфильтрованные данные в новый файл
    writeFilteredData(owners, outputFilename);

    cout << "Данные о владельцах автомобилей марки 'Ваз' записаны в файл " << outputFilename << endl;

    return 0;
}
