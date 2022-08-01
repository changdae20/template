#include <fmt/core.h>
#include <google/protobuf/util/json_util.h>

#include "protobuf/test.pb.h"
#include "util.hpp"

#include <iostream>
#include <string>

int main() {
    Test a;
    a.set_id( 1 );
    a.set_str( "Hello World from protobuf!" );

    std::string buf;
    google::protobuf::util::MessageToJsonString( a, &buf );
    std::cout << buf << std::endl;

    fmt::print( Util::hello() );
    return 0;
}