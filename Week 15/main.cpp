#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a single video game entry
class GameEntry {
public:
    string name;
    string platform;
    int year;
    string genre;
    string publisher;
    double globalSales;

    // Constructor
    GameEntry(const string& n, const string& p, int y, const string& g, const string& pub, double gs)
        : name(n), platform(p), year(y), genre(g), publisher(pub), globalSales(gs) {}

    // Display function
    void display() const {
        cout << "Name: " << name << "\n"
             << "Platform: " << platform << "\n"
             << "Year: " << year << "\n"
             << "Genre: " << genre << "\n"
             << "Publisher: " << publisher << "\n"
             << "Global Sales (millions): " << globalSales << "\n\n";
    }
};

// Class responsible for loading entries from the CSV file
class Load {
public:
    vector<GameEntry> loadData(const string& filename) {
        vector<GameEntry> entries;
        ifstream file(filename);
        string line;

        // Skip header line
        getline(file, line);

        int count = 0;
        while (getline(file, line) && count < 10) { // Load at least 10 entries
            stringstream ss(line);
            string name, platform, yearStr, genre, publisher, globalStr;

            // Extract each comma-separated field
            getline(ss, name, ',');
            getline(ss, platform, ',');
            getline(ss, yearStr, ',');
            getline(ss, genre, ',');
            getline(ss, publisher, ',');

            // Skip regional sales columns
            string temp;
            for (int i = 0; i < 4; i++) getline(ss, temp, ',');

            // Extract global sales
            getline(ss, globalStr, ',');

            // Handle missing or invalid year values
int year = 0;
try {
    year = stoi(yearStr);
} catch (...) {
    year = 0; // default value when stoi fails
}
            double globalSales = 0.0;
try {
    globalSales = stod(globalStr);
} catch (...) {
    globalSales = 0.0; // default when conversion fails
}

            entries.emplace_back(name, platform, year, genre, publisher, globalSales);
            count++;
        }

        return entries;
    }
};

int main() {
    Load loader;
    vector<GameEntry> games = loader.loadData("vgsales.csv");

    cout << "Loaded Video Game Entries:\n\n";
    for (const auto& game : games) {
        game.display();
    }

    return 0;
}