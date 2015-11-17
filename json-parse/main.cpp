#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

int main() {
    string inputJSON = "{\"id\":567,\"name\":\"Removed\",\"age\":null,\"about\":null,\"avatar_id\":null,\"avatar\":{\"id\":null,\"url\":\"http:\\/\\/cdn.blabla.eu\\/img\\/sad_smile.png\",\"width\":null,\"height\":null,\"fill_color\":null,\"parent_id\":null},\"gender\":\"F\",\"friends_count\":1,\"subscribers_count\":0,\"interests_count\":0,\"birth_year\":null,\"birth_month\":null,\"birth_day\":null,\"country\":null,\"region\":null,\"city\":null,\"map_image\":null,\"relation\":null,\"is_service\":false,\"last_act\":\"2015-08-19 10:41:28.473371\",\"is_online\":false}";

    std::stringstream ss;
    ss << inputJSON;

    boost::property_tree::ptree pt;
    boost::property_tree::read_json(ss, pt);

    std::cout << pt.get<std::string>("id") << std::endl;

    return 0;
}