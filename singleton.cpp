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

static Singleton* get_instance()
  {
    // В первый раз создаем объект, в последующие разы возвращается адрес созданного объекта.
    if(instance_ptr == nullptr)
    {
      instance_ptr = new Singleton();
    }
    return instance_ptr;
  }
  
  void set_data (int value)
  {data = value;}
  
  int get_data ()
  {return data;}
  
};
Singleton* Singleton::instance_ptr = nullptr;

int main() {

    std::cout << "=== Singleton ===" << std::endl;
    
    //Singleton s; - напрямую создавать объекты класса нельзя - конструктор приватный
    Singleton* ptr = Singleton::get_instance();
    
    std::cout << "ptr = "<< ptr << std::endl;
    // Адрес второго объекта будет совпадать с первым, тк это один объект
    Singleton* ptr2 = Singleton::get_instance();
    std::cout << "ptr = "<< ptr2 << std::endl;
    
    ptr->set_data(1);
    std::cout <<" data obj 1= "<< ptr->get_data() << std::endl;
    std::cout <<" data obj 2= "<< ptr2->get_data() << std::endl;
    
  delete ptr;
  return 0;
}
