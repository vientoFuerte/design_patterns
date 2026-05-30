// Паттерн Одиночка (Singleton)
// 1. Дает гарантию что у класса будет всего лишь один экземпляр класса.
// 2. Предоставляет глобальную точку доступа к экземляру данного класса.

#include <iostream>

class Singleton{

int data {0}; // данные класса
static Singleton* instance_ptr;//Статический указатель будет ссылаться на единственный объект этого класса.
//конструктор по умолчанию в приватной секции, чтобы запретить создание объектов класса.
Singleton() = default;


public:
//запретим создание конструктора копирования ()
Singleton (const Singleton&) = delete;
//деструктор. Можно заново создать объект класса при удалении прежнего
~Singleton(){instance_ptr = nullptr;}


};
Singleton* Singleton::instance_ptr = nullptr;

int main() {

    std::cout << "=== Singleton ===" << std::endl;

}
