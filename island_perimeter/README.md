<img  height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/resources/images/logo-holberton_school.png" alt="Holberton School logo">

# Island Perimeter

## 🔖 Table of contents

<details>
        <summary>
        CLICK TO ENLARGE 😇
        </summary>
        📄 <a href="#description">Description</a>
        <br>
        🎓 <a href="#objectives">Objectives</a>
        <br>
        📋 <a href="#requirements">Requirements</a>
        <br>
        📝 <a href="#instructions">Instructions</a>
        <br>
        🔨 <a href="#tech-stack">Tech stack</a>
        <br>
        📂 <a href="#files-description">Files description</a>
        <br>
        💻 <a href="#installation_and_how_to_use">Installation and how to use</a>
        <br>
        ♥️ <a href="#thanks">Thanks</a>
        <br>
        👷 <a href="#authors">Authors</a>
</details>

## 📄 <span id="description">Description</span>

This project focuses on creating a function `island_perimeter(grid)` that calculates the perimeter of an island represented in a 2D grid. The function adheres to specific constraints:

- Land is represented by `1`, and water is represented by `0`.
- The grid is surrounded by water and contains no lakes (internal water that is completely enclosed by land).

This exercise is a common problem in algorithmic challenges, useful for understanding grid traversal, edge cases, and geometric logic in a discrete space.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- How to traverse a 2D grid to analyze data (like land and water).
- How to calculate the perimeter of an island based on adjacent cells.
- How to handle edge cases in a grid-based problem.
- Why subtracting shared edges between land cells is necessary for perimeter calculation.
- How to write clean, modular, and `PEP8` compliant Python code.

## 📋 <span id="requirements">Requirements</span>

- All your files should end with a new line.
- The first line of all your files should be exactly `#!/usr/bin/python3`.
- A `README.md` file, at the root of the folder of the project, is mandatory.
- Your code should use the `PEP 8` style (version 1.7).
- You are not allowed to import any module.
- All modules and functions must be documented.
- All your files must be executable.

## 📝 <span id="instructions">Instructions</span>

<details>
    <summary>
        <b>0. Island Perimeter</b>
    </summary>
    <br>

Create a function `def island_perimeter(grid):` that returns the perimeter of the island described in `grid`:

- `grid` is a list of list of integers:
    - 0 represents water.
    - 1 represents land.
    - Each cell is square, with a side length of 1.
    - Cells are connected horizontally/vertically (not diagonally).
    - `grid` is rectangular, with its width and height not exceeding 100.
- The grid is completely surrounded by water.
- There is only one island (or nothing).
- The island doesn’t have “lakes” (water inside that isn’t connected to the water surrounding the island).

```
guillaume@ubuntu:~/$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = __import__('0-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))

guillaume@ubuntu:~/$ 
guillaume@ubuntu:~/$ ./0-main.py
12
guillaume@ubuntu:~/$ 
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `island_perimeter`.
- File: `0-island_perimeter.py`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/PYTHON-3776ab?logo=python&logoColor=white&style=for-the-badge" alt="Python badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**                | **DESCRIPTION**                                           |
| :---------------------: | --------------------------------------------------------- |
| `0-island_perimeter.py` | Contains the function `island_perimeter(grid)`.           | 
| `0-main.py`             | Example script to test the `island_perimeter` function.   |
| `README.md`             | The readme file you are currently reading 😉.             |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Installation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned.

3. Navigate to the `island_perimeter` directory:

```
cd island_perimeter
```

4. Ensure the files are executable:

```
chmod 777 0-island_perimeter.py 0-main.py
```

**How to use:**

1. Run the `0-main.py` file to test the island_perimeter function:

```
./0-main.py
```

2. Modify the grid in `0-main.py` to test with different scenarios.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
