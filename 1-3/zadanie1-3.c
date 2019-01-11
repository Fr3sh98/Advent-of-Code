#include <stdio.h>

//deklaracja tablicy 1000x1000 potrzebej do zadnia nr. 3
int fabric[1000][1000];

void f1() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data1", "r");
//buffor ktory jest w stanie przyjąć do 1000 znaków
    char currentline[1000];
//zmienna przechowujaca sumę liczb wejścoiwych
    int a = 0;

//pętla przechodząca przez plik i wczytująca wszystkie linie aż do końca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int n = 0;
//wczytanie lini z pliku do zmiennej n
        sscanf(currentline, "%d", &n);
//dodawanie zmiennej n do zmiennej a
        a += n;
    }
//zamknięcie pliku
    fclose(file);

    printf("1) %d\n", a);
}

void f2() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data2", "r");
//wszystiie linie w pliku mają taką samą długość więc mozemy z góry ustalić długość buffora
    char currentline[32];
    int a = 0, b = 0;

//pętla przechodząca przez plik i wczytująca wszystkie linie aż do końca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        int aa = 0, bb = 0;
        int letters = 'z' - 'a' + 1;
        int array[letters];
//wypełniamy naszą tablicę zerami
        for (int i = 0; i < letters; i++)
            array[i] = 0;

//zliczanie ilości wystąpień liter w linii
        for (int i = 0; i < 27; i++)
            array[currentline[i] - 'a']++;

//sprawdzanie czy linia spełnia warunki zadania
        for (int i = 0; i < letters; i++) {
            if (array[i] == 2)
                aa = 1;
            else if (array[i] == 3)
                bb = 1;
        }

        if (aa == 1) a++;
        if (bb == 1) b++;
    }

//wypisanie wyniku
    printf("2) %d\n", (a * b));

//zamykamy plik
    fclose(file);
}

void f3() {
//deklaracja oraz otwarcie pliku z danymi
    FILE *file = fopen("data3", "r");
//deklaracja zmiennych które pozwolą nam się 'poruszać' po dwuwymiarowej tablicy
    int l = 0, t = 0, w = 0, h = 0;
    char currentline[50];

//wypełnianie naszej tablicy zerami
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            fabric[i][j] = 0;

//pętla przechodząca przez plik i wczytująca wszystkie linie aż do końca pliku
    while (fgets(currentline, sizeof(currentline), file) != NULL) {
//'wyciąganie' danych z linii
        sscanf(currentline, "%d%d%d%d", &l, &t, &w, &h);
//zliczanie ilości punktów które należą do danego elfa
        for (int y = t; y < t + h; y++)
            for (int x = l; x < w + l; x++)
                fabric[y][x]++;
    }

    int area = 0;

//sprawdzamy wszystkie pola w tablicy, jezeli sa wieksze od 1 do zmiennej area dodajemy 1
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            if (fabric[i][j] > 1)
                area++;

    printf("3) %d\n", area);

//zamknięcie pliku
    fclose(file);
}


int main() {
    f1();
    f2();
    f3();
    return 0;
}