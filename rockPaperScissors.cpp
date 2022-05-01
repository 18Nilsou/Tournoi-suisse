/**
 *
 * @file    rockPaperScissors.cpp
 *
 * @author  Melon - Capelier Mathieu - Ceccarelli Luca - Hugues Mélanie - Saadi Nils  - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   This game is a rock paper scissors.
 *          Each player can choose to play rock, paper or scissors.
 *          According to the choice of each player, one of them got 1 point.
 *          The first one to win is the one with the higher score.
 *
 **/
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fstream>
#include "input.h"
/***
 * The last two are used in hideInput()
***/

using namespace std;

//ifstream ifs("FichierOracleEntree.txt");
//string line;

//string hideInput()
//{
//    /***
//     * This part come from StackOverflow.
//     * It takes the input of user without showing it on screen, so other players can't know what he's typing, then return it.
//    ***/
//    termios oldt;
//    tcgetattr(STDIN_FILENO, &oldt);
//    termios newt = oldt;
//    newt.c_lflag &= ~ECHO;
//    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

//    string input;
//    getline(cin, input);

//    return input;
//}

string transformInputToName(const string & input)
{
    /***
     * This function return the user input transformed into the complete name of his choice.
     * There is no other choice, because the possibility of an other choice has been verified before.
    ***/
    if(input == "p")
        return "pierre";
    else if (input == "f")
        return "feuille";
    else
        return "ciseaux";
}

unsigned rockPaperScissors()
{
    /***
     * RockPaperScissors game
     * Displays are in french
    ***/

    /* Variables */
    string inputPlayer1, inputPlayer2;

    /* Starting game message */
    cout << "Jouons à CHIFOUMI" << endl
         << endl
         << "La feuille gagne la pierre," << endl
         << "la pierre gagne les ciseaux" << endl
         << "et les ciseaux gagnent la feuille." << endl
         << "PAS DE PUIT ICI, si un joueur joue le puit, il perds la partie." << endl
         << endl
         << "Les entrées sont : \"p\" pour pierre," << endl
         << "                   \"f\" pour feuille," << endl
         << "                   \"c\" pour ciseaux." << endl
         << endl;
    global_files::ofs<< "Jouons à CHIFOUMI" << endl
                     << endl
                     << "La feuille gagne la pierre," << endl
                     << "la pierre gagne les ciseaux" << endl
                     << "et les ciseaux gagnent la feuille." << endl
                     << "PAS DE PUIT ICI, si un joueur joue le puit, il perds la partie." << endl
                     << endl
                     << "Les entrées sont : \"p\" pour pierre," << endl
                     << "                   \"f\" pour feuille," << endl
                     << "                   \"c\" pour ciseaux." << endl
                     << endl;

    /* inputs and checkings in a while loop to restart when something went wrong */
//    while (true)
//    {
        /* players inputs */
        cout << "Le joueur 1 commence : ";
        global_files::ofs<< "Le joueur 1 commence : ";
        //cin>>inputPlayer1;
        inputPlayer1=global_func::ask4UInput("");
        cout << endl << "Au tour du joueur 2 :";
        global_files::ofs<< endl << "Au tour du joueur 2 :";
        //cin>>inputPlayer2;
        inputPlayer2=global_func::ask4UInput("");
        cout << endl;
        global_files::ofs<< endl;

        /* checking if both players said "puit" */
        if (inputPlayer1 == "puit" && inputPlayer2 == "puit"){
            cout << "Non mais les gars abusez pas, j'ai dis pas de puit quoi faites un effort, allez on recommence." << endl;
            global_files::ofs<< "Non mais les gars abusez pas, j'ai dis pas de puit quoi faites un effort, allez on recommence." << endl;
        }
        /* checking if player 1 said "puit" */
        else if(inputPlayer1 == "puit")
        {
            cout << "Le joueur 1 a joué le puit, il perd la partie." << endl
                 << "Le joueur 2 gagne la partie !" << endl;
            global_files::ofs<< "Le joueur 1 a joué le puit, il perd la partie." << endl
                             << "Le joueur 2 gagne la partie !" << endl;
            //break; // SHLOUD RETURN PLAYER 2 WINNER
        }

        /* checking if player 2 said "puit" */
        else if (inputPlayer2 == "puit")
        {
            cout << "Le joueur 2 a joué le puit, il perd la partie." << endl
                 << "Le joueur 1 gagne la pertie !" << endl;
            global_files::ofs<< "Le joueur 2 a joué le puit, il perd la partie." << endl
                             << "Le joueur 1 gagne la pertie !" << endl;
            //break; // SHOULD RETURN PLAYER 1 WINNER
        }

        /* verifying inputs are goods, in this case we restart the loop */
        else if ((inputPlayer1 != "p" && inputPlayer1 != "f" && inputPlayer1 != "c") || (inputPlayer2 != "p" && inputPlayer2 != "f" && inputPlayer2 != "c")){
            cout << "L'un de vous n'a pas mis une bonne entrée, on doit donc recommencer." << endl;
            global_files::ofs<< "L'un de vous n'a pas mis une bonne entrée, on doit donc recommencer." << endl;
        }
        /* verifying inputs aren't the same, in this case we restart the loop */
        else if (inputPlayer1 == inputPlayer2){
            cout << "Match nul ! " << transformInputToName(inputPlayer1) << " contre " << transformInputToName(inputPlayer2) << "." << endl;
            global_files::ofs<< "Match nul ! " << transformInputToName(inputPlayer1) << " contre " << transformInputToName(inputPlayer2) << "." << endl;
        }
        /* if everything is fine, we continue and check who win */
        //else if (inputPlayer1 != inputPlayer2) break;
    //}

    if ((inputPlayer1 == "p" && inputPlayer2 == "c") || (inputPlayer1 == "c" && inputPlayer2 == "f") || (inputPlayer1 == "f" && inputPlayer2 == "p"))
    {
        cout << transformInputToName(inputPlayer1) << " contre " << transformInputToName(inputPlayer2) << endl
             << "Le joueur 1 gagne la partie !" << endl;
        global_files::ofs<< transformInputToName(inputPlayer1) << " contre " << transformInputToName(inputPlayer2) << endl
                         << "Le joueur 1 gagne la partie !" << endl;
          return 0;
    }
    else
    {
        cout << transformInputToName(inputPlayer2) << " contre " << transformInputToName(inputPlayer1) << endl
             << "Le joueur 2 gagne la partie !" << endl;
        global_files::ofs<< transformInputToName(inputPlayer2) << " contre " << transformInputToName(inputPlayer1) << endl
                         << "Le joueur 2 gagne la partie !" << endl;
        return 1;
    }
}
