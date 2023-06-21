//
// Created by 25721 on 2023/6/20.
//
//set
#include <iostream>
#include <set>
#include <string>
using namespace std;

void printSetInt(set<int> &s){
    //set容器是只读迭代器，const_iterator
    set<int>::const_iterator it = s.begin();
    for(;it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void set_test1(){
    set<int> s1;
    s1.insert(10);
    s1.insert(90);
    s1.insert(30);
    s1.insert(40);
    printSetInt(s1);
}


class MyGreater{
public:
    bool operator()(int v1,int v2){
        return v1>v2;
    }
};
void printSetIntM(set<int,MyGreater> &s){
    //set容器是只读迭代器，const_iterator
    set<int,MyGreater>::const_iterator it = s.begin();
    for(;it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void set_test2(){
    //从大到小排序，set容器
    set<int,MyGreater> s1;
    s1.insert(10);
    s1.insert(90);
    s1.insert(30);
    s1.insert(40);
    printSetIntM(s1);
}


class MyGreaterPerson;
//set存自定义数据，必须修改排序规则
class Person{
    friend class MyGreaterPerson;
    friend void printSetPerson(set<Person,MyGreaterPerson> &s);
private:
    int num;
    string name;
    float score;
public:
    Person(){}
    Person(int num, string name,float score){
        this->num = num;
        this->name = name;
        this->score = score;
    }
};
class MyGreaterPerson{
public:
    bool operator()(Person v1,Person v2){
        return v2.score < v1.score;
    }
};
void printSetPerson(set<Person,MyGreaterPerson> &s){
    //set容器是只读迭代器，const_iterator
    set<Person,MyGreaterPerson>::const_iterator it = s.begin();
    for(;it!=s.end();it++){
        cout << "num "<<(*it).num<< ", name : "<< (*it).name<<", score is "<< (*it).score<<endl;
    }
}
void set_test3(){
    set<Person,MyGreaterPerson> s;
    s.insert(Person(32,"wjx",0.0f));
    s.insert(Person(23,"sjb",32.3));
    s.insert(Person(24,"wjk",32.7));
    printSetPerson(s);
}


void set_test4(){
    //set查找
    set<int> s;
    s.insert(10);
    s.insert(40);
    s.insert(20);
    s.insert(30);
    s.insert(50);
    printSetInt(s);

    set<int>::iterator it = s.begin();
    it = s.find(50);
    if(it!=s.end()){
        cout<<*it<<endl;
    }

    //查找某个元素的个数（0，或者1）
    cout<<s.count(50)<<endl;

}
void set_test5(){
    set<int> setInt;
    setInt.insert(3);
    setInt.insert(1);
    setInt.insert(7);
    setInt.insert(5);
    setInt.insert(9);
    printSetInt(setInt);
    set<int>::iterator itA = setInt.find(5);
    cout<<*itA<<endl;
    int iA = *itA; //iA == 5
    int iCount = setInt.count(5); //iCount == 1

    set<int>::iterator itB = setInt.lower_bound(5);//>=x
    set<int>::iterator itC = setInt.upper_bound(5);//>x
    int iB = *itB; //iB == 5
    int iC = *itC; //iC == 7
    cout<<iA<<" "<<iCount <<" \n"<<iB <<" "<<iC<<endl;
    //对组
    pair<set<int>::iterator,set<int>::iterator> pa;
    pa=setInt.equal_range(5);
    cout<< *pa.first<<" "<< *pa.second<<endl;
}
void multisettest6(){
    //允许键值重复，其他的和set一样；
    multiset<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(22);
    s.insert(34);
    s.insert(22);
    multiset<int>::const_iterator it=s.begin();
    for(;it!=s.end();it++){
        cout<<*it<<" ";    }
    cout<<endl;
}
void pairtest7(){
    //方式一
    pair<int,string> p(10086,"wjx");
    //方式二：推荐方式
    pair<int,string> p1= make_pair(10085,"wjj");
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p.first<<" "<<p.second<<endl;
}
//int main(){
//    pairtest7();
//    return 0;
//}