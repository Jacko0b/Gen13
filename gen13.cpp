#include <iostream>
#include <vector>

using namespace std;

vector<char> alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c'};

// 2 przypadki
// Dla n parzystego bierzemy wszystkie cyfry pokolei
// Dla n nieparzystego cyfry "dookoła" te co się powtarzają są wszystkie (nieparzyste i parzyste),
// ale cyfra "środkowa" musi być parzysta - bo nie ma pary 

bool isDigitOdd (char digit){
    bool isOdd = false;
    if (digit == '1' || digit == '3' || digit == '5' ||
        digit == '7' || digit == '9' || digit == 'b'){

        isOdd=true;
    }
    return isOdd;
}

void generatePalindromes(int n, int currentPosition, vector<char>& currentPalindrome) {
    // Podstawiamy cyfry z pierwszej polowy na ich lustrzane miejsca od konca i wypisujemy palindrom
    if (currentPosition >= (n + 1) / 2) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            currentPalindrome[n - 1 - i] = currentPalindrome[i];
        }     
        for (char c : currentPalindrome) {
            printf("%c", c);
        }
        return;
    }

    // Generuj palindromy w kolejności rosnącej
    for (char digit : alphabet) {
        
        currentPalindrome[currentPosition] = digit;

        //Jak n jest parzysty to generuj wszystkie palindromy
        if(n%2==0){       
            generatePalindromes(n, currentPosition + 1, currentPalindrome);  
        }
        
        //Jak n jest nieparzysty to generuj wszystkie palindromy, które w środku mają cyfrę parzystą
        else {
            if(currentPosition == n / 2 && isDigitOdd(digit)){
            }
            else{
                generatePalindromes(n, currentPosition + 1, currentPalindrome);
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
            vector<char> currentPalindrome(n);
            generatePalindromes(n, 0, currentPalindrome);
            printf("\n");
        }
        
        stringsToGenerate--;
    }
    return 0;
}
