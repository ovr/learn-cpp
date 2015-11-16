#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;

void print(const boost::system::error_code& /*e*/,
           boost::asio::deadline_timer* t, int* count)
{
    cout << "Async timer " << *count << endl;
    ++(*count);

    /**
     * Restart timer
     */
    t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
    t->async_wait(
            boost::bind(
                    print, boost::asio::placeholders::error, t, count
            )
    );
}

int main() {
    cout << "Hello, World!" << endl;

    boost::asio::io_service io;

    boost::asio::deadline_timer asyncTimer(io, boost::posix_time::seconds(1));

    int count = 0;
    asyncTimer.async_wait(
            /**
             * http://www.boost.org/doc/libs/1_58_0/libs/bind/doc/html/bind.html
             */
            boost::bind(
                    print,
                    boost::asio::placeholders::error, &asyncTimer, &count
            )
    );

//    boost::asio::deadline_timer syncTimer(io, boost::posix_time::seconds(5));
//    syncTimer.wait();
//    cout << "Sync timer, 5sec was expired!" << endl;

    io.run();

    return 0;
}