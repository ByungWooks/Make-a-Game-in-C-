#include<iostream>  // Preprocessor Directive
#include<ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are secret agent breaking into a " << Difficulty ; // Expression Statements
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty,int MaxDifficulty)
{

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty; // Declaration Statements
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ here are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The coudes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player 
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if(Difficulty == MaxDifficulty)
        {
            return true;
        }
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***\n\n";
        return false;
    }

}

int main() // Main Function
{ 
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 2;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discords the buffer

        if (bLevelComplete)
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }
        
    }
    std:: cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}