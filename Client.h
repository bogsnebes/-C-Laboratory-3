#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

using namespace std;
/**
 * @class Client
 * �������� � ���� ������ � �������� � ������� ������ � ����
 */
class Client {
    public:
    Client() {}
    /**
     * ����������� �������� fio ��������
     * @param value - ��������
     */
    void setFio(char *value) {
        this -> fio = value;
    }

    /**
     * ����������� �������� adress ��������
     * @param value - ��������
     */
    void setAdress(char *value) {
        this -> adress = value;
    }

    /**
     * ����������� �������� discount ��������
     * @param value - ��������
     * @note Value ������ ���� �� 0 �� 100
     */
    void setDiscount(int value) {
        if (value <= 100 and value >= 0)
            this -> discount = value;
    }

    /**
     * ��������� ������� �������� �������� fio
     * @return fio
     */
    char* getFio() {
        return this->fio;
    }

    /**
     * ��������� ������� �������� �������� adress
     * @return adress
     */
    char* getAdress() {
        return this->adress;
    }

    /**
     * ��������� ������� �������� �������� discount
     * @return discount
     */
    int getDiscount() {
        return this->discount;
    }

    /**
     * �����������
     * @param name - ��� �������
     * @param adress - ������ �������
     * @param discount - ������ �������
     */
    Client(char *name, char *adress, int discount) {
        setFio(name);
        setAdress(adress);
        setDiscount(discount);
    }

    /**
     * ������� � ������� �������� �������: fio, adress, discount
     */
    void ShowClient() {
        setlocale(0, "");
        cout << "Name client:" << getFio() << endl;
        cout << "Adress client:" << getAdress() << endl;
        cout << "Discount client:" << getDiscount() << endl;
    }
    ~Client() {}

    /**
     * C��������� �������
     * @param value - ������ ������ ������ Client
     * @return true, ���� ������� ����� �� ���� ���������. false, ���� ���� ���� ������� �� �����.
     */
    bool operator==(Client &value) {
        if (string(fio) == string(value.getFio()) and string(adress) == string(value.getAdress()) and discount == value.getDiscount())
            return true;
        return false;
    }
    private:
    char *fio; // ��� �������
    char *adress; // ������ �������
    int discount; // ������ �������
};
#endif