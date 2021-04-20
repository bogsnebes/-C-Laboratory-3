#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

using namespace std;
/**
 * @class Client
 * Содержит в себе данные о клиентах и функции работы с ними
 */
class Client {
    public:
    Client() {}
    /**
     * Присваивает атрибуту fio значение
     * @param value - значение
     */
    void setFio(char *value) {
        this -> fio = value;
    }

    /**
     * Присваивает атрибуту adress значение
     * @param value - значение
     */
    void setAdress(char *value) {
        this -> adress = value;
    }

    /**
     * Присваивает атрибуту discount значение
     * @param value - значение
     * @note Value должно быть от 0 до 100
     */
    void setDiscount(int value) {
        if (value <= 100 and value >= 0)
            this -> discount = value;
    }

    /**
     * Возращает текущее значение атрибута fio
     * @return fio
     */
    char* getFio() {
        return this->fio;
    }

    /**
     * Возращает текущее значение атрибута adress
     * @return adress
     */
    char* getAdress() {
        return this->adress;
    }

    /**
     * Возращает текущее значение атрибута discount
     * @return discount
     */
    int getDiscount() {
        return this->discount;
    }

    /**
     * Конструктор
     * @param name - имя клиента
     * @param adress - адресс клиента
     * @param discount - скидка клиента
     */
    Client(char *name, char *adress, int discount) {
        setFio(name);
        setAdress(adress);
        setDiscount(discount);
    }

    /**
     * Выводит в консоль атрибуты объекта: fio, adress, discount
     */
    void ShowClient() {
        setlocale(0, "");
        cout << "Name client:" << getFio() << endl;
        cout << "Adress client:" << getAdress() << endl;
        cout << "Discount client:" << getDiscount() << endl;
    }
    ~Client() {}

    /**
     * Cравнивает объекты
     * @param value - другой объект класса Client
     * @return true, если объекты равны по всем атрибутам. false, если хоть один атрибут не равен.
     */
    bool operator==(Client &value) {
        if (string(fio) == string(value.getFio()) and string(adress) == string(value.getAdress()) and discount == value.getDiscount())
            return true;
        return false;
    }
    private:
    char *fio; // Имя клиента
    char *adress; // Адресс клиента
    int discount; // Скидка клиента
};
#endif