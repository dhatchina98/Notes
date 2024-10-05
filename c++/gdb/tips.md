# Gnu DeBugger (GDB) Tips

## 1. printing objects 

- to print object `p "object name" ` -> ex: p a
  
  ```
   $1 = { b = {a = {i=2}}}
  ```

- to print object in hierarchy `set print pretty on`. then print using `p`

   ```
   $2 = {
     b = {
        a = {
            i=2
            }
        }
    }
  ``` 
  
## 2. reuse break points

- when u debug with gdb if u add breakpoints it will be available until that runtime. if u rerun the code all break points will be not available.
- to solve this u can store ur break points in file and u can reload while running again and again.

after adding break points save that in file
```
(gdb) save breakpoints bp_file
```
now all breakpoints are stored in bp_file

to restore that next time

```
(gdb) source bp_file
```
now all breakpoints are restored from file

## 3. to know type of object

- to know the type variables, objects, pointers u can use `ptype` command with the instance.

- ex: i have class Point and that object name is a 

```
(gdb) ptype a
```
output:

```c++
class Point{

int x;
int y;

};
```
it will print the class which is type of a.



