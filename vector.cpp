#include <iostream>
#include "vector.h"
int main()
{
    Vector<int> Vec {1, 2, 3, 4, 5};
    Vec.replace(4,9924539);
    Vector<int> anotherVec {1, 3, 5, 7, 9};
    std::cout << anotherVec << std::endl;
    Vector<std::string> ob;
    ob.push_back("hello");
    ob.clear();
    if(ob.isEmpty())
    {
        std::cout << "cleary ashxatec" << std::endl;
    }    
    ob = {"hello" , "C++" , "how are you" , "initializer list"};
    ob.push_back("vector implementation");
    for(int i = 0; i < ob.size(); i++)
    {
        std::cout << ob[i] << std::endl;
    }
    Vector<int> another {1, 2, 3, 4, 5};
    another.erase(3);
    another.insert(4,99);
    another.insert(5,100);
    another.replace(4,1000);
    std::cout << another;
}