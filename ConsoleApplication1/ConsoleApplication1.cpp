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


    vector<string> heroes = { "Brave Knight", "Cunning Thief", "Wizard", "Fearless Pirate", "Daring Explorer" };
    vector<string> places = { "in a distant kingdom", "at an abandoned factory", "in a dense forest", "in the vastness of space", "at the foot of the mountains" };
    vector<string> actions = { "defeated a dragon", "discovered treasures", "won a battle", "hosted a ball", "uncovered an ancient mystery" };
    vector<string> details = { "with a magic sword", "on a flying carpet", "to the sounds of magical music", "with incredible strength", "accompanied by a magical creature" };

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
