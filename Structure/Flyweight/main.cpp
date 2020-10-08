#include "Flyweight.h"

int main() {
    WebsiteFactory *website_factory_ = new WebsiteFactory();
    Website  *website_ = website_factory_->GetWebsiteCategory("bbs");
    website_->Use(new User("Bob"));
    website_->Use(new User("Alice"));
    website_factory_->GetWebsiteCount();

    website_ = website_factory_->GetWebsiteCategory("blog");
    website_->Use(new User("Bob"));
    website_->Use(new User("Alice"));
    website_factory_->GetWebsiteCount();

    website_ = website_factory_->GetWebsiteCategory("bbs");
    website_->Use(new User("Bob"));
    website_->Use(new User("Alice"));
    website_factory_->GetWebsiteCount();
    return 0;
}