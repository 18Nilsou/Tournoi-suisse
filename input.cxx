/**
 *
 * @file    input.cxx
 *
 * @author  Melon - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Saadi Nils - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   This file contains a function that will be used to read into the input file and write into the output file.
 *
 **/
#include <fstream>
#include "input.h"
#include <iostream>

// Definition des fichiers d'entree et sortie
ifstream global_files::ifs;
ofstream global_files::ofs;

string global_func::ask4UInput(const string & invite, const bool & putInOutput) {
    /// Fonction utilisee pour demander une entree a l'utilisateur
    if (putInOutput) global_files::ofs << invite;         // On met l'invite dans le fichier de sortie (s'il est ouvert)
    string answer;
    while (true) {
        getline(global_files::ifs, answer);
        cout<<answer;
        if (global_files::ifs.eof()) {                   // Si on essaye de lire plus loin que la fin du fichier
            cout << "fin du fichier : aucune donnee recuperee" << endl;
            return "";                                   // On affiche dans la console qu'on a une erreur de lecture
        }
        if (answer.size() < 2 || answer[0] != '/' || answer[1] != '/')
            break;                                       // Si on a une ligne de commentaire on lis la ligne suivante, sinon on sort dela boucle
    }
    if (putInOutput) global_files::ofs << answer << endl;  // On affiche la reponse dans le fichier de sortie (s'il est ouvert)
    return answer;
}
