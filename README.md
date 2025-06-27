# Aplikacja Dziekanat

Aplikacja Dziekanat to mały projekt systemu do zarządzania danymi studentów, przedmiotów i ocen. Pozwala na wczytywanie i zapisywanie tych danych do plików CSV, a także na wykonywanie podstawowych operacji, takich jak dodawanie, usuwanie i wyszukiwanie danych.

## Główne funkcjonalności:

* **Zarządzanie studentami:** Dodawanie, usuwanie, wyszukiwanie studentów oraz generowanie dla nich unikalnych identyfikatorów. Aplikacja zlicza również przedmioty, w których uczestniczy dany student.
* **Zarządzanie przedmiotami:** Dodawanie, usuwanie, wyszukiwanie przedmiotów oraz generowanie dla nich unikalnych identyfikatorów. 
* **Zarządzanie ocenami:** Dodawanie, usuwanie i wyszukiwanie ocen.
* **Trwałe przechowywanie danych:** Wszystkie dane (studenci, przedmioty, oceny) są wczytywane z plików CSV i zapisywane do tych samych plików, co zapewnia ich trwałość.

## Pliki wejścia/wyjścia:

Aplikacja wczytuje i zapisuje dane z plików CSV. Domyślne ścieżki do tych plików są zdefiniowane w pliku `datamanager.cpp`:

* `studenci.csv` - dla danych studentów.
* `przedmioty.csv` - dla danych przedmiotów.
* `oceny.csv` - dla danych ocen.

Aby zmienić ścieżki do plików, należy zmodyfikować następujące linie w pliku `datamanager.cpp`:

* Dla studentów:
    ```cpp
    QFile plikStudentow("C:/dziekanat/studenci.csv");
    ```
* Dla przedmiotów:
    ```cpp
    QFile plikPrzedmioty("C:/dziekanat/przedmioty.csv");
    ```
* Dla ocen:
    ```cpp
    QFile plikOcen("C:/dziekanat/oceny.csv");
    ```

Należy zmodyfikować ścieżki zarówno w funkcjach zapisu jak i wczytywania (łączenie 6 funkcji).

## Wymagania i budowanie (CMake):

Projekt korzysta z systemu budowania CMake. W pliku `CMakeLists.txt` zdefiniowano następujące zależności i ustawienia:

* Wymagana wersja CMake to 3.16 lub nowsza
* Projekt jest napisany w języku C++ w standardzie C++17
* Wymaga bibliotek Qt (Widgets) w wersji 5 lub 6
* Pliki źródłowe to `main.cpp`, `mainwindow.cpp`, `mainwindow.h`, `mainwindow.ui`, `student.h`, `student.cpp`, `przedmiot.h`, `przedmiot.cpp`, `ocena.h`, `ocena.cpp`, `datamanager.h`, `datamanager.cpp`
* Obsługiwane są platformy docelowe takie jak iOS i macOS, z opcją ustawienia identyfikatora pakietu

Aby zbudować projekt, należy użyć CMake i odpowiedniego generatora (np. make, Visual Studio).
