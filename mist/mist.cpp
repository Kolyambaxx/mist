// mist.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Abstraction {
public:
    virtual void operation() const = 0;
    virtual ~Abstraction() = default;
};


class Implementation {
public:
    virtual void implementationOperation() const = 0;
    virtual ~Implementation() = default;
};


class ConcreteAbstraction : public Abstraction {
public:
    ConcreteAbstraction(Implementation* impl) : implementation(impl) {}

    void operation() const override {
        std::cout << "Abstraction: ";
        implementation->implementationOperation();
    }

private:
    Implementation* implementation;
};


class ConcreteImplementationA : public Implementation {
public:
    void implementationOperation() const override {
        std::cout << "Concrete Implementation A" << std::endl;
    }
};


class ConcreteImplementationB : public Implementation {
public:
    void implementationOperation() const override {
        std::cout << "Concrete Implementation B" << std::endl;
    }
};

int main() {
 
    ConcreteImplementationA implA;
    ConcreteImplementationB implB;

    ConcreteAbstraction abstractionA(&implA);
    abstractionA.operation();

    ConcreteAbstraction abstractionB(&implB);
    abstractionB.operation();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
