## [<<< back](../Index.md)             
# Copy Constructor 

- copy constructor is member function of the object create the object using the another object of same class.
- All class of c++ has default copy constructor.but, default copy constructor do `shallow copy` of object. it will make problem if our object used dynamically allocated data.
- so, if dynamically allocated data exists we have to do `deep copy` of the object.

```c++
#include <iostream>

using namespace std;

class BasicNumber
{
public:
  int n;

  BasicNumber(int set_n)
  {
    n = set_n; 
  }    

}

int main()
{
    BasicNumber num1(7);

    cout<<"num1: "<< num1.n <<endl;

    /** copy constructor
    * - here instead of calling num2 default constructor
    * the copy constructor will be called.
    * - all member variables will be copied to new object 
    */
    BasicNumber num2 = num1;
    
    cout<<"num2: "<< num2.n <<endl;

    return 0;
}
```
### output
```
num1: 7
num2: 7
```
- we can override the `copy constructor` function with our own implementations.

```c++
class BasicNumber
{
public:
  int n;

  BasicNumber(int set_n)
  {
    n = set_n; 
  }    

  // override default copy constructor
  BasicNumber(const BasicNumber& basicNum)
  {
    // own implementation
    n = 2 * basicNum.n; 
  }  

}

int main()
{
    BasicNumber num1(7);

    cout<<"num1: "<< num1.n <<endl;

    BasicNumber num2 = num1;
    
    cout<<"num2: "<< num2.n <<endl;

    return 0;
}
```
### output
```
num1: 7
num2: 14
```

## Note :
- copy constructor is not same as assignment operation

```c++
class BasicNumber
{
public:
  int n;

  BasicNumber(int set_n)
  {
    n = set_n; 
  }    

  BasicNumber(const BasicNumber& basicNum)
  {
    n = 2 * basicNum.n; 
    cout<<"copy constructor called: "<< n <<endl;
  }  

}

int main()
{
    BasicNumber num1(7);

    cout<<"num1: "<< num1.n <<endl;
    
    // copy constructor
    BasicNumber num2 = num1;
    
    cout<<"num2: "<< num2.n <<endl;

    BasicNumber num3(10);
    BasicNumber num4(15);

    //  assignment operator (not copy constructor)
    num3 = num4;

    return 0;
}
```
### output
```
num1: 7
copy constructor called: 14
num2: 14
```
- in above code copy construtor called only first time.  
- because, `num3=num4` is assignment operation. copy contructor called when one object initialize another object `BasicNumber num2 = num1`.


## Shallow Copy

```c++
class Number
{
public:
  int *n;

  // constructor which dynamically allocates memory
  Number(int set_n)
  {
    n = (int *) malloc(sizeof(int));
    *n = set_n; 
  } 
  
  // destructor to free memory
  ~Number
  {
    free(n);
  }   

  // get dereferenced n value
  int get()
  {
    return *n;
  }

}

int main()
{
    Number numA(7);

    cout<<"numA: "<< numA.get() <<endl;
    
    // copy constructor
    Number numB = numA;
    
    cout<<"numB: "<< numB.get() <<endl;

    return 0;
}
```
### output
```
numA: 7
numB: 7
```

- here default copy constructor is used and output looks like everything fine but not.
- it does shallow copy. it is copying the `numA int *` value to `numB int * `so, both has same address which means both are pointing same value in heap.

- once we change of numA value in heap its changed in numB also.

```c++
int main()
{
    Number numA(7);

    cout<<"numA: "<< numA.get() <<endl;
    
    // copy constructor
    Number numB = numA;
    
    cout<<"numB: "<< numB.get() <<endl;

    // change value of numA n 
    *(numA.n)=20;

    cout<<"numA: "<< numA.get() <<endl;
    cout<<"numB: "<< numB.get() <<endl;
    
    // exit before crashing to see output
    exit(0);

    /**
      when main reaches return both objects destructor will be called.but  both are pointing same memory in heap. so, its try to double free then code crashed.
     */
    return 0;
}
```
### output
```
numA: 7
numB: 7
numA: 20
numB: 20
```

## Deep Copy
- here we are overriding the default copy constructor and deep copying the given object member value to this object member.
- now both objects are pointing different `int *`. so, changes in one object will not affect another object. this is deep copy.
- in another words deep copy means not only stack values we are duplicating the heap values also.

```c++
class Number
{
public:
  int *n;

  // copy constructor for deep copy
  Number(const Number& anotherNum)
  {
    // allocates new memory for new object memner
     n = (int *) malloc(sizeof(int));
    // deep copy the value
    *n = *(anotherNum.n);
  }

  Number(int set_n)
  {
    n = (int *) malloc(sizeof(int));
    *n = set_n; 
  } 
  
  ~Number
  {
    free(n);
  }   

  int get()
  {
    return *n;
  }

}

int main()
{
    Number numA(7);

    cout<<"numA: "<< numA.get() <<endl;
    
    // copy constructor
    Number numB = numA;
    
    cout<<"numB: "<< numB.get() <<endl;

    // change value of numA n 
    *(numA.n)=20;

    cout<<"numA: "<< numA.get() <<endl;
    cout<<"numB: "<< numB.get() <<endl;
    
    return 0;
}
```

### output
```
numA: 7
numB: 7
numA: 20
numB: 7
```

## Copy Constructor Parameter Breakdown

```c++
Number(const Number& anotherNum)
  {
   // content for deep copy
  }
```

- here we have to use `const` keyword to restrict changes in given object
- we can't pass `(Number anotherNum)` by value because, if pass parameter by value it will take one more copy and for that copy you need copy constructor but already you are trying to create copy constructor.this will cause `circular dependency`. so, we have to pass by reference that is the reason for `Number& anotherNum`.