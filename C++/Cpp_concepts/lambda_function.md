# lambda function

- lambdas are essentially a way to create anonymous function.they are quickly disposable functions.

### 1. passing parameters
-  here this lambda expression accepts one integer parameter `(int a)`. that we are passing after its definition `value = 5`

```c++
    [](int a)
      { cout << a << endl; }(5);
```
- u can pass reference of another variable as a parameter `(int &a)`. here we are passing reference of `b` and changing its value inside of lambda function.

```c++
    int b = 10;
    
    [](int &a)
      { a = 15; }(b);
```

### 2. using outside variable inside lambda

if u want to use variables which is initialized outside of lambda function u have to pass respective operator to use it.

- if it has `[ ]` lambda function don't have access to outside variables. 

- if it has `[=]` outside variables passed inside lambda function as a values `(passed by values)`  

 ```c++
    int b = 10;

    // we can use b inside lambda but can't change it.
    [=](int a)
       { cout << b + a << endl; }(5);
 ```
    
- if it has `[&]` outside variables passed inside lambda function as a reference `(passed by reference)`

 ```c++
    int b = 10;

    // we can change b inside lambda.
    [&](int a)
       { b = a; }(5);
 ```



