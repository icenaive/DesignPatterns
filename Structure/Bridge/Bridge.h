#include <iostream>
using namespace std;

class HandsetSoft {
public:
    virtual void Run() {}
};

class HandsetGame : public HandsetSoft {
public:
    void Run();
};

class HandsetAddressList : public HandsetSoft {
public:
    void Run();
};

class HandsetBrand {
public:
    HandsetBrand() {}
    HandsetBrand(HandsetSoft*);
    virtual ~HandsetBrand() {}
    virtual void Run() {}
protected:
    HandsetSoft *handset_soft_;
};

class HandsetBrandM : public HandsetBrand {
public:
    HandsetBrandM() {}
    HandsetBrandM(HandsetSoft*);
    ~HandsetBrandM();
    void Run();
};

class HandsetBrandN : public HandsetBrand {
public:
    HandsetBrandN() {}
    HandsetBrandN(HandsetSoft*);
    ~HandsetBrandN();
    void Run();
};
