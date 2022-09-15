class Singleton
{
public:
  static Singleton* getInstance()
  {
    if(_instance == nullptr)
    {
      _instance = new Singleton();
    }
    return _instance;
  }

private:
  static Singleton* _instance;
};