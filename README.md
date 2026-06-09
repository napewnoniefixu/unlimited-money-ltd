# 📈 C++ Stock Plotter

Narzędzie konsolowe (CLI) napisane w nowoczesnym C++ (C++17), które integruje się z API Yahoo Finance w celu pobierania historycznych danych giełdowych, a następnie generuje z nich gotowe do analizy wykresy w formacie `.png` oraz umożliwia ich interaktywne wyświetlanie.

Projekt zaliczeniowy z programowania obiektowego w C++.

---

## 🎯 Główne Funkcje

* **Asynchroniczne pobieranie danych**: Wykorzystanie biblioteki `cpr` do komunikacji z API finansowym.
* **Parsowanie JSON**: Wykorzystanie `nlohmann/json` do przetwarzania złożonych struktur danych giełdowych.
* **Renderowanie wykresów**: Automatyczne generowanie plików PNG oraz opcjonalne wyświetlanie interaktywnego okna wykresu.
* **Architektura obiektowa**: Podział na klasy odpowiedzialne za konfigurację (`Config`), komunikację (`StockClient`), przetwarzanie danych (`DataParser`) i wizualizację (`PlotRenderer`).
* **Profesjonalny interfejs CLI**: Obsługa argumentów wiersza poleceń za pomocą `CLI11`.

---

## 🛠 Użyte Biblioteki Niestandardowe

Projekt automatycznie zarządza zależnościami za pomocą CMake `FetchContent`:
* **`cpr` (C++ Requests)**: Obsługa zapytań HTTP.
* **`nlohmann/json`**: Parsowanie formatu JSON.
* **`matplotplusplus`**: Generowanie i zapisywanie wykresów.
* **`CLI11`**: Obsługa argumentów wiersza poleceń.

---

## 💻 Wymagania Systemowe

1. Kompilator wspierający standard **C++17** (np. GCC/MinGW, MSVC).
2. **CMake** (w wersji min. 3.15).
3. **Gnuplot** – niezbędny do działania biblioteki `matplot++` (generowanie obrazów i okien wykresów).
   * *Windows*: Pobierz i zainstaluj z [oficjalnej strony Gnuplot](http://www.gnuplot.info/). Upewnij się, że folder `bin` gnuplota jest w zmiennej środowiskowej **PATH**.

---

## 🚀 Jak zbudować projekt?

Projekt wykorzystuje CMake do automatycznego pobrania bibliotek. 

```bash
# 1. Konfiguracja (używając MinGW)
cmake -G "MinGW Makefiles" -S . -B build

# 2. Kompilacja
cmake --build build
```

*Uwaga: Po kompilacji na Windowsie, wymagane pliki .dll zostaną skopiowane do folderu `build`, aby umożliwić uruchomienie programu.*

---

## 📖 Jak używać programu?

Uruchom plik wykonywalny z folderu `build`:

```bash
./build/stock_plotter.exe --help
```

### Argumenty:
* `-s, --symbol TEXT`: Symbol giełdowy (np. AAPL, TSLA, BTC-USD). Domyślnie: AAPL.
* `-d, --days INT`: Liczba dni wstecz dla danych historycznych. Domyślnie: 30.
* `-o, --output TEXT`: Nazwa pliku wyjściowego PNG. Domyślnie: plot.png.
* `-c, --config TEXT`: Ścieżka do pliku konfiguracyjnego JSON. Domyślnie: config.json.
* `--show`: Flaga, która sprawia, że okno z wykresem pozostaje otwarte do czasu ręcznego zamknięcia.

### Przykłady:
1. Podstawowy wykres dla Apple:
   ```bash
   ./build/stock_plotter.exe --symbol AAPL
   ```

2. Interaktywny wykres dla Microsoftu z ostatnich 90 dni:
   ```bash
   ./build/stock_plotter.exe --symbol MSFT --days 90 --show
   ```

3. Zapisanie wykresu pod konkretną nazwą:
   ```bash
   ./build/stock_plotter.exe --symbol TSLA --output tesla_90d.png
   ```

---

## ⚙️ Konfiguracja

Program ładuje klucz API z pliku `config.json` (zgodnie z wymogami projektowymi), choć obecna integracja z Yahoo Finance nie wymaga klucza do podstawowych zapytań. Wzór znajduje się w `config.example.json`.

---

## 🤖 Oświadczenie o użyciu AI

Narzędzia oparte na sztucznej inteligencji posłużyły jako asystent pomocniczy do:
* Zrozumienia dokumentacji i przyspieszenia nauki korzystania z bibliotek zewnętrznych
* Zaplanowania czytelnej struktury katalogów i plików w projekcie.
* Wygenerowania, sformatowania i korekty dokumentacji technicznej (w tym tego pliku README).
