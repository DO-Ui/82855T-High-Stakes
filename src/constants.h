//Detection threshold in mm for distance sensor at the top of conveyor
const float CONVEYOR_DISTANCE_OFFSET = 35;


//Ladybrown constants
const float REST = 0;
const float CAPTURE = 42;
const float WALLSTAKE_PREP = 100;
const float WALLSTAKE = 200;
const float MANUAL = 350;
const float positions[4] = {REST, CAPTURE, WALLSTAKE_PREP, WALLSTAKE};

const float DESCORE_POSITION = 90;
const float WALLSTAKE_RING_6 = 160;
const float WALLSTAKE_RING_5 = 170;
const float WALLSTAKE_RING_4 = 180;
const float WALLSTAKE_RING_3 = 190;
const float WALLSTAKE_RING_2 = 200;
const float WALLSTAKE_RING_1 = 210;
const float descorePositions[7] = {DESCORE_POSITION, WALLSTAKE_RING_6, WALLSTAKE_RING_5, WALLSTAKE_RING_4, WALLSTAKE_RING_3, WALLSTAKE_RING_2, WALLSTAKE_RING_1};