#pragma once

class Pong{
    private:
        const float ballSpeed = 0.6;
        const float paddleWidth = 40;

        float leftPaddleY = 136;
        float rightPaddleY = 136;
        float ballX = 240;
        float ballY = 272/2;
        float ballTheta = 90;

        float prevLeftPaddleY;
        float prevrightPaddleY;
        float prevballX;
        float prevballY;
        float prevballThet;
    
    public:
        void update(screen_touch_status_s_t status){
            if(status.touch_status == E_TOUCH_HELD){
                if(coordinateWithinBounds(status.x, status.y, 0, 0, 20, 272)){
                    leftPaddleY = status.y;
                }
                if(coordinateWithinBounds(status.x, status.y, 480-20, 0, 480, 272)){
                    rightPaddleY = status.y;
                }
            }
            ballX += ballSpeed*sin(ballTheta);
            ballY += ballSpeed*cos(ballTheta);

            if(ballX+5 >= 480-paddleWidth) ballTheta *= -1;
            if(ballX-5 <= paddleWidth) ballTheta *= -1;
        }
        void draw(){
            screen::set_pen(Color::black);
            screen::fill_rect(0, 0, 480, 272);
            screen::set_pen(Color::white);
            screen::fill_rect(ballX-5, ballY-5, ballX+5, ballY+5);
            screen::fill_rect(0, leftPaddleY-40, paddleWidth, leftPaddleY+40);
            screen::fill_rect(480-paddleWidth, rightPaddleY-40, 480, rightPaddleY+40);
        }

    
};