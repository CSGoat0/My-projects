//Program: tic tac toe game, player 1 can add odd numbers, player two can add even numbers (include 0), the player who complete 15 in a raw, colomn or diagonal wins.
//Author: Abdelrahman Nabil Hassan
//ID: 20230219
//version: My first version, with c++
//Date: 29 / 2 / 2023

#include<iostream>
#include <vector>
using namespace std;

// function that display whatever board i need
static void board_dis(int board[3][3])
{
    int length = 3;
    for (int i = 0; i < 3; i++)
    {

        //to move the board to right
        cout << "                                                    ";

        for (int j = 0; j < 3; j++)
        {
            cout << "   ";
            cout << board[i][j];
            if (j < length - 1)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < length - 1)
        {
            //to move boarder to right
            cout << "                                                       ___________" << endl;
        }
    }
}

//function that detect that the game is finished in draw so, i can end it
bool finish_counter(int counter)
{
    if (counter >= 9)
    {
        return true;
    }
    return false;
}

//function that detect that there is a winner so, i can end the game
bool finish_15(int board[3][3])
{
    if (board[0][0] + board[0][1] + board[0][2] == 15)
    {
        return true;
    }
    else if (board[1][0] + board[1][1] + board[1][2] == 15)
    {
        return true;
    }
    else if (board[2][0] + board[2][1] + board[2][2] == 15)
    {
        return true;
    }
    else if (board[0][0] + board[1][0] + board[2][0] == 15)
    {
        return true;
    }
    else if (board[0][1] + board[1][1] + board[2][1] == 15)
    {
        return true;
    }
    else if (board[0][2] + board[1][2] + board[2][2] == 15)
    {
        return true;
    }
    else if (board[0][0] + board[1][1] + board[2][2] == 15)
    {
        return true;
    }
    else if (board[0][2] + board[1][1] + board[2][0] == 15)
    {
        return true;
    }
    return false;
}

//function to prevent taking the same index twice
bool index_repeat_denier(int I, vector <int> indices)
{
    int length = size(indices);
    for (int i = 0; i < length; i++)
    {
        if (I == indices[i])
        {
            return false;
        }
    }
    return true;
}

//function to prevent taking the same input twice in different turns
bool input_repeat_denier(int N, vector <int> numes)
{
    int length = size(numes);
    for (int i = 0; i < length; i++)
    {
        if (N == numes[i])
        {
            return false;
        }
    }
    return true;
}

//function that detect invalid input from player_1
bool player1_validation(int N1)
{
    if ((N1 != 1) && (N1 != 3) && (N1 != 5) && (N1 != 7) && (N1 != 9))
    {
        return false;
    }
    return true;
}

//function that detect invalid input from player_2
bool player2_validation(int N2)
{
    if ((N2 != 2) && (N2 != 4) && (N2 != 6) && (N2 != 8) && (N2 != 0))
    {
        return false;
    }
    return true;
}

//function to put the user input in the board
bool elem_changer(int index, int elem, int board[3][3])
{
    if (index == 0)
    {
        board[0][0] = elem;
    }
    else if (index == 1)
    {
        board[0][1] = elem;
    }
    else if (index == 2)
    {
        board[0][2] = elem;
    }
    else if (index == 3)
    {
        board[1][0] = elem;
    }
    else if (index == 4)
    {
        board[1][1] = elem;
    }
    else if (index == 5)
    {
        board[1][2] = elem;
    }
    else if (index == 6)
    {
        board[2][0] = elem;
    }
    else if (index == 7)
    {
        board[2][1] = elem;
    }
    else if (index == 8)
    {
        board[2][2] = elem;
    }
    else
    {
        return false;
    }
    return true;
}

int main()
{
    // indices is to save every valid index to be sure not using it again
    //numes is to save every valid input numper to make sure not using it again
    vector <int> indices;
    vector <int> numes;

    cout << "Welcome to Tic_Tac_Toe game!\n";

    //main game board
    int board[3][3] =
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    //index board
    int index_board[3][3] =
    {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };

    //draw detector
    int counter = 0;
    while (counter < 9)
    {
        //N1 is the choosen numper
        //I1 is the index
        int I1, N1;
        cout << "Player_1's Turn\n";
        cout << "Please, enter a valid number\n";
        cin >> N1;

        //to display index board
        board_dis(index_board);
        cout << "Please, choose your index\n";
        cin >> I1;

        //to try again in case of invalid input with this cases
        if ((input_repeat_denier(N1, numes) == false) || (index_repeat_denier(I1, indices) == false) || (player1_validation(N1) == false))
        {
            cout << "Invalid Input, please try again\n";
            continue;
        }

        //to try again in case of invalid input to avoid placing the invalid input in the board, so it has been handeled in another if condition
        if (elem_changer(I1, N1, board) == false)
        {
            cout << "Invalid Input, please try again\n";
            continue;
        }

        //to save the valid inputs and indices to avoid using it again
        indices.push_back(I1);
        numes.push_back(N1);

        //to put the inputs in the board
        elem_changer(I1, N1, board);

        //if the game is ended, finish excuting
        if (finish_15(board) == true)
        {
            cout << "Player 1 wins, congrates!\n";
            return 0;
        }

        //to detect that a new turn is played
        counter++;

        //if the game is ended, finish excuting
        if (finish_counter(counter) == true)
        {
            cout << "Draw";
            return 0;
        }

        //to display the main game progress board
        board_dis(board);

        cout << "Player_2's Turn\n";
        int I2, N2;
        cout << "Please, enter a valid number\n";
        cin >> N2;

        //to display the index board
        board_dis(index_board);

        cout << "Please, choose your index\n";
        cin >> I2;
        while ((input_repeat_denier(N2, numes) == false) || (index_repeat_denier(I2, indices) == false) || (player2_validation(N2) == false))
        {
            cout << "Invalid input, please try again\n";
            cout << "Please, enter a valid number\n";
            cin >> N2;
            board_dis(index_board);
            cout << "Please, choose your index\n";
            cin >> I2;
        }
        while (elem_changer(I2, N2, board) == false)
        {
            cout << "Invalid Input, please try again\n";
            cout << "Please, enter a valid number\n";
            cin >> N2;
            board_dis(index_board);
            cout << "Please, choose your index\n";
            cin >> I2;
        }
        board_dis(board);
        indices.push_back(I2);
        numes.push_back(N2);
        elem_changer(I2, N2, board);
        if (finish_15(board) == true)
        {
            cout << "Player 2 wins, congrates!\n";
            return 0;
        }
        counter++;
        if (finish_counter(counter) == true)
        {
            cout << "Draw\n";
            return 0;
        }
    }
}