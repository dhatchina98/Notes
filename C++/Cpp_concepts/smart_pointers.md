
# smart pointers

### raw pointers con's
- raw pointers allow sharing but, it is allow room for errors (forgetting to deallocate)
- ownership of pointers (deallocate pointer from some where and using it from other place without knowing)
- smart pointers are addressing these issues 

# 1. unique_ptr (scoped smart pointer)

```c++
#include <iostream>
#include <memory>  // for smart pointers

class Base
{
    Base(){ std::cout << "constructor" << std::endl;}
   ~Base(){ std::cout << "destructor" << std::endl;}
};

int main()
{
    // creating one unique pointer 
    std::unique_ptr<Base> ptr1 = std::unique_ptr<Base>(new Base);

    // creating an array that is pointed to, by one unique pointer
     std::unique_ptr<Base[]> ptr2 = std::unique_ptr<Base[]>(new Base[10]);

    // equivalent to above line and preferred way
     std::unique_ptr<Base[]> ptr3 = std::make_unique<Base[]>(10); // pass count

     //Note:
     // treat this brackets ( ) like constructor brackets

}
```

- we `can't share or copy` (no copies allowed). because, unique ptr's are not CopyConstructable and not CopyAssignable.

```c++

int main()
{
    // creating one unique pointer 
    std::unique_ptr<Base> ptr1 = std::make_unique<Base>(); 
    
    // trying to copy 
    std::unique_ptr<Base> ptr2 = ptr1; // compilation error

}
```

- we `can move`. we can transfer the ownership to another unique ptr.

```c++

int main()
{
    // creating one unique pointer 
    std::unique_ptr<Base> ptr1 = std::make_unique<Base>();
    
    // moving ownership
    std::unique_ptr<Base> ptr2 = std::move(ptr1); // valid

}
```
- we `don't have to delete`. when scope ends automatically unique ptr memory address will be automatically deallocated.
 
```c++

int main()
{
    // creating one unique pointer 
    std::unique_ptr<Base> ptr1 = std::make_unique<Base>();
    
    // no need to delete
    //delete ptr1; 
}
```
