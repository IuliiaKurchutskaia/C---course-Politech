#pragma once
// Объявление класса A, инкапсулирующего одномерный динамический массив
class a {
private:
    int* m_p=nullptr; // Указатель на динамический массив
    int capacity; // Размерность массива
    size_t count = 0;
public:
    // Конструктор, который принимает размерность одномерного массива int
    a(int size) {
        capacity = size;
        count = 0; //количество элементов 
        m_p = new int[capacity];
    }

	
    // Конструктор копирования
    a(const a& other) {
        capacity = other.capacity;
        count = other.count;
        m_p = new int[capacity];
        for (size_t i = 0; i < count; i++) {
            m_p[i] = other.m_p[i];
        }
    }

    // Конструктор перемещения
    a(a&& other) {
        capacity = other.capacity;
        count = other.count;
        m_p = other.m_p;
        other.capacity = 0;
        other.count = 0;
        other.m_p = nullptr;
    }



    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const a& obj) {
        for (size_t i = 0; i < obj.count; i++) {
            os << obj.m_p[i] << " ";
        }
        return os;
    }

    // Оператор сравнения "больше"
    bool operator>(const a& other) const {
        return count > other.count;
    }

    // Оператор сравнения "меньше"
    bool operator<(const a& other) const {
        return count < other.count;
    }

    // Оператор индексирования
    int& operator[](int index) {
        return m_p[index];
    }


    // метод для добавления элемента в массив
    void add(int value) {
        if (count < capacity) {
            m_p[count++] = value;
        }
    }

    // метод для получения количества элементов в массиве
    size_t getCount() const {
        return count;
    }

    // метод для проверки, является ли массив пустым
    bool isEmpty() const {
        return count == 0;
    }


    a operator+(const a& other) const {
        int size = count + other.count;
        a result(size); // создаем новый объект суммарного размера
        for (size_t i = 0; i < count; i++) {
            result.m_p[i] = m_p[i]; // копируем элементы текущего объекта
        }
        for (size_t i = count; i < size; i++) {
            result.m_p[i] = other.m_p[i - count]; // копируем элементы другого объекта
        }
        result.count = size; // обновляем количество элементов в новом объекте
        return result;
    }

    
    // Деструктор, освобождающий выделенную память
    ~a() {
        delete[] m_p;
    }
};

