#include <iostream>
#include <stdlib.h> 

using namespace std;

int PreGame();
void PrintIntroduction(int LanguageSelected, int Difficulty);
bool PlayGame(int LanguageSelected, int Difficulty);
bool TryAgain(int LanguageSelected);
void Credits(bool bGameComplete, int LanguageSelected);
int CodeSum(int CodeA, int CodeB, int CodeC);
int CodeProduct(int CodeA, int CodeB, int CodeC);

int main(){
    int LanguageSelected = PreGame();
    int Difficulty = 1;
    bool bGameContinue = true;

    while (bGameContinue && Difficulty <= 5)
    {
        system("CLS");
        bool bLevelCompleted = PlayGame(LanguageSelected, Difficulty);
        cin.clear();
        cin.ignore();
        if(bLevelCompleted) Difficulty++;
        else{
            bool bTryAgain = TryAgain(LanguageSelected);
            if(bTryAgain)Difficulty = 1;
            else bGameContinue = false;
        }
    }
    
    Credits(Difficulty > 5, LanguageSelected);
    system("PAUSE");
    return 0;
}

int PreGame(){
    cout << "Select Language \n";
    cout << "1. English\n";
    cout << "2. Portuguese\n";
    int LanguageSelected = 0;
    do
    {
        cout << "Your Selection: ";
        cin >> LanguageSelected;
        switch (LanguageSelected)
        {
        case 1:
            cout << "\nEnglish Selected!\n";
            break;
        case 2:
            cout << "\nPortugues Selecionado!\n";
            break;
        }
    } while (LanguageSelected == 0);
    return LanguageSelected;
}

void PrintIntroduction(int LanguageSelected, int Difficulty){
    switch (LanguageSelected)
    {
    case 1:
        cout << "\n\nYou are a secret agent breaking a Level " << Difficulty << " secure service room...\n";
        cout << "Enter the correct code to continue...\n\n";
        break;
    case 2:
        cout << "\n\nVoce eh um agente secreto que precisa descobrir a senha do nivel " << Difficulty << " para entrar na sala de servico secreto...\n";
        cout << "Introduza o codigo correto para continuar...\n\n";
        break;
    }
}

bool PlayGame(int LanguageSelected, int Difficulty){
    PrintIntroduction(LanguageSelected, Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;


    switch (LanguageSelected)
    {
    case 1:
        cout << "+ There are 3 numbers in the code";
        cout << "\n+ The codes add-up to: " << CodeSum(CodeA, CodeB, CodeC);
        cout << "\n+ The codes multiply to give: " << CodeProduct(CodeA, CodeB, CodeC) << endl;
        break;
    case 2:
        cout << "+ Existem 3 numeros no codigo";
        cout << "\n+ Os codigos somados resulta em: " << CodeSum(CodeA, CodeB, CodeC);
        cout << "\n+ Os codigos multiplicados resulta em: " << CodeProduct(CodeA, CodeB, CodeC) << endl;
        break;
    }

    int GuessA, GuessB, GuessC;

    cin >> GuessA >> GuessB >> GuessC;
    
    switch (LanguageSelected)
    {
    case 1:
        cout << "\nCode Entered: " << GuessA << GuessB << GuessC<< endl;
        break;
    case 2:
        cout << "\nCodigo digitado: " << GuessA << GuessB << GuessC << endl;
        break;
    }
    if(CodeSum(CodeA, CodeB, CodeC) == CodeSum(GuessA, GuessB, GuessC) && CodeProduct(CodeA, CodeB, CodeC) == CodeProduct(GuessA, GuessB, GuessC)){
        
        switch (LanguageSelected)
        {
        case 1:
            cout << "Correct Code!";
            break;
        case 2:
            cout << "Codigo Certo!";
            break;
        }
        _sleep(2000);
        return true;
    }
    else{
        switch (LanguageSelected){
        case 1:
            cout << "Wrong Code!";
            break;
        case 2:
            cout << "Codigo Errado!";
            break;
        }
        _sleep(2000);
        return false;
    }
}

bool TryAgain(int LanguageSelected){
    int PlayAgain = 0;
    while(PlayAgain == 0){
        switch (LanguageSelected)
        {
        case 1:
            cout << "\n\nTry Again? \n";
            cout << "1. Yes\n";
            cout << "2. No\n";
            break;
        case 2:
            cout << "\n\nTentar novamente? \n";
            cout << "1. Sim\n";
            cout << "2. Nao\n";
            break;
        }
        cin >> PlayAgain;
    }
    return PlayAgain == 1 ? true : false;
}

void Credits(bool bGameComplete, int LanguageSelected){
    if(bGameComplete){
        if(LanguageSelected == 2) cout << "Voce completou o jogo, Parabens!\n\n";
        else cout << "You have completed the game, Congratulations!\n\n";
    }
    if(LanguageSelected == 2)cout << "\n\nJogo desenvolvido por Gabriel Cassimiro,\njogo baseado no jogo desenvolvido no curso https://www.udemy.com/course/unrealcourse/ \n\n\n";
    else cout << "\n\nGame developed by Gabriel Cassimiro,\nbased on the game developed in the course https://www.udemy.com/course/unrealcourse/ \n\n\n";
}

int CodeSum(int CodeA, int CodeB, int CodeC){
    return CodeA + CodeB + CodeC;
}

int CodeProduct(int CodeA, int CodeB, int CodeC){
    return CodeA * CodeB * CodeC;
}