#include <iostream>
#include <vector>

using namespace std;

vector<char> alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c'};

// 2 przypadki
// Dla n parzystego bierzemy wszystkie cyfry pokolei
// Dla n nieparzystego cyfry "dookoła" te co się powtarzają są wszystkie (nieparzyste i parzyste),
// ale cyfra "środkowa" musi być parzysta - bo nie ma pary 
bool isDigitEven (char digit){
    bool isEven = false;
    if (digit == '0' || digit == '2' || digit == '4' ||
        digit == '6' || digit == '8' || digit == 'a' ||
        digit == 'c') 
    {
        isEven=true;
    }
    return isEven;
}

void generatePalindromes(int n, int currentPosition, vector<char>& currentDigit) {

    if (currentPosition >= (n + 1) / 2) {
        // Podstawiamy cyfry z pierwszej polowy na ich lustrzane odbicia od konca i wypisujemy
        for (int i = n / 2 - 1; i >= 0; --i) {
            currentDigit[n - 1 - i] = currentDigit[i];
        }     
        for (char c : currentDigit) {
            printf("%c", c);
        }
        return;
    }

    // Generuj cyfry w kolejności rosnącej
    for (char digit : alphabet) {
        //Jak n jest parzysty to generuj wszystkie palindromy
        currentDigit[currentPosition] = digit;
        if(n%2==0){       
            generatePalindromes(n, currentPosition + 1, currentDigit);  
        }

        else {
            if(currentPosition == n / 2 && !isDigitEven(digit)){
            }
            else{
                generatePalindromes(n, currentPosition + 1, currentDigit);
            }
        } 
    }
}

int main() {
    int stringsToGenerate;
    scanf("%d",&stringsToGenerate);

    //Wywołanie generatora dla każdego wiersza danych
    while(stringsToGenerate>0){
        int n;
        scanf("%d",&n) ;
        //Sprawdzenie czy się mieścimy w warunkach dlugosci palindromu
        if (n > 10 || n < 1) {
            printf("Błędne dane");
        }
        else{
            vector<char> currentDigit(n);
            generatePalindromes(n, 0, currentDigit);
            printf("\n");
        }
        
        stringsToGenerate--;
    }
    return 0;
}
