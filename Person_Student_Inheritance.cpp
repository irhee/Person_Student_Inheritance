/******************************************************************************
pracitce using Vectory, and string header file
virtual, polimorphism and override function
and dynamic_cast 
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person{
    public:
        person();
        virtual ~person();
        void setName(string n);
        void setAge(int n);
        virtual void overWrite();
        string getName() const;
        int getAge() const;
    
    private:
        int age;
        string name;
};
        person::person(){
            cout<<"Person Constructor"<<endl;   
        }
        person::~person(){
            cout<<"Person Destructor"<<endl;
        }
        void person::overWrite(){
            cout<<"This is person overWrite"<<endl;
        }
        void person::setName(string n){
            name = n;
        }
        void person::setAge(int n){
            age = n;
        }
        string person::getName() const{
            return name;
        }
        int person::getAge() const{
            return age;
        }
class student:public person{
    public:
        student();
        ~student();
        void setSubject(string n);
        void setGrade(int n);
        void overWrite();
        string getSubject() const;
        int getGrade() const;
    
    private:
        int grade;
        string subject;
};
        student::student(): person() {
            cout<<"Student Constructor"<<endl;   
        }
        student::~student(){
            cout<<"Student Destructor"<<endl;
        }
        void student::overWrite(){
            cout<<"This is student overWrite"<<endl;
        }
        void student::setSubject(string n){
            subject = n;
        }
        void student::setGrade(int n){
            grade = n;
        }
        string student::getSubject() const{
            return subject;
        }
        int student::getGrade() const{
            return grade;
        }
int main()
{
    cout<<"Hello World"<<endl;
    vector <person*> p(10);
    
    p[0] = new person;    
    p[0]->setName("John");
    p[0]->setAge(10);
    cout<<"Name: "<<p[0]->getName()<<endl;
    cout<<"Age: "<<p[0]->getAge()<<endl;
    
    p[1] = new student;    
    p[1]->setName("Sue");
    p[1]->setAge(22);
    student* sp = dynamic_cast<student*> (p[1]);
    sp->setSubject("Calculus");
    sp->setGrade(80);
    cout<<"Name: "<<p[1]->getName()<<endl;
    cout<<"Age: "<<p[1]->getAge()<<endl;
    cout<<"Subject: "<<sp->getSubject()<<endl;
    cout<<"Grade: "<<sp->getGrade()<<endl;
    
    delete p[0];
    delete p[1];
    return 0;
}
