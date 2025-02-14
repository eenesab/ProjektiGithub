#include <iostream>;
#include <string>;
using namespace std;

// Funksion per te vleresuar nivelin e aktivitetit
string vleresoAktivitetin(int hapa) {
    if (hapa < 2000) return "Shume pak aktivitet. Duhet te levizesh me shume!";
    else if (hapa < 6000) return "Aktivitet mesatar. Mund te permiresohesh!";
    else if (hapa < 10000) return "Shume mire! Vazhdoni keshtu!";
    else return "Super! Po jeton shendetshem!";
}

// Funksion per te llogaritur kalorite e djegura nga ushtrimet fizike
float llogaritKaloriUshtrime(float koheMinuta, float intensitet) {
    return koheMinuta * intensitet * 5.0; // Mesatarisht 5 kalori per minute per nivel mesatar
}

