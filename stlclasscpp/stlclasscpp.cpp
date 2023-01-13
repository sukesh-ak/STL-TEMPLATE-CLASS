// 
// STL Template class which supports only 2 implementation for int & float
// Since using static_assert, the unsupported type error shows during compile
//

#include "stlclasscpp.h"
#include <vector>
#include <cassert>
#include <type_traits>

using namespace std;

// Template class which supports only int & float, otherwise assert during compile
template <typename T>
class MySTLClass {
private:
    std::vector<T> data;
public:
    MySTLClass() {
        // static_assert gives compile time error
        static_assert(std::is_same<T, int>::value || std::is_same<T, float>::value, 
            "Invalid type for MySTLClass. Only int and float are supported.");
    }

    // Different function implementation code for int and float
    void push_back(T element) {
        // Implementation for int
        if constexpr (std::is_same<T, int>::value) {
            std::cout << "Special push_back for int type" << std::endl;
            data.push_back(element);
        }
        // Implementation for float
        else if constexpr (std::is_same<T, float>::value) {
            std::cout << "Special push_back for float type" << std::endl;
            data.push_back(element);
        }
    }
    T operator[](int index) {
        return data[index];
    }
    int size() {
        return data.size();
    }
};


int main()
{
	cout << "Hello STL Template Class." << endl;

    MySTLClass<int> int_container;
    int_container.push_back(1);
    int_container.push_back(2);
    int_container.push_back(3);
    std::cout << "Size of int container: " << int_container.size() << std::endl;
    std::cout << "Second element: " << int_container[1] << std::endl;

    MySTLClass<std::string> string_container;
    string_container.push_back("first");
    string_container.push_back("second");
    string_container.push_back("third");
    std::cout << "Size of string container: " << string_container.size() << std::endl;
    std::cout << "Second element: " << string_container[1] << std::endl;

    MySTLClass<float> float_container;
    float_container.push_back(1.1);
    float_container.push_back(2.2);
    float_container.push_back(3.3);
    std::cout << "Size of int container: " << float_container.size() << std::endl;
    std::cout << "Second element: " << float_container[1] << std::endl;

	return 0;
}
