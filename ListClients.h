#include "Client.h"
#include <string.h>

class ListClients {
    public:
    ListClients(int value) {
        list = new Client[value];
        free = new int[value];
        for (int i = 0; i < value; i++) {
            free[i] = 0;
        }
        this->count = value;
    }

        int checkList() {
        countFreeList = 0;
        for(int i = 0; i < count; i++) {
            if (free[i] == 0) {
                countFreeList += 1;
            }
        return (count - countFreeList);
    }
    }

    void add(Client &value) {
        for(int i = 0; i < count; i++) {
            if (free[i] == 0) {
                list[i] = value;
                free[i] = 1;
                return;
            }
        }
    }
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

    void deleteClient(int value) {
        setlocale(0, "");
        if (value > (sizeof(list) - 1) and value < 0)
            return;
        list[value] = Client(_strdup("0"), _strdup("0"), 0);
        free[value] = 0;
    }

    void showList() {
        for(int i = 0; i < count; i++) {
            if (free[i] == 1) {
            list[i].ShowClient();
            cout << "------------------------" << endl;
            }
        }
    }
    private:
    Client *list;
    int *free;
    int countFree = 0;
    int count;
    int countFreeList;
};