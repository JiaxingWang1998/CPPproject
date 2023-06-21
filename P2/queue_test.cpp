//
// Created by 25721 on 2023/6/20.
//
//queue先进先出，无迭代器，不提供遍历行为
#include <iostream>
#include <queue>
using namespace std;
void queue_test1(){
    queue<int> s;
    s.push(1);s.push(3);s.pop();
    s.push(5);s.push(7);s.push(9);s.pop();
    cout<<"size " << s.size()<<endl;
    while(!s.empty()){
        cout<<s.front()<<endl;
        s.pop();
    }
}
//int main(){
//    queue_test1();
//    return 0;
//}