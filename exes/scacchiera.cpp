#include <iostream>
#include <stdexcept>
#include <string>
#include <time.h>
#include <string.h>
#include <fstream>
#include "../src/color/Color.h"
#include "../src/Game/Game.h"
#include "../src/player/Human.h"
#include "../src/player/Computer.h"

// Metodo usato per pulire la console
void clearConsole() {
    std::cout << std::string(50, '\n');
}

// Metodo che mi ritorna la data e il tempo di "now" per dare nome ai file
std::string getCurrentDateTime() {
    time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d%b%Y_%H.%M.%S", &tstruct);
    return std::string(buf);
};

int main(int argc, char* argv[])
{

    std::string input;

    // Controllo gli argomenti
    if (argc != 2 || (strcmp(argv[1], "pc") != 0 && strcmp(argv[1], "cc") != 0)) {
        std::cout << "Utilizzo:" << std::endl;
        std::cout << argv[0] << " pc  - Effettua una partita giocatore vs computer." << std::endl;
        std::cout << argv[0] << " cc  - Effettua una partita computer vs computer." << std::endl;
        return 0;
    }

    // Mappa in modo che dal colore ottengo il giocatore
    std::map<Color, Player*> players;

    // Capisco se mostrare la board
    bool display = strcmp(argv[1], "pc") == 0;

    // Genero il seed del random
    srand(time(NULL));

    // Genero casualmente i colori
    int p1Color = rand() % 2;
    int p2Color = !p1Color;

    // Inizializzo la partita
    Game game{ 100 };

    // Genero i giocatori
    if (display) {
        players[(Color)p1Color] = new Human{ (Color)p1Color, &game };
        players[(Color)p2Color] = new Computer{ (Color)p2Color, &game };
    }
    else {
        players[(Color)p1Color] = new Computer{ (Color)p1Color, &game };
        players[(Color)p2Color] = new Computer{ (Color)p2Color, &game };
    }
    std::string message = "";

    // Gameloop
    do {

        if (display) {
            clearConsole();
            std::cout << "TOCCA AL " << game.getTurn() << "!" << std::endl << std::endl;

            // Il giocatore è in scacco?
            if (game.isPlayerInCheck()) {
                std::cout << "!! ATTENZIONE !!" << std::endl;
                std::cout << "Sei sotto scacco." << std::endl;
                std::cout << "Sei obbligato a uscirne." << std::endl;
            }

            // Mostro la scacchiera
            std::cout << game << std::endl << std::endl;

            // Mostro i messaggi di errore
            if (message != "") {
                std::cout << "!! ATTENZIONE !!" << std::endl;
                std::cout << message << std::endl << std::endl;
                message = "";
            }

            std::cout << ">> ";
        }


        try {
            // Prendo l'input (Se chiedere al giocatore o al pc -> polimorfismo)
            input = players[game.getTurn()]->takeInput();
            game.takeTurn(input);
        }
        catch (const std::runtime_error& e) {
            message = e.what();
        }


    } while (!game.isFinished());

    // Stampo il risultato
    if (game.getWinner() != Color::NONE) 
        std::cout << game.getWinner() << " ha vinto!" << std::endl;
    else
        std::cout << "Non ha vinto nessuno!" << std::endl;

    // Genero il file di log
    std::string date = getCurrentDateTime();
    date += ".txt";
    std::ofstream log{ date.c_str()};
    std::vector<Move> his = game.getHistory();
    for (Move m : his) 
        log << m;
    log.close();


    return 0;
}
