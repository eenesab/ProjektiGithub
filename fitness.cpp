#include <iostream>
#include <string>
using namespace std;

// Funksion per te llogaritur kalorite e djegura bazuar ne numrin e hapave
float llogaritKalorite(int hapa) {
    return hapa * 0.04; // Mesatarisht 0.04 kalori per hap
}

// Funksion per te konvertuar kalorite ne minuta vrapimi (mesatarisht 10 kalori per minutë)
float konvertoNeVrapim(float kaloringaecja) {
    return kaloringaecja / 10.0;
}
