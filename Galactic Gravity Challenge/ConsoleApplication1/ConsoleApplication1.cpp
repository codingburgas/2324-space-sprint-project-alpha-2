#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

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
    displayCentered("Back-end Developer - Mihail Nikolov");
    displayCentered("Back-end Developer - Viktor Kanev");
    displayCentered("=======================");
    displayCentered("Press any key to go back to main menu.");
    cin.ignore(); // Ignore any previous newline character
    cin.get(); // Wait for user input
}

// Function to start the game
void startGame() {
    // Array of questions about planets
    vector<pair<string, string>> questions = {
        {"Which planet is closest to the Sun?", "Mercury"},
        {"Which planet is known as the Red Planet?", "Mars"},
        {"What is the largest planet in our solar system?", "Jupiter"},
        {"Which planet has the most moons?", "Jupiter"},
        {"Which planet is nicknamed the 'Morning Star' or 'Evening Star'?", "Venus"},
        {"Which planet has the shortest day?", "Jupiter"},
        {"Which planet is known for its beautiful rings?", "Saturn"},
        {"Which planet is known as the 'Blue Planet'?", "Earth"},
        {"Which planet is sometimes called Earth's sister planet?", "Venus"},
        {"What is the smallest planet in our solar system?", "Mercury"},
        {"Which planet has the highest mountain in the solar system?", "Mars"},
        {"Which planet is the only one known to support life?", "Earth"},
        {"Which planet is known for its Great Dark Spot?", "Neptune"},
        {"Which planet spins on its side?", "Uranus"},
        {"Which planet is known as the 'Ice Giant'?", "Neptune"},
        {"Which planet has the longest day?", "Venus"},
        {"Which planet has the most rings?", "Saturn"},
        {"Which planet is known as the 'Red Planet'?", "Mars"},
        {"Which planet is known as the 'Evening Star'?", "Venus"},
    };

    // Shuffle the questions
    random_shuffle(questions.begin(), questions.end());

    int score = 0;
    int totalQuestions = questions.size(); // Number of questions

    // Ask questions
    for (int i = 0; i < totalQuestions; ++i) {
        cout << "Question " << i + 1 << ": " << questions[i].first << endl;
        string userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer; // Getting input using cin
        if (userAnswer == questions[i].second) {
            cout << "Correct!\n";
            ++score;
        }
        else {
            cout << "Incorrect. The correct answer is: " << questions[i].second << endl;
        }
        cout << endl;
    }

    // Display final score
    cout << "Quiz ended. Your score is: " << score << "/" << totalQuestions << endl;
    cout << "Press Enter to return to the main menu." << endl;
    cin.ignore();
    cin.get();
}

void displayPlanetInfo(const Planet& planet) {
    system("cls"); // Clear screen
    displayCentered("==== " + planet.name + " ====");
    displayCentered("Gravity: " + to_string(planet.gravity) + " m/s^2");
    displayCentered("Interesting Fact: " + planet.fact);
    displayCentered("=================");
    char key;
    cin.ignore(); // Ignore any newline characters in the input buffer
    cin >> key;
}

int main() {
    // Define planets
    vector<Planet> planets = {
    {"Mercury", 3.7, "Mercury has the largest temperature variations of any planet in the Solar System. And the closest planet to the Sun. The smallest planet in our Solar system."},
    {"Venus", 8.87, "Venus rotates in the opposite direction to most other planets. Has two nicknames 'Morning Star' and 'Evening Star'. Sometimes called Earth's sister planet. Has the longest day. Known as the 'Evening Star'."},
    {"Earth", 9.81, "Earth is the only planet in the Solar System known to support life. Known as the 'Blue Planet'. The only one known to support life."},
    {"Mars", 3.71, "Mars is home to the tallest volcano and the largest canyon in the Solar System. Also known as The Red Planet. Has the highest mountain in the solar system. Known as the 'Red Planet'."},
    {"Jupiter", 24.79, "Jupiter has the shortest day of all the planets. The largest planet in the Solar system and the planet with the most moons. The planet with the shortest day."},
    {"Saturn", 10.44, "Saturn is the least dense of all the planets in the Solar System. Well known for its beautiful rings. Has the most rings."},
    {"Uranus", 8.69, "Uranus is the coldest planet in the Solar System. Spins on its side."},
    {"Neptune", 11.15, "Neptune's blue color is due to the presence of methane in its atmosphere. Known for its Great Dark Spot. Known as the 'Ice Giant'."}
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
                displayCentered(to_string(i + 1) + ". " + planets[i].name);
            }
            displayCentered("================");
            displayCentered("Enter the number of the planet to view its information.");
            int planetOption;
            cin >> planetOption;
            if (planetOption >= 1 && planetOption <= planets.size()) {
                displayPlanetInfo(planets[planetOption - 1]);
            }
            else {
                displayCentered("Invalid planet option. Please try again.");
            }
            displayMainMenu = true;
            break;
        }
        case 2:
            startGame();
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