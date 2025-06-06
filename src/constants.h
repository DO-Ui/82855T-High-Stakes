//Detection threshold in mm for distance sensor at the top of conveyor
const float CONVEYOR_DISTANCE_OFFSET = 45;


//Ladybrown constants
const float KCOS = 13;
const float LB_STARTING_ANGLE = 20; //angle between ladybrown starting angle and the horizontal
#define LB_STABILIZER (cos(lemlib::degToRad((LB_STARTING_ANGLE-currTheta)))) * KCOS //if you want to brake the ladybrown put ladybrown.move(LB_STABILIZER) so it doesn't sink down

const float REST = 0;
const float CAPTURE = 40;
const float WALLSTAKE_PREP = 100;
const float WALLSTAKE = 220;
const float MANUAL = 300;
const float positions[4] = {REST, CAPTURE, WALLSTAKE, MANUAL};

const float DESCORED_POSITION = 90;
const float WALLSTAKE_RING_6 = 160;
const float WALLSTAKE_RING_5 = 170;
const float WALLSTAKE_RING_4 = 183;
const float WALLSTAKE_RING_3 = 195;
const float WALLSTAKE_RING_2 = 207;
const float WALLSTAKE_RING_1 = 219;
const float descorePositions[7] = {DESCORED_POSITION, WALLSTAKE_RING_6, WALLSTAKE_RING_5, WALLSTAKE_RING_4, WALLSTAKE_RING_3, WALLSTAKE_RING_2, WALLSTAKE_RING_1};