#include "Bridge.h"

int main() {
    HandsetBrand *handset_brand;
    handset_brand = new HandsetBrandM(new HandsetGame());
    handset_brand->Run();

    handset_brand = new HandsetBrandN(new HandsetAddressList());
    handset_brand->Run();
    delete handset_brand;
    return 0;
}