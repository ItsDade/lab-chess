#include "Human.h"

std::string Human::takeInput()
{
	// Prendo l'input e lo ritorno, il controllo sar� altrove
	std::string input; 
	getline(std::cin, input);
	return input;
}
