<img height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/assets/images/logo-holberton_school.png" alt="Holberton School logo">

# Making Change

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

This project implements a solution to the Making Change problem, where the goal is to determine the minimum number of coins required to reach a specific total using given coin denominations. The solution employs dynamic programming techniques to efficiently handle various inputs.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- How to solve the coin change problem using dynamic programming.
- How to optimize the solution for better time complexity.
- How to handle edge cases when implementing dynamic programming solutions.

## 📋 <span id="requirements">Requirements</span>

- All my files should end with a new line.
- The first line of all my files should be exactly `#!/usr/bin/python3`.
- A `README.md` file, at the root of the folder of the project, is mandatory.
- My code should be documented.
- My code should use the PEP 8 style (version 1.7.x).
- All my files must be executable.

## 📝 <span id="instructions">Instructions</span>

<details>
    <summary>
        <b>0. Change comes from within</b>
    </summary>
    <br>

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount `total`.

- Prototype: `def makeChange(coins, total)`.
- Return: fewest number of coins needed to meet `total`.
    - If total is 0 or less, return `0`.
    - If total cannot be met by any number of coins you have, return `-1`.
- `coins` is a list of the values of the coins in your possession.
- The value of a coin will always be an integer greater than 0.
- You can assume you have an infinite number of each denomination of coin in the list.
- Your solution’s runtime will be evaluated in this task.

```
carrie@ubuntu:~/making_change$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([1256, 54, 48, 16, 102], 1453))

carrie@ubuntu:~/making_change$
```

```
carrie@ubuntu:~/making_change$ ./0-main.py
7
-1
carrie@ubuntu:~/making_change$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `making_change`.
- File: `0-making_change.py`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
        <img src="https://img.shields.io/badge/PYTHON-3776ab?logo=python&logoColor=white&style=for-the-badge" alt="Python badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**             | **DESCRIPTION**                                        |
| :------------------: | ------------------------------------------------------ |
| `0-making_change.py` | Python module implementing the Making Change solution. | 
| `0-main.py`          | Example testing file.                                  |
| `README.md`          | The readme file you are currently reading 😉.          |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Installation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

``` bash
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned.

3. Ensure Python files are executable:

``` bash
chmod 777 0-making_change.py 0-main.py
```

**How to use:**

1. Run the provided test file:

``` bash
./0-main.py
```

2. You can modify the `0-main.py` script with your own test cases if you want.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
