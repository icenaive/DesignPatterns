#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    Player() {}
    Player(string name) : name_(name) {}
    virtual void Attack() = 0;
    virtual void Defense() = 0;
protected:
    string name_;
};

class Forward : public Player{
public:
    Forward() {}
    Forward(string name) : Player(name) {}
    void Attack();
    void Defense();
};

class Center: public Player {
public:
  Center() {}
  Center(string name) : Player(name ) {}
  void Attack();
  void Defense();
};
class ForeignCenter {
public:
  ForeignCenter() {}
  ForeignCenter(string name) : name_(name) {}
  void Gong();
  void Shou();
private:
  std::string name_;
};

class Translator : public Player {
public:
    Translator() {}
    Translator(string);
    ~Translator();
    void Attack();
    void Defense();
private:
    ForeignCenter *foreign_center_;
};