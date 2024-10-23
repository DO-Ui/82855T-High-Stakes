#include <string>
#include "json.hpp"

using json = nlohmann::json;

struct Message {
    std::string topic;
    json payload; 
};

inline void to_json(json& j, const Message& msg) {
    j = json{{"topic", msg.topic}, {"payload", msg.payload}};
}

struct ExampleStruct {
    int x;
};

inline void to_json(json& j, const ExampleStruct& msg) {
    j = json{{"x", msg.x}};
}