<img  height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/resources/images/logo-holberton_school.png" alt="Holberton School logo">

# Lockboxes

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

In this project, you have several locked boxes, each containing keys to other boxes. The first box (box 0) is unlocked, and you can use the keys inside to open more boxes. For example, if box 1 contains the key to box 2, that means box 2 can now be opened. You continue using the keys found in each box to unlock as many boxes as possible. The goal is to determine if all the boxes can be opened. If you can open every box, the function returns True; otherwise, it returns False.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- How to understand and implement an algorithm that solves the Lockboxes problem.
- How to write Python code that adheres to best practices, including following PEP8 style guidelines.
- How to analyze the problem requirements and translate them into working, functional code.
- How to ensure that the solution is efficient and capable of handling various edge cases.

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

You have `n` number of locked boxes in front of you. Each box is numbered sequentially from `0` to `n - 1` and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

- Prototype: `def canUnlockAll(boxes)`.
- `boxes` is a list of lists.
- A key with the same number as a box opens that box.
- You can assume all keys will be positive integers:
    - There can be keys that do not have boxes.
- The first box `boxes[0]` is unlocked.
- Return `True` if all boxes can be opened, else return `False`.

```
carrie@ubuntu:~/lockboxes$ cat 0-main.py
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

carrie@ubuntu:~/lockboxes$
```

```
carrie@ubuntu:~/lockboxes$ ./0-main.py
True
True
False
carrie@ubuntu:~/lockboxes$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `lockboxes`.
- File: `0-lockboxes.py`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/PYTHON-3776ab?logo=python&logoColor=white&style=for-the-badge" alt="Python badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**         | **DESCRIPTION**                                                                |
| :-----------:    | ------------------------------------------------------------------------------ |
| `0-lockboxes.py` | Python script that solves the Lockboxes problem.                               |
| `README.md`      | The readme file you are currently reading 😉.                                  |
| `0-main.py`      | Sample main program to test the `canUnlockAll` function with different inputs. |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Installation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned  and go in the `lockboxes` folder.

**How to use:**

1. To test the function, run the `0-main.py` file with the following command:

```
./0-main.py
```

or:

```
python3 0-main.py
```

3. You can modify the `0-main.py` script with your own test cases if you want.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
