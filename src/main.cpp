#include <iostream>
#include "cli.hpp"
#include <string>
#include "utils.hpp"

using namespace std;
using namespace disco;

int main() {
    // On préremplit la discographie.
    string const dave_brubeck{ "Dave Brubeck " };
    string const secret_garden{ "Secret Garden" };
    string const indochine{ "Indochine" };

    string const time_out{ "Time Out" };
    string const songs_from_a_secret_garden{ "Songs from a Secret Garden" };
    string const l_aventurier{ "L'aventurier" };
    string const paradize{ "Paradize" };

    Track const take_five{ "Take Five", dave_brubeck, time_out };
    Track const blue_rondo_a_la_turk{ "Blue Rondo a la Turk", dave_brubeck, time_out };
    Track const nocturne{ "Nocturne", secret_garden, songs_from_a_secret_garden };
    Track const aventurier{ "L'aventurier", indochine, l_aventurier };
    Track const j_ai_demande_a_la_lune{ "J'ai demandé à la lune", indochine, paradize };

    Discography discography{{ take_five, blue_rondo_a_la_turk, nocturne, aventurier, j_ai_demande_a_la_lune} };

    bool running{true };
    do
    {
        try
        {
            std::string entree{ get_command() };
            auto[commande, instructions] = analyse_command(entree);
            instructions = string_cleanup(instructions);
            running = run_command(discography, commande, instructions);
        }
        catch (std::runtime_error const & exception)
        {
            std::cout << "Erreur : " << exception.what() << std::endl;
        }

    } while (running);

    return 0;
}
