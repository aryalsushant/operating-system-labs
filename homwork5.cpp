#include <iostream>
#include <stack>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class SafeStack {
private:
    stack<int> s;
    mutex mtx;
    condition_variable cv;

public:
    void add(int value) {
        unique_lock<mutex> lk(mtx);
        s.push(value);
        cv.notify_one();
    }

    int remove() {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [this]() { return !s.empty(); });
        int x = s.top();
        s.pop();
        return x;
    }

    bool isEmpty() {
        lock_guard<mutex> lk(mtx);
        return s.empty();
    }
};

SafeStack sharedStack;

void process(int threadNum) {
    while (true) {
        if (sharedStack.isEmpty()) break;
        int v = sharedStack.remove();
        cout << "Worker " << threadNum << " processed: " << v << endl;
        this_thread::sleep_for(chrono::milliseconds(80));
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        sharedStack.add(i);
    }

    thread a(process, 1);
    thread b(process, 2);

    a.join();
    b.join();

    cout << "Finished" << endl;
    return 0;
}
