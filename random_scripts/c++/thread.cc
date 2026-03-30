#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm> //mainly for find, it always returns an iterator
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <future>

using namespace std;

vector<int> xx;
int x;
mutex gate;
condition_variable basket;
bool ready = false;

void tfunc(int y){
    cout << endl;
    cout << "first thread" << endl;
    {
        lock_guard<mutex> lock(gate);
        xx.push_back(y);
        x++;
        ready=true;
    }
    basket.notify_one();
}

void cunc(){
    cout << "green thread" << endl;
}

int intcunc(){
    return 5;
}

int intcunc2(int x){
    return x;
}

int main(){

    thread th([] (int y){
        cout << endl;
        cout << "first second thread" << endl;
        unique_lock<mutex> lock(gate);
        xx.push_back(y);
        x++;
        basket.wait(lock, []{return ready;});
        cout << "received yo" << endl;

    }, 50);
    thread t(tfunc, 100);

    if(t.joinable() && th.joinable()){
        t.join();
        th.join();
    }

    cout << "x is: " << x << endl;
    for(int &xxx:xx){
        cout << xxx << endl;
    }

    cout << "green threads are NOT a bust, it's awesome" << endl;


    future<void> a1 = async(launch::async, cunc);
    future<int> a2 = async(launch::async, intcunc);
    future<int> a3 = async(launch::async, intcunc2, 10);

    a1.get();
    cout << a2.get() << a3.get() << endl;

    bool done=false;
    int ii=0;
    for(int i = 0; i<10 && done==false; i++){
        ++ii;
        cout << "i is: " << i << endl;
        cout << "ii is: " << ii << endl;
        if(ii==5){
            done=true;
        }
    }



    

}