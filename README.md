# 🔫 Menedżer Ekwipunku CS2 (CS2 Skin Manager)

Prosta i wydajna aplikacja konsolowa napisana w języku C++ do zarządzania wirtualnym portfelem przedmiotów z gry Counter-Strike 2. Projekt pozwala na śledzenie posiadanych skinów, ich jakości, obecności technologii StatTrak™ oraz bieżącej wartości rynkowej.

Projekt został zrealizowany w ramach zaliczenia zajęć na kierunku Informatyka Stosowana.

## 🚀 Funkcjonalności (CRUD)
* **Wyświetlanie ekwipunku:** Przejrzysty widok listy przedmiotów wraz z automatycznym obliczaniem łącznej wartości całego inwentarza (w PLN).
* **Dodawanie skinów:** Możliwość wprowadzenia nazwy (np. *AK-47 Redline*), jakości, ceny oraz statusu StatTrak.
* **Usuwanie przedmiotów:** Bezpieczne usuwanie rekordów po unikalnym ID z automatycznym nadpisywaniem i przesuwaniem elementów w pamięci.
* **Wyszukiwanie:** Wyszukiwanie cząstkowe (substring) po nazwie lub typie broni (np. wpisanie samego słowa "Asiimov" zwróci wszystkie pasujące wyniki).
* **Sortowanie:** Układanie ekwipunku rosnąco według ceny rynkowej (implementacja algorytmu Bubble Sort).
* **Trwały zapis (I/O):** Automatyczny zapis i odczyt stanu ekwipunku z lokalnego pliku tekstowego (`ekwipunek.txt`).

## 🛠️ Technikalia i Struktura Kodu
Aplikacja została zaprojektowana z myślą o optymalizacji i stabilności działania w terminalu:
* **Struktury danych:** Wykorzystanie statycznej tablicy struktur (`struct Skin`) ze sztywnym limitem 100 elementów dla kontrolowanego zarządzania pamięcią (brak wycieków).
* **Parsowanie danych:** Zapis wartości logicznych (bool) jako `0/1` oraz konwersja tekstowych cen prosto z pliku na ułamki za pomocą funkcji `stof()`.
* **Zarządzanie buforem wejścia:** Zabezpieczony interfejs konsolowy wykorzystujący `cin.ignore()` do prawidłowego odczytu wieloczłonowych stringów funkcją `getline()`.

## 💻 Jak uruchomić?
1. Sklonuj repozytorium na swój dysk lokalny.
2. Skompiluj plik źródłowy `menedzer-skinow-cs2.cpp` w środowisku Visual Studio lub za pomocą kompilatora g++:
   ```bash
   g++ menedzer-skinow-cs2.cpp -o cs2_manager
