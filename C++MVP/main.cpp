#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// Struktur für ein Gemälde
struct Painting {
    std::string url;
    std::string artist;
    std::string creationDate;
    std::string title;
    int officialPrice;
};

// Funktion zum Öffnen einer URL in Chrome
void openURL(const std::string& url) {
    std::string cmd = "open " + url;
    std::system(cmd.c_str());
}

// ANSI-Escape-Codes für verschiedene Farben
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[94m";
const std::string RESET = "\033[0m";

int main() {
    // Liste der Gemälde
    std::vector<Painting> paintings = {
        {"https://upload.wikimedia.org/wikipedia/commons/thumb/e/ec/Mona_Lisa%2C_by_Leonardo_da_Vinci%2C_from_C2RMF_retouched.jpg/800px-Mona_Lisa%2C_by_Leonardo_da_Vinci%2C_from_C2RMF_retouched.jpg", "Lionardo di ser Piero da Vinci", "1503–1506", "Mona Lisa (La Gioconda)", 792150000},
        {"https://upload.wikimedia.org/wikipedia/en/e/e5/Magritte_TheSonOfMan.jpg", "René François Ghislain Magritte", "1964", "The Son of Man", 8750000},
    };
    std::system("clear");
    std::cout << BLUE << "Willkommen bei ArtGuessr!\n" << RESET;
    std::cout << "Erraten Sie den Preis der folgenden Gemälde.\n\n";
    std::cout << YELLOW << "Drücken Sie ENTER, um zu beginnen." << RESET;
    std::cin.get();

    for (const Painting& painting : paintings) {
        std::system("clear");
        std::cout << BLUE << "ArtGuessr\n" << RESET;
        std:: cout << "\n";
        std::cout << GREEN << "\nEin neues Gemälde wird geladen...\n\n" << RESET;

        // Öffnen Sie das Gemälde in Chrome
        openURL(painting.url);

        // Geben Sie die Hinweise aus
        std::cout << BLUE << "Hier sind einige Hinweise zum Gemälde:\n";
        std::cout << "-------------------------------------\n";
        std::cout << "Künstler: " << RESET << painting.artist << "\n";
        std::cout << BLUE << "Erstellungsdatum: " << RESET << painting.creationDate << "\n";
        std::cout << BLUE << "Titel: " << RESET << painting.title << "\n";
        std::cout << BLUE << "-------------------------------------\n\n" << RESET;

        // Warten Sie auf die Schätzung des Benutzers
        int userGuess;
        std::cout << "Ihre Schätzung in EUR: ";
        std::cin >> userGuess;

        // Geben Sie den offiziellen Preis und die Differenz aus
        std::cout << "\n";
        std::cout << GREEN <<"Offizieller Preis: " << painting.officialPrice << " EUR\n" << RESET;
        std::cout << RED << "Sie lagen daneben um: " << abs(painting.officialPrice - userGuess) << " EUR\n\n" << RESET;

        // Warten Sie auf den Benutzer, um fortzufahren
        std::cout << YELLOW << "Drücken Sie ENTER, um fortzufahren." << RESET;
        std::cin.get();
        std::cin.get(); // Ein zusätzliches get(), um das '\n' Zeichen zu entfernen, das von cin >> userGuess hinterlassen wurde
    }

    return 0;
}
