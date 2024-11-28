#include <iostream>

using namespace std;

// struct to hold allocated and deallocated memory size
struct mem_mgr
{
    int alloc_mem;
    int dealloc_mem;

    int cur_mem()
    {
        return alloc_mem - dealloc_mem;
    }
};

static mem_mgr mmgr;

// overloading new operator
void *operator new(size_t size)
{
    mmgr.alloc_mem += size;
    return malloc(size);
}

// overloading delete operator
void operator delete(void *memory, size_t size)
{
    mmgr.dealloc_mem += size;
    free(memory);
}

// object struct
struct object
{
    int a;
    int b;
    long c;
};

static void printCurUsage()
{
    cout << "occupied memory : " << mmgr.cur_mem() << endl;
}

int main()
{
    printCurUsage();
    object *obj1 = new object();
    object *obj2 = new object();
    printCurUsage();
    delete obj1;
    printCurUsage();
    delete obj2;
    printCurUsage();
    return 0;
}