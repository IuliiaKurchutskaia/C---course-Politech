//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

const char* sep = "------------------------------------\n";

class Circle {
private:
    double x, y, r;
    double string_to_double( const std::string& s )
    {
        std::istringstream i(s);
        double x;
        if (!(i >> x))
            return 0;
        return x;
    }

public:
	// конструктор, принимает строку вида "Circle: center( " << c.x << " , " << c.y << " ), radius = " << c.r",
	// разбивает её на подстроки по пробелам и инициализирует переменные x, y, z 
	Circle(string str) {
        char separator = ' ';
        string s;
        string tokens[9];
        
        int j = 0 ;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != separator) {
                s += str[i];
            } else {
                tokens[j] = s;
                j++;
                s.clear();
            }
        }
        tokens[j] = s;
        s.clear();
        x = string_to_double(tokens[2]);
        y = string_to_double(tokens[4]);
        r = string_to_double(tokens[8]);
	}

	// конструктор, принимает три значения типа double и инициализирует переменные x, y, z
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}

	// метод, возвращающий площадь круга
    double area() const {
        return M_PI * r * r;
    }

	// переопределение оператора ==, сравнивает круги по площади и координатам центра
	friend bool operator==(const Circle& c1, const Circle& c2) {
    	return c1.x == c2.x && c1.y == c2.y && c1.area() == c2.area();
	}

	// перегрузка оператора вывода объекта в консоль
    friend std::ostream& operator<<(std::ostream& os, const Circle& c) {
        os << "Circle: center( " << c.x << " , " << c.y << " ), radius = " << c.r;
        return os;
    }
};

// класс ноды листа
class Node {
public:
    Circle data;
    Node *next;
    Node *prev;

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
        } else {
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
        } else {
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
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                } else {
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
                } else if (temp == tail) {
                    tail = temp->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                } else {
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
                if (current->data.area() > current->next->data.area()) {
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
	friend std::istream& operator>>(std::istream& is, List& list) {
		std::string str;
		while (std::getline(is, str)) {
			Circle c = Circle(str);
			list.AddToTail(c);
		}
		return is;
	}

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

int main()
{
	//
	// 1. Создаем список
	//
	List ls1;
	
	ls1.AddToTail(Circle(1, 1, 1));		//добавляем элементы в список
	ls1.AddToTail(Circle(5, 5, 5));
	ls1.AddToTail(Circle(2, 2, 2));	
	ls1.AddToTail(Circle(4, 4, 4));
	ls1.AddToTail(Circle(2, 2, 2));	
	ls1.AddToTail(Circle(3, 3, 3));
	std::cout << "Out List 1 after init" << endl << ls1 << sep;					//выводим список	

	ls1.Remove(Circle(5,5,5));			// удаляем первый элемент, равный заданному
	std::cout << "Out List 1 after delete 5 circle" << endl << ls1 << sep;

	ls1.RemoveAll(Circle(2, 2, 2));     // удаляем все элементы, равные заданному
	std::cout << "Out List 1 after delete all 2 circles" << endl << ls1 << sep;	
	//
	// 2. Приведенный ниже код должен выполняться корректно	
	//
	List ls2 = ls1;
	std::cout << "Out List 2 - copy List 1" << endl << ls2 << sep; 
	List ls3 = ls2;
	std::cout << "Out List 3 - copy List 2" << endl << ls3 << sep; 

	ls2.AddToHead(Circle(2, 2, 2));
	ls2.AddToHead(Circle(5, 5, 5));	
	
	std::cout << "Out List 2 after add to head 2 and 5 circles" << endl << ls2 << sep;	
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << "Out List 1 after copy from List 2" << endl << ls1 << sep;	
	
	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << "Out List 1 after copy from List 3" << endl << ls1 << sep;	
	//
	// 3. Вспоминаем про семантику перемещения	
	//
	List ls4 = std::move(ls2);
	std::cout << "Out List 4 after move from List 2" << endl << ls4 << sep; 
	std::cout << "Out List 2 after move List 4 from List 2" << endl << ls2 << sep; 	

	ls3 = std::move(ls4);
	std::cout << "Out List 3 after move from List 4" << endl << ls3 << sep; 
	std::cout << "Out List 4 after move List 3 from List 4" << endl <<ls4 << sep;
	//
	//4.  Сортировка по возрастанию площади кружка
	//
	std::cout << "Out List 3 before sorting" << endl << ls3 << sep;
	ls3.SortList();
	std::cout << "Out List 3 after sorting" << endl << ls3 << sep;
	//
	// 5. Файловый ввод/вывод
	//
	ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();
		
	ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();
	
	std::cout << "Out List 5 after read from file, which contains List 3" << endl << ls5 << sep;
	// 6. Дополнительные проверки
	//
	// ...

	return 0;
}