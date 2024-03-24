#pragma once
// ���������� ������ A, ���������������� ���������� ������������ ������
class a {
private:
    int* m_p=nullptr; // ��������� �� ������������ ������
    int capacity; // ����������� �������
    size_t count = 0;
public:
    // �����������, ������� ��������� ����������� ����������� ������� int
    a(int size) {
        capacity = size;
        count = 0; //���������� ��������� 
        m_p = new int[capacity];
    }

	
    // ����������� �����������
    a(const a& other) {
        capacity = other.capacity;
        count = other.count;
        m_p = new int[capacity];
        for (size_t i = 0; i < count; i++) {
            m_p[i] = other.m_p[i];
        }
    }

    // ����������� �����������
    a(a&& other) {
        capacity = other.capacity;
        count = other.count;
        m_p = other.m_p;
        other.capacity = 0;
        other.count = 0;
        other.m_p = nullptr;
    }



    // �������� ������
    friend std::ostream& operator<<(std::ostream& os, const a& obj) {
        for (size_t i = 0; i < obj.count; i++) {
            os << obj.m_p[i] << " ";
        }
        return os;
    }

    // �������� ��������� "������"
    bool operator>(const a& other) const {
        return count > other.count;
    }

    // �������� ��������� "������"
    bool operator<(const a& other) const {
        return count < other.count;
    }

    // �������� ��������������
    int& operator[](int index) {
        return m_p[index];
    }


    // ����� ��� ���������� �������� � ������
    void add(int value) {
        if (count < capacity) {
            m_p[count++] = value;
        }
    }

    // ����� ��� ��������� ���������� ��������� � �������
    size_t getCount() const {
        return count;
    }

    // ����� ��� ��������, �������� �� ������ ������
    bool isEmpty() const {
        return count == 0;
    }


    a operator+(const a& other) const {
        int size = count + other.count;
        a result(size); // ������� ����� ������ ���������� �������
        for (size_t i = 0; i < count; i++) {
            result.m_p[i] = m_p[i]; // �������� �������� �������� �������
        }
        for (size_t i = count; i < size; i++) {
            result.m_p[i] = other.m_p[i - count]; // �������� �������� ������� �������
        }
        result.count = size; // ��������� ���������� ��������� � ����� �������
        return result;
    }

    
    // ����������, ������������� ���������� ������
    ~a() {
        delete[] m_p;
    }
};

