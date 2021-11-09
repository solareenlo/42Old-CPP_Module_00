# 42Old-CPP_Module_00

## ex02
#### Time format
- [strftime](https://www.cplusplus.com/reference/ctime/strftime/)

#### Static member function
> Static member functions have no *this pointer
>
>Static member functions have two interesting quirks worth noting. First, because static member functions are not attached to an object, they have no this pointer! This makes sense when you think about it -- the this pointer always points to the object that the member function is working on. Static member functions do not work on an object, so the this pointer is not needed.
>
>Second, static member functions can directly access other static members (variables or functions), but not non-static members. This is because non-static members must belong to a class object, and static member functions have no class object to work with!

Ref: [12.14 — Static member functions](https://www.learncpp.com/cpp-tutorial/static-member-functions/)
