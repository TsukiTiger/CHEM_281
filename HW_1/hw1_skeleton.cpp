
#include <chrono>
#include <unistd.h>
#include <iostream>
#include <queue>
using namespace std;

unsigned long get_current_time_in_secs()
{
    auto now = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(now.time_since_epoch());
    return duration.count();
}

class Dispatcher
{
public:
    Dispatcher (unsigned int n, unsigned int t);
    void dispatch_requests(unsigned long delay,  unsigned int request_count);
private:
    bool enable_request();
private:
    unsigned int numberOfRequests;
    unsigned int time_interval;
    queue<unsigned long> timestamps;  // Queue to store request timestamps
};

Dispatcher::Dispatcher(unsigned int numberOfRequests, unsigned int time_interval) :
        numberOfRequests(numberOfRequests), time_interval(time_interval) {}

bool Dispatcher::enable_request() {
    unsigned long current_time = get_current_time_in_secs();

    // Remove outdated requests
    while (!timestamps.empty() && current_time - timestamps.front() >= time_interval) {
        timestamps.pop();
    }

    // Check if we can process the new request
    if (timestamps.size() < numberOfRequests) {
        timestamps.push(current_time);
        return true;
    } else {
        return false;
    }
}

void Dispatcher::dispatch_requests(unsigned long delay, unsigned int request_count)
{
    sleep(delay);
    for (unsigned int k = 0; k < request_count; k++) {
        if (enable_request()) {
            cout << "Request " << k << " is being processed" << endl;
        } else {
            cout << "Request " << k << " has been rejected" << endl;
        }
    }
}

void scenario1()
{
  // Process one request per second
  Dispatcher dispatcher(1,1);
  cout << "scenario1 first dispatch" << endl;
  dispatcher.dispatch_requests(0, 1);
  cout << "scenario1 second dispatch" << endl;
  dispatcher.dispatch_requests(1, 2); //dispatch 2 requests after waiting 1 sec;
}

void scenario2()
{
  // Process up to 4 request every two second
  Dispatcher dispatcher(4,2);
  cout <<"scenario2 first dispatch" << endl;
  dispatcher.dispatch_requests(0, 1);
  cout << "scenario2 second dispatch" << endl;
  dispatcher.dispatch_requests(1, 4); //dispatch 4 requests after waiting 1 sec;
  cout << "scenario2 third dispatch" << endl;
  dispatcher.dispatch_requests(2, 4); //dispatch 4 requests after waiting 2 sec;
  cout << "scenario2 fourth dispatch" << endl;
  dispatcher.dispatch_requests(2, 5); //dispatch 5 requests after waiting 2 sec;
}

int main(int argc, char** argv)
{
  cout << "Running scenario 1" << endl;
  scenario1();
  cout << "Running scenario 2" << endl;
  scenario2();
  return 0;
}
