// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    // Welcomeing The Player
    PrintLine(TEXT("Welcome to Bull Cows!")); // TEXT marco encodes it on various platforms
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number Remove!
    PrintLine(TEXT("Press enter to continue..."));
    
    // Setting Up Game
    HiddenWord = TEXT("cake"); // Set the HiddnWord
    // Set Lives
    
    // Prompt Player For Guess
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    // Checking PlayerGuess

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You have Won!"));
    }
    else
    {
        PrintLine(TEXT("You have Lost!"));
        
    }
    // Check If Isogram
    // Prompt To Guess Again
    // Check Right Numbers Of Characters
    // Prompt To Guess Again

    // Remove Life
    
    // Chcek If Lives > 0
    // If Yes GuessAgain
    // Show Lives Left
    // If No Show GameOver and HiddenWord?
    // Prompt To Play Again, Press Enter To Play Again?
    // Check User Input
    // PlayAgain Or Quit
    
}
	
