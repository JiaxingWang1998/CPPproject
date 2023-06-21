//
// Created by 25721 on 2023/6/19.
//

#include "string_test.h"
#include <iostream>
#include <string>
using namespace std;
void void_test(){
    //string对象的初始化和赋值
    string str1;//创建一个空字符
    str1="str1-hello world"; //把字符串赋值给当前字符
    cout<<str1<<endl;

    string str2("str2-hellostr2");//使用字符串初始化
    cout<<str2<<endl;
    string str3(3,'v'); //使用n个char字符初始化
    cout<<str3<<endl;
    str3 = 'c';
    cout<<str3<<endl;

    const string& str4(str3);//使用一个string对象初始化另一个string对象
    cout<<str4<<endl;
//赋值运算符 = 完成
    string str5= str1; //
    cout<<str5<<endl;
    str5 = str3;      //
    cout<<str5<<endl;
//成员函数完成
    str5.assign("str5");
    cout<<str5<<endl;
    str5.assign(str2,2);
    cout<<str5<<endl;
    str5.assign(str1);
    cout<<str5<<endl;
    str5.assign(3,'v'); //
    cout<<str5<<endl;
    str5.assign(str2,2,3);//把string对象的从pos开始的n个字符复制过来
    cout<<str5<<endl;
}
void test02(){
    //string方法 的读取和赋值  []   at()
    string str1("hello world");
    cout<<str1[1]<< " " << str1.at(1) <<endl;
    str1[1] = 'E';
    str1.at(6) = 'H';
    cout<<str1<<endl;
    //[]不会抛出异常，at方法会抛出异常
    try{
//        str1[100] = 'W';
//        cout<< str1<<endl;
        str1.at(100) = 'c';
//        cout<< str1<<endl;
    }
    catch (exception &e){
        cout<<"捕获到异常："<<e.what()<<endl;
    }
}
void test03(){
    //字符串的相加 +  +=  append
    string  str1 = "hello";
    str1+="world";
    cout<< str1<< endl;
    string str2 = "here";
    str1 += str2;
    cout<< str1<<endl;
    string  str3 = "good";
    cout<< str3+str1<<endl;
    str3.append(str1,2,3);//将str1的pos后的n个字节加在str3后
    cout<< str3<<endl;
    str3.append("world",3);//把字符串s的前n个追加到str3后面
    cout<<str3<<endl;
}
void test04(){
    //查找与替换 find  rfind   replace
    string str1 = "hello world";
    cout<<str1.find('l')<<endl;
    cout<< str1.rfind('l')<<endl;
    string str2 = "http://www.sex.hundsdf/com";
    cout<< str2<< endl;
    while(1){
        int ret;
        ret = str2.find("sex");
        if (ret==-1){
            break;
        }
        str2.replace(ret,3,"***");
    }
    cout<< str2<< endl;
}
void test05(){
    //字符串比较  compare
    //重载了> < == 等关系运算符
    string str1 = "hello world";
    string str2 = "http://www.sex.hundsdf/com";
    int key =str1.compare(str2);
    if(key==0){
        cout<< "same" << endl;
    }
    else if(key <0){
        cout<< "small" << endl;
    }
    else {
        cout << "big" << endl;
    }
    if(str1 == str2){
        cout<<"yes" << endl;
    }
    else{
        cout<<"no"<<endl;
    }

}
void test06(){
    //提取子串 substr
    //通常与find配合使用
    string str1 = "hello: world:hehe:lala";
    int pos = 0;
    while(1){
        int ret = str1.find(':', pos);
        if(ret < 0){
            string tmp = str1.substr(pos,str1.size()-pos);
            cout<<tmp<<endl;
            break;
        }
        string tmp = str1.substr(pos,ret-pos);
        cout<< tmp<<endl;
        pos = ret+1;
    }
//    str1.substr()
}
void test07(){
    //插入与删除 insert erase
    string str1 = "hello";
    str1.insert(2,"###");
    str1.erase(1,3);
    cout<<str1<<endl;
    str1.erase(0,str1.size());//相当于将字符串清空
    cout<<str1<<endl;
    cout<<str1.size()<<" " << str1.capacity()<<endl;  //此时大小为0，容量15
}
void test08(){
    //C语言风格与C++的string类转换的问题
    //char*转换成string（默认支持）
    string str1 ;
    str1 = (string)"hello";
    cout<<str1<<endl;
    //string转成char*,需要成员函数c_str
    string str2 = "hello";
    char *p = (char *) str2.c_str();
    cout<<str2<<endl;
}
//int main(){
//    test08();
//    return 0;
//}
