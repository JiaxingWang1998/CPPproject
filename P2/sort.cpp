//
// Created by 25721 on 2023/6/19.
//

#include <iostream>

using namespace std;


template<class T, class Compare>
void sort(T array[], int start, int end, Compare compare) {
    //从当前往后找最小的交换
    for (int i = start; i < end; ++i) {
        T min = array[i];
        int minIndex = i;
        for (int j = i; j < end; ++j) {
            if (compare(array[j], min)) {
                min = array[j];
                minIndex = j;
            }
        }
        //交换
        T tmp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
}

template<class T, class Compare>
void sortBy(T array[], int start, int end) {
    Compare compare;
    //从当前往后找最小的交换
    for (int i = start; i < end; ++i) {
        T min = array[i];
        int minIndex = i;
        for (int j = i; j < end; ++j) {
            if (compare[array[j]]< compare[min]) {
                min = array[j];
                minIndex = j;
            }
        }
        //交换
        T tmp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
}

class Person {
public:
    string name;
    int age;
    float score;

    Person(string name, int age, float score) : name(name), age(age), score(score) {};
};

void print(Person array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "name: "<<array[i].name << ", age: "<<array[i].age<<", score: "<<array[i].score<<endl;
    }
    cout<<"______________________________________________________________"<<endl;
}

bool comparePerson(Person a , Person b) {
    return a.name < b.name;
}

string compareByPerson(Person a) {
    return a.name;
}
class comPare
{
public:
    string operator[] (Person a) {
        return a.name;
    }
};
int main() {
    Person array[] = {
            Person("wjx", 24, 99),
            Person("yjj", 23, 100),
            Person("yxj", 30, 0),
    };
    print(array , 3);
    sortBy<Person ,comPare >(array,0,3);
//    sort(array , 0 ,3, [](Person a , Person b)-> bool {
//        return a.name < b.name;
//    });
////    sort(array , 0 ,3, comparePerson);
////    sortBy(array , 0 ,3 , compareByPerson);
////    sortBy(array , 0 ,3 , [](Person a)->int {
////        return a.age;
////    });
//    print(array,3);
}
