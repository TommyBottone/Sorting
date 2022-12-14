template<class T>

class SmartPtr
{
  T* ptr;
public:

  explicit SmartPtr(T* p = nullptr) 
  {
    ptr = p;
  }

  ~SmartPtr()
  {
    delete (ptr);
  }

  T& operator*()
  {
     return *ptr; 
  }

  T* operator->() 
  {
    return ptr;
  }

};