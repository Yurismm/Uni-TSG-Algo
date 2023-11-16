// TSG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <string_view>
#include <algorithm>

#define DEBUG_MODE
// FOR MY OWN USE

using namespace std;

// function decl
int BinarySearchArr(string GameNames[], int count, string search); // binary search
void SortStrings(string GameNames[]); // bubble sort 


int BinarySearchArr(string GameNames[], int count, string search) {
	int i = -1;	// look at index from 1 - 16
	int min = 0;
	int max = count - 1; // if the count was 17 for example the highest i (index) would be 16
	int indexpoint;
	// decide which index to look at 
	while (min <= max) 
	{
		indexpoint = (min + max) / 2;
		// it will give an int response
		if (search.compare(GameNames[indexpoint]) < 0) {
			// if it is negative, the portion of the word is before the halfpoint (index point)
			// remove the end of the array (ignore)
			max = indexpoint - 1;
		}
		else if (search.compare(GameNames[indexpoint]) > 0) {
			// if it is positive it will be everything after the halfpoint
			min = indexpoint + 1;
		}
		else {
			// if it is 0 then it means it is the same word that is found
			i = indexpoint;
			min = max + 1;
		}
	}
	return i;
}

void SortStrings(string GameNames[]) {
	// bubble sort

	GameNames[17];
	string t;

	for (int i = 0; i < 17; i++) {

		// we nest the for loop to compare each string to each other and traverse between them
		for (int k = i + 1; k < 17; k++) {
			// comparing the indexes in the array to each other
			if (GameNames[i] > GameNames[k]) {

				t = GameNames[i];
				GameNames[i] = GameNames[k];
				// swapping if the string is higher (in int) than the other
#if defined(DEBUG_MODE)

				// debug for myself
				cout << "Swapping (Debug) " << GameNames[i] << " With string: " << t << endl;

#endif
				GameNames[k] = t; // replacing in the array

			}

		}

	}

#if defined(DEBUG_MODE)

	cout << "In order test (of string array, bubble sort, debug);" << endl;
    for (int i = 0; i < 17; i++) {
        // we nest the for loop to compare each string to each other and traverse between them
        for (int k = i + 1; k < 17; k++) {        
            if (GameNames[i] > GameNames[k]) {       
                t = GameNames[i];
                GameNames[i] = GameNames[k];
                cout << "Swapping (Debug) " << GameNames[i] << " (With string: " << t << ")" << endl;
#endif
                GameNames[k] = t;
            }    
        }        
    }
    cout << "In order test (of string array, bubble sort);" << endl;
	for (int i = 0; i < 17; i++) {
		cout << GameNames[i] << endl;
	}
}

int main()
{
	// somewhat unordered array so that we can bind the arrays together below, sorted later on, no worries
	// array of the game sales

	int GameSales[17] = 
	{ 0,
	238000000,
	100000000,
	160000000,
	75000000,
	82900000,
	58000000,
	51000000,
	47520000,
	43800000,
	43000000,
	43071632,
	37620000,
	37380000,
	35000000,
	33140000 };

	// array of strings of the game names
	// the sort needs to be alphabetically
	string GameNames[17] = 
	{ "None", 
	"Minecraft", 
	"TetrisEA", 
	"GrandTheftAuto", 
	"PUBG", 
	"Wii_sports",
	"SuperMarioBros", 
	"Pokemon",
	"WiiFit", 
	"RedDeadRedemption",
	"TetrisWii", 
	"PacMan",
	"AnimalCrossing",
	"MarioKartWii",
	"Terraria",
	"WiiSportsResort" };

	// "none" input for 0 array so that we have no issues later down the line with the 0 index
	// using this count to help specifically find the string when the user inputs the string
	// comes in within the binary sort
	int count = 17;
	// rankings stored here
	int GameRanking[17] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 };
	// sorting strings before i pair the arrays
	SortStrings(GameNames);
    // creating the pairs from the arrays below of the names of the games and the sales of the games
    pair<int, string> Games[17];
    // pairing the sales with the game names together / taking the array from the main function to add to the actual pair array
	for (int i = 0; i < 16; i++) {
		for (int i = 0; i < 16; i++) 
		{
			Games[i].first = GameSales[i];
			Games[i].second = GameNames[i];
		}
		for (int i = 0; i < 16; i++) 
		{
			GameSales[i] = Games[i].first;
			GameNames[i] = Games[i].second;
		}
		cout << "Array before" << "   " << endl;
		for (int i = 16 - 1; i >= 0; i--) 
		{
			cout << GameSales[i] << "   " << GameNames[i] << "   " << endl;
		}
		pair <int, string> GameRanks[17];
		// showing the array before the sort
		cout << "Array before" << "   " << endl;
		for (int i = 16 - 1; i >= 0; i--) 
		{
			cout << GameSales[i] << "   " << GameNames[i] << "   " << endl;
		}
		for (int i = 0; i < 16; i++) 
		{
			GameRanks[i].first = GameRanking[i];
			GameRanks[i].second = GameNames[i];
		}

		// SUCCESSFUL TEST WITH PAIR
		// BCOS it's now sorted, we can also make sure that the normal sales are sorted using the simple sort above, embedded within c++
		// and now it is easier to search that array as the strings need to first be sorted
		// before i add bind both the sales and ranking
		// (Names first must be sorted as traversing and searching strings must be alphabetical before I can
		// return the position of array it is in)
		// then we can sort the numbers
		cout << "Array after sort" << "   " << endl;
		for (int i = 16 - 1; i >= 0; i--) {
			cout << GameSales[i] << "   " << GameNames[i] << "   " << endl;
		}
		bool GameFound = false;
		// resorting the names (even though done earlier, I have to do it again here so that if the sort earlier had altered the positioning
		// it will still be name first
		SortStrings(GameNames);
		while (GameFound = true) {
			// User input
			string input;
			// asking for input
			cout << "Please input the game you'd like the sales for" << endl;
			cin >> input;
			// while loop so we can call back if the search is incorrect
			// calling the binary search of the array and bringing
			// back the value to check if it is negative or not
			if (BinarySearchArr(GameNames, count, input) == -1) {
				GameFound = false;
				cout << "You must input the name directly, exact to the case (case sensitive), or you have not entered a game that exists within this list." << endl;
			}
			// if it is negative it will return that it is not in the list (as it would not be)
			// this was a constant error I would get if my list was unsorted or I inputted a
			// incorrect string
			else {
				// debug mode check for own use
				SortStrings(GameNames);
				if (BinarySearchArr(GameNames, count, input) == -1) {
					cout << "You must input the name directly, exact to the case (case sensitive), or you have not entered a game that exists within this list." << endl;
				}
				else {
#if defined(DEBUG_MODE)
					cout << "Debug - Position of input in array is: " << BinarySearchArr(GameNames, count, input) << endl;
#endif
					cout << "The sales of: " << input << " is: " << endl;
					// calling the function again as it returns as an int, so I can call the int within the array
					// returned from the binary search. 
					cout << GameSales[BinarySearchArr(GameNames, count, input)] << " in respective currency " << endl;
					cout << "Sales ranking at: " << GameRanking[BinarySearchArr(GameNames, count, input)] << endl;
					GameFound = true;

				}


			}
		}
	}

}


