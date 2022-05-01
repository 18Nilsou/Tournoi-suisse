/**
 *
 * @file    connectFour.cpp
 *
 * @author  Melon - Valls Marion - Ceccarelli Luca - Capelier Mathieu - Hugues Mélanie - Saadi Nils - Vollaire Mathis
 *
 * @date    28/11/2021
 *
 * @brief   This game is a connect 4.
 *          Two players share the same grid and the first one to align 4 of his symbols wins.
 *
 **/
#include <iostream> //for output (on screen) and input (by keyboard)
#include <vector>   //allows to create dynamic 2d arrays
#include <limits>   //allows to cancel a wrong input
#include <stdlib.h> //allows to use the abs() fonction
#include <fstream>
#include "input.h"

//Connect 4
using namespace std;

void gameRules()
{
    cout<<"Regles du jeu:\nVous allez vous affronter dans un puissance 4.\n"
        <<"Le but de ce jeu est d'aligner 4 pions (des X ou des O).\n"
        <<"Vous pouvez les aligner en ligne, colone ou diagonale.\n"
        <<"Le premier a aligner 4 pions gagne.\n"
        <<"Bonne chance ! \n";
    global_files::ofs<<"Regles du jeu:\nVous allez vous affronter dans un puissance 4.\n"
                    <<"Le but de ce jeu est d'aligner 4 pions (des X ou des O).\n"
                    <<"Vous pouvez les aligner en ligne, colone ou diagonale.\n"
                    <<"Le premier a aligner 4 pions gagne.\n"
                    <<"Bonne chance ! \n";
    //cin.ignore();
    //system("clear");
}
//function to initialize the grid at the beginning of the game
vector<vector<char>> initGrid(vector<vector<char>> & grid, unsigned & rowGrid, unsigned & columnGrid)
{
    //initializing the row
    vector<char> row;
    for (unsigned i = 0; i < columnGrid; ++i)
    {
        row.push_back('-');
    }
    //adding the row inside another vector to get a 2d vector
    for(unsigned i=0; i< rowGrid;++i)
    {
        grid.push_back(row);
    }
    return grid;
}
//function to print the grid
void printGrid(vector<vector<char>> & grid, unsigned & rowGrid, unsigned & columnGrid)
{
    //browse the array
    for(unsigned i=0; i<rowGrid;++i){
        for(unsigned j=0; j<columnGrid;++j){
            cout<<"|"<<grid[i][j];
            global_files::ofs<<"|"<<grid[i][j];
        }
        cout<<"|"<<endl;//at the end of each row, it goes to the next line
        global_files::ofs<<"|"<<endl;
    }
}

unsigned enterColumn(unsigned & columnGrid)
{
    //player enter column number
    int column;
    cout<<"Quelle colonne? Entrez un nombre entre 0 et "<<(columnGrid-1)<<".";
    global_files::ofs<<"Quelle colonne? Entrez un nombre entre 0 et "<<(columnGrid-1)<<".";

    //cin>>column;
    column =stoi( global_func::ask4UInput(""));
    //takes the absolute value if the player gives a negative number
    //column = abs(column);
    //if the player gives a letter instead of a number we asks to give a number again
//    if(cin.fail())
//    {
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(),'\n');
//        column = enterColumn(columnGrid);
//    }
    return column;
}

//check if one of the player won and print it
unsigned win(vector<vector<char>> & grid, unsigned & rowGrid, unsigned & columnGrid, string & teamOne, string & teamTwo)
{
    //check if there is four succesive signs on a row
    for(unsigned i = 0; i <rowGrid; ++i)
    {
        for(unsigned j = 0; j <(columnGrid-3); ++j)
        {
            if((grid[i][j]=='X')&&(grid[i][j+1]=='X')&&(grid[i][j+2]=='X')&&(grid[i][j+3]=='X'))
            {
                cout<<"Le gagnant est "<<teamOne<<endl;
                global_files::ofs<<"Le gagnant est"<<teamOne<<endl;
                return true;
            }
            else if((grid[i][j]=='O')&&(grid[i][j+1]=='O')&&(grid[i][j+2]=='O')&&(grid[i][j+3]=='O'))
            {
                cout<<"Le gagnant est "<<teamTwo<<endl;
                global_files::ofs<<"Le gagnant est "<<teamTwo<<endl;
                return true;
            }
        }
    }


    //check if there is four succesive signs on a column
    for(unsigned i = 0; i <(rowGrid-3); ++i)
    {
        for(unsigned j = 0; j <columnGrid; ++j)
        {
            if((grid[i][j]=='X')&&(grid[i+1][j]=='X')&&(grid[i+2][j]=='X')&&(grid[i+3][j]=='X'))
            {
                cout<<"Le gagnant est "<<teamOne<<endl;
                global_files::ofs<<"Le gagnant est "<<teamOne<<endl;
                return true;
            }
            else if((grid[i][j]=='O')&&(grid[i+1][j]=='O')&&(grid[i+2][j]=='O')&&(grid[i+3][j]=='O'))
            {
                cout<<"Le gagnant est "<<teamTwo<<endl;
                global_files::ofs<<"Le gagnant est "<<teamTwo<<endl;
                return true;
            }
        }
    }

    //check if there is four succesive signs on a diagonal starting from the left corner on the top and going down
    for(unsigned i = 0; i<(rowGrid-3); ++i)
    {
        for(unsigned j = 0; j < (columnGrid-3); ++j)
        {
            if((grid[i][j]=='X')&&(grid[i+1][j+1]=='X')&&(grid[i+2][j+2]=='X')&&(grid[i+3][j+3]=='X'))
            {
                cout<<"Le gagnant est "<<teamOne<<endl;
                global_files::ofs<<"Le gagnant est "<<teamOne<<endl;
                return true;
            }
            if((grid[i][j]=='O')&&(grid[i+1][j+1]=='O')&&(grid[i+2][j+2]=='O')&&(grid[i+3][j+3]=='O'))
            {
                cout<<"Le gagnant est "<<teamTwo<<endl;
                global_files::ofs<<"Le gagnant est "<<teamTwo<<endl;
                return true;
            }
        }
    }

    //check if there is four succesive signs on a diagonal starting from the left corner on the bottom and going up
    for(unsigned i = 3; i<rowGrid; ++i)
    {
        for(unsigned j = 0; j < (columnGrid-3); ++j)
        {
            if((grid[i][j]=='X')&&(grid[i-1][j+1]=='X')&&(grid[i-2][j+2]=='X')&&(grid[i-3][j+3]=='X'))
            {
                cout<<"Le gagnant est "<<teamOne<<endl;
                global_files::ofs<<"Le gagnant est "<<teamOne<<endl;
                return 0;
            }
            if((grid[i][j]=='O')&&(grid[i-1][j+1]=='O')&&(grid[i-2][j+2]=='O')&&(grid[i-3][j+3]=='O'))
            {
                cout<<"Le gagnant est "<<teamTwo<<endl;
                global_files::ofs<<"Le gagnant est "<<teamTwo<<endl;
                return 1;
            }
        }
    }
    return 3;
}


unsigned runConnectFour(string & teamOne, string & teamTwo)
{
    unsigned winner = 0;
    gameRules();
    vector<vector<char>> grid;
    unsigned rowGrid = 6;                       //number of row of the grid
    unsigned columnGrid = 7;                    //number of column of the grid
    grid=initGrid(grid, rowGrid, columnGrid);
    cout<<teamOne<<" vous commencez"<<endl;
    global_files::ofs<<teamOne<<" vous commencez"<<endl;
    printGrid(grid, rowGrid, columnGrid);       //we print the grid (empty) a first time
    bool flag = true;                           //this booleen check if the grid is full
    int player = -1;                            //alloxs to change the player and so put an 'X' or an 'O'
    unsigned turns = 0;
    //this variable stores the number of time each player has played.
    //As long as it is under 6, it is impossible that one of the player wins, so we don't check if there is a victory
    while(flag)//flag will be false if the grid is full
    {
        unsigned column;
        column = enterColumn(columnGrid);       //asks to the player to chose a column
        //fill the grid
        if(grid[0][column]=='-')                //check if the column isn't full before filling it
        {
            //search for the first index not already filled starting by the bottom
            for(unsigned i = (rowGrid-1); i>=0; --i)
            {
                if(grid[i][column] == '-')
                {
                    //according to the value of player, we put an 'X' or a 'O'
                    if(player<0)
                    {
                        grid[i][column]='X';
                        cout<<teamTwo<<" a vous de jouer"<<endl;
                        global_files::ofs<<teamTwo<<" a vous de jouer"<<endl;
                    }
                    else
                    {
                        grid[i][column]='O';
                        cout<<teamOne<<" a vous de jouer"<<endl;
                        global_files::ofs<<teamOne<<" a vous de jouer"<<endl;
                    }
                    break;
                }
            }
            //check if the grid is full, to do so it checks if the top of each column filled (if there is no '-')
            flag = (grid[0][0]=='-');
            for(unsigned k = 1; k<(columnGrid-1); ++k)
            {
                flag = flag || (grid[0][k]=='-');
            }

            player = player * -1;               //if player = -1 it will become 1 and if player = 1, it will become -1

            printGrid(grid, rowGrid, columnGrid);//print the grid once it is filled

            ++turns;
            if((turns > 6)&&(win(grid, rowGrid, columnGrid,teamOne,teamTwo) !=3))
            {
                //we quit the while because one of the player won
                winner = win(grid, rowGrid, columnGrid,teamOne,teamTwo);
                break;
            }
        }
        //if the column is full or if the number given is too big
        else
        {
            cout<<"Saisie incorrecte. ";
            global_files::ofs<<"Saisie incorrecte. ";
        }
    }
    if(!flag)                                   //if the grid is full, we restart a new game
    {
        runConnectFour(teamOne,teamTwo);
    }
    return winner;
}


unsigned connectFour()
{
    string teamOne = "Team One";
    string teamTwo = "Team Two";
    return runConnectFour(teamOne, teamTwo);
}
