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

**Examples with the word `"Apple"`:**
- `a` →  **CORRECT** 
- `A` →  **CORRECT**
- `B` →  **INCORRECT**
- `A P` →  **CORRECT** (the game will only process the fist letter, in this case `A`)
- `O A` →  **INCORRECT** (the game will flag `O` as incorrect and will ignore `A`, the same reason as above)

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

To protect game from crashing, while using words that include spaces program will ignore each word after first space.

## Word Categories

The game automatically loads words from `.txt` files in the program directory:

### Recommended files:
- `Zwierzeta.txt` 
- `Geografia.txt` 
- `Marki.txt` 
- `Zawody.txt` 

### File format:
1 dog

2 computer

3 apple

...