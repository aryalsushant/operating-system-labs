#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
using namespace std;

const int SIZE = 10;
vector<char> buf;
mutex mtx;
condition_variable notFull, notEmpty;
bool finished = false;

void functionOne() {
    char c = 'A';
    for (int i = 0; i < 100; i++) {
        unique_lock<mutex> lk(mtx);
        notFull.wait(lk, [] { return buf.size() < SIZE; });
        buf.push_back(c);
        cout << "Produced: " << c << endl;
        c = (c == 'Z') ? 'A' : c + 1;
        lk.unlock();
        notEmpty.notify_one();
    }

    unique_lock<mutex> lk(mtx);
    finished = true;
    lk.unlock();
    notEmpty.notify_all();
}

void functionTwo() {
    while (true) {
        unique_lock<mutex> lk(mtx);
        notEmpty.wait(lk, [] { return !buf.empty() || finished; });
        if (buf.empty() && finished) break;
        char c = buf.front();
        buf.erase(buf.begin());
        cout << "  Consumed: " << c << endl;
        lk.unlock();
        notFull.notify_one();
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main() {
    thread t1(functionOne);
    thread t2(functionTwo);
    t1.join();
    t2.join();
    cout << "\nDone" << endl;
    return 0;
}
