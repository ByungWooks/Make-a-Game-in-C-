#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>

// Output HangMan Sequentially
void HangManFunc(int HangMan)
{
    switch (HangMan)
    {
    case 1: 
        std::cout << "           -------------            \n";
        std::cout << "          /             \\           \n"; 
        std::cout << "         |               |          \n";
        std::cout << "         |               |          \n";
        std::cout << "          \\             /           \n";
        std::cout << "           -------------            \n";   
        break;
    case 2:
        std::cout << "           -------------            \n";
        std::cout << "          /             \\           \n"; 
        std::cout << "         |               |          \n";
        std::cout << "         |               |          \n";
        std::cout << "          \\             /           \n";
        std::cout << "           -------------            \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        break;
    case 3:
        std::cout << "           -------------            \n";
        std::cout << "          /             \\           \n"; 
        std::cout << "         |               |          \n";
        std::cout << "         |               |          \n";
        std::cout << "          \\             /           \n";
        std::cout << "           -------------            \n"; 
        std::cout << "       \\\\        |        //        \n"; 
        std::cout << "         \\\\      |      //          \n"; 
        std::cout << "           \\\\    |    //            \n"; 
        std::cout << "             \\\\  |  //              \n"; 
        std::cout << "               \\\\|//                \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        break;
    case 4:
        std::cout << "           -------------            \n";
        std::cout << "          /             \\           \n"; 
        std::cout << "         |               |          \n";
        std::cout << "         |               |          \n";
        std::cout << "          \\             /           \n";
        std::cout << "           -------------            \n"; 
        std::cout << "       \\\\        |        //        \n"; 
        std::cout << "         \\\\      |      //          \n"; 
        std::cout << "           \\\\    |    //            \n"; 
        std::cout << "             \\\\  |  //              \n"; 
        std::cout << "               \\\\|//                \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "                 |                  \n"; 
        std::cout << "               // \\\\                \n"; 
        std::cout << "             //     \\\\              \n"; 
        std::cout << "           //         \\\\            \n"; 
        std::cout << "         //             \\\\          \n"; 
        std::cout << "       //                 \\\\        \n"; 
        break;
    case 5:
        std::cout << "You died!!";
        break;
    }
}

// FileStream & One of the randomly word in read file Fucntion
std::string FileStream()
{
    std::ifstream file("English_Words.txt"); // read file
    std::string str; // One of the word in read file 

    srand(time(NULL)); // Use actual time at random
    int RandomNumber = rand() % 26;
    int count = 0;  

    std::string FindWord = "";

    // This is the process. FindWord = file[RandomNumber](= str)
    while(getline(file, str,','))
    {
        if(count == RandomNumber)
        {
            FindWord = str;
        }
        count++;
    }
    std::cout << FindWord << std::endl; // Output FindWord!! This sentence must remove!!!
    return FindWord;
}

int main()
{  
    std::string FindWord;
    FindWord=FileStream();

    int AnswerLength = FindWord.length();
    char AnswerChar[AnswerLength];
    char InputChar = 'a'; // initialize
    int HangMan = 0;

    // Make the word lowercase
    for(int i=0;i<AnswerLength;i++)
    {
        FindWord[i] = tolower(FindWord[i]);
    } 


    for(int i=0;i<AnswerLength;i++) // Answer initialize
    { 
        AnswerChar[i] = '_';
    }

    std::cout << "Let's find the word\n";
    std::cout << "The length of the word is " << AnswerLength << std::endl;
    
    while(HangMan < 5)
    {
        std::cout << "Please enter the Alphabet : ";
        std::cin >> InputChar;

        // Make the Alphabet lowercase
        InputChar = tolower(InputChar);

        int count = 0;

        for(int i=0;i<AnswerLength;i++)
        {
            if(FindWord[i]==InputChar)
            {
                AnswerChar[i] = InputChar;
                count++;
            }
        }
        if(count == 0)
        {
            HangMan++;
            HangManFunc(HangMan);
        }else
        {
            for(int i=0;i<AnswerLength;i++)
            {
                std::cout << AnswerChar[i];
            }
            std::cout << std::endl;
        }
        if(std::string(AnswerChar) == FindWord)
        {
            std::cout << "You are winner!!\n";
            std::cout << "The answer is " << FindWord << " !!\n";
            break;
        }
        
    }
    return 0;

}