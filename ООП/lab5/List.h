
#pragma once
#include <string>
#include "Circle.h"
#include <fstream>
#include <sstream>
class Node {
public:
    Circle data;
    Node* next;
    Node* prev;

    // конструктор ноды, принимает в себя ссылку на объект класса Circle 
    Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {}
};

// класс двусвязного списка
class List {
private:
    Node* head;
    Node* tail;

public:
    // пустой конструктор
    List() : head(nullptr), tail(nullptr) {}

    // Конструктор перемещения
    List(List&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    // Оператор присваивания перемещения
    List& operator=(List&& other) {
        if (this != &other) {
            // Очищаем текущий список
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;

            // Перемещаем данные из другого списка
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }

    // оператор присваивания копирования
    List& operator=(const List& other) {
        if (this != &other) {
            // Очищаем текущий список
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;

            // Копируем данные из другого списка
            current = other.head;
            while (current != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // метод добавления ноды в конец списка
    void AddToTail(const Circle& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // метод добавления ноды в начало списка
    void AddToHead(const Circle& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // метод удаления первой ноды, поля которой совпадают с данной
    void Remove(const Circle& data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                break;
            }
            current = current->next;
        }
    }

    // метод удаления всех нод, поля которых совпадают с данной
    void RemoveAll(const Circle& data) {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            if (temp->data == data) {
                if (temp == head) {
                    head = temp->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                else if (temp == tail) {
                    tail = temp->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
        }
    }

    // сортировка спика по площади кругов
    void SortList() {
        // Bubble sort
        if (head == nullptr || head == tail)
            return;

        Node* current;
        Node* temp = nullptr;
        bool swapped;

        do {
            swapped = false;
            current = head;

            while (current->next != temp) {
                if (current->data.GetS() > current->next->data.GetS()) {
                    Circle tempData = current->data;
                    current->data = current->next->data;
                    current->next->data = tempData;
                    swapped = true;
                }
                current = current->next;
            }
            temp = current;

        } while (swapped);
    }

    // конструктор, принимает в себя другой список
    List(const List& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current != nullptr) {
            AddToTail(current->data);
            current = current->next;
        }
    }

    // метод, выводящий содержимое списка, с помощью вывода в консоль каждого своего элемента
    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* current = list.head;
        while (current != nullptr) {
            os << current->data << endl;
            current = current->next;
        }
        return os;
    }

    // метод, позволяющий из поступающего потока задать двусвязный список
    //friend std::istream& operator>>(std::istream& is, List& list) {
    //    std::string str;
    //    while (std::getline(is, str)) {
    //        Circle c = Circle(str);
    //        list.AddToTail(c);
    //    }
    //    return is;
    //}

    // очищаем память после использованя класса
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};