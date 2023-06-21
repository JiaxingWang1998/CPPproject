//
// Created by 25721 on 2023/6/20.
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void printListInt(list<int> &l){
    list<int>::iterator it = l.begin();
    for(;it!=l.end();it++){
        cout<<(*it)<<endl;
    }
}
void list_test1(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    printListInt(l);
}
void list_test2(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    //list的双向迭代器，不支持+2，但支持++
    list<int>::iterator it=l.begin();
//    it+2;
    it++;
    l.insert(it,3,100);
    printListInt(l);
    //STL提供的算法，只支持随机访问迭代器，而list是双向迭代器，所以sort不支持list
//    sort(l.begin(),l.end());
//因而list自己内部实现了sort
    l.sort();
    printListInt(l);
}


//
//int main(){
//    list_test2();
//    return 0;
//}