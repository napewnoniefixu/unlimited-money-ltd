# 📈 C++ Stock Plotter

Narzędzie konsolowe (CLI) napisane w nowoczesnym C++, które integruje się z zewnętrznym API finansowym w celu pobierania historycznych danych giełdowych, a następnie generuje z nich gotowe do analizy wykresy w formacie `.png`. 

Projekt zaliczeniowy z programowania obiektowego w C++.

---

## 🎯 Kryteria

Program jest wersją alfa w pełni spójnego narzędzia. Został zaprojektowany zgodnie z paradygmatem programowania obiektowego (podział na oddzielne klasy odpowiedzialne za HTTP, parsowanie danych i renderowanie obrazu).

Zamiast prostego wypisywania danych w konsoli, program łączy asynchroniczne zapytania sieciowe z lokalnym silnikiem renderującym grafikę. Automatyzuje proces tworzenia fizycznych plików analitycznych na podstawie dynamicznych danych z sieci.

---

## 🛠 Użyte Biblioteki Niestandardowe

Projekt korzysta z następujących zewnętrznych bibliotek (zarządzanych przez CMake):
* **`cpr` (C++ Requests):** Obsługa zapytań HTTP do API giełdowego.
* **`nlohmann/json`:** Parsowanie i obróbka formatu JSON zwracanego przez API.
* **`matplotplusplus`:** Generowanie i zapisywanie wykresów do plików graficznych (np. PNG).
* **`CLI11`:** Profesjonalna obsługa argumentów z poziomu wiersza poleceń (flagi i menu pomocy).

---

## 💻 Wymagania Systemowe

Aby bezproblemowo skompilować i uruchomić projekt, potrzebujesz:
1. Kompilatora wspierającego standard **C++17** (lub nowszy).
2. **CMake** (w wersji min. 3.15).
3. **Gnuplot** – niezbędny do działania biblioteki `matplot++`.
   * *Linux (Ubuntu/Debian):* `sudo apt install gnuplot`
   * *Windows:* Pobierz i zainstaluj z [oficjalnej strony Gnuplot](http://www.gnuplot.info/), pamiętając o dodaniu programu do zmiennej środowiskowej PATH.

---

## 🚀 Jak zbudować projekt?

Projekt wykorzystuje standardowy system budowania CMake, który sam pobierze potrzebne biblioteki C++ za pomocą `FetchContent` (wymagane połączenie z internetem podczas pierwszej kompilacji).

Wykonaj poniższe polecenia w terminalu, będąc w głównym folderze projektu:

```bash
# 1. Konfiguracja projektu i wygenerowanie plików budowania w folderze 'build'
cmake -S . -B build

# 2. Kompilacja programu
cmake --build build


---

## 📖 Jak używać programu?

Po pomyślnej kompilacji plik wykonywalny znajdzie się w folderze `build`.

Aby sprawdzić pełne możliwości programu i listę argumentów, użyj flagi `--help` (zgodnie z wymogami projektowymi):

```bash
./build/stock_plotter --help

```

**Przykłady użycia:**

1. Pobranie danych i wygenerowanie wykresu dla firmy Apple (domyślne 30 dni):

```bash
./build/stock_plotter --symbol AAPL

```

2. Wygenerowanie wykresu dla Microsoftu z ostatnich 90 dni i zapisanie pod własną nazwą:

```bash
./build/stock_plotter --symbol MSFT --days 90 --output moj_wykres_msft.png

```

**Ważne:** Aby program działał, musisz posiadać darmowy klucz API (np. z Alpha Vantage/Finnhub) i umieścić go w pliku `config.json` w głównym folderze projektu (wzór znajduje się w pliku `config.example.json`).

---

## 🤖 Oświadczenie o użyciu AI

Zgodnie z zasadami projektu, oświadczam, że podczas tworzenia tej aplikacji korzystałem ze wsparcia modeli sztucznej inteligencji (Gemini). AI zostało wykorzystane do:

* Burzy mózgów przy wymyślaniu architektury obiektu i doborze nowoczesnych bibliotek C++.
* Przygotowania struktury i sformatowania tego pliku `README.md`.
* Pomocy w zrozumieniu logiki konfigurowania pliku budowania `CMakeLists.txt`.
Główna logika biznesowa i integracja komponentów została napisana i spięta samodzielnie.

```

```
