#include "vector.h"

template <typename T>
Vector<T>::Vector() : m_size{} , m_capacity{2}
{
    m_vec = new T[m_capacity];
}

template <typename T>
Vector<T>::Vector(int capacity)
{
    m_capacity = capacity;
    m_size = 0;
    m_vec = new T[m_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_vec = new T[m_capacity];
    for(int i = 0; i < other.m_size; i++)
    {
        m_vec[i] = other.m_vec[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector&& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    for(int i = 0; i < other.m_size; i++)
    {
        m_vec[i] = other.m_vec[i];
    }
    other.m_size = 0;
    other.m_capacity = 0;
    delete[] other;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_vec;
    m_vec = nullptr;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
    if(m_size == m_capacity)
    {
        resize();
    }
    m_vec[m_size++] = value;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init)
{
    m_capacity = init.size();
    m_size = m_capacity;
    m_vec = new T[m_capacity];
    int i = 0;
    for(auto iter = init.begin() ; iter != init.end(); ++iter)
    {
        m_vec[i++] = *iter;
    }
}

template <typename T>
void Vector<T>::pop_back()
{
    --m_size;
}

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
void Vector<T>::resize()
{
    m_capacity *= 2;
    T* tmp = new T[m_capacity];
    if(tmp == nullptr)
    {
        std::cerr << "Failed in resize() function ! " << std::endl;
        exit(0);
    }
    else
    {
        for(int i = 0; i < m_size; i++)
        {
            tmp[i] = m_vec[i];
        }
        for(int i = m_size; i < m_capacity; i++)
        {
            tmp[i] = ' ';
        }
        delete[] m_vec;
        m_vec = tmp;
    }
}

template <typename T>
void Vector<T>::erase(int index)
{
    if (index >= 0 && index < m_size)
    {
        m_size--; 
        T* tmp = new T [m_size];
        for (int i = 0, j = 0; i < m_size + 1, j < m_size; i++, j++) 
        {
            if (i == index) 
            {
                j--;
                continue;
            }
            else
            {
                tmp[j] = m_vec[i];
            }
        }
        delete[] m_vec;
        m_vec = tmp;
        tmp = nullptr;       
    }
    else
    {
        std::cerr << "Wrong index , check erase() function ! " << std::endl;
        exit(0);
    }
}

template <typename T>
const T& Vector<T>::at(int index)
{
    if(index < m_size && index >= 0)
    {
        return m_vec[index];
    }
    else
    {
        std::cerr << "Wrong index  , check at() function !" << std::endl;
        exit(0);
    }
}

template <typename T>
const T& Vector<T>::operator[](int index)
{
    return m_vec[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    delete[] m_vec;
    if(this == &other) {return *this;}
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_vec = new T[other.m_capacity];
    for(int i = 0; i < other.m_size; i++)
    {
        m_vec[i] = other.m_vec[i];
    }
    return *this;
}

template <typename T>
bool Vector<T>::isEmpty()
{
    return !m_size;
}

template <typename T>
int Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    if(m_capacity > m_size) 
    {
        m_capacity = m_size;
    }
}


template <typename T>
void Vector<T>::clear() 
{
    m_size = 0;
    delete[] m_vec;
    m_vec = new T[m_capacity];
}

template <typename T>
void Vector<T>::insert(int index ,const T& value)
{   
   T* tmp = new T[m_capacity]; 
   for(int i = 0; i < m_size; i++)
   {
       if(i == index)
       {
           std::cerr << "The index " << index << " has already occupied , check insert() function !" << std::endl;
           exit(0);
       }
       else
       {
           tmp[i] = m_vec[i];
       }
   }
   m_size += 1;
   tmp[index++] = value;
   delete[] m_vec;
   m_vec = tmp;
   tmp = nullptr; 
}

template <typename T>
void Vector<T>::replace(int index ,const T& value)
{
    if(index < 0 || index >= m_size)
    {
        std::cerr << "Wrong index , please check replace() function !" << std::endl;
        exit(0);
    }
    T* tmp = new T[m_capacity];
    for(int i = 0; i < m_size; i++)
    {
        tmp[i] = m_vec[i];
    }
    for(int i = 0; i < m_size; i++)
    {
        if(i != index)
        {
            continue;
        }
        else
        {
            tmp[i] = tmp[i + 1];
            tmp[index] = value;
        }
    }
    delete[] m_vec;
    m_vec = tmp;
    tmp = nullptr;
}