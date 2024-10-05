# gdb commands

- To debug your code using gdb u have to compile the code by adding `-g` argument.
  
  ```c++
  //command for compiling
  g++ -g example.cpp -o ex
  ``` 

  ```c++
  //command for debugging
  gdb ex
  ``` 

### example.cpp
  ```c++ 
  #include <iostream>          // line 1
  using namespace std;         //  2
                               //  3
void fun3()                  //  4
  {                            //  5
    int fun3Var = 25;          //  6
    cout << fun3Var << endl;   //  7
  }                            //  8
                               //  9
void fun2()                  //  10
  {                            //  11
    int fun2Var = 20;          //  12
    cout << fun2Var << endl;   //  13
    fun3();                    //  14
  }                            //  15
                               //  16
void fun1()                  //  17
  {                            //  18
    int fun1Var = 10;          //  19
    cout << fun1Var << endl;   //  20
    fun2();                    //  21
  }                            //  22
                               //  23
int main()                   //  24
  {                            //  25
    int mainVar = 5;           //  26
    cout << mainVar << endl;   //  27
    fun1();                    //  28
    return 0;                  //  29
  }                            //  30
  ```

## 1. breakpoint (or) b  
- you can add breakpoints using `line number` or `function name`.

```
(gdb) b main
```  
output

```
Breakpoint 1 at 0x00wgbw: file example.cpp, line 24
```

## 2. run (or) r
- to run the program. 

```
(gdb) r
```  
output

```
Starting program:

Breakpoint 1, main () at example.cpp:26
26     int mainVar = 5;
```

## 3. list (or) l
- to see some part of ur program.

```
(gdb) l
```  
output

```
    int fun1Var = 10;          
    cout << fun1Var << endl;   
    fun2();                    
  }                           
                               
int main()                   
  {                            
    int mainVar = 5;           
    cout << mainVar << endl;   
    fun1();                    
    return 0;                  
  } 
```

## 4. next (or) n
- using this u can go to `next line`

```
(gdb) n
```  
output

```
27    cout << mainVar << endl;
```

## 5. print (or) p
- to print a variable / object

```
(gdb) p mainVar
```  
output

```
$1 = 5
```

## 6. step (or) s
- if u use `next` command instead of entering into function u will come to the next line of function call

your current line is 
`fun1();`                    

```
(gdb) n
```  
output

```c++
5     //output of main
10    //output of fun1
20    //output of fun2
25    //output of fun3

29   return 0;   // u r jumping to next line 
```

so, instead of `next` u should use `step`

```
(gdb) s
```  
output

```
19    int fun1Var = 10;
```

## 7. backtrace (or) bt
- from where u r coming and currently where u are

```
(gdb) bt
```  
output

```
#0 fun2 () at example.cpp:12
#1 0x000008545  in fun1 () at example.cpp:21
#2 0x000008596 in main () at example.cpp:28
```

## 8. info 
- `info b` -  it will show u `how many break points` are there

```
(gdb) info b
```  
output

```
1 breakpoint in main() at example.cpp:26 
```

- `info locals` -  it will print all local variables

```
(gdb) info locals
```  
output

```
fun3var = 25
```

## 9. delete 
- you can `delete` the break point using its number

```
(gdb) delete 1
```  
then,

```
(gdb) info b
```  
output

```
No breakpoints or watchpoints.
```

## 10. continue (or) c 
- jump to `next break point`.

```
(gdb) c
```  
output

```
Breakpoint 3, fun3 () at example.cpp:6
6   int fun3Var = 25; 
```

## 11. frame (or) f
- it will show where are u right now
  
```
(gdb) f
```    
output

```
26     int mainVar = 5;
```

### frame with number (or) f "num"
- when u r in other place that time u can jump to other frames using f along with that frame number 
- to know frame numbers u can use `backtrace` or `bt` 

```c++
(gdb) bt

// output
#0 fun2 () at example.cpp:12
#1 0x000008545  in fun1 () at example.cpp:21
#2 0x000008596 in main () at example.cpp:28
```
- currently u r in fun2 and its frame number is 0
  
- now go to main and print its variable

```c++
(gdb) f 2

// output
#2 0x000008596 in main () at example.cpp:28

(gdb) p mainVar

// output
$6 = 5
```

#### Note:
 if  u try to print this mainVar from the fun2 itself u will get the error. because its local variable to that function. 

 ```
 No symbol "mainVar" in current context. 
 ```
