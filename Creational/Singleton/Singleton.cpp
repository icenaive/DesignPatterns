#include "Singleton.h"

Singleton *Singleton::instance_ = nullptr;
pthread_mutex_t Singleton::mutex_;


Singleton* Singleton::GetInstance() {
    if(instance_ == nullptr) {
        pthread_mutex_lock(&mutex_);
        if(instance_ == nullptr) {
            instance_ = new Singleton();
        }
        pthread_mutex_unlock(&mutex_);
    }
    return instance_;
}