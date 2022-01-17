#include <iostream>
#include <stdexcept>
#include <string>
#include "../src/color/Color.h"
#include "../src/game/Game.h"
#include "../src/player/Human.h"
#include "../src/player/Computer.h"
#include <time.h>
#include <string.h>
#include <fstream>
#include <regex>
#include <chrono>
#include <thread>

void clearConsole() {
    std::cout << std::string(50, '\n');
}

int main(int argc, char* argv[])
{
    // Controllo numero argomenti
    if (argc < 3 || argc > 4) {
        if (argc == 1 || argc > 4 || (argc == 2 && strcmp(argv[1], "v") != 0 && strcmp(argv[1], "f") != 0)) {// Chiamata solo di replay.exe
            std::cout << "Utilizzo:" << std::endl;
            std::cout << argv[0] << " v [nome_file_log]  - Stampa a video il replay della partita." << std::endl;
            std::cout << argv[0] << " f [nome_file_log] [nome_file_output] - Stampa nel file destinazione il replay della partita." << std::endl;
        }
        else if (argc == 2) {
            // Dato il controllo prima, so che e' stato fatto "replay.exe v" oppure "replay.exe f"
            if (strcmp(argv[1], "v") == 0) {
                std::cout << "Utilizzo:" << std::endl;
                std::cout << argv[0] << " v [nome_file_log]  - Stampa a video il replay della partita." << std::endl;
            } else if(strcmp(argv[1], "f") == 0){
                std::cout << "Utilizzo:" << std::endl;
                std::cout << argv[0] << " f [nome_file_log] [nome_file_output] - Stampa nel file destinazione il replay della partita." << std::endl;
            }

        }
        return 0;
    }

    // Numeri argomenti validi, controllo dei file
    if (argc == 3 && strcmp(argv[1], "v") == 0 && !std::regex_match(argv[2], std::regex{ ".+\\.txt" })) {
        std::cout << "Utilizzo:" << std::endl;
        std::cout << argv[0] << " v [nome_file_log]  - Stampa a video il replay della partita." << std::endl;
        return 0;
    }

    if ((argc == 3 && strcmp(argv[1], "f") == 0) || (argc == 4 && (!std::regex_match(argv[2], std::regex{ ".+\\.txt" }) || !std::regex_match(argv[3], std::regex{ ".+\\.txt" })))) {
        std::cout << "Utilizzo:" << std::endl;
        std::cout << argv[0] << " f [nome_file_log] [nome_file_output] - Stampa nel file destinazione il replay della partita." << std::endl;
        return 0;
    }

    // Capisco dove devo stampare
    bool printToCmd = argc == 3;

    // Creo il file da dove leggo le mosse
    std::ifstream inputStream { argv[2] , std::ios::in};

    // Creo il file di output che userò solo se necessario
    std::ofstream output{ argv[3] , std::ios::out };

    // Creo una partita
    Game game;

    // Variabileche conterra' la riga letta da file
    std::string move;

    // Finchè leggo una riga dal file
    try{
        while(getline( inputStream, move )){
            // Controllo se la mossa letta è valida
            if(!std::regex_match(move, std::regex{"([a-h][1-8] [a-h][1-8])( [CATD])?", std::regex_constants::icase}))
                throw std::runtime_error("Il file log non e' valido.");

            // Se accade un errore allora il file è stato manomesso, perchè nel log vengono solo 
            // salvate le mosse eseguite con successo
            try{
                game.takeTurn(move);
            } catch(const std::runtime_error& e) {
                throw std::runtime_error("Il file log e' stato manomesso.");
            }

            // Capisco dove stampare
            if (printToCmd) {
                // Stampo
                clearConsole();
                std::cout << game << std::endl;

                // Aspetto un secondo
                std::chrono::seconds dura(1);
                std::this_thread::sleep_for( dura );
            }
            else 
                output << game << std::endl << std::endl; // Essendo su file non serve aspettare
        }   
    } catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;      
    }

    // Chiudo i file usati
    output.close();
    inputStream.close();
    return 0;
}
