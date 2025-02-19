
# Honeywell Written Test

1.Write example for Friend function

2.`+` Operator Overloading for two complex integers

3.Create class patient (id, name, age, status) with get and print function

4.Create get Area function to find area for circle, square, rectangle using function overloading

5.Find Mistake in code snippet

```c++
class Example {
public:
     Example () {  
           a = new int [10]; 
           }
     ~Example () { 
          delete a; 
          }
Private:
      Int * a;
};
```

6.Remove the unwanted condition

```c++
float income;

if(income < 0.0) { 
    cout << “debt” <<endl; }
else if(income >=0.0 && income < 1200.0) { 
   cout << “managable” <<endl; }
else if(income >=1200.0 && income < 2500.0) { 
   cout << “managable” <<endl; }
else if(income >=2500.0 && income > 2500.0) { 
   cout << “managable” <<endl; }
```

7.Write the output

```c++
void passValues(int &a, int& b, int& c){
a *= 2;
b *= 2;
c *= 2;
}

int main () {
int a = 2;
int b = 5;
int c = 10;

passValues(a, b, c);
cout << a << b << c <<endl;
return 0;
}
```

# Honeywell F2F Round 1

1.struct vs union

2.register storage class

3.struct padding

4.polymorphism

5.static global variables vs global variables

6.singleton

7.inline function

8.Coding - find minimum value in array

9.Coding - concat two strings using operator overloading

# Honeywell F2F Round 2

1.struct vs class

2.polymorphism

3.mutex vs semaphore

4.without virtual keyword calling method

5.friend function

6.singleton

7.pointer vs reference

8.create array of function pointers

9.Coding - operator overloading pre increment(++i) and post increment(i++)
