#include <string>
#include <iostream>
using namespace std;

class WorkExperience {
public:
    void set_company(string company) {
        this->company_ = company;
    }
    void set_time_area(string time_area) {
        this->time_area_ = time_area;
    }
    string get_company() { return company_; }
    string get_time_area() { return time_area_; }
    WorkExperience *clone() {
        WorkExperience *new_work_clone = new WorkExperience();
        new_work_clone->set_company(company_);
        new_work_clone->set_time_area(time_area_);
        return new_work_clone;
    }
private:
    string company_;
    string time_area_;
};

class Resume {
public:
    Resume() {}
    Resume(string name) { this->name_ = name; this->word_experience_ = new WorkExperience(); }
    ~Resume() { delete this->word_experience_;}
    void set_name(string name) {
        this->name_ = name;
    }
    void set_person_info(string sex, string age) {
        sex_ = sex;
        age_ = age;
    }
    void set_work_experence(string company, string time_area) {
        word_experience_->set_time_area(time_area);
        word_experience_->set_company(company);
    }
    Resume *clone() {
        Resume *new_resume = new Resume(name_);
        new_resume->set_person_info(sex_, age_);
        new_resume->word_experience_ = word_experience_->clone();
        return new_resume;
    }
    void print_resume() {
        cout << name_ << "," << sex_ << "," << age_ << "," << word_experience_->get_company()\
         << "," << word_experience_->get_time_area() << endl;
    }
private: 
    string name_;
    string sex_;
    string age_;
    WorkExperience *word_experience_;
};
