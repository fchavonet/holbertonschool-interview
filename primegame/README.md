<img height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/assets/images/logo-holberton_school.png" alt="Holberton School logo">

# Prime Game

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

This project implements a strategic game between two players, Maria and Ben, involving prime numbers and optimal game theory. The game is played on a set of consecutive integers starting from `1` up to and including `n`. Players take turns choosing a prime number from the set and removing that number along with all its multiples from the set. The player who cannot make a move loses the game.

The challenge is to determine the winner across multiple rounds of the game, where each round may have a different value of `n`, assuming both players play optimally and Maria always goes first.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- How to implement the Sieve of Eratosthenes algorithm to efficiently find prime numbers.
- Game theory concepts and how to determine optimal strategies.
- How to analyze multiple game rounds and determine the overall winner.
- The relationship between prime numbers and game theory in competitive scenarios.
- How to optimize algorithms for performance within given constraints.

## 📋 <span id="requirements">Requirements</span>

- All my files should end with a new line.
- The first line of all my files should be exactly `#!/usr/bin/python3`.
- A `README.md` file, at the root of the folder of the project, is mandatory.
- My code should be documented.
- My code should use the `PEP 8` style (version 1.7.x).
- All my files must be executable.

## 📝 <span id="instructions">Instructions</span>

<details>
    <summary>
        <b>0. Prime Game</b>
    </summary>
    <br>

Maria and Ben are playing a game. Given a set of consecutive integers starting from `1` up to and including `n`, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

They play `x` rounds of the game, where `n` may be different for each round. Assuming Maria always goes first and both players play optimally, determine who the winner of each game is.

- Prototype: `def isWinner(x, nums)`.
- where x is the number of rounds and `nums` is an array of `n`.
- Return: name of the player that won the most rounds.
- If the winner cannot be determined, return `None`.
- You can assume `n` and `x` will not be larger than 10000.
- You cannot import any packages in this task.

Example:

- `x` = `3`, `nums` = `[4, 5, 1]`.

First round: `4`

- Maria picks 2 and removes 2, 4, leaving 1, 3.
- Ben picks 3 and removes 3, leaving 1.
- Ben wins because there are no prime numbers left for Maria to choose.

Second round: `5`

- Maria picks 2 and removes 2, 4, leaving 1, 3, 5.
- Ben picks 3 and removes 3, leaving 1, 5.
- Maria picks 5 and removes 5, leaving 1.
- Maria wins because there are no prime numbers left for Ben to choose.

Third round: `1`

- Ben wins because there are no prime numbers for Maria to choose

**Result: Ben has the most wins!**

```bash
carrie@ubuntu:~/primegame$ cat main_0.py
#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

carrie@ubuntu:~/primegame$
```

```bash
carrie@ubuntu:~/primegame$ ./main_0.py
Winner: Ben
carrie@ubuntu:~/primegame$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `primegame`.
- File: `0-prime_game.py`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/PYTHON-3776ab?logo=python&logoColor=white&style=for-the-badge" alt="Python badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**          | **DESCRIPTION**                                                               |
| :---------------: | ----------------------------------------------------------------------------- |
| `0-prime_game.py` | Python script that implements the prime game logic and determines the winner. |
| `0-main.py`       | Sample main program to test the isWinner function with different inputs.      |
| `README.md`       | The README file you are currently reading 😉.                                 |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Installation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```bash
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned.

3. Navigate to the `primegame` directory:

```bash
cd primegame
```

4. Ensure the files are executable:

```bash
chmod 777 0-prime_game.py main_0.py
```

**How to use:**

1. To test the function, run the `main_0.py` file with the following command:

```bash
./main_0.py
```

You can modify the `main_0.py` script with your own test cases by changing the parameters passed to the isWinner function.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
