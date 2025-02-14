# Hyperfit - Programi për Ndjekjen e Fitnesit

## Përmbledhje
Hyperfit është një program i thjeshtë për ndjekjen e fitnesit i shkruar në C++. Ai ndihmon përdoruesit të monitorojnë aktivitetin fizik të përditshëm, të llogarisin kaloritë e djegura dhe të ndjekin progresin drejt objektivave të fitnesit, si humbja ose shtimi i peshës.

---

## Karakteristika
- Llogarit **kaloritë e djegura** bazuar në numrin e hapave.
- Konverton kaloritë e djegura në **minuta vrapimi ekuivalent**.
- Llogarit kaloritë e djegura gjatë **ushtrimeve** bazuar në kohëzgjatje dhe intensitet.
- Vlerëson **nivelin e aktivitetit ditor** me mesazhe motivuese.
- Llogarit **balancën ditore të kalorive** bazuar në kaloritë e djegura, të konsumuara dhe objektivat e përdoruesit.
- Mbështet dy objektiva të fitnesit:
  - **Humbje peshe** (`humbje`)
  - **Shtim peshe** (`shtim`)

---

## Funksionet

### `float llogaritKalorite(int hapa)`
- **Përshkrimi**: Llogarit kaloritë e djegura bazuar në numrin e hapave.
- **Formula**: `0.04 kalori` për hap.
- **Input**: Numri i hapave (`hapa`).
- **Output**: Kaloritë e djegura (`kaloringaecja`).

---

### `float konvertoNeVrapim(float kaloringaecja)`
- **Përshkrimi**: Konverton kaloritë e djegura në kohë ekuivalente vrapimi.
- **Formula**: `1 minutë = 10 kalori`.
- **Input**: Kaloritë e djegura (`kaloringaecja`).
- **Output**: Koha e vrapimit në minuta (`minutaVrapim`).

---

### `string vleresoAktivitetin(int hapa)`
- **Përshkrimi**: Vlerëson nivelin e aktivitetit bazuar në numrin e hapave të bërë.
- **Intervalet**:
  - `< 2000`: `"Shume pak aktivitet. Duhet te levizesh me shume!"`
  - `2000 - 5999`: `"Aktivitet mesatar. Mund te permiresohesh!"`
  - `6000 - 9999`: `"Shume mire! Vazhdoni keshtu!"`
  - `>= 10000`: `"Super! Po jeton shendetshem!"`
- **Input**: Numri i hapave (`hapa`).
- **Output**: Niveli i aktivitetit si string.

---

### `float llogaritKaloriUshtrime(float koheMinuta, float intensitet)`
- **Përshkrimi**: Llogarit kaloritë e djegura gjatë ushtrimeve.
- **Formula**: `koheMinuta * intensitet * 5.0`.
- **Input**: Koha e ushtrimeve në minuta (`koheMinuta`) dhe niveli i intensitetit (`intensitet`).
- **Output**: Kaloritë e djegura gjatë ushtrimeve (`kaloriUshtrime`).

---

### `float llogaritBalancin(float kaloriHumbura, float kaloriUshtrime, float kaloriMarr, float kalorigoli, string qellimi)`
- **Përshkrimi**: Llogarit balancën ditore të kalorive.
- **Formula**:
  - Për humbje peshe (`humbje`):  
    `(kaloritë e synuara - kaloritë totale të djegura) + kaloritë e konsumuara`.
  - Për shtim peshe (`shtim`):  
    `(kaloritë e synuara - (kaloritë e konsumuara - kaloritë totale të djegura))`.
- **Input**:
  - Kaloritë e djegura nga ecja (`kaloriHumbura`).
  - Kaloritë e djegura nga ushtrimet (`kaloriUshtrime`).
  - Kaloritë e konsumuara (`kaloriMarr`).
  - Synimi i përditshëm i kalorive (`kalorigoli`).
  - Qëllimi i fitnesit (`qellimi`).
- **Output**: Balanca e kalorive për ditën (`balanci`).

---

## Si të Përdoret

1. **Vendosni Qëllimin Tuaj**: Programi mbështet humbjen (`humbje`) ose shtimin e peshës (`shtim`).
2. **Jepni të Dhënat Tuaja**:
   - Vendosni numrin e hapave të bërë sot.
   - Specifikoni kohëzgjatjen dhe intensitetin e ushtrimeve.
   - Vendosni qëllimin ditor të kalorive dhe kaloritë e konsumuara.
3. **Merrni Raportin e Fitnesit**:
   - Programi llogarit kaloritë e djegura nga ecja dhe ushtrimet.
   - Shfaq nivelin e aktivitetit me një mesazh motivues.
   - Llogarit balancën ditore të kalorive.
4. **Rregulloni Aktivitetin Tuaj**: Bazuar në balancën e kalorive, programi sugjeron si të arrini objektivin tuaj.

---

# Shembull Output-i i Programit Hyperfit

### Shembull për një përdorues që synon humbjen e peshës:

Ju keni djegur rreth 300 kalori sot nga ecja!
Kjo eshte ekuivalente me 30 minuta vrapim.
Ju keni djegur rreth 450 kalori sot nga ushtrimet!
Vleresimi i aktivitetit tuaj: Shume mire! Vazhdoni keshtu!
Balanca e kalorive per sot: -250 kalori.
Ju keni kaluar synimin me 250 kalori.

---

### Shembull për një përdorues që synon shtimin e peshës:

Miresevini ne programin e fitnesit Hyperfit!
Cili eshte qellimi juaj, te humbni apo te shtoni peshe? (humbje/shtim): shtim
Shkruani numrin e hapave te bere sot: 3500
Sa minuta keni ushtruar sot? 20
Cili ishte niveli i intensitetit te ushtrimeve? (1.0 per i ulet, 2.0 mesatar, 3.0 i larte): 1.0
Sa kalori synoni te konsumoni ne dite? 3000
Shkruani sa kalori keni konsumuar sot nga ushqimi: 2500

---Raporti ditor i Aktiviteteve---
Ju keni djegur rreth 140 kalori sot nga ecja!
Kjo eshte ekuivalente me 14 minuta vrapim.
Ju keni djegur rreth 100 kalori sot nga ushtrimet!
Vleresimi i aktivitetit tuaj: Aktivitet mesatar. Mund te permiresohesh!
Balanca e kalorive per sot: 440 kalori.
Ju duhet te konsumoni 440 kalori me shume per te arritur objektivin tuaj.
---
Ky dokumentim i output-it është i përgatitur për të përcjellë qartë funksionalitetet e programit në një dosje README.
---

## Kërkesat
- **Kompajluesi**: Çdo kompajlues C++ që mbështet C++11 ose më të vonë.
- **Input**: Të dhëna nga përdoruesi në terminal.
- **Output**: Raporte të shfaqura në terminal.

---

## Si të Ekzekutohet
1. Klononi repositorin:
   ```bash
   git clone https://github.com/username/hyperfit.git
   ```
2. Hyni në dosjen e projektit:
   ```bash
   cd hyperfit
   ```
3. Kompiloni programin:
   ```bash
   g++ -o hyperfit hyperfit.cpp
   ```
4. Ekzekutoni programin:
   ```bash
   ./hyperfit
   ```

---

## Licensa
Ky projekt është i licensuar nën **MIT License**. Mund ta përdorni, modifikoni dhe shpërndani sipas dëshirës!
```
