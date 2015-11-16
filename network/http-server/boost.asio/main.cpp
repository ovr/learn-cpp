#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.wait();

    cout << "Sync timer, 5sec was expired!" << endl;

    return 0;
}