#include "Bridge.h"

void HandsetGame::Run() {
    cout << "run game " << endl;
}

void HandsetAddressList::Run() {
    cout << "run address list" << endl;
}

HandsetBrand::HandsetBrand(HandsetSoft *handset_soft): handset_soft_(handset_soft) {}
HandsetBrandM::HandsetBrandM(HandsetSoft *handset_soft): HandsetBrand(handset_soft) {}

HandsetBrandM::~HandsetBrandM() {
  delete handset_soft_;
}

void HandsetBrandM::Run() {
    cout << "handset brand M :";
    handset_soft_->Run();
}

HandsetBrandN::HandsetBrandN(HandsetSoft *handset_soft): HandsetBrand(handset_soft) {}

HandsetBrandN::~HandsetBrandN() {
  delete handset_soft_;
}

void HandsetBrandN::Run() {
  std::cout << "handset brand N: ";
  handset_soft_->Run();
}