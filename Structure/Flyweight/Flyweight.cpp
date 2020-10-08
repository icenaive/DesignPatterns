#include "Flyweight.h"

User::User(string name) : name_(name) {}
string User::GetName() {
    return name_;
}

ConcreteWebsite::ConcreteWebsite(std::string website_name): website_name_(website_name) {}
void ConcreteWebsite::Use(User *user) {
    cout << user->GetName() << " use " << website_name_ << endl;
}

WebsiteFactory::~WebsiteFactory() {
  for(auto it = flyweights_.begin(); it != flyweights_.end(); it++) {
    delete it->second;
  }
}

Website* WebsiteFactory::GetWebsiteCategory(string Website_name) {
    if(flyweights_.find(Website_name) == flyweights_.end()) {
        Website *website = new ConcreteWebsite(Website_name);
        flyweights_[Website_name] = website;
    }
    return flyweights_[Website_name];
}

int WebsiteFactory::GetWebsiteCount() {
    int cnt = (int)flyweights_.size();
    cout << cnt << endl;
    return cnt;
}