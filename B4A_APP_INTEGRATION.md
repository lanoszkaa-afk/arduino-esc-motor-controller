# Integracja z aplikacją Basic4Android

## Opis
Integracja z aplikacją Basic4Android (B4A) pozwala na łatwe łączenie z urządzeniem sterującym wykorzystując protokół szeregowy.

## Komendy protokołu szeregowego
1. **CMD_START** - Rozpoczyna komunikację z urządzeniem.
2. **CMD_STOP** - Zatrzymuje komunikację.
3. **CMD_SET_SPEED [wartość]** - Ustawia prędkość silnika. Wartość powinna być liczbą całkowitą od 0 do 100.

## Przykłady
### Przykład 1: Rozpoczęcie komunikacji
```basic4android
Serial1.Initialize("/dev/ttyUSB0", 9600, 0)
Serial1.WriteBytes("") ' Rozpocznij komunikację
```

### Przykład 2: Ustawienie prędkości silnika
```basic4android
Dim speed As Int
speed = 50 ' Prędkość na poziomie 50%
Serial1.WriteBytes(Array As Byte(CMD_SET_SPEED, speed))
```

## Ustawienia połączenia
1. Podłącz urządzenie do portu USB.
2. Skonfiguruj port szeregowy w aplikacji B4A tak, aby odpowiadał parametrom urządzenia (np. prędkość transmisji).
3. Użyj powyższych komend do komunikacji z urządzeniem.

---
Dokumentacja ta ma na celu ułatwienie integracji z aplikacją B4A, zapewniając niezbędne informacje dotyczące komend i ustawień.