<img height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/assets/images/logo-holberton_school.png" alt="Holberton School logo">

# UTF-8 Validation

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

This project focuses on creating a Python module to validate whether a given data set represents a valid UTF-8 encoding. UTF-8 is a variable-width character encoding used for electronic communication, where each character can be represented by 1 to 4 bytes.

The module verifies that all sequences of bytes adhere to UTF-8 encoding rules and detects invalid encodings.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- What UTF-8 is and why it’s used.
- How UTF-8 encodes characters in 1 to 4 bytes.
- How to detect invalid sequences in a UTF-8 encoding.
- How to manipulate bits in Python to check byte patterns.
- Implementing an efficient algorithm to validate UTF-8 sequences.

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
        <b>0. UTF-8 Validation</b>
    </summary>
    <br>

Write a method that determines if a given data set represents a valid UTF-8 encoding.

- Prototype: `def validUTF8(data)`.
- Return: `True` if data is a valid UTF-8 encoding, else return `False`.
- A character in UTF-8 can be 1 to 4 bytes long.
- The data set can contain multiple characters.
- The data will be represented by a list of integers.
- Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer.

```
carrie@ubuntu:~/utf8_validation$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))

carrie@ubuntu:~/utf8_validation$
```

```
carrie@ubuntu:~/utf8_validation$ ./0-main.py
True
True
False
carrie@ubuntu:~/utf8_validation$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `utf8_validation`.
- File: `0-validate_utf8.py`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/PYTHON-3776ab?logo=python&logoColor=white&style=for-the-badge" alt="Python badge">
    <img src="https://img.shields.io/badge/GIT-f05032?logo=git&logoColor=white&style=for-the-badge" alt="Git badge">
    <img src="https://img.shields.io/badge/GITHUB-181717?logo=github&logoColor=white&style=for-the-badge" alt="GitHub badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**             | **DESCRIPTION**                                                             |
| :------------------: | --------------------------------------------------------------------------- |
| `0-validate_utf8.py` | The main Python file containing the validation logic.                       | 
| `0-main.py`          | Sample main program to test the `validUTF8` function with different inputs. |
| `README.md`          | The readme file you are currently reading 😉.                               |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Instalation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned.

3. Navigate to the `utf8_validation` directory:

```
cd utf8_validation
```

4. Ensure the files are executable:

```
chmod 777 0-validate_utf8.py.py 0-main.py
```

**How to use:**

1. To test the function, run the `0-main.py` file with the following command:

```
./0-main.py
```

2. You can modify the `0-main.py` script with your own test cases if you want.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
