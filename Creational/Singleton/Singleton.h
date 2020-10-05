#include <pthread.h>
using namespace std;

class Singleton {
private:
    Singleton() {} ;
public:
    static Singleton *GetInstance();
private:
    static Singleton *instance_;
    static pthread_mutex_t mutex_;
};