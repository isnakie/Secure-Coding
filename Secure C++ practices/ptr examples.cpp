/*
// Demonstrating why the following code is not secure practice
// vulnerable to race condition on which of the two ended up deleting the pointer
// The second one will cause a double-free condition.
// The last will execute arbitrary code.

class DumbPtrHolder
{
public:
DumbPtrHolder(void* p) : m_ptr(p)
{
}
~DumbPtrHolder()
{
delete m_ptr; 
// 'delete'-ing m_ptr can lead to undefined behavior since 'delete' requires a pointer
// the 'delete' operator requires a pointer to a specific type to properly invoke 
// the destructor and deallocate the correct amount of memory.
// m_ptr is a void*, which does not carry any type of information.
}
private:
void* m_ptr;
};\
*/

// Utilizing template parameter for typing - use a template to specify the type of pointer 
// Ensures proper destructor is called
template <typename T>
class BetterPtrHolder
{
public:
    BetterPtrHolder(T* p) : m_ptr(p) {}
    ~BetterPtrHolder() { delete m_ptr; }

private:
    T* m_ptr;
};

// Or utilize Smart pointers
// std::unique_ptr is efficient, lightweight, and reduces likelihood of memory leaks
// ideal for managing resources that should not be shared, such as file handles or network connections
#include <memory>

class SmartPtrHolder
{
public:
    SmartPtrHolder(std::unique_ptr<int> p) : m_ptr(std::move(p)) {}
    // No need for an explicit destructor

private:
    std::unique_ptr<int> m_ptr;
};
