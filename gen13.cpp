#include <iostream>
#include <vector>

using namespace std;

vector<char> alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c'};



//#############################################
// 2 przypadki
// Dla n parzystego bierzemy wszystkie cyfry pokolei
// Dla n nieparzystego cyfry "dookoła" te co się powtarzają są wszystkie,
// ale cyfra "środkowa" musi być parzysta - bo nie ma pary 

void generatePalindromes(int n, int pos, vector<char>& current) {
    // jeżeli pos jest większy rowny niż połowa - (n+1/2)
    if (pos >= (n + 1) / 2) {
        // Utwórz pełny palindrom z częściowo wygenerowanego ciągu
        for (int i = n / 2 - 1; i >= 0; --i) {
            current[n - 1 - i] = current[i];
        }                                                                               //TO-DO dziala tylko dla n=1,2
        //Sprawdzenie czy n jest nieparzyste - wsadzanie w srodek tylko parzystej liczby
        if(n%2==1){
            if (current[n - 1] == '0' || current[n - 1] == '2' || current[n - 1] == '4' ||
             current[n - 1] == '6' || current[n - 1] == '8' || current[n - 1] == 'a' ||
             current[n - 1] == 'c') {
            for (char c : current) {
                printf("%c", c);
            }
        }
        }else{
           for (char c : current) {
                printf("%c", c);
            } 
        }
        
        return;
    }

    // Generuj cyfry w kolejności rosnącej
    for (char c : alphabet) {
        current[pos] = c;
        generatePalindromes(n, pos + 1, current);
    }
}

int main() {
    int stringsToGenerate;
    scanf("%d",&stringsToGenerate);

    if (stringsToGenerate >= 11 || stringsToGenerate <= 0) {
        return 1;
    }
    //Wywołanie generatora dla każdego wiersza
    while(stringsToGenerate>0){
        int n;
        scanf("%d",&n) ;
        vector<char> current(n);
        generatePalindromes(n, 0, current);
        printf("\n");
        stringsToGenerate--;
    }

    return 0;
}
