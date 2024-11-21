# **so_long**

## **Overview**
**so_long** is a 2D grid-based game built using the MiniLibX library. The objective is to guide the player character (P) to collect all collectibles (C) and exit the map through the exit (E). The game enforces specific map design rules, and improper maps or moves result in error handling.

---

## **Features**
- **Grid-Based Movement**: The player can move up, down, left, and right using `W`, `A`, `S`, and `D` keys.
- **Collectibles**: All collectibles must be collected before accessing the exit.
- **Error Handling**: The program validates the map and the player's moves, with detailed error messages for invalid inputs or situations.
- **Flood-Fill Path Validation**: Ensures that all collectibles and exits are accessible from the player's starting position.
- **MiniLibX Rendering**: Displays the map and elements using images for a graphical interface.

---

## **Getting Started**

### **Requirements**
- A C compiler (e.g., GCC).
- The MiniLibX library.
- A Unix-like operating system (Linux or macOS).

---

### **Compiling the Game**
Run the following command in the terminal to compile the game:

```bash
make
```

---

### **Running the Game**
To start the game, execute:

```bash
./so_long <map_file.ber>
```

- Replace `<map_file.ber>` with the path to your `.ber` map file.

---

## **Game Rules**

1. **Map Requirements**:
   - The map must be a rectangle.
   - The map must be surrounded by walls (`1`).
   - The map must contain:
     - **One** player (`P`).
     - **One** exit (`E`).
     - **At least one** collectible (`C`).
   - Only valid characters are `0`, `1`, `P`, `E`, `C`, and newlines.

2. **Player Movement**:
   - Use `W`, `A`, `S`, and `D` to move the player character.
   - The player cannot move through walls (`1`).

3. **Winning Condition**:
   - Collect all collectibles (`C`) and reach the exit (`E`).

4. **Losing Condition**:
   - Improper map configurations or unreachable collectibles/exit.

---

## **Error Messages**
The game validates the input and map, providing clear error messages:

| Error Code | Description                                      |
|------------|--------------------------------------------------|
| **1**      | Wrong map file format (not `.ber`).              |
| **2**      | Invalid file descriptor.                        |
| **3**      | Empty map file.                                 |
| **4**      | Map is not valid or surrounded by walls.        |
| **5**      | Invalid characters in the map.                  |
| **6**      | Invalid number of player, exit, or collectibles.|
| **7**      | Unreachable collectibles or exit.               |
| **8**      | Map is not a rectangle.                         |

---

## **Files Overview**

- **src/**: Source code files.
- **inc/**: Header files.
- **assets/**: Game assets (e.g., `1.png`, `P.png`, etc.).
- **Makefile**: Build configuration for the game.

---

## **Controls**
| Key             | Action                |
|------------------|-----------------------|
| `W`             | Move up               |
| `A`             | Move left             |
| `S`             | Move down             |
| `D`             | Move right            |
| `Esc`           | Exit the game         |

---

## **Map Format**
The map must be saved in a `.ber` file. Example:

```
111111
1P0C1E
111111
```

- `1`: Wall.
- `0`: Walkable space.
- `P`: Player start position.
- `C`: Collectible.
- `E`: Exit.
