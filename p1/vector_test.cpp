//
// Created by 25721 on 2023/6/19.
//
//vector 单端动态数组

#include "vector_test.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;
void test0(){
    //vector的构造函数 迭代器
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    cout<< v1[0]<< endl;
    cout<<v1.at(0)<<endl;

    //遍历该容器
    //定义一个迭代器iterator，保存起始迭代器
    vector<int>::iterator it=v1.begin();
    for(;it!=v1.end();it++){
        //*it == int
        cout<< *it << " ";
    }
    cout<<endl;
}
void test1(){
    //vector的未雨绸缪机制：空间不够则会另外开辟空间
    vector<int> v1;
//    v1.reserve(1000);
    cout<<"capacity "<<v1.capacity()<<" size "<<v1.size()<<endl;

    vector<int>::iterator it;
    int i=0;
    int count = 0;
    for(i=0;i<1000;i++){
        v1.push_back(i);
        if(it!=v1.begin()){//判断这个vector是否另开辟空间，开辟空间不是在原来空间的后面接，而是选择另辟
            count++;
            cout<<"where "<<count << ", open cap " << v1.capacity()<<endl;
            it=v1.begin();
        }
    }
}
void printVectorInt(vector<int> &v) {
    vector<int>::iterator it;
    it =v.begin();
    for(;it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test2(){
    //vector的常用API操作
    vector<int> v1(5,100);//n个value拷贝给本身
    printVectorInt(v1);
    vector<int> v2(v1.begin(),v1.end());//区间构造
    printVectorInt(v2);

    vector<int> v3;
    v3 = v2;
    v3.assign(v1.begin(),v1.end());//区间赋值
    printVectorInt(v3);
    v3.assign(10,100); //n个value拷贝给本身
    printVectorInt(v3);
    v3.swap(v2); //将v3与v2交换
    printVectorInt(v3);
    //大小操作 size()  empty()   resize()  capacity()  reverse()
    vector<int> v4;
    if(v4.empty()){ //
        cout<<"empty"<<endl;
    }
    else{
        cout<<"not empty"<< endl;
    }
    vector<int> v5(10,30);
    cout<<v5.size() << " " << v5.capacity()<<endl;
    v5.resize(15,3); //重置大小，如过比之前长，则将空的部分用x填充； 如果比之前小，则尾部会被删除
    cout<<v5.size() << " " << v5.capacity()<<endl;
    printVectorInt(v5);
}
void test3(){
    //
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    cout<<"head "<<v1.front()<<" tail " <<v1.back()<<endl;
    cout<< v1[0] << " "<< v1.at(3) <<endl;
    v1[3] = 300;
    v1.at(2)=200;
    printVectorInt(v1);

    //尾部删除
    v1.pop_back(); // 尾部删除
    printVectorInt(v1);
    v1.insert(v1.begin()+2,3,500);//迭代器指向位置pos插入n个x元素
    printVectorInt(v1);
    v1.erase(v1.begin()+2,v1.begin()+5); //删除区间
    printVectorInt(v1);
    cout<< v1.size() << " " << v1.capacity() <<endl;
}
void test4(){
    vector<int> v1;
    v1.reserve(1000);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    cout<<v1.size()<<" " << v1.capacity() <<endl;
//发现预留的地方大了，如何更改？ resize只能改大小，因而使用swap
//    vector<int> (v1).swap(v1);   //基于swap拷贝的时候是把实际大小空间拷贝出来，而非原来的cap
    v1.shrink_to_fit();//reduce capacity() to size().
    cout<<v1.size()<<" " << v1.capacity() <<endl;
}
void test5(){
    //容器嵌套:类似二维数组
    vector<int> v1(5,10);
    vector<int> v2(5,100);
    vector<int> v3(5,1000);
    //需求：定义一个vector存放v1,v2,v3
    vector<vector<int>> v;  //定义一个容器类型的容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    //遍历
//    vector<vector<int>>::iterator it=v.begin();
    auto it=v.begin();
    //*it的类型永远是外层vector尖括号<>内的数据类型，即此处为vector<int>类型的数据
    for(;it!=v.end();it++){
//        vector<int>::iterator mit =(*it).begin();//所取到的vector，再再vector里取int类型的元素
        auto mit =(*it).begin();
        for(;mit!=(*it).end();mit++){
            cout<<(*mit) <<" ";
        }
        cout<<endl;
    }
}

#include <algorithm>
void test6(){
    //算法
    vector<int> v1;
    v1.push_back(18);
    v1.push_back(20);
    v1.push_back(3);
    v1.push_back(4);
    printVectorInt(v1);
    //排序算法
    sort(v1.begin(),v1.end());
    printVectorInt(v1);
}

//当vector容器是其他数据类型时，如自定义的Person类型
class PersonCom
{
    friend void printVectorPerson(vector<PersonCom> &v);
    friend bool comparePerson(PersonCom obj1, PersonCom obj2);
private:
    int num;
    string name;
    float score;
public:
    PersonCom(){};
    PersonCom(int num, string name, float score): num(num), name(std::move(name)), score(score){};
};
void printVectorPerson(vector<PersonCom> &v){
    vector<PersonCom>:: iterator it = v.begin();
    for(;it!=v.end();it++){
        cout<<(*it).name<<" " << (*it).num << " "<< (*it).score<<endl;
    }
}
bool comparePerson(PersonCom obj1, PersonCom obj2){
    return obj1.num<obj2.num;
}
void test7(){
    //其他数据类型的算法使用
    vector<PersonCom> p1;
    p1.push_back(PersonCom(12, "wjx", 99));
    p1.push_back(PersonCom(23, "yxj", 100));
    p1.push_back(PersonCom(34, "sjb", 76));
    printVectorPerson(p1);

    //排序
    sort(p1.begin(),p1.end(),comparePerson);
    printVectorPerson(p1);
}
//int main(){
//    test7();
//    return 0;
//}