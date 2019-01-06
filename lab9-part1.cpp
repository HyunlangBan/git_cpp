//==============================================================================
// Filename     : lab9-part1.cpp
// Author       : Hank Feild (Based on a YouTube tutorial by thecplusplusguy:
//                https://www.youtube.com/watch?v=4HgyStstIhw)
// Date         : 02-Nov-2014; updated 02-Apr-2017
// Description  : A terminal-based version of snake. The goal is to guide a
//                snake around the screen and eat as many apples as possible.
//                with each apple, the snake grows longer, eventually becoming
//                unmanageable. If you direct the snake into itself or a wall,
//                it's lights out. Press 'q' to quit the game at any time.
//
//                To compile on Windows, do:
//                    g++ lab9-part1.cpp -lpdcurses -o lab9-part1
//                To compile on OSX or Linux, do:
//                    g++ lab9-part1.cpp -lncurses -o lab9-part1
// Collaborators: None.
//==============================================================================
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

// Different platforms need different header files. Here's how, using
// most C++ compilers, you can include different libraries for different
// operating systems.
#ifdef _WIN32
    #include <curses.h>
#elif __APPLE__
    #include <ncurses.h>
#elif __linux
    #include <ncurses.h>
#endif

const static int  SNAKE_LENGTH     = 1;
const static int  INITIAL_DELAY    = 110000; // Micro seconds.
const static int  DELAY_DECREASE   = 40000;  // Micro seconds.
const static int  FOOD_POINTS      = 20;
const static int  POINTS_DELAY_TRIGGER = 60;
const static char SNAKE_CHAR       = 'x';
const static char FOOD_CHAR        = '*';
const static char BORDER_CHAR      = char(219); // Filled rectangle.

/**
 * Represents a "pixel" or block on the screen, e.g., the box that a character
 * goes in.
 */
struct Pixel
{
    int x, y;
};

/**
 * Represents a snake.
 */
struct Snake
{
    int points, delay, adjustedDelay, maxWidth, maxHeight;
    char direction, borderChar;
    bool foodEaten;
    Pixel food;
    std::vector<Pixel> snakeBody;
};

// Function declarations.
Pixel createPixel(int col, int row);

void startGame();
void initSnake(Snake &snake);
void putFood(Snake &snake);
bool collision(Snake &snake);
void moveSnake(Snake &snake);
void initializeBoard(Snake &snake);
void drawBorder(Snake &snake);
int display(Snake &snake);


/**
 * Runs a game of snake.
 *
 * @return The exit status.
 */
int main()
{
    startGame();
    return 0;
}

//==============================================================================
// Below this point are the definitions for the methods of class SnakeGame. We
// are putting them down here rather than up in the class interface above so 
// that we can reduce clutter. 
//==============================================================================

/**
 * Pixel constructor. Sets the x and y coordinates.
 *
 * @param col The column of the pixel (counting from the left of the screen).
 * @param row The row of the pixel (counting from the top of the screen).
 */
Pixel createPixel(int col, int row)
{
    Pixel pixel;
    pixel.x = col;
    pixel.y = row;
    return pixel;
}


/**
 * Initializes the fields of the given Snake instance.
 *
 * @param snake A snake instance.
 */
void initSnake(Snake &snake)
{
    int i;
    
    // Initialize the data members.
    snake.borderChar = BORDER_CHAR;
    snake.food.x = 0;
    snake.food.y = 0;
    snake.points = 0;
    snake.delay = INITIAL_DELAY;
    snake.foodEaten = false;
    snake.direction = 'l'; // Start going right.
    
    srand(time(0));

    // Sets up the board.
    initializeBoard(snake);

    // Create the snake.
    for(i = 0; i < SNAKE_LENGTH; i++)
        snake.snakeBody.push_back(createPixel(
            snake.maxWidth-SNAKE_LENGTH-2+i, 10));

    // Draw the snake.
    for(i = 0; i < snake.snakeBody.size(); i++)
    {
        move(snake.snakeBody[i].y, snake.snakeBody[i].x);
        addch(SNAKE_CHAR);
    }

    // Place some food for the snake.
    putFood(snake);

    refresh();
}


/**
 * Initializes the snake board, placing a border around the edge of the terminal
 * and a score board at the bottom.
 *
 * @param snake A snake instance.
 */
void initializeBoard(Snake &snake)
{
    // initscr() is a function defined by ncurses/pdcurses. It initializes
    // the screen.
    initscr();

    // Says to not wait for the user to enter a key when getch is called -- just
    // start processing.
    nodelay(stdscr, true);
    
    // Allows the user to touch all keys, including F1-12, up, down, etc.
    keypad(stdscr, true);

    // If user presses a key, it won't be written to the screen.
    noecho();

    // Removes the cursor.
    curs_set(0);

    // Get the max width and height.
    getmaxyx(stdscr, snake.maxHeight, snake.maxWidth);

    // Draws the border.
    drawBorder(snake);

    // Print the score banner at the bottom.
    move(snake.maxHeight-1, 0);
    printw("%d", snake.points);

    // Print a message about exiting.
    move(snake.maxHeight-1, 20);
    printw("Press 'q' to quit.");
}

/**
 * Draws the boarder around the edge of the screen.
 *
 * @param snake A snake instance.
 */
void drawBorder(Snake &snake) 
 {
    // Draw the the top border.
    for(int i = 0; i < snake.maxWidth; i++)
    {
        move(0,i);
        addch(snake.borderChar);
    }
    // Draw the bottom border.
    for(int i = 0; i < snake.maxWidth; i++)
    {
        move(snake.maxHeight-2,i);
        addch(snake.borderChar);
    }
    // Draw the left border.
    for(int i = 0; i < snake.maxHeight-2; i++)
    {
        move(i,0);
        addch(snake.borderChar);
        addch(snake.borderChar);
    }
    // Draw the right border.
    for(int i = 0; i < snake.maxHeight-2; i++)
    {
        move(i, snake.maxWidth-2);
        addch(snake.borderChar);
        addch(snake.borderChar);
    }
}

/**
 * Places a piece of food on the board, somewhere not where the snake is.
 *
 * @param snake A snake instance.
 */
void putFood(Snake &snake)
{
    int x, y;
    bool collidesWithSnake;

    // Find an (x,y) pair that does not overlap with the snake.
    do {
        collidesWithSnake = false;
        x = (rand() % (snake.maxWidth-2))+1;
        y = (rand() % (snake.maxHeight-3))+1;

        for(int i = 0; i < snake.snakeBody.size(); i++)
            collidesWithSnake = collidesWithSnake || 
                (snake.snakeBody[i].x == x && snake.snakeBody[i].y == y);

    } while(collidesWithSnake);

    snake.food.x = x;
    snake.food.y = y;

    move(snake.food.y, snake.food.x);
    addch(FOOD_CHAR);
    refresh();
}

/**
 * Checks if the snake has collided with a wall or itself. Also checks if the
 * snake has intercepted food, at which point the score is updated and a new
 * piece of food is placed on the board.
 *
 * @param snake A snake instance.
 * @return True if the snake has collided with a wall or itself.
 */
bool collision(Snake &snake)
{
    // Check if the snake has collided with a wall.
    if(snake.snakeBody[0].x == 0 || snake.snakeBody[0].x == snake.maxWidth-1 ||
        snake.snakeBody[0].y == 0 || snake.snakeBody[0].y == snake.maxHeight - 2)
        return true;

    // Check if the snake has collided with itself.
    for(int i = 2; i < snake.snakeBody.size(); i++)
        if(snake.snakeBody[0].x == snake.snakeBody[i].x && 
            snake.snakeBody[0].y == snake.snakeBody[i].y)
            return true;

    // Check if the snake has found food.
    if(snake.snakeBody[0].x == snake.food.x && 
        snake.snakeBody[0].y == snake.food.y)
    {
        snake.foodEaten = true;
        putFood(snake);
        snake.points += FOOD_POINTS;
        move(snake.maxHeight-1, 0);
        printw("%d", snake.points);
        if(snake.points%POINTS_DELAY_TRIGGER == 0)
            snake.delay -= DELAY_DECREASE;
    } else {
        snake.foodEaten = false;
    }

    return false;
}

/**
 * Moves the snake based on the current direction and the arrows keys pressed
 * by the user.
 *
 * @param snake A snake instance.
 */
void moveSnake(Snake &snake)
{

    // We're making this an int instead of a char so it works with the
    // keyboard constants below, which are octal numbers.
    int keyPress = getch();

    // Check which key was pressed and update the direction of the snake.
    switch(keyPress)
    {
        case KEY_LEFT: 
            if(snake.direction != 'r')
                snake.direction = 'l';
            break;
        case KEY_UP:
            if(snake.direction != 'd')
                snake.direction = 'u';
            break;
        case KEY_DOWN:
            if(snake.direction != 'u')
                snake.direction = 'd';
            break;
        case KEY_RIGHT:
            if(snake.direction != 'l')
                snake.direction = 'r';
            break;
        case 'q':
            snake.direction = 'q';
            break;
    }

    // Replaces the end of the snake on the board with an empty character. 
    // Removes the tail of the snake.
    if(!snake.foodEaten)
    {
        move(snake.snakeBody[snake.snakeBody.size()-1].y, 
            snake.snakeBody[snake.snakeBody.size()-1].x);
        addch(' ');
        refresh();
        snake.snakeBody.pop_back();
    }

    // delay keeps track of how quickly the screen should refresh; adjustedDelay
    // increases the refresh rate when the snake is going up or down, since
    // character blocks are taller than they are wide.
    snake.adjustedDelay = snake.delay;

    // Add a new head to the snake based on the direction it's headed in.
    // Left.
    if(snake.direction == 'l')
    {
        snake.snakeBody.insert(snake.snakeBody.begin(), 
            createPixel(snake.snakeBody[0].x-1, snake.snakeBody[0].y));
        snake.adjustedDelay /= 2;
    }
    // Right.
    else if(snake.direction == 'r')
    {
        snake.snakeBody.insert(snake.snakeBody.begin(), 
            createPixel(snake.snakeBody[0].x+1, snake.snakeBody[0].y));
        snake.adjustedDelay /= 2;
    }
    // Up.
    else if(snake.direction == 'u')
    {
        snake.snakeBody.insert(snake.snakeBody.begin(), 
            createPixel(snake.snakeBody[0].x, snake.snakeBody[0].y-1));
    }
    // Down.
    else if(snake.direction == 'd')
    {
        snake.snakeBody.insert(snake.snakeBody.begin(), 
            createPixel(snake.snakeBody[0].x, snake.snakeBody[0].y+1));
    }

    // Draw the new head that was added above.
    move(snake.snakeBody[0].y, snake.snakeBody[0].x);
    addch(SNAKE_CHAR);
    refresh();
}

/**
 * Starts and keeps running the game until the user looses or presses 'q' to 
 * quit.
 *
 * @param snake A snake instance.
 */
void startGame()
{
    Snake snake;
    char keyPress;

    initSnake(snake);

    // As long as the 'q' key hasn't been pressed and the snake hasn't collided,
    // keep going.
    while(snake.direction != 'q')
    {
        if(collision(snake))
        {
            move(snake.maxHeight/2, snake.maxWidth/2-4);
            printw("GAME OVER!!!");
            break;
        }
        moveSnake(snake);

        // Pauses for just a moment. If this weren't here, the game would be
        // over instantaneously. This is what gives us the delay between frames.
        usleep(snake.adjustedDelay);
    }

    // Make the user press 'e' to exit.
    move(snake.maxHeight/2+2, snake.maxWidth/2-8);
    printw("Press 'e' key to exit");
    display(snake);

    // We want to start waiting for the user's input.
    nodelay(stdscr, false);

    // Wait for the user to press 'e'.
    do
    {
        keyPress = getch();
    } while(keyPress != 'e');

    endwin();
}
/**
 * Displays a prompt for the user to enter their initials.
 *
 * @return The exit status.
 */
int display(Snake &snake)
{
    // This is a character array -- it's like a string. It only holds 3
    // characters, plus a '\0' -- the end of string character.
    char initials[4]; 

    // Initialize ncurse stuff.
    initscr();
    nodelay(stdscr, false); // Wait for user input.
    keypad(stdscr, true);   // Interpret all keyboard keys.
    curs_set(1);            // Display the cursor.
    echo();                 // Makes user inputs display on the screen.

    // Prompt the user.
    mvprintw(5, 10, "Please enter your initials (up to 3): ");

    // Read in only three characters.
    getnstr(initials, 3);

    // Display the user's input a few lines below.
    mvprintw(7, 10, "Thanks, %s!, your score was %d; press any key to exit.", initials, snake.points);

    // Don't exit until the user presses another key.
    getch();

    endwin();
    return 0;
}