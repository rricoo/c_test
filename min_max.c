/*
 * Array (Min, Max, Mittel und Summe) mit Funktionen ermitteln
 * und Elemente mit optimierten BubbleSort sortieren.
 * Rico, 07.07.2022
 */

#include <stdio.h>
#include <stdlib.h>         // srand(), rand()
#define MAX 5
#define SEED 4710           // Zufallszahlen wiederholen sich in bestimmter Reichenfolge
#define loop(n) for(int i = 0; i < n; i++)          // Makro fuer for-Schleife

// Funktions-Protoyp, zur besseren Uebersicht
void ausgabeArray(int zahlen[], int n);
void testdaten(int zahlen[], int n);
int pruefen(int zahlen[], int n);
void minMax(int zahlen[], int n);
void sumMittel(int zahlen[], int n);
void bubbleSort(int zahlen[], int n);

int main()
{
    int zahlen[MAX], eingabe;

    // Laenge des Arrays ermitteln
    size_t n = sizeof(zahlen) / sizeof(zahlen[0]);

    // Mit Eingabe von Werten
    /*
    loop(n)
    {
        //fputs("Bitte Zahlen eingeben: ", stdout);
        printf("%d. Zahl eingeben: ", i+1);
        scanf("%d", &zahlen[i]);
    }
    */

    // Zufallszahlen verwenden
    srand(SEED);
    testdaten(zahlen, n);

    // Ausgabe unsortiertes Array
    ausgabeArray(zahlen, n);

    // Array sortiert und ausgeben
    bubbleSort(zahlen, n);
    ausgabeArray(zahlen, n);

    // Pruefen ob richtig sortiert wurde
    (pruefen(zahlen, n)) ? puts("OK\n") : puts("Nicht OK\n");

    // Kleinestes und groessetes Element
    minMax(zahlen, n);

    // Summe und Mittel aller Elemente
    sumMittel(zahlen, n);

    return 0;
}

void ausgabeArray(int zahlen[], int n)
{
    loop(n)
    {
        i < n-1 ? printf("%d, ", zahlen[i]) : printf("%d\n", zahlen[i]);
    }
}

// Zufallszahlen erzeugen
void testdaten(int zahlen[], int n)
{
    loop(n)
    {
        zahlen[i] = rand() %n;
    }
}

int pruefen(int zahlen[], int n)
{
    loop(n)
    {
        if(zahlen[i] > zahlen[i+1])
            return 0;
    }
    return 1;
}

void minMax(int zahlen[], int n)
{
    int min = zahlen[0];
    int max = zahlen[0];
    loop(n)
    {
        if(min > zahlen[i])
            min = zahlen[i];
        else if(max < zahlen[i])
            max = zahlen[i];
        else
            continue;
    }
    printf("\nMin: %d\t\tMax: %d\n", min, max);
}

void sumMittel(int zahlen[], int n)
{
    int sum = 0;
    loop(n)
    {
        sum += zahlen[i];
    }
    double mittel = (double)sum / n;
    printf("Mittelwert: %.1f\nSumme: %d\n", mittel, sum);
}

// Optimierter BubbleSort, sortierte Werte werden ignoiert
void bubbleSort(int zahlen[], int n)
{
    int vertauscht;
    do
    {
        vertauscht = 0;
        for(int i = n -1; i > 0; i--)
        {
            if(zahlen[i] < zahlen[i -1])
            {
                int temp = zahlen[i];
                zahlen[i] = zahlen[i - 1];
                zahlen[i - 1] = temp;
                vertauscht = 1;             // es wurde etwas veraendert
            }
        }
    } while(vertauscht);
}