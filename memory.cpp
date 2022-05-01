/**
 *
 * @file    nom_du_fichier.extension
 *
 * @author  Melon - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Saadi Nils - Valls Marion - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   This is a memory game.
 *          Each player have to memorize a position in a grid printed on the terminal.
 *          Every right answer give 1 point.
 *          The first one to win is the one with the higher score.
 *
 **/
#include <iostream>
#include <vector>   // Arrays, and 2 dimensions arrays
#include <stdlib.h> // srand(), rand()
#include <time.h>   // time() -> create a random seed
#include <string>   // stoi()
#include <chrono>   // seconds()
#include <thread>   // sleep_for()
#include <cctype>   // isdigit()
#include <fstream>
#include "input.h"

using namespace std;

/***
 * Colored Text:
 * "\033[1;30m string \033[0m" this format is used to write a colored string in a Linux terminal
 *  the color and the style depends on the values after the square brackets
 *  1 means that the text will be in bold, we can use 0 for normal text
 *  and 30am its the foreground color of the text, wich in this case is black
 *  the colors used are : black : 30 , red : 31 , green : 32 , white : 37
***/

vector<vector<string>> newGrid(){
    /***
     * Generate a new grid of 11x11 values
     * the grid used for the game its a 9x9, the rest its for aesthetic
    ***/
    vector<vector<string>> grid;
    vector<string> filledRow;
    vector<string> notFilledRow;

    /***
     * Loop used to create the differents types of rows that will be used
    ***/
    for(unsigned i=0; i<2; ++i){
        if(i==0){
            for(unsigned j=0; j<11; ++j){
                filledRow.push_back("\033[1;30m - \033[0m");
            }
        }
        else{
            for(unsigned j=0; j<11; ++j){
                if(j==0 or j==10){
                    notFilledRow.push_back("\033[1;30m | \033[0m");
                }
                else{
                    notFilledRow.push_back("\033[1;37m 0 \033[0m");
                }
            }
        }
    }

    /***
     * Loop used to create the 2 dimension grid
     * using the differents types of rows
    ***/
    grid.push_back(filledRow);
    for(unsigned i=0; i<9; ++i){//i<23
        grid.push_back(notFilledRow);
    }
    grid.push_back(filledRow);

    return grid;
}


void printGrid(const vector<vector<string>> & grid){
    /***
     * Print a grid, and the aesthetic
    ***/
    cout<<"      1  2  3  4  5  6  7  8  9   "<<endl;
    global_files::ofs<<"      1  2  3  4  5  6  7  8  9   "<<endl;
    for(unsigned i=0; i<11; ++i){
        if(i>0 && i<10){
            cout<<i<<" ";
            global_files::ofs<<i<<" ";
        }
        for(unsigned j=0; j<11; ++j){
            cout<<grid[i][j];
            global_files::ofs<<grid[i][j];
        }
        cout<<endl;
        global_files::ofs<<endl;
    }
}

vector<vector<string>> changeGrid(vector<vector<string>> & grid,const vector<unsigned> & valuesToAdd){
    /***
     * Changes a value in the grid
     * using the informations given in the list valuesToAdd
     * which contains a value, the row and the column
    ***/
    string convertedValue = to_string(valuesToAdd[0]);
    string color;

    unsigned row = valuesToAdd[1];
    unsigned column = valuesToAdd[2];
    color = "\033[1;31m "+convertedValue+" \033[0m";
    grid[row][column]= color;

    return grid;
}

bool isListInTwoDimensionList(const vector<vector<unsigned>> & listOfValuesAndPositions, const vector<unsigned> & listOfValuesToFind){
    /***
     * Checks if in a 2 dimension array
     * there is a list containing 2 of the 3 values
     * stored in another list
    ***/
    for(unsigned i = 0 ; i<listOfValuesAndPositions.size(); ++i){
        if(listOfValuesAndPositions[i][1] == listOfValuesToFind[1] && listOfValuesAndPositions[i][2] == listOfValuesToFind[2]){
            return true;
        }
    }
    return false;
}

vector<vector<unsigned>> findNewValues(const unsigned & numberOfValues){
    /***
     * Find a number of values to insert in the grid
     * and checks if the position isnt already occupied
    ***/
    vector<vector<unsigned>> listOfValuesAndPositions;
    vector<unsigned> valueAndPositions;//[val, row, column]

    unsigned row, column;
    row=rand() % 9 + 1;
    column=rand() % 9 + 1;

    //Insert the first value in the empty list
    valueAndPositions.push_back(1);
    valueAndPositions.push_back(row);
    valueAndPositions.push_back(column);
    listOfValuesAndPositions.push_back(valueAndPositions);

    //If only 1 value is required stops the fonctions whitout doing any useless test
    if (numberOfValues == 1) return listOfValuesAndPositions;

    //Adds random values to the row and column position, and checks if they are used
    for(unsigned i= 2 ; i<numberOfValues+1; ++i){
        valueAndPositions[0]=i;
        valueAndPositions[1]=row;
        valueAndPositions[2]=column;
        while(true){ //Checking values
            if( isListInTwoDimensionList(listOfValuesAndPositions,valueAndPositions)){ //If the values are already used, change them
                row=rand() % 9 + 1;
                column=rand() % 9 + 1;
                valueAndPositions[1]=row;
                valueAndPositions[2]=column;
            }
            else{ //Else, exit the loop, add the values to the list, and start the process back
                break;
            }
        }
        listOfValuesAndPositions.push_back(valueAndPositions);
    }

    return listOfValuesAndPositions;
}

unsigned playerInput(){
    /***
     * Function that asks a user input
     * If the user input its a character or a number higher then 10
     * asks the user a new input
     * If the user passes all the tests the value that has been guessed will be returned and assigned
    ***/
    unsigned guessedValue;

    while(true){
        //cin>>guessedValue;
        guessedValue=stoul(global_func::ask4UInput(""));
        if(cin.fail())
        {
            cout<<"Vous avez saisi autre chose qu'un nombre, veuillez resseyer"<<endl;
            global_files::ofs<<"Vous avez saisi autre chose qu'un nombre, veuillez resseyer"<<endl;
            cout<<"Entrez la valeur "<<endl;
            global_files::ofs<<"Entrez la valeur "<<endl;
        }
        if(not(cin.fail()))
        {
            if (guessedValue<10){
                break;
            }
            else{
                cout<<"Vous avez saisi un nombre superieur a 10, veuillez resseyer"<<endl;
                global_files::ofs<<"Vous avez saisi un nombre superieur a 10, veuillez resseyer"<<endl;
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return guessedValue;
}

bool playerInputMaster(const vector<vector<unsigned>> & listOfValuesAndPositions , const unsigned & numberOfValues){
    /***
     * Function that asks a user input
     * and checks if the user has a right or wrong answer
     * for each number of the memory game
     * listOfValuesAndPositions and playerGuessedValues are structured as (number on grid, row, column)
    ***/
    vector<unsigned> playerGuessedValues;

    //Initialize the array with Null values
    playerGuessedValues.push_back(0);
    playerGuessedValues.push_back(0);
    playerGuessedValues.push_back(0);

    /***
     * Loop wich asks a user input
     * checks if the input is fine
     * adds the answer of the user to an array
     * checks if the values in the user array are equals to the ones to guess in the grid
     * if correct the player goes on to the next value
     * if not the function stops and returns false
    ***/
    for(unsigned i=0 ; i<numberOfValues; ++i){

        cout<<"Entrez la ligne de la valeur "<<i+1<<endl;
        global_files::ofs<<"Entrez la ligne de la valeur "<<i+1<<endl;
        playerGuessedValues[1]=playerInput();                   //enter row value in the list of guesses

        cout<<"Entrez la colonne de la valeur "<<i+1<<endl;
        global_files::ofs<<"Entrez la colonne de la valeur "<<i+1<<endl;
        playerGuessedValues[2]=playerInput();                   //enter column value in the list of guesses

        playerGuessedValues[0]=i+1;                             //change the value that is being guessed to match with the number on the grind

        /***
         * Checks if the guessed values are equals to the real values
        ***/

        if(listOfValuesAndPositions[i][0]==playerGuessedValues[0] &&
           listOfValuesAndPositions[i][1]==playerGuessedValues[1] &&
           listOfValuesAndPositions[i][2]==playerGuessedValues[2]){
            //system("clear");
            continue;
        }
        else{
            //system("clear");
            cout<<"\033[1;31m"<<"Vous vous etes trompes"<<"\033[0m"<<endl;
            global_files::ofs<<"\033[1;31m"<<"Vous vous etes trompes"<<"\033[0m"<<endl;
            return false;
        }
    }
    return true;
}

int memoryGame(){
    /***
     * Function to assign to a player a score after playing the game
    ***/
    srand(1); // random seed for different gameplay
    vector<vector<string>> grid =newGrid();
    vector<vector<unsigned>> listOfValuesAndPositions;
    vector<unsigned> valuesToAdd;

    unsigned round = 1;

    //Loop used to play the game
    while (true) {

        //system("clear");
        listOfValuesAndPositions=findNewValues(round);

        for(unsigned i =0; i<listOfValuesAndPositions.size();++i){ //Insert new values in the grid
            valuesToAdd=listOfValuesAndPositions[i];
            grid=changeGrid(grid,valuesToAdd);
        }

        //The player has 5 seconds to memorize the new grid
        printGrid(grid);
        //this_thread::sleep_for(chrono::seconds(5));

        grid =newGrid();
        //system("clear");

        /***
         * Ask the player to return the position of the differents values displayed
         * If the player is correct the game goes on, gaining a point for each round succeded
         * Else the game stops, exit the loop, and return the score
        ***/
        if(playerInputMaster(listOfValuesAndPositions, round)){
            round+=1;
            cout<<"\033[1;32m"<<"Congratulations vous avez les bonnes valeurs, vous pouvez passer a la suite.."<<"\033[0m"<<endl;
            global_files::ofs<<"\033[1;32m"<<"Congratulations vous avez les bonnes valeurs, vous pouvez passer a la suite.."<<"\033[0m"<<endl;
            //this_thread::sleep_for(chrono::seconds(2));
            continue;
        }
        else{
            break;
        }

    }

    cout<<endl;
    global_files::ofs<<endl;
    cout<<"\033[1;37m"<<"Votre score est de "<<round - 1<<" points"<<"\033[0m"<<endl;
    global_files::ofs<<"\033[1;37m"<<"Votre score est de "<<round - 1<<" points"<<"\033[0m"<<endl;
    cout<<endl;
    global_files::ofs<<endl;
    //this_thread::sleep_for(chrono::seconds(5));
    return round - 1; //The score is the number of rounds succeded

}

int memory()
{

    /***
     * Display Rules
    ***/

    cout<<"\033[1;37m"<<"Bienvenu sur le jeu du Memory."<<"\033[0m"<<endl
        <<endl
        <<"Les regles sont simples : "<<endl
        <<" - Pendant 5 secondes une grille affichant des nombres va apparaitre, et votre objectif est de retenir leur position, dans l'ordre indique"<<endl
        <<" - Ensuite vous allez devoir rentrer le nombre de la ligne, et colonne de chaque valeur, comme il vous sera indique à l'ecran"<<endl
        <<" - Si vous avez reussi a retenir la position de chaque valeur dans l'ordre vous allez passer a la prochaine grille, qui aura une valeur a retenir en plus de la precedente, et aisni suite"<<endl
        <<" - Le jeu s'arrete quand vous entrez les mauvaises coordonnees d'une valeur, et vos points vont etre calcules en fonction du nombre de manches passees"<<endl
        <<" - Vous allez jouer par tour, chacun va faire une partie, et celui qui arrive a avoir le meilleur score gagne, les roles s'inversent lors de la mort du premier joueur"<<endl
        <<endl
        <<"\033[1;37m"<<"Une fois que vous avez pris conscience des regles du jeu veuillez appuyer sur entree pour commencer"<<"\033[0m"<<endl;
    global_files::ofs<<"\033[1;37m"<<"Bienvenu sur le jeu du Memory."<<"\033[0m"<<endl
                    <<endl
                    <<"Les regles sont simples : "<<endl
                    <<" - Pendant 5 secondes une grille affichant des nombres va apparaitre, et votre objectif est de retenir leur position, dans l'ordre indique"<<endl
                    <<" - Ensuite vous allez devoir rentrer le nombre de la ligne, et colonne de chaque valeur, comme il vous sera indique à l'ecran"<<endl
                    <<" - Si vous avez reussi a retenir la position de chaque valeur dans l'ordre vous allez passer a la prochaine grille, qui aura une valeur a retenir en plus de la precedente, et aisni suite"<<endl
                    <<" - Le jeu s'arrete quand vous entrez les mauvaises coordonnees d'une valeur, et vos points vont etre calcules en fonction du nombre de manches passees"<<endl
                    <<" - Vous allez jouer par tour, chacun va faire une partie, et celui qui arrive a avoir le meilleur score gagne, les roles s'inversent lors de la mort du premier joueur"<<endl
                    <<endl
                    <<"\033[1;37m"<<"Une fois que vous avez pris conscience des regles du jeu veuillez appuyer sur entree pour commencer"<<"\033[0m"<<endl;
    //cin.ignore();
    //system("clear");

    //Game starts for the first player
    int playerOneScore = memoryGame();

    //system("clear");
    cout<<"Le deuxieme joueur vas bientot jouer"<<endl;
    global_files::ofs<<"Le deuxieme joueur vas bientot jouer"<<endl;
    //this_thread::sleep_for(chrono::seconds(10));

    //Game starts for the second player
    int playerTwoScore = memoryGame();

    //this_thread::sleep_for(chrono::seconds(3));
    //system("clear");

    if(playerOneScore == playerTwoScore){
        cout<<"Le match est nul, car vous avez fait le meme score, veuillez rejouer"<<endl;
        global_files::ofs<<"Le match est nul, car vous avez fait le meme score, veuillez rejouer"<<endl;
        return 2;
    }
    else if(playerOneScore>playerTwoScore){
        cout<<"Le premier joueur remporte la partie, bravo"<<endl;
        global_files::ofs<<"Le premier joueur remporte la partie, bravo"<<endl;
        return 0;
    }
    else{
        cout<<"Le deuxieme joueur remporte la partie, bravo"<<endl;
        global_files::ofs<<"Le deuxieme joueur remporte la partie, bravo"<<endl;
        return 1;
    }
}
