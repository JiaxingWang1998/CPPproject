//
// Created by 25721 on 2023/6/20.
//stack
#include <iostream>
#include <stack>
using namespace std;
void stack_test1(){
    stack<int> s;
    s.push(1);s.push(3);s.pop();
    s.push(5);s.push(7);s.push(9);s.pop();
    cout<<"size " << s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
//int main(){
//    stack_test1();
//    return 0;
//}
