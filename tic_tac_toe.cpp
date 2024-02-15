#include <iostream>
using namespace std;

void drawBoard(char mat[3][3]){                   //For drawing the board
    cout << "Board :" << endl;
    cout << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------";
        cout << endl;
    }
}

bool winner(char mat[3][3], char win)            //Checking the winner
{
    for (int i = 0; i < 3; i++)
    {
        if ((mat[0][i] == win) && (mat[1][i] == win) && (mat[2][i] == win))    //Checking Columns
            return true;

        if ((mat[i][0] == win) && (mat[i][1] == win) && (mat[i][2] == win))    //Checking Rows
            return true;
    }
    if ((mat[0][0] == win) && (mat[1][1] == win) && (mat[2][2] == win))     //Checking the diagonals
            return true;
    if ((mat[0][2] == win) && (mat[1][1] == win) && (mat[2][0] == win))
            return true;
    return false;
}

int main()
{
    char mat[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};   //Intializing the board
    char curr_player = 'O';
    char win;


    cout << endl;
    cout<<"\t\t\t\t\t\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\t| ";
    cout << "Welcome to Tic-Tac-Toe World |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t--------------------------------\n"<<endl;

    //The empty board
    drawBoard(mat); 



    for (int i = 0; i < 9; i++)
    {
        cout << endl;
        cout << curr_player << "'s turn:" << endl;
        cout << "-----------------------------------" << endl;
        int r, c;
        cout << "Enter the row no (1~3):";
        cin >> r;
        cout << endl;
        cout << "Enter the col no (1~3):";
        cin >> c;
        cout << endl;
        r--;
        c--;

        if ((mat[r][c] == ' ') && (r < 3 && c < 3) && (r >= 0 && c >= 0))
        {
            mat[r][c] = curr_player;
            win = curr_player;

            if (curr_player == 'O')       //Checking for the player's turns
                curr_player = 'X';
            else
                curr_player = 'O';
        }
        else
        {
            cout<<endl;
            cout << "Invalid Input!!!! Please try again......\n"<<endl; //Checking whether the input is valid or not...
        }

        drawBoard(mat);

        if (winner(mat, win))           //Checking the winner
        {
            cout<<endl;
            cout << win << " has won...\n"<<endl;
            break;
        }

        if (i == 8 && !winner(mat, win)) //Check for the draw
        {
            cout<<endl;
            cout << "Draw!!!!!\n" << endl;
        }
    }
    return 0;
}
