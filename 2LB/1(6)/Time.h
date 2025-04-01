#pragma once
class TimeConverter { // Класс, объявляется с двумя приватными полями
   
public:
        TimeConverter(int minutes, int seconds); // Конструктор
        void console();
        double half_TimeConverter(int minutes, int seconds);

    private:
        int minutes;
        int seconds;
    };

