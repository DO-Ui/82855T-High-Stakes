//AUTO STATES
bool auton_active = false;
int auto_selected = -1;

//COLOR SORT
char team_color = 'n'; //this color is not sorted out. make sure to set to a value other than 'n' in the code
bool sorter_active = true;

//CONVEYOR MACROS
bool stopNextRing = false;
bool unjamLB = false;

//DOINKER MACROS
bool reactiveClawClampOn = false;

//MOGO MACROS
bool mogoClampRequested = false;

//LADYBROWN
int lbTarget = 0; //NUMBER FROM 0-SIZE OF POSITIONS ARRAY, DO NOT PUT THE ACTUAL ANGLE
int lbDescoreTarget = 0; //NUMBER FROM 0-SIZE OF DESCORE POSITIONS ARRAY, DO NOT PUT THE ACTUAL ANGLE
bool manualLBMode = false;
bool lbDescoreMode = false;
