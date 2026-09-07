        if (ball.getX() == 0 && ball.getY() >= player.getY() && ball.getY() < player.getY() + player.getHeight()) ball.bounceX();
        if (ball.getX() == game.getWidth() -1 && ball.getY() >= computer.getY() && ball.getY() < computer.getY() + computer.getHeight()) ball.bounceX();
        if (ball.getY() == 0 || ball.getY() == game.getHeight()-1) ball.bounceY();
        render(game, player, computer, ball);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}