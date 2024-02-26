#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// Function to get the width of the console window
int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

// Function to display centered text
void displayCentered(const string& text) {
    int width = getWindowWidth();
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}

// Define the structure for a planet
struct Planet {
    string name;
    double gravity; // Gravity in m/s^2
    string fact;

};

// Function to display game instructions
void displayInstructions() {
    system("cls");
    displayCentered("==== Galactic Gravity Challenge ====");
    displayCentered("Instructions:");
    displayCentered("You are piloting a spaceship through space.");
    displayCentered("Navigate through the gravitational fields of different planets.");
    displayCentered("Avoid crashing into planets and obstacles.");
    displayCentered("Reach the target destination to win.");
    displayCentered("Controls: Use arrow keys to move the spaceship.");
    displayCentered("Press any key to start the game...");
    cin.ignore();
    cin.get();
}

void displayCredits() {
    system("cls");
    displayCentered("==== Credits ====");
    displayCentered("Scrum - Stefan Ivanov");
    displayCentered("Back-end Developer - Veselin Boyanov");
    displayCentered("Back-end Developer (Designer) - Mihail Nikolov");
    displayCentered("Back-end Developer (QA) - Viktor Kanev");
    displayCentered("=======================");
    displayCentered("Press any key to go back to main menu.");
    cin.ignore(); // Ignore any previous newline character
    cin.get(); // Wait for user input
}

// Function to start the game
void startGame(const vector<Planet>& planets) {
    system("cls");
    displayInstructions();

    // Initialize game variables
    const int targetX = 50; // Target destination X coordinate
    const int targetY = 5;  // Target destination Y coordinate
    int spaceshipX = 10;    // Initial spaceship X coordinate
    int spaceshipY = 20;    // Initial spaceship Y coordinate
    double velocityX = 0;   // Initial velocity along X axis
    double velocityY = 0;   // Initial velocity along Y axis
    double accelerationX = 0; // Initial acceleration along X axis
    double accelerationY = 0; // Initial acceleration along Y axis
    double gravity = planets[0].gravity; // Initial gravity

    // Main game loop
    bool gameover = false;
    while (!gameover) {
        system("cls");

        // Update velocity and position based on acceleration
        velocityX += accelerationX;
        velocityY += accelerationY;
        spaceshipX += static_cast<int>(velocityX);
        spaceshipY += static_cast<int>(velocityY);

        // Display spaceship
        cout << setw(spaceshipX) << "  ^  " << endl;
        cout << setw(spaceshipX - 1) << " /_\\ " << endl;

        // Display target destination
        cout << setw(targetX) << "  X  " << endl;
        cout << setw(targetX) << "     " << endl;

        // Display planet
        cout << setw(0) << "Planet: " << planets[0].name << " (Gravity: " << planets[0].gravity << " m/s^2)" << endl;

        // Check for collision with planet
        if (spaceshipX == 0 || spaceshipY == 0) {
            displayCentered("Spaceship crashed into the planet!");
            gameover = true;
        }

        // Check for collision with target
        if (spaceshipX == targetX && spaceshipY == targetY) {
            displayCentered("Congratulations! You reached the target destination.");
            gameover = true;
        }

        // Prompt user for action
        displayCentered("Use arrow keys to control the spaceship. Press 'Q' to quit.");

        // Handle user input
        char key;
        cin >> key;
        switch (key) {
        case 'Q':
        case 'q':
            gameover = true;
            break;
        case 'W':
        case 'w':
            accelerationY = -gravity;
            break;
        case 'S':
        case 's':
            accelerationY = gravity;
            break;
        case 'A':
        case 'a':
            accelerationX = -gravity;
            break;
        case 'D':
        case 'd':
            accelerationX = gravity;
            break;
        default:
            break;
        }
    }
}

void displayPlanetInfo(const Planet& planet) {
    system("cls"); // Clear screen
    displayCentered("==== " + planet.name + " ====");
    displayCentered("Gravity: " + to_string(planet.gravity) + " m/s^2");
    displayCentered("Interesting Fact: " + planet.fact);
    displayCentered("=================");
    displayCentered("Press any key to go back to main menu.");
    cin.ignore(); // Ignore any previous newline character
    cin.get(); // Wait for user input
}



int main() {
    // Define planets
    vector<Planet> planets = {

        {"Mercury", 3.7, "Mercury has the largest temperature variations of any planet in the Solar System."},
        {"Venus", 8.87, "Venus rotates in the opposite direction to most other planets."},
        {"Earth", 9.81, "Earth is the only planet in the Solar System known to support life."},
        {"Mars", 3.71, "Mars is home to the tallest volcano and the largest canyon in the Solar System."},
        {"Jupiter", 24.79, "Jupiter has the shortest day of all the planets."},
        {"Saturn", 10.44, "Saturn is the least dense of all the planets in the Solar System."},
        {"Uranus", 8.69, "Uranus is the coldest planet in the Solar System."},
        {"Neptune", 11.15, "Neptune's blue color is due to the presence of methane in its atmosphere."},

        {"Mercury", 3.7},
        {"Venus", 8.87},
        {"Earth", 9.81},
        {"Mars", 3.71},
        {"Jupiter", 24.79},
        {"Saturn", 10.44},
        {"Uranus", 8.69},
        {"Neptune", 11.15}
    };

    int option;
    bool displayMainMenu = true;
    do {
        if (displayMainMenu) {
            system("cls");
            displayCentered("==== Galactic Gravity Challenge ====");
            displayCentered("1. View Planets");
            displayCentered("2. Start Game");
            displayCentered("3. Credits");
            displayCentered("4. Quit");
        }
        cin >> option;

        switch (option) {
        case 1: {
            system("cls");
            displayCentered("==== Planets ====");
            for (int i = 0; i < planets.size(); ++i) {
                displayCentered(to_string(i + 1) + ". " + planets[i].name + " (Gravity: " + to_string(planets[i].gravity) + " m/s^2)");
            }
            displayCentered("================");
            displayCentered("Press any key to go back to main menu.");
            cin.ignore(); // Ignore any previous newline character
            cin.get(); // Wait for user input
            displayMainMenu = true;
            break;
        }
        case 2:
            startGame(planets);
            displayMainMenu = true;
            break;
        case 3:
            displayCredits();
            displayMainMenu = true;
            break;
        case 4:
            displayCentered("Exiting game. Goodbye!");
            break;
        default:
            displayCentered("Invalid option. Please try again.");
            displayMainMenu = false;
        }
    } while (option != 4);

    return 0;
}
