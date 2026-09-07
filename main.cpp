#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <windows.h>

class Paddle
{
    private:
    int y{}, height{};
    int maxY{};

    public:
    Paddle(int y_val, int h_val, int screenHeight)
    {
        y = y_val;
        height = h_val;
        maxY = screenHeight;
    };

    void moveUp()
    {
       if (y > 0) y -= 1;
    };

    void moveDown()
    {
        if (y + height < maxY) y += 1;
    };

    int getY() const {return y;}
    int getHeight() const {return height;}
};

class Ball
{
    private:
    int x{}, y{};
    int velX{}, velY{};

    public:
    Ball(int x_val, int y_val, int vx_val, int vy_val)
    {
        x = x_val;
        y = y_val;
        velX = vx_val;
        velY = vy_val;
    };

    void move()
    {
        x += velX;
        y += velY;
    };

    void bounceX()
    {
        velX *= -1;
    };

    void bounceY()
    {
        velY *= -1;
    };

    void reset(int startX, int startY)
    {
        x = startX;
        y = startY;
    };

    int getX() const {return x;}
    int getY() const {return y;}
};
 
class Screen
{
    private:
    int width{};
    int height{};

    public:
    Screen(int w_val, int h_val)
    {
        width = w_val;
        height = h_val;
    };

    int getWidth() const {return width;}
    int getHeight() const {return height;}
};

void render(const Screen& screen, const Paddle& playerPaddle, const Paddle& computerPaddle, const Ball& ball)
{
    int width = screen.getWidth();
    int height = screen.getHeight();
    int playerY = playerPaddle.getY();
    int playerH = playerPaddle.getHeight();
    int computerY = computerPaddle.getY();
    int computerH = computerPaddle.getHeight();
    int ballY = ball.getY();
    int ballX = ball.getX();

    for (int r=0; r<height; r++)
    {
        for (int c=0; c<width; c++)
        {
            if (r==0 || r == height-1) std::cout << "-";
            else if (r >= playerY && r < playerH + playerY && c == 0){
                std::cout << "|";
            }
            else if (r >= computerY && r < computerH + computerY && c == width-1){
                std::cout << "|";
            }
            else if (r == ballY && c == ballX){
                std::cout << "O";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
};

int main() {
    Screen game(40, 20);
    Paddle player(8, 4, game.getHeight());
    Paddle computer(8, 4, game.getHeight());
    Ball ball(20, 10, 1, 1);
    int playerScore{}, computerScore{};

    while (true)
    {
        while (_kbhit()){
            char key = _getch();
            if(key == 'w') player.moveUp();
            if(key == 's') player.moveDown();
        }
        
        system("cls");
        static int frameCount = 0;
        frameCount++;
        if (frameCount % 1 == 0){
            int diff = ball.getY() - (computer.getY() + computer.getHeight()/2);
            if (diff < -1) computer.moveUp();
            else if (diff > 1) computer.moveDown();
        }
        ball.move();
        if (ball.getX() == 0 && ball.getY() >= player.getY() && ball.getY() < player.getY() + player.getHeight()) ball.bounceX();
        if (ball.getX() == game.getWidth() -1 && ball.getY() >= computer.getY() && ball.getY() < computer.getY() + computer.getHeight()) ball.bounceX();
        if (ball.getY() == 0 || ball.getY() == game.getHeight()-1) ball.bounceY();
        if (ball.getX() < 0){
            computerScore += 1;
            ball.reset(20, 10);
        }
        if (ball.getX() >= game.getWidth()){
            playerScore += 1;
            ball.reset(20, 10);
        }
        std::cout << "First to 10pts wins!" << std::endl;
        render(game, player, computer, ball);
        std::cout << "Player: " << playerScore << "*   Computer: " << computerScore << "*" << std::endl;
        if (playerScore == 10 || computerScore == 10) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    if (playerScore == 10) std::cout << "YOU WIN!";
    else std::cout << "COMPUTER WINS!";
}