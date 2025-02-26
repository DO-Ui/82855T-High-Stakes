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

struct Colour {
    double hue;
    char colours;
    bool sees;
};

inline void to_json(json& j, const Colour& msg) {
    j = json{{"hue", msg.hue}, {"colours", msg.colours}, {"sees", msg.sees}};
}
