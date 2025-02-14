#include <iostream>
#include <string>
using namespace std;

// Funksion per te llogaritur kalorite e djegura bazuar ne numrin e hapave
float llogaritKalorite(int hapa) {
    return hapa * 0.04; // Mesatarisht 0.04 kalori per hap
}

// Funksion per te konvertuar kalorite ne minuta vrapimi (mesatarisht 10 kalori per minut�)
float konvertoNeVrapim(float kaloringaecja) {
    return kaloringaecja / 10.0;
}

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

// Funksion per te llogaritur balancin ditor te kalorive bazuar ne qellimin e fitnesit
float llogaritBalancin(float kaloriHumbura, float kaloriUshtrime, float kaloriMarr, float kalorigoli, string qellimi) {
    float totalKaloriDjegur = kaloriHumbura + kaloriUshtrime;
        if (qellimi == "humbje") {
            return (kalorigoli - totalKaloriDjegur) + kaloriMarr;
        }
        else if (qellimi == "shtim") {
            return kalorigoli - (kaloriMarr - totalKaloriDjegur);
        }
        else {
            cout << "Nuk keni shenuar vleren e kerkuar per qellimin."; // Rasti kur qellimi nuk eshte i sakte
            return 0;
        }
}
int main() {
    string qellimi;
    int hapa;
    float kalorigoli = 0.0;
    float kaloriMarr, koheUshtrime, intensitetUshtrime;

    cout << "Miresevini ne programin e fitnesit Hyperfit!" << endl;

    // Përsërit pyetjen derisa përdoruesi të shkruajë "humbje" ose "shtim"
    while (true) {
        cout << "Cili eshte qellimi juaj, te humbni apo te shtoni peshe? (humbje/shtim): ";
        cin >> qellimi;
        if (qellimi == "humbje" || qellimi == "shtim") {
            break; // Dalja nga loop-i nëse qellimi është i vlefshëm
        }
        cout << "Ju lutem shkruani 'humbje' ose 'shtim'.\n";
    }

    cout << "Shkruani numrin e hapave te bere sot: ";
    cin >> hapa;

    cout << "Sa minuta keni ushtruar sot? ";
    cin >> koheUshtrime;
    
    cout << "Cili ishte niveli i intensitetit te ushtrimeve? (1.0 per i ulet, 2.0 mesatar, 3.0 i larte): ";
    cin >> intensitetUshtrime;

    // Përsërit pyetjen për kaloritë e synuara derisa përdoruesi të shkruaj një numër të vlefshëm
    while (true) {
        if (qellimi == "humbje") {
            cout << "Sa kalori synoni te humbni ne dite? ";
        }
        else {
            cout << "Sa kalori synoni te konsumoni ne dite? ";
        }
        cin >> kalorigoli;

        if (kalorigoli > 0) break; // Dalja nga unaza nëse vlera është pozitive
        cout << "Ju lutem shkruani nje numer te vlefshem per kaloritë.\n";
    }
   
    cout << "Shkruani sa kalori keni konsumuar sot nga ushqimi: ";
    cin >> kaloriMarr;

    float kaloringaecja = llogaritKalorite(hapa);
    float minutaVrapim = konvertoNeVrapim(kaloringaecja);
    float kaloriUshtrime = llogaritKaloriUshtrime(koheUshtrime, intensitetUshtrime);
    string vleresim = vleresoAktivitetin(hapa);
    float balanci = llogaritBalancin(kaloringaecja, kaloriUshtrime, kaloriMarr, kalorigoli, qellimi);

    cout << "\n ~~~Raporti ditor i Aktiviteteve~~~ \n";
    cout << "Ju keni djegur rreth " << kaloringaecja << " kalori sot nga ecja!" << endl;
    cout << "Kjo eshte ekuivalente me " << minutaVrapim << " minuta vrapim." << endl;
    cout << "Ju keni djegur rreth " << kaloriUshtrime << " kalori sot nga ushtrimet!" << endl;
    cout << "Vleresimi i aktivitetit tuaj: " << vleresim << endl;

    cout << "Balanca e kalorive per sot: " << balanci << " kalori." << endl;
    if (balanci > 0) {
        if (qellimi == "humbje") {
            cout << "Ju duhet te humbni edhe " << balanci << " kalori per te arritur objektivin tuaj." << endl;
        }
        else if (qellimi == "shtim") {
            cout << "Ju duhet te konsumoni " << balanci << " kalori me shume per te arritur objektivin tuaj." << endl;
        }
    }
    else if (balanci < 0) {
        cout << "Ju keni kaluar synimin me " << -balanci << " kalori." << endl;
    }
    else {
        cout << "Ju e keni arritur pikërisht synimin tuaj!" << endl;
    }

    return 0;
}
