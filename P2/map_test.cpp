//map  multimap   存键值对 pair
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <time.h>
using namespace std;
//1、map基础，定义数据和插入方式
class Person{
    friend void printMap(map<int,Person>&m);
    friend void maptest1();
private:
    int num;
    string name;
    float score;
public:
    Person(){};
    Person(int num,string name, float score){
        this->name=name;
        this->num=num;
        this->score = score;
    };
};
void printMap(map<int,Person>&m){
    map<int,Person>::const_iterator it=m.begin();
    for(;it!=m.end();it++){
        cout<<(*it).first<<" "<<((*it).second).num <<" " <<((*it).second).name <<" " <<((*it).second).score<<endl;
    }
}
void maptest1(){
    //map的定义和插入数据的方式
    map<int,Person> m;
    //方式一
    m.insert(pair<int,Person>(103,Person(102,"lucy",88.8f)));//pair键值对，Person匿名对象
    //方式二  推荐
    m.insert(make_pair(101,Person(100,"Tom",99.4f)));
    //方式三
    m.insert(map<int,Person>::value_type(100,Person(99,"LIly",89.1f)));
    //方式4：要注意，容易出问题
    m[99]=Person(98,"md",79.3f);
    printMap(m);

    //测试m[]访问的危险性，如果里面没有这个键值对，那么它会新建一个key值
//    cout<<m[107].num<<" "<<m[107].name<<" "<<m[107].score<<endl;
    cout<<m[103].num<<" "<<m[103].name<<" "<<m[103].score<<endl;
    printMap(m);
    //使用at相较安全，会报错。
//    cout<<m.at(108).name<<endl;
}

//2、应用场景：
//公司新加入5人，需要指派他们到哪个部门工作，每个员工有信息（姓名，年龄，电话，工资等），
// 通过multimap进行信息插入，保存显示分部门显示员工信息显示全部员工信息
class Employee{
    friend void creatEmployees(vector<Employee> &v,int n);
    friend void printVecEmployee(vector<Employee> &v);
    friend void employeeJoinDepartment(vector<Employee> &v,multimap<int,Employee> &m);
    friend void printMultimapEmployee(multimap<int,Employee> &m);
private:
    string name;
    int age;
    int money;
    string tel;
public:
    Employee(){}
    Employee(string name,int age,int money,string tel){
        this->name=name;
        this->age=age;
        this->money=money;
        this->tel=tel;
    }
};
void creatEmployees(vector<Employee> &v,int n){
    //创建员工基本信息，存入vector
    if(n>26) return;
    string setname = "ABCDE";
    //设置随机数种子
    string emp = "employee";
    for(int i=0;i<n;i++){
        string tmp;
//        tmp = setname[i]+"emp";
        tmp = setname[i]+emp;
        Employee p(tmp,17+i,1800+rand()%10*1000, to_string(rand()));
        cout<<p.name<<endl;
        v.push_back(p);
    }
}
void printVecEmployee(vector<Employee> &v){
//    打印vector员工信息
    vector<Employee>::iterator it=v.begin();
    for(;it!=v.end();it++){
        cout<<"name: " << (*it).name<<", age "<< (*it).age << ", money:" <<(*it).money <<", tel:" << (*it).tel <<endl;
    }
}
void employeeJoinDepartment(vector<Employee> &v,multimap<int,Employee> &m){
    //将vector里的员工加入到multimap中去
    vector<Employee>::iterator it = v.begin();
    for(;it!=v.end();it++){
//        m.insert((7,*it));
        cout<<"Please [" <<(*it).name<<"] will be joined in [0(tech),1(sale),3(bus)";
        int op = 0;
        cin>>op;
//        m.insert(pair<int,Employee>(op,(*it)));
        m.insert(make_pair(op,(*it)));
    }
}
void printMultimapEmployee(multimap<int,Employee> &m){
    //打印某个部门的员工
    cout<<"Please enter where department you wanna know employee:" <<endl;
    int op;
    cin>>op;
//    multimap<int,Employee>::iterator it=m.begin();
    switch(op){
        case 0:
            cout<<"---------------------------------Technology----------------------------"<<endl;
            break;
        case 1:
            cout<<"-----------------------------------sales--------------------------------"<<endl;
            break;
        case 3:
            cout<<"-----------------------------------busyniess-----------------------------"<<endl;
            break;
        default:
            break;
    }
    //寻找op的位置 ： 返回的是op的迭代器
    multimap<int,Employee>::const_iterator ret;
    ret = m.find(op);
    if(ret == m.end()){
        return;
    }
    int count=m.count(op);
    for(int i=0;i<count;i++,ret++){
        cout<< " name : " << (*ret).second.name  <<", age:  " <<(*ret).second.age << ", money : "<< (*ret).second.money <<", tel:  "<<(*ret).second.tel<<endl;
    }
}
void multimaptest2(){
    //公司新加入5人，需要指派他们到哪个部门工作，每个员工有信息（姓名，年龄，电话，工资等），通过multimap进行信息插入，保存显示分部门显示员工信息显示全部员工信息

    //先用vector把五名员工信息存下来
    vector<Employee> v;
    creatEmployees(v,5);
    //测试：打印员工信息
    printVecEmployee(v);
    //将员工分配到不同的部门
    //用multimap存键值对，公司的部门是key值，员工Employee是value值，
    multimap<int,Employee> m;
    employeeJoinDepartment(v,m);
    //显示部门员工
    printMultimapEmployee(m);
}
//int main(){
//    multimaptest2();
//    return 0;
//}