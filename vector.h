#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>

class Vector
{
public:
    Vector();
    Vector(int);
	Vector(const Vector&);
	Vector(Vector&&);
    Vector<T>& operator=(const Vector&);
    Vector(std::initializer_list<T>);
    const T& operator[](int);
    ~Vector();

public:
    void push_back(const T&);
    void pop_back();
    int size() const;
    int capacity() const;
    const T& at(int);
    void erase(int);
    void resize();
    void shrink_to_fit();
    void clear();
    bool isEmpty();
    void insert(int,const T&);
    void replace(int , const T&);
    T* begin();
    T* end();
    template <typename Y>
    friend std::ostream& operator << (std::ostream& print,  Vector<T>& obj);
private:
    T* m_vec;
    int m_capacity;
    int m_size;
};

template <typename T>
std::ostream& operator << (std::ostream& print, Vector<T>& obj)
    {
        print << "Your vector contains : ";
        for(int i = 0; i < obj.size(); i++)
        {
            print << obj[i]<< "\t";
        }
        print << std::endl;
        return print;
    }

#include "implementation.hpp"
#endif