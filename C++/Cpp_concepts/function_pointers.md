## [< back](../../Index.md)   
# Function Pointers

- Function pointer is way for assign funtion to a variable.

## Normal Function Call

```c++
#include <iostream>

void HelloWorld(){
    std::cout<<" hello ..."<<std::endl;
}

int main(){
   HelloWorld();
}
```

## Assign function pointer to variable

```c++
#include <iostream>

void HelloWorld(){
    std::cout<<" hello ..."<<std::endl;
}

int main(){
   auto func = HelloWorld; // implicitly &HelloWorld

   func();
   func();
}
```
- type of this function pointer is `void(*func)()`. // `return_type(* fun_ptr_name)(params)`
- so , we can write 

```c++

int main(){

   void(*func)() = HelloWorld;
   
   func();
   func();

    //------- or -----------

   typedef void(*helloworldFunc)();
    
    helloworldFunc function = HelloWorld;
   
    function();
    function();

}
```

## where to use ?

```c++
#include <iostream>
#include <vector>

void printValue(int value){
std::cout<<"value :"<<value<<std::endl;
}

void forEach(std::vector<int>& values, void(*func)(int)){
    for(int val:values){
        // calling function through its pointer
        func(val);
    }
}

int main(){
   std::vector<int> values ={1,2,3,4,5};
   
   // passing function ptr to another function
   forEach(values, printValue);

}
```

- we can make this even more simple using lambda 

```c++
#include <iostream>
#include <vector>

void forEach(std::vector<int>& values, void(*func)(int)){
    for(int val:values){
        // calling function through its pointer
        func(val);
    }
}

int main(){
   std::vector<int> values ={1,2,3,4,5};
   
   forEach(values, [](int value){std::cout<<"value :"<<value<<std::endl;});

}
```


