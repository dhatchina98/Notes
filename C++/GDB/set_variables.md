# set variable
There are 3 type of variables is there in gdb context.
1. history variable `$1`, `$2`, etc
2. program variable `a`, `b`, etc
3. debugger variable `$var1`, `$var2`, etc

## 1. access object through history variable 
- `history variable` preceded by $ symbol and will created by gdb automatically.we can use that to access objects.

- Point a(1,2);   -> this is the object
- if i print this using `print(or)p` command output is 
 
```
$1 = {x=1, y=2}
```  
i can use this history variable `$1` to access that object values

```c++
(gdb) p $1

//output
$2 = {x=1, y=2}

(gdb) p $1.x

//output
$3 = 1

(gdb) p $1.y

//output
$4 = 2

(gdb) p $4

//output
$5 = 2
```

## 2. set program variable
- `program variables` is which are exist inside the code. we can set those values.

```c++
#include <iostream>
using namespace std;

class Node{
  int data;
  Node * next;

public:
  Node(int x, Node * next = nullptr):data{x},next{next} {}
};

int main(){
  Node a(1, NULL);
  Node b(2, NULL);
}
```

now i can print this object a, b using p

#### Note:
here a, b are `program variables`.

```c++
(gdb) p a

//output
$1 = {data = 2, next = 0x0}
```

i can set value to that object variable using `set variable` command

```c++
// set value to program variable
(gdb) set variable a.data=5

// check 
(gdb) p a

// output
$2 = {data = 5, next = 0x0}
```

```c++
// set pointers also using this
(gdb) set variable b.next=&a

// check 
(gdb) p b

// output
$2 = {data = 2, next = 0x000257784f}
```

```c++
//print the object stored in next
(gdb) p b.next

// output
$3 = (Node *) 0x000257784f

//to dereference this
(gdb) p *b.next

// output
$4 = {data = 5, next = 0x0}
```

## 3. set gdb/debugger variable
- `gdb/debugger variables` are created by us using $ symbol and it will accept any data type and we can use that in run time.

```c++
// create and set gdb variable
(gdb) set variable $myVar=10

// print
(gdb) p $myVar

// output
$5 = 10
```

```c++
// reassign that with expressions
(gdb) set variable $myVar=10*4*5

// print
(gdb) p $myVar

// output
$6 = 200
```
```c++
// assign address also
(gdb) set variable $myVar=&a

// print
(gdb) p $myVar

// output
$7 = (Node *) 0x000257784f
```
