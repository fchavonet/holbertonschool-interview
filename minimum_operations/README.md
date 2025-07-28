<img height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/assets/images/logo-holberton_school.png" alt="Holberton School logo">

# Minimum Operations

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

In this project, we tackle a classic algorithmic challenge: determining the minimum number of operations required to achieve a specific number of characters in a text file using only two operations: `Copy All` and `Paste`.
The problem starts with a single character `H` and asks for the minimal sequence of operations to reach exactly `n` `H` characters.
This task emphasizes efficient algorithm design and optimization techniques.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- How to understand and implement an efficient algorithm to solve the Minimum Operations problem.
- The significance of prime factorization in optimizing the sequence of copy and paste operations.
- How to write clean, well-documented Python code adhering to PEP 8 style guidelines.
- How to analyze problem requirements and translate them into functional code.
- How to handle edge cases and ensure the solution is robust and efficient.

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
        <b>0. Lockboxes</b>
    </summary>
    <br>

In a text file, there is a single character `H`. Your text editor can execute only two operations in this file: `Copy All` and `Paste`. Given a number `n`, write a method that calculates the fewest number of operations needed to result in exactly `n` `H` characters in the file. Be smart about how you utilize the memory!

- Prototype: `def minOperations(n)`.
- Returns an integer.
- If n is impossible to achieve, return `0`.

**Example:**

`n = 9`

`H` => `Copy All` => `Paste` => `HH` => `Paste` => `HHH`=> `Copy All` => `Paste` => `HHHHHH` => `Paste` => `HHHHHHHHH`

Number of operations: `6`

```
carrie@ubuntu:~/minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

carrie@ubuntu:~/minoperations$
```

```
carrie@ubuntu:~/minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/minoperations$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `minimum_operations`.
- File: `0-minoperations.py`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/PYTHON-3776ab?logo=python&logoColor=white&style=for-the-badge" alt="Python badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**         | **DESCRIPTION**                                                                     |
| :-----------:    | ----------------------------------------------------------------------------------- |
| `0-lockboxes.py` | Python script that calculates the minimum operations to reach `n` `H` characters.   |
| `0-main.py`      | Sample main program to test the `minOperations` function with different inputs.     |
| `README.md`      | The readme file you are currently reading 😉.                                       |

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

3. Navigate to the `minimum_operations` directory:

```
cd minimum_operations
```

4. Ensure the files are executable:

```
chmod 777 0-minoperations.py 0-main.py
```

**How to use:**

1. To test the function, run the `0-main.py` file with the following command:

```
./0-main.py
```

3. You can modify the `0-main.py` script with your own test cases if you want.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
