# Racingame

Gioco arcade in **console** scritto in **C++**: guidi la macchina su una strada, eviti gli ostacoli e raccogli monete per fare punti. Progetto sviluppato con **Visual Studio** (Windows).

## Obiettivo

Restare in pista il più a lungo possibile accumulando punti. Se il punteggio scende a zero, la partita termina (**game over**).

## Gameplay

La schermata mostra:

- la **strada** (mappa)
- la **macchina del giocatore** (`^`)
- **ostacoli** generati dinamicamente

| Elemento | Simbolo | Effetto |
|----------|---------|---------|
| Moneta | `@` | Aumenta i punti se raccolta |
| Bomba | `+` | Può esplodere e farti perdere punti |
| Auto nemica | `8` | Arriva dal verso opposto; collisione = penalità |

### Livelli e difficoltà

- Più punti accumuli, più **sale il livello** (circa ogni 100 punti).
- Salendo di livello aumenta il numero massimo di ostacoli sulla strada.
- Se perdi punti e scendi sotto certe soglie, il **livello diminuisce**.
- All’avvio puoi scegliere una delle **tre gare** (Race 1, 2 o 3), con difficoltà crescente.

## Comandi

| Tasto | Azione |
|-------|--------|
| **Freccia sinistra / destra** | Sposta la macchina |
| **Freccia su / giù** | Naviga nel menu gare |
| **Invio** | Conferma la scelta |
| **Qualsiasi tasto** | Prosegue dalla schermata titolo |

## Requisiti

- **Windows** (usa API console: `Windows.h`, `conio.h`)
- **Visual Studio** con workload “Sviluppo di applicazioni desktop con C++”
- Solution: `racingame.sln`

## Compilazione ed esecuzione

1. Apri `racingame.sln` in Visual Studio.
2. Se manca il file di progetto `.vcxproj`, ricrea un progetto **Console App (C++)** nella cartella `racingame/` e aggiungi i sorgenti `.cpp` / `.hpp` (in repo è presente `racingame.vcxproj.filters` come riferimento).
3. Seleziona configurazione **Debug** o **Release** (x86 o x64).
4. **Build → Build Solution**, poi avvia con **Debug → Start Without Debugging**.

L’eseguibile non è incluso nel repository: va generato in locale.

## Struttura del codice

| File | Ruolo |
|------|--------|
| `main.cpp` | Entry point, titolo e loop partite |
| `intro.cpp` / `intro.hpp` | Titolo e menu delle tre gare |
| `engine.cpp` / `engine.hpp` | Logica di gioco, livelli, input |
| `track.cpp` / `track.hpp` | Mappa / strada |
| `car.cpp` / `car.hpp` | Macchina del giocatore |
| `enemy.cpp`, `bomb.cpp`, `coins.cpp` | Tipi di ostacolo |
| `lists.cpp` / `lists.hpp` | Liste collegate per ostacoli |
| `obstacle.cpp`, `basic.cpp` | Classi base e utilità |

## Licenza

Codice pubblicato a scopo didattico/portfolio. Per riutilizzo o redistribuzione, contatta l’autore del repository.
