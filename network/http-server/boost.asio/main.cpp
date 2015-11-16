#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;

void print(const boost::system::error_code& /*e*/)
{
    cout << "Async timer" << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    boost::asio::io_service io;

    boost::asio::deadline_timer asyncTimer(io, boost::posix_time::seconds(5));
    asyncTimer.async_wait(print);

//    boost::asio::deadline_timer syncTimer(io, boost::posix_time::seconds(5));
//    syncTimer.wait();
//    cout << "Sync timer, 5sec was expired!" << endl;

    io.run();

    return 0;
}