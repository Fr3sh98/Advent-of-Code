#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia nr. 3
int fabric[1000][1000];
//tablica do zliczania znalezionych liczb
int numberFound[200000];
//tablica przechowujÄ…ca linie z zadania 2
char lines2[10000][32];


void f1() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data1", "r");
//buffor ktory jest w stanie przyjÄ…Ä‡ do 1000 znakĂłw
    char currentline[1000];
    int lines[10000];
    int size = 0;
//zmienna przechowujaca sumÄ™ liczb wejĹ›coiwych
    int a = 0;
//zmienna przechowujaca sumÄ™ liczb wejĹ›coiwych dla 2 czÄ™Ĺ›ci z zadania
    int b = 0;
    int found = 0;

//pÄ™tla przechodzÄ…ca przez plik i wczytujÄ…ca wszystkie linie aĹĽ do koĹ„ca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int n = 0;
//wczytanie lini z pliku do zmiennej n
        sscanf(currentline, "%d", &n);
//dodawanie zmiennej n do zmiennej a
        a += n;
        lines[size] = n;
//zwiÄ™kszamy wielkoĹ›Ä‡ tablicy
        size++;
    }
    printf("1) a. %d", a);


//wypeĹ‚nienie tablicy zerami
    int i = 0;
    for (; i < 200000; i++)
        numberFound[i] = 0;

    i = 0;
//pÄ™tla dzaĹ‚ajÄ…ca do momentu znalezienia wartoĹ›ci powtarzajÄ…cej siÄ™ 2 razy
    while (!found) {
        b += lines[i];
        numberFound[b+100000]++;
//jeĹĽeli liczba b wystÄ…piĹ‚a 2 razy tp wypisujemy jÄ… i wychodzimy z pÄ™tli przez zmianÄ™ zmiennej foun na 1
        if(numberFound[b+100000] == 2){
            printf(" b. %d\n", b);
            found = 1;
        }

        i = (i+1)%size;
    }
//zamkniÄ™cie pliku
    fclose(file);

}

void f2() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data2", "r");
//wszystiie linie w pliku majÄ… takÄ… samÄ… dĹ‚ugoĹ›Ä‡ wiÄ™c mozemy z gĂłry ustaliÄ‡ dĹ‚ugoĹ›Ä‡ buffora
    char currentline[32];
    int a = 0, b = 0;
    int n = 0;

//pÄ™tla przechodzÄ…ca przez plik i wczytujÄ…ca wszystkie linie aĹĽ do koĹ„ca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int i = 0;
        for(; i < 32; i++)
            lines2[n][i] = currentline[i];

        int aa = 0, bb = 0;
//obliczamy iloĹ›Ä‡ liter w alfabecie
        const int letters = 'z' - 'a' + 1;
        int array[letters];
//wypeĹ‚niamy naszÄ… tablicÄ™ zerami
        i = 0;
        for (; i < letters; i++)
            array[i] = 0;

//zliczanie iloĹ›ci wystÄ…pieĹ„ liter w linii
        i = 0;
        for (; i < 27; i++)
            array[currentline[i] - 'a']++;

        i = 0;
//sprawdzanie czy linia speĹ‚nia warunki zadania
        for (; i < letters; i++) {
            if (array[i] == 2)
                aa = 1;
            else if (array[i] == 3)
                bb = 1;
        }

        if (aa == 1) a++;
        if (bb == 1) b++;

        n++;
    }

//wypisanie wyniku
    printf("2) a. %d", (a * b));
//zamykamy plik
    fclose(file);

//porĂłwnujemy wszystkie linie ze sobÄ…
    int i = 0, j = 0, k = 0;
    for(; i < n; i++){
        for(; j < n; j++){
            int different = 0;
            for(; k < 27; k++){
//zliczamy iloĹ›Ä‡ rĂłĹĽnych znakĂłw
                if(lines2[i][k] != lines2[j][k])
                    different++;
            }

//jeĹĽeli liczba rĂłĹĽnych znakĂłw wynosi 1 to koĹ„czymy porĂłwnynwanie linii i wypisujemy wyniki
            if(different == 1){
                printf(" b. ");
//tworzenie wyniku ze wspĂłlnych liter
                k = 0;
                for(; k < 27; k++){
                    if(lines2[i][k] == lines2[j][k]){
                        printf("%c", lines2[i][k]);
                    }
                }
//wypisanie wynikiu
                printf("\n");
                return;
            }
        }
    }

}

void f3() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data3", "r");
//deklaracja zmiennych ktĂłre pozwolÄ… nam siÄ™ 'poruszaÄ‡' po dwuwymiarowej tablicy
    int l = 0, t = 0, w = 0, h = 0;
    char currentline[50];

//wypeĹ‚nianie naszej tablicy zerami
    int i = 0;
    int j = 0;
    for (; i < 1000; i++)
        for (; j < 1000; j++)
            fabric[i][j] = 0;

//pÄ™tla przechodzÄ…ca przez plik i wczytujÄ…ca wszystkie linie aĹĽ do koĹ„ca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
//'wyciÄ…ganie' danych z linii
        sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h);
//zliczanie iloĹ›ci punktĂłw ktĂłre naleĹĽÄ… do danego elfa
        int y = t, x = l;
        for (; y < t + h; y++)
            for (; x < w + l; x++)
                fabric[y][x]++;
    }
//zamkniÄ™cie pliku
    fclose(file);

    int area = 0;

//sprawdzamy wszystkie pola w tablicy, jezeli sa wieksze od 1 do zmiennej area dodajemy 1
    i = 0;
    j = 0;
    for (; i < 1000; i++)
        for (; j < 1000; j++)
            if (fabric[i][j] > 1)
                area++;
    printf("3) a. %d", area);


    int n = 1;
//ponownie owtieramy plik
    file = fopen("data3", "r");
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
//'wyciÄ…ganie' danych z linii
        sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h);
//zliczanie iloĹ›ci punktĂłw ktĂłre sÄ… wspĂłĹ‚dzielone przez wiÄ™cej niĹĽ jednego elfa
        int claimed = 0;

        int y = t, x = l;
        for (; y < t + h; y++)
            for (; x < w + l; x++)
//sprawdzamy przez ilu elfĂłw punkt jest wspĂłĹ‚dzielony
                if(fabric[y][x] > 1)
                    claimed++;

//jeĹĽeli ĹĽaden z punktĂłw nie jest wspĂłĹ‚dzielony z innym elfem to koĹ„czymy pÄ™tlÄ™ i wypisujemy wyniki
        if(claimed == 0){
            printf(" b. %d", n);
            return;
        }
        n++;
    }

//zamkniÄ™cie pliku
    fclose(file);
}


int main() {
    f1();
    f2();
    f3();
    return 0;
}
