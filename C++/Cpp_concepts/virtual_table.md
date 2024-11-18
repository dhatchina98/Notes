# Virtual Table (vtable)

- C++ standard doesn't force any particular way the virtual functions should be implemented.
- However, c++ compilers like MSVC, Clang or GCC implement the virtual functions using the `virtual method table`.
- when a class implements `virtual function`, the compiler is going to create `Virtual Table`. this table is a simple array which contains addresses of the virtual functions that the class implements or derives.  
