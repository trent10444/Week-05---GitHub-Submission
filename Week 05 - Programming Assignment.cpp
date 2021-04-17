#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

void ShowUsage() { //Shows how to use the program when called
    cout << "************************************************************" << endl;
    cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << "************************************************************" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display tolal amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
    cout << "" << endl;
    cout << "Please enter selection :";
    

}
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) { //Makes a purchase when called
    int amount = 0;
    char size = ' ';
    cout << "Please enter the quanity and type (X=xxxl, S=small, M=medium, L=large) of surfboard you would like to purchase:";
    cin >> amount;//Input for amount of boards
    cin >> size;// Input for size of boards
    if (size == 's' || size == 'S') {
        iTotalSmall = amount;
    }
    else if(size == 'm' || size == 'M') {
        iTotalMedium = amount;
    }
    else if (size == 'l' || size == 'L') {
        iTotalLarge = amount;
    }
    else if (size == 'x' || size == 'X') {
        iTotalXXXS = amount;
    }
    cout << "" << endl;
}
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {// Displays the amount of surfboards being purchased
    if (iTotalSmall > 0) {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    if (iTotalXXXS > 0) {
        cout << "The total number of xxxl surfboards is " << iTotalXXXS << endl;
    }
    cout << "" << endl;

}
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) { // Displays the total amount of surfboards, the total price for each size, and the sum total
    
    double dueSmall = iTotalSmall * 175.00;//Amount due for small surfboards
    double dueMedium = iTotalMedium * 190.00;//Amount due for medium surfboards
    double dueLarge = iTotalLarge * 200.00;//Amount due for large surfboards
    double dueXXXS = iTotalXXXS * 50.00;//Amount due for xxxl surfboards for squirrel surfing
    double Total = dueSmall + dueMedium + dueLarge + dueXXXS;//Sum Total for all surfboards

    if (iTotalSmall > 0) {//If there is a surfboard being purchased, output will show total amount and for the price of each size.
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << dueSmall << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << dueMedium <<endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << dueLarge << endl;
    }
    if (iTotalXXXS > 0) {
        cout << "The total number of xxxl surfboards is " << iTotalXXXS << " at a total of $" << dueXXXS << endl;
    }
    cout << "Amount due: $" << Total << endl;// Shows the sum total
    cout << "" << endl;
}



int main()
{
    char Input; //this is the users input
    int iTotalSmall = 0;// = 0 because i didnt want to do a bunch of if statements to get Total
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int iTotalXXXS = 0;
    int c = 0;// Variable for the loop
    ShowUsage();//Automatically shows the directions
    
    while (c < 20)//Just incase problems occur, if the while loop gets to 20 it will end.
    {
        cin >> Input;// Gets the users input
        switch (Input)// Checks users input
        {
        case'S': // if input is = s it will clear and then show the directions for the program again
        case's':
            system("cls");
            ShowUsage();
            break;
        case'P':// if the input = p it will allow the user to purchase a surfboard
        case'p':
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
            cout << "Please enter selection :";
            break;
        case'C':// if the input = c it will display the total amount of surfboards being purchased
        case'c':
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
            cout << "Please enter selection :";
            break;
        case'T': // if the input = t it will display the total amount of surfboards and amount for each size and the sum total
        case't':
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
            cout << "Please enter selection :";
            break;
        case'Q': // if the input = q it will say thank you and end
        case'q':
            cout << "Thank You" << endl;
            return -1;
            break; 
        default: // if the user's input is not equal to above it will ask them to re-enter their selection
            cout << "Please enter selection :";
        }
        c++;
    }
    return 0;
}


