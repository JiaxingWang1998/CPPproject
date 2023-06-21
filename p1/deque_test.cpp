//
// Created by 25721 on 2023/6/19.
//
//deque:双端开口动态数组
#include <iostream>
#include <deque>
using namespace std;
void printDequeInt(deque<int> &d){
    auto it = d.begin();
    for(;it!=d.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void dequetest1(){
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_front(6);
    d1.push_front(7);
    printDequeInt(d1);
    cout<< "size " << d1.size()<<endl;
    d1.pop_front();//头删
    d1.pop_back();//尾删
    printDequeInt(d1);
    d1.insert(d1.begin()+1,3,100); //插入
    printDequeInt(d1);
}

#include <vector>
#include <string>
#include <cstring>

class PersonCom
{
public:
    string name ;
    float score;
//public:
    PersonCom(){}
    PersonCom(string n, float score){
//        this->name(n);
//        strcpy(name,n);
        this->name= n ;
//        name.assign(n);
        this->score=score;
    }
};

void creatPerson(vector<PersonCom> &v){
    string tmpstr = "ABCDE";
    string name = string("xuanshou");
    for(int i=0;i<5;i++) {
        //name += ";
//        PersonCom p =  PersonCom(name, 0.0);
//        v.push_back( p );
          v.push_back(PersonCom("xuanshou",0.0f));
//        v.emplace_back(name,0.0f);
        cout << i << " ";
    }
        cout<<endl;
}
void printDequePerson(vector<PersonCom> &v){
    cout<<"begin_printDequePerson"<<endl;
//    vector<PersonCom>::iterator it;
//    it = v.begin();
//    for(;it!=v.end();it++){
//        cout<<(*it).name << " " <<(*it).score<<endl;
//    }
    for(int i=0;i<v.size();i++){
        cout<<"yes";
        cout<< v.at(i).name <<endl;
    }
    cout<<"printDequePerson"<<endl;
}
void deque_test2(){
    //应用
    //创建五名选手
    vector<PersonCom> v;
    creatPerson(v);
    //打印五名选手，查看是否创建成功
    printDequePerson(v);
    //遍历vector容器，取出每一位选手，执行for循环，可以把10个评分存到deque容器中
    //sort算法容器遍历一遍，累加分数，累加分数/d.size()
    //person.score = 平均分

}
int main(){
     deque_test2();
     return 0;
}
