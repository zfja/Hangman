#  Hangman Game - Console Edition

Console implementation of the classic Hangman game in C++ with object-oriented design and multiplayer support.

##  Features

- **Multiple Game Modes:**
  - Single Player (vs computer with word categories)
  - Multiplayer (PvP with custom words)
  
- **Advanced Gameplay:**
  - Real-time ASCII art visualization
  - Points system with streaks
  - Player statistics tracking
  - Multiple word categories

- **Technical Implementation:**
  - Object-oriented architecture with inheritance and polymorphism
  - Dynamic word category loading from `.txt` configuration files
  - Clean, responsive console-based user interface
  - Case-insensitive input processing (all letters normalized to uppercase)
  - **Full-word guess support** in addition to single-letter guessing

**Examples with the word `"Apple"`:**
- `a` →  **CORRECT** 
- `A` →  **CORRECT**
- `B` →  **INCORRECT**
- `apple` →  **CORRECT** 
- `APPLE` →  **CORRECT** 
- `ApPlE` →  **CORRECT** 
- `apply` →  **PARTIALLY CORRECT** (While `y` is flagged as incorrect, all other letters in the guess are validated as correct.)

## IMPORTANT: Word Input Restriction

### **CRITICAL LIMITATION:**
The program **CANNOT HANDLE WORDS WITH SPACES** and will crash if you try to use them!

### ✅ **Allowed:**
- `dog`
- `computer`
- `apple`
- `pizza`

### ❌ **NOT Allowed (will crash):**
- `new york` 
- `ice cream` 
- `san francisco` 
- `happy birthday` 

**Always use single words without spaces when playing!**

## Word Categories

The game automatically loads words from `.txt` files in the program directory:

### Recommended files:
- `zwierzeta.txt` 
- `geografia.txt` 
- `marki.txt` 
- `zawody.txt` 

### File format:
1 dog
2 computer
3 apple
...
