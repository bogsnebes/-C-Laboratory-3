#include "Client.h"
#include <string.h>
/**
 * @class ListClient
 * Содержит в себе массив объектов класса Client и функции работы с ними
 */
class ListClients {
    public:
        /**
        * Конструктор
         * @param value - количество ячеек массива (list, free) для хранения объектов Client
         */
    ListClients(int value) {
        list = new Client[value];
        free = new int[value];
        for (int i = 0; i < value; i++) {
            free[i] = 0;
        }
        this->count = value;
    }
    /**
    * Проверяет количество занятых ячеек массива list
    * @return количество объектов в list, которые не являются пустыми
    */
        int checkList() {
        countFreeList = 0;
        for(int i = 0; i < count; i++) {
            if (free[i] == 0) {
                countFreeList += 1;
            }
        return (count - countFreeList);
    }
    }
        /**
        * Добавляет объект класса Client в массив list
        * @param value - объект класса Client
        * @return void
        */
    void add(Client &value) {
        for(int i = 0; i < count; i++) {
            if (free[i] == 0) {
                list[i] = value;
                free[i] = 1;
                return;
            }
        }
    }
    /**
    * Создает и добавляет объект класса Client в массив list
    * @param name - имя клиента
    * @param adress - адресс клиента
    * @param discount - скидка клиента
    * @return void
    */
    void add(char *name, char *adress, int discount) {
        for(int i = 0; i < count; i++) {
            if (free[i] == 0) {
                Client NewClient = Client(name, adress, discount);
                list[i] = NewClient;
                free[i] = 1;
                return;
            }
        }
    }

    /**
    * Создает и добавляет объект класса Client в массив list. Ввод производиться в консоли пользователем.
    * @return void
    */
    void addKey() {
        setlocale(0, "");
        for(int i = 0; i < count; i++) {
            if (free[i] == 0) {
                char* name = new char[80];
                char* adress = new char[80];
                int discount;
                cout << "Name client: ";
                cin >> name;
                cout << "\nAdress client: ";
                cin >> adress;
                cout << "\nDiscount client: ";
                cin >> discount;
                cout << "\n";
                Client NewClient = Client(name, adress, discount);
                list[i] = NewClient;
                free[i] = 1;
                return;
            }
        }
              }

    /**
    * Удаляет объект из массива list
    * @param value - номер ячейки массива
    * @return void
    * @note value Номер ячейки должен входить в размерность массива.
    */
    void deleteClient(int value) {
        setlocale(0, "");
        if (value > (sizeof(list) - 1) and value < 0)
            return;
        list[value] = Client(_strdup("0"), _strdup("0"), 0);
        free[value] = 0;
    }

    /**
    * Отображает в консоли данные всех объектов Clients находящихся в массиве list (кроме пустых)
    * @return void
    */
    void showList() {
        for(int i = 0; i < count; i++) {
            if (free[i] == 1) {
            list[i].ShowClient();
            cout << "------------------------" << endl;
            }
        }
    }
    private:
    Client *list; // Массив объектов Client
    int *free; // Массив свободных ячеек
    int countFree = 0; // Количество свободных ячеек
    int count; // Количество ячеек
    int countFreeList;
};