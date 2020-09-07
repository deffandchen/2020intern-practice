#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <typename T>
class sharedPtr{
public:
    sharedPtr(T* ptr = nullptr):_ptr(ptr) {
        if(_ptr!=nullptr){
            use_count = new size_t(1);
        }
        else{
            use_count = new size_t(0);
        }
    };
    sharedPtr(const sharedPtr<T>& ptr){
        if(this != &ptr){
            cout<< "error" << endl;
            return;
            //this->_ptr = ptr._ptr;
            //this->use_count = ptr.use_count;
            //(*this->use_count)++;
        }
    };
    T operator*(){
        return *this->_ptr;
    };
    int get_count(){
        return *this->use_count;
    };
    ~sharedPtr(){
        (*this->use_count)--;
        if(*this->use_count==0){
            delete this->_ptr;
            delete this->use_count;
        }
    };
private:
    T* _ptr;
    size_t* use_count;

};

int main(){

    sharedPtr<string> p(new string("ab"));
    cout << "p:" <<p.get_count() << endl;
    cout << *p << endl;
    {
        vector<sharedPtr<string>> vec;
        sharedPtr<string> p2(p);
        cout << "p:" << p.get_count() << endl;
        cout << "p2:" <<p2.get_count() << endl;
        vec.push_back(p);
        cout << "p:" << p.get_count() << endl;
        cout << "p2:" <<p2.get_count() << endl;
        vec.push_back(p2);
        cout << "p:" << p.get_count() << endl;
        cout << "p2:" <<p2.get_count() << endl;
    }
    cout << "p:" <<p.get_count() << endl;
    return 0;
}