#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


int getRandomIndex(int size) {
    return rand() % size;
}


string generateStory(const vector<string>& heroes, const vector<string>& places,
    const vector<string>& actions, const vector<string>& details) {
    int heroIndex = getRandomIndex(heroes.size());
    int placeIndex = getRandomIndex(places.size());
    int actionIndex = getRandomIndex(actions.size());
    int detailIndex = getRandomIndex(details.size());

    return heroes[heroIndex] + " " + places[placeIndex] + ", " +
        actions[actionIndex] + " " + details[detailIndex] + ".";
}

void saveStory(const string& story) {
    ofstream outFile("stories.txt", ios::app);
    if (outFile.is_open()) {
        outFile << story << "\n";
        outFile.close();
        cout << "Story saved to stories.txt" << endl;
    }
    else {
        cout << "Error opening file for writing!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); 

    vector<string> heroes = { "detective", "wise elder", "time traveler", "mysterious stranger", "fearless princess" };
    vector<string> places = { "in an abandoned castle", "on a distant planet", "in an underground city", "at the top of a skyscraper", "in a hidden laboratory" };
    vector<string> actions = { "uncovered a great mystery", "discovered an artifact", "changed the course of history", "saved the world from catastrophe", "exposed a conspiracy" };
    vector<string> details = { "with the help of an ancient scroll", "accompanied by a talking animal", "during a solar eclipse", "using supernatural powers", "thanks to a mysterious ally" };

    char playAgain;
    do {
 
        string story = generateStory(heroes, places, actions, details);
        cout << "\nGenerated Story:\n" << story << endl;

        char saveChoice;
        cout << "\nSave the story to file (stories.txt)? (Y/N): ";
        cin >> saveChoice;
        if (saveChoice == 'Y' || saveChoice == 'y') {
            saveStory(story);
        }

        cout << "\nDo you want to create a new story? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
