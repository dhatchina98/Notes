# decltype keyword

- decltype is a keyword in C++ that allows you to deduce the type of an expression at compile-time. It was introduced in C++11 as a way to simplify template metaprogramming and make code more expressive.

```c++
decltype(expression)
```

- When you use decltype, the compiler evaluates the given expression and returns its type. The expression itself is not evaluated at runtime; it's only analyzed by the compiler to determine its type.

### Key Aspects

1. `Compile-time evaluation`: The expression inside decltype is evaluated at compile-time, which means that the result is determined before your program even runs.

2. `No runtime execution`: The expression itself is not executed at runtime; it's only analyzed by the compiler to determine its type.

3. `Type deduction`: decltype deduces the type of the given expression based on the operator overloads, implicit conversions, and other language rules that apply to the expression.

```c++
int x = 5;
decltype(x) y; // Type of y is int

decltype(5 + 3.14) z; // Type of z is double (due to implicit conversion)

struct Point {
    int x, y;
};

Point p;
decltype(p.x) q; // Type of q is int
```

### Advantages:

- `Expressiveness`: You can write more expressive and concise code by directly specifying the type of an expression.

- `Less typing`: You don't need to manually specify types for variables or function return values when you use decltype.

- `Fewer errors`: Since decltype deduces the correct type at compile-time, it helps reduce the likelihood of type-related errors.

### Note:
However, keep in mind that overusing decltype can make your code harder to read and understand. It's essential to strike a balance between conciseness and readability when using this feature.