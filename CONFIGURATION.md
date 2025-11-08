# CONFIGURATION.md

## Dokumentacja parametrów konfiguracyjnych

Poniżej znajduje się szczegółowa dokumentacja wszystkich 13 parametrów konfiguracyjnych:

### 1. polePairs
**Opis:** Liczba par biegunów w silniku.
**Przykład:** Jeśli masz silnik z 14 biegunami, to liczba par biegunów wynosi 7.

### 2. loopMs
**Opis:** Czas trwania jednej iteracji pętli w milisekundach.
**Przykład:** Dla wartości 15, modulacja PWM działa co 15 milisekund.

### 3. timeoutMs
**Opis:** Czas oczekiwania na zgłoszenie lub odbiór sygnału.
**Przykład:** Ustawienie 500 ms oznacza, że po 500 ms bez aktywności silnik wejdzie w tryb oszczędzania energii.

### 4. minValidDt
**Opis:** Minimalna wartość delta czasu dla ważnych pomiarów.
**Przykład:** Może być ustawiona na 0.005 dla stabilności pomiarów.

### 5. hallAvgCount
**Opis:** Liczba pomiarów średnich dla czujników Halla.
**Przykład:** Ustawić na 10 dla uzyskania lepszego uśrednienia sygnałów.

### 6. maxRpmRise
**Opis:** Maksymalna szybkość przyrostu RPM.
**Przykład:** Ustawienie 100 oznacza, że RPM nie wzrośnie o więcej niż 100 na jeden cykl.

### 7. maxReduction
**Opis:** Maksymalne ograniczenie obrotów silnika.
**Przykład:** Limit 50% oznacza, że maksymalne obroty to połowa wartości nominalnej.

### 8. silaRedukcji
**Opis:** Siła redukcji obrotów wewnętrznych w wartości procentowej.
**Przykład:** Ustawienie 20% oznacza, że obroty zostaną zredukowane o 20%.

### 9. pwmRampUp
**Opis:** Ramp up czas dla sygnału PWM.
**Przykład:** Ustawienie na 200 ms spowoduje, że PWM potrzebuje 200 ms na osiągnięcie 100%.

### 10. pwmRampDown
**Opis:** Ramp down czas dla sygnału PWM.
**Przykład:** Ustawienie na 100 ms oznacza, że PWM redukuje się do 0% w ciągu 100 ms.

### 11. ignoreImpulsesAfterStart
**Opis:** Opcja ignorowania impulsów po starcie. 
**Przykład:** Ustawienie na true zablokuje reakcje na impulsy przez 1 sekundy po włączeniu.

### 12. minRpmForLimit
**Opis:** Minimalne RPM wymagane do zastosowania ograniczenia.
**Przykład:** Ustawienie na 300 obrotów na minutę, aby ograniczenie działało tylko powyżej tej wartości.

### 13. bypassMode
**Opis:** Tryb omijania, kiedy parametry konfiguracyjne mogą być zignorowane.
**Przykład:** Ustawienie trybu prawdziwego (true) spowoduje pominięcie wszystkich ograniczeń nałożonych przez pozostałe parametry.

### Przykład:
```cpp
Configuration conf;
conf.polePairs = 7;
conf.loopMs = 15;
conf.timeoutMs = 500;
...
```

Uwagi: Dostosuj parametry zgodnie z potrzebami aplikacji.