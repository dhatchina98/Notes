# lvalue & rvalue

## -> lvalues

- lvalues are known as `locator values` and lvalues are objects that have an identifiable memory address.
- something like a double variable would be an lvalue.

## -> rvalues
- any expression that is not an lvalue is an rvalue and rvalues are expressions that can't have values assigned to them even if the rvalues are temporarily stored in memory at some location as part of the program's execution.
- something like a double literal value would be an rvalue it's technically stored in memory at some point but we `can't assign` to a literal value.


```c++

int x = 20;

// x - lvalue (identifiable memory address) - we can assign to x

// 20 - rvalue (not identifiable) - we can't assign to 20

```

```c++
// lvalue  =  rvalue
   int z   =  20;

// lvalue  =  lvalue
   int s   =  z;   

// above case both side is lvalues so we can't say always which is leftside that is lvalue like that    

```

```c++

int getValue1()
{
    return 10;
}

int& getValue2()
{
    static int value = 20;
    return value;
}

int main()
{
    int i = getValue1(); // method returns rvalue

    getValue1() = 20; // not possible (compiler error)  

    getValue2() = 5; // possible becoz it returns lvalue reference
} 

```

```c++
void setValue1(int i)
{
}

void setValue2(int& i)
{
}

void setValue3(const int& i)
{
}

int main()
{
   int i = 10;

   setvalue1(i); // possible - passing lvalue

   setvalue1(20); // possible - passing rvalue (temporary value)

   setvalue2(20); // not possible passing rvalue to reference (compiler error)

   setvalue3(20);  // possible see Note: 2
} 
```

## Note:

1. can't re-assign to lvalue when it's `const` variable

```c++

const int y = 10;

y = 15; // this is not possible becoz y is constant

```

2. can assign to lvalue reference when it's `const` 

```c++

int& a = 10; // not possible passing rvalue to reference (compiler error)

const int& a = 10; // possible 

//because compiler do this implicitly in background in this way

int temp = 10;

const int& a = temp; 

```

3. can't assign to lvalue when it's `memory address`

```c++

&x = 5; // not possible

```

4. can't get address of `rvalue`

```c++

int x = 20;

int *ptr1 = &x;  //  valid 

int *ptr2 = &(x+4);  // not valid -> x+4 is rvalue (stored somewhere but not identifiable)

```

5. we can get address of `rvalues` when its string literals

```c++

void *ptr = &"abc";  // valid

// because string literals are effectly stored as arrays in memory there's no other way to store them so we can get the memory address of that array

```

## Example

```c++

void printName1(std::string& name)
{
  std::cout << name << std::endl;
}

void printName2(const std::string& name)
{
  std::cout << name << std::endl;
}

void printName3(std::string&& name)
{
  std::cout << name << std::endl;
}

int main()
{
   //         lvalue     =   rvalue 
   std::string FirstName = "Dhatchina";
   std::string LastName  = "moorthi";
   std::string FullName  =  FirstName + LastName;

   printName1(FullName); // possible because its lvalue

   printName1(FirstName + LastName); // not possible because its rvalue

   printName2(FirstName + LastName); // possible 

   printName3(FullName); // not possible because its expecting rvalue reference

   printName3(FirstName + LastName); // possible because its rvalue reference

}



```