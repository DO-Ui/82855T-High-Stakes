#include <string>
#include <cmath>
#include "json.hpp"

using json = nlohmann::json;

struct Message {
    std::string topic;
    json payload; 
};

inline void to_json(json& j, const Message& msg) {
    j = json{{"topic", msg.topic}, {"payload", msg.payload}};
}

// x, y, and heading follow same conventions as https://path.jerryio.com/ / LemLib 
struct Odometry {
    double x;
    double y;
    double theta; // heading in radians. 
};

inline void to_json(json& j, const Odometry& msg) {
    j = json{{"x", msg.x}, {"y", msg.y}, {"theta", msg.theta}};
}

struct Speed {
    double left;
    double right;
};

inline void to_json(json& j, const Speed& msg) {
    j = json{{"left", msg.left, "right", msg.right}};
}
