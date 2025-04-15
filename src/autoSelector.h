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
	}


	screen::set_eraser(Color::white);
	screen::print(E_TEXT_MEDIUM, 15, 50, "RING");
	screen::print(E_TEXT_MEDIUM, 15, 70, "RUSH");
	screen::print(E_TEXT_MEDIUM, 415, 200, "PONG");
	screen::print(E_TEXT_MEDIUM, 415, 60, "PONG");

	screen_touch_status_s_t status;
	Pong pongGame;

    while(true) {
		status = c::screen_touch_status();
		pongGame.update(status);
		pongGame.draw();
    	pros::delay(16.67);
    }
}