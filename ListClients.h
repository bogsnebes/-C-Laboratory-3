#include "Client.h"
#include <string.h>
/**
 * @class ListClient
 * �������� � ���� ������ �������� ������ Client � ������� ������ � ����
 */
class ListClients {
    public:
        /**
        * �����������
         * @param value - ���������� ����� ������� (list, free) ��� �������� �������� Client
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
    * ��������� ���������� ������� ����� ������� list
    * @return ���������� �������� � list, ������� �� �������� �������
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
        * ��������� ������ ������ Client � ������ list
        * @param value - ������ ������ Client
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
    * ������� � ��������� ������ ������ Client � ������ list
    * @param name - ��� �������
    * @param adress - ������ �������
    * @param discount - ������ �������
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
    * ������� � ��������� ������ ������ Client � ������ list. ���� ������������� � ������� �������������.
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
    * ������� ������ �� ������� list
    * @param value - ����� ������ �������
    * @return void
    * @note value ����� ������ ������ ������� � ����������� �������.
    */
    void deleteClient(int value) {
        setlocale(0, "");
        if (value > (sizeof(list) - 1) and value < 0)
            return;
        list[value] = Client(_strdup("0"), _strdup("0"), 0);
        free[value] = 0;
    }

    /**
    * ���������� � ������� ������ ���� �������� Clients ����������� � ������� list (����� ������)
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
    Client *list; // ������ �������� Client
    int *free; // ������ ��������� �����
    int countFree = 0; // ���������� ��������� �����
    int count; // ���������� �����
    int countFreeList;
};