#include <iostream>
#include <conio.h>

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

int main() {
    Screen game(40, 20);

    void render(const Screen& screen, const Paddle& playerPaddle, const Paddle& computerPaddle, const Ball& ball)
    {
        
    };

    return 0;
}