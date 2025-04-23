#pragma once

void autoSelector(){
    //screen is 480 wide by 272 tall

	screen::set_pen(Color::blue);
	screen::fill_rect(0, 0, 480, 136);
	screen::set_pen(Color::red);
	screen::fill_rect(0, 136, 480, 272);
	screen::set_pen(Color::black);

	int numSeperatingLines = 5;
	for(int i = 1; i <= numSeperatingLines; i++){
		screen::draw_line(i*480/(numSeperatingLines+1), 0, i*480/(numSeperatingLines+1), 272);
		//80 width per rectangle when numSepLines = 5
	}


	screen::set_eraser(Color::white);
	screen::print(E_TEXT_MEDIUM, 15, 50, "MOGO");
	screen::print(E_TEXT_MEDIUM, 15, 70, "RUSH");

	screen::print(E_TEXT_MEDIUM, 15, 212, "MID");
	screen::print(E_TEXT_MEDIUM, 15, 222, "RUSH");
	// screen::print(E_TEXT_MEDIUM, 415, 200, "PONG");
	// screen::print(E_TEXT_MEDIUM, 415, 60, "PONG");

	screen_touch_status_s_t status;
	// Pong pongGame;

    while(true) {
		status = c::screen_touch_status();
		if(status.touch_status == TOUCH_PRESSED){
			if(coordinateWithinRectangle(status.x, status.y, 0, 136, 80, 272)){
				screen::print(E_TEXT_MEDIUM, 415, 200, "SELECTED");
				auto_selected = 2; //lower left rectangle
				return;
			}
			else if(coordinateWithinRectangle(status.x, status.y, 0, 0, 80, 180)){
				screen::print(E_TEXT_MEDIUM, 415, 60, "SELECTED");
				auto_selected = 1; //upper right rectangle
				return;
			}
			
		}
		// pongGame.update(status);
		// pongGame.draw();
    	pros::delay(16.67);
    }
}