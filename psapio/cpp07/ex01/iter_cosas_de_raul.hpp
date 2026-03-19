// - ex01 → iter + función template aplicada a arrays.

#pragma once

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>   // para __cxa_demangle
#include <stdlib.h>

/*
template <typename T>
struct remove_const {
    typedef T type;
};

template <typename T>
struct remove_const<const T> {
    typedef T type;
};

template <typename T>
struct is_pointer { static const bool value = false; };

template <typename T>
struct is_pointer<T*> { static const bool value = true; };

template <typename T>
struct is_reference { static const bool value = false; };

template <typename T>
struct is_reference<T&> { static const bool value = true; };

template <typename T>
struct is_const { static const bool value = false; };

template <typename T>
struct is_const<const T> { static const bool value = true; };

template <typename T>
std::string demangled_name() {
    const char* mangled = typeid(T).name();
    int status = 0;
    char* demangled = abi::__cxa_demangle(mangled, 0, 0, &status);
    std::string result = (status == 0 && demangled != NULL) ? demangled : mangled;
    std::free(demangled);
    return result;
}

template <typename T>
void showTypeInfo() {
    std::cout << demangled_name<T>() << " : ";

    if (is_pointer<T>::value) std::cout << "puntero, ";
    else if (is_reference<T>::value) std::cout << "referencia, ";
    else std::cout << "normal, ";

    if (is_const<T>::value) std::cout << "const top-level";
    else if (is_pointer<T>::value && is_const<typename remove_const<T>::type>::value)
        std::cout << "puntero a const";
    else
        std::cout << "no const";

    std::cout << std::endl;
}

template <typename T>
void showTypeInfo(T) {
    showTypeInfo<T>();
}
 */


// imprime un elemento
template <typename T>
void print_array_element(T elementos)
{
    std::cout << elementos << "\n";
}



template <typename T>
void iter(T *array, int length, void (*func)(T &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}
/* 
template <>
void iter<const std::string>(const std::string *array, int length, void (*funct)(const std::string &))
{
    (void)array;
    (void)length;
    (void)funct;
    std::cout << "Hola\n";
}

template <>
void iter<const int>(const int *array, int length, void (*funct)(const int &))
{
    (void)array;
    (void)length;
    (void)funct;
    std::cout << "10\n";
}
 */