
template<typename T>
class Singleton {
public:
  static T *getInstance() {
    if (_instance == nullptr) {
      _instance = new T();
    }
    return _instance;
  }

private:
  static T *_instance;
};