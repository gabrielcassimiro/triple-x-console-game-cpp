<h1 align='center'>Tripe X - Console Game</h1>

- [English](#English)
- [Português](#Português)

## **English**

<p>Triple X - Console Game, is a game that as the name says, is played on the console (cmd or PowerShell), the Game was made following much of a section <b>Triple X - Write Pure C++</b>, from the course <a href="https://www.udemy.com/course/unrealcourse/">Unreal Engine C++ Developer: Learn C++ and Make Video Games</a>.</p>
<p>In the game you are a secret agent who must go through password protection levels in order to access the secret service room.</p>
<p>In addition to the standard game made according to the course, some <b>"features"</b> were added by me, such as:</p>

- Translation to 2 languages: Portuguese and English.
- Menu of: Play again?
- Credits.

<h2>Code Explanation</h2>

<h3>Functions</h3>

```cpp
int PreGame();
void PrintIntroduction(int LanguageSelected, int Difficulty);
bool PlayGame(int LanguageSelected, int Difficulty);
bool TryAgain(int LanguageSelected);
void Credits(bool bGameComplete, int LanguageSelected);
int CodeSum(int CodeA, int CodeB, int CodeC);
int CodeProduct(int CodeA, int CodeB, int CodeC);
```

<h4>PreGame()</h4>
<p>The PreGame function is the function responsible for showing the user the language selection menu, thus defining for the rest of the game in which language the entire game will be played.</p>

```cpp
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
```

</h4>PrintIntroduction(int LanguageSelected, int Difficulty)</h4>
<p>The PrintIntroduction function is responsible for printing the introduction message for each level to the console.</p>

```cpp
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
```

<h4>PlayGame(int LanguageSelected, int Difficulty)</h4>
<p>The function PlayGame, is where all interaction of the game occurs, is where it generates the password, and receives the inputs from the player, thus returning a bool that is responsible for saying whether the player got the password right or not.</p>

```cpp
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
```

<h4>TryAgain(int LanguageSelected)</h4>
<p>The function TryAgain, is responsible for printing to the player the menu of play again?, so with the answer defines whether the player wants to continue playing or not.</p>

```cpp
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
```

<h4>void Credits(bool bGameComplete, int LanguageSelected)</h4>
<p>The Credits function, is responsible for printing the credits after the game is finished, either by having reset, or by not wanting to try again.</p>

```cpp
void Credits(bool bGameComplete, int LanguageSelected){
    if(bGameComplete){
        if(LanguageSelected == 2) cout << "Voce completou o jogo, Parabens!\n\n";
        else cout << "You have completed the game, Congratulations!\n\n";
    }
    if(LanguageSelected == 2)cout << "\n\nJogo desenvolvido por Gabriel Cassimiro,\njogo baseado no jogo desenvolvido no curso https://www.udemy.com/course/unrealcourse/ \n\n\n";
    else cout << "\n\nGame developed by Gabriel Cassimiro,\nbased on the game developed in the course https://www.udemy.com/course/unrealcourse/ \n\n\n";
}
```

<h4>int CodeSum(int CodeA, int CodeB, int CodeC) & int CodeProduct(int CodeA, int CodeB, int CodeC)</h4>
<p>The CodeSum and CodeProduct functions, are the ones responsible for doing the sum of the codes and Multiplication of the Codes, to thus give as a hint to try to crack the password.</p>

```cpp
int CodeSum(int CodeA, int CodeB, int CodeC){
    return CodeA + CodeB + CodeC;
}

int CodeProduct(int CodeA, int CodeB, int CodeC){
    return CodeA * CodeB * CodeC;
}
```

## **Português**

<p>Triple X - Console Game, é um jogo que como o nome diz, se joga no console (cmd ou PowerShell), o Jogo foi feito seguindo boa parte de uma seção <b>Triple X - Write Pure C++</b>, do curso <a href="https://www.udemy.com/course/unrealcourse/">Unreal Engine C++ Developer: Learn C++ and Make Video Games</a>.</p>
<p>No jogo você é um agente secreto que precisa passar por níveis de proteção de senha para poder acessar a sala de serviço secreto.</p>
<p>Além do jogo padrão feito de acordo com o curso, foram adicionados por mim algumas <b>"features"</b>, como:</p>

- Tradução para 2 idiomas: Português e Inglês.
- Menu de: Jogar novamente?
- Creditos.

<h2>Explicação do Código</h2>

<h3>Funções</h3>

```cpp
int PreGame();
void PrintIntroduction(int LanguageSelected, int Difficulty);
bool PlayGame(int LanguageSelected, int Difficulty);
bool TryAgain(int LanguageSelected);
void Credits(bool bGameComplete, int LanguageSelected);
int CodeSum(int CodeA, int CodeB, int CodeC);
int CodeProduct(int CodeA, int CodeB, int CodeC);
```

<h4>PreGame()</h4>
<p>A função PreGame é a função responsável por mostrar pra o usuário o menu de seleção de idioma, assim definindo para o resto do jogo em qual lingua irá ser jogado o jogo inteiro.</p>

```cpp
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
```

<h4>PrintIntroduction(int LanguageSelected, int Difficulty)</h4>
<p>A função PrintIntroduction é responsável por printar no console a mensagem de introdução de cada nível.</p>

```cpp
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
```

<h4>PlayGame(int LanguageSelected, int Difficulty)</h4>
<p>A função PlayGame, é onde ocorre toda interação do game, é onde gera a senha, e recebe os inputs do jogador, assim retornando um bool que é responsável por dizer se o jogador acertou a senha ou não.</p>

```cpp
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
```

<h4>TryAgain(int LanguageSelected)</h4>
<p>A função TryAgain, é responsável por printar ao jogador o menu de jogar novamente?, assim com a resposta define se o jogador quer continuar jogando ou não.</p>

```cpp
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
```

<h4>void Credits(bool bGameComplete, int LanguageSelected)</h4>
<p>A função Credits, é responsável para printar os créditos depois que o game for finalizado, seja por ter zerado, ou por não querer tentar novamente.</p>

```cpp
void Credits(bool bGameComplete, int LanguageSelected){
    if(bGameComplete){
        if(LanguageSelected == 2) cout << "Voce completou o jogo, Parabens!\n\n";
        else cout << "You have completed the game, Congratulations!\n\n";
    }
    if(LanguageSelected == 2)cout << "\n\nJogo desenvolvido por Gabriel Cassimiro,\njogo baseado no jogo desenvolvido no curso https://www.udemy.com/course/unrealcourse/ \n\n\n";
    else cout << "\n\nGame developed by Gabriel Cassimiro,\nbased on the game developed in the course https://www.udemy.com/course/unrealcourse/ \n\n\n";
}
```

<h4>int CodeSum(int CodeA, int CodeB, int CodeC) & int CodeProduct(int CodeA, int CodeB, int CodeC)</h4>
<p>As funções CodeSum e CodeProduct, são as responsáveis por fazer a soma dos códigos e Multiplicação dos Códigos, para assim dar como dica para tentar decifrar a senha.</p>

```cpp
int CodeSum(int CodeA, int CodeB, int CodeC){
    return CodeA + CodeB + CodeC;
}

int CodeProduct(int CodeA, int CodeB, int CodeC){
    return CodeA * CodeB * CodeC;
}
```
