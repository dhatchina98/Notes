# `Standard Template Library (STL)`

- `#include <bits/stdc++.h>` - all the libraries automatically included by including this single header. 

### Four Parts of STL 
1. Algorithms
2. Containers
3. Functions
4. Iterators


## Introduction to `pair` 
-  pair is the part of `utility` library. it can store two values of any type within it. that two part also can be a another pair and so on.

```c++
   void explain_pair()
   {
    // store two integer in pair
    pair<int,int> p = {1,3};
    
    // access values from pair
    cout << p.first << " " << p.second;

    // nested pair 
    pair<int,pair<int,int>> p ={1, {2, 3}}; 
 
    // access nested pair
    cout << p.first << " " << p.second.first<< " "<< p.second.second;
     
    // arrays of pair
    pair<int,int> arr[] ={ {1, 2}, {3, 4}, {5, 6} };
    
    // access pair from array
    cout << arr[1].second;
   }
```

# 1. `Vector`

- vector is a container which dynamic in nature. we can increase the size of vector whenever u need.

- even if you're defining vector with size `vector<int> v(5);` still u can add element to the end. it grows dynamically.

```c++

using namespace std;

void explain_vector()
{
    // define a empty vector with data type
    vector<int> v;

    // add element to end 
    v.push_back(1);

    // similar to pushback but dynamically create new size and add
    v.emplace_back(2);

    // define vector with pair
    vector<pair<int, int>> vec;

    // push back pair 
    vec.push_back({1, 2});

    // no need to give { } for emplace back even if it is a pair
    vec.emplace_back(4, 7);
   
    // define vector with size and value {100, 100, 100, 100, 100}
    vector<int> v(5,100);
    
    // define vector with only size (it can be 0 or garbage value based on compiler)
    vector<int> v(5);

    vector<int> v1(5,20);
    // copying vector to another
    vector<int> v2(v1);

    //==========
    // Iterator 
    //==========

    // ex { 10, 15, 32, 14, 56}
    
    // iterator pointing the address
    vector<int>::iterator it = v1.begin();  // address of 10
    
    // shifting the pointer to next
    it++;       // pointing 15 address                                         
    
    // print the value from iterator/pointer
    cout<< *(it)<< endl;   // print 15 
   
   // shifting 2 position
   it =it + 2;    // move to address of 14

   cout<< *(it)<< endl;   // print 14

   // pointing to next position of end ( after 56 it will point )
   vector<int>::iterator it = v1.end();

   // reverse end  (pointing before 10)
   vector<int>::iterator it = v1.rend();

   // reverse begin ( pointing after 56)
   vector<int>::iterator it = v1.rbegin();

   // get value 
   cout<< v1[0] << " " << v1.at(0) << endl;

   // get the last value
   cout<< v1.back() << endl;


   //======================
   // iterating using loops
   //======================

   for(vector<int>::iterator it=v.begin(); it != v.end(); it++){
       cout<< *(it) << endl;
     }
   
            // or

   for(auto it=v.begin(); it != v.end(); it++){
    cout<< *(it) << endl;
    }     

            // or

    for(auto it : v){
     cout<< it << endl;
    }      


    //=========
    // deletion
    //=========      

    // ex { 10, 15, 32, 14, 56} 

    // erase the second element ( 15 )
    v.erase(v.begin()+1);  
    
    // erase given limit of vector { 32, 14 } removed
    v.erase(v.begin()+2, v.begin()+4); 


    //=========
    // insert
    //========= 

     vector<int> v(2,100); // {100, 100}
     v.insert(v.begin(), 300);  //  {300, 100, 100}
     v.insert(v.begin() +1 , 2 , 10);  //  {300, 10, 10, 100, 100}

     vector<int> copy(2, 50);  // {50, 50}
     v.insert(v.begin() , copy.begin() , copy.end());  //  {50, 50, 300, 10, 10, 100, 100}


    //=========
    // others
    //=========

     // gives size 
     cout << v.size() << endl;
     
     // pops out the last element {10, 20} 
     v.pop_back(); // {10}

     // v1 -> {10, 20}
     // v2 -> {30, 40}
     v1.swap(v2); // v1 -> {30, 40}  v2 -> {10, 20}

     // clear the vector
     v.clear();

     // check vector is empty
     cout << v.empty() << endl;

}

```

# 2. `List`

- list is a container which dynamic in nature. it is exactly similar to vector but u can do front side operation as well.


```c++

using namespace std;

void explain_list()
{   
    // declaration
    list<int> ls;

    // add element to end
    ls.push_back(2); // {2}

    // add element using its constructor
    ls.emplace_back(4); // {2, 4}

    // add element in front
    ls.push_front(5);  // {5, 2, 4} 
     
    ls.emplace_front()  // {2,4}

}

```
   
### `Note:`
- push front opertion u can achieve in vector by insert but insert is costlier than this push front because list is using double linked list and vector is using single linked list.

- `begin()` , `end()` , `rbegin()` , `rend()` , `clear()` , `insert()` , `size()` , `swap()` all methods works same like vector in list also.
     