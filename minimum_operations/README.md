<div align="center">
<br>

![Minimum_operations.png](README-image/minimum_operations.png)

</div>


<p align="center">
<img src="https://img.shields.io/badge/-PYTHON-yellow">
<img src="https://img.shields.io/badge/-Linux-lightgrey">
<img src="https://img.shields.io/badge/-WSL-brown">
<img src="https://img.shields.io/badge/-Ubuntu%2020.04.4%20LTS-orange">
<img src="https://img.shields.io/badge/-JetBrains-blue">
<img src="https://img.shields.io/badge/-Holberton%20School-red">
<img src="https://img.shields.io/badge/License-not%20specified-brightgreen">
</p>


<h1 align="center"> Minimum Operations </h1>


<h3 align="center">
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/minimum_operations#eye-about">About</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/minimum_operations#computer-requirements">Requirements</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/minimum_operations#hammer_and_wrench-task">Task</a>
</h3>

---

<!-- ------------------------------------------------------------------------------------------------- -->

<br>
<br>

## :eye: About

<br>

<div align="center">

**`Minimum Operations`** project involves finding the minimum operations to achieve a target number.
<br>
The project demonstrates optimization techniques.
<br>
<br>
This project has been created by **[Holberton School](https://www.holbertonschool.com/about-holberton)** to enable every student to understand how optimization in `Python` works.

</div>

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :computer: Requirements

<br>

```diff

General

+ Allowed editors: vi, vim, emacs

+ All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)

+ All your files should end with a new line

+ The first line of all your files should be exactly #!/usr/bin/python3

+ A README.md file, at the root of the folder of the project, is mandatory

+ Your code should be documented

+ Your code should use the PEP 8 style (version 1.7.x)

+ All your files must be executable

```

<br>

**_Why all your files should end with a new line? See [HERE](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file/18789)_**

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :hammer_and_wrench: Task

<br>

<table align="center">
<tr>
<td>

### **`0. Minimum Operations`**

---

<br>

In a text file, there is a single character `H`. <br>
Your text editor can execute only two operations in this file: `Copy All` and `Paste`. <br>

<br>

- Given a number `n`, write a method that calculates the fewest number of operations needed to result in exactly `n` `H` characters in the file. <br>
  Be smart about how you utilize the memory!

    - Prototype: `def minOperations(n)`

    - Returns an integer

    - If `n` is impossible to achieve, return `0`

<br>

**Example**:

`n = 9`

`H` => `Copy All` => `Paste` => `HH` => `Paste` =>`HHH` => `Copy All` => `Paste` => `HHHHHH` => `Paste` => `HHHHHHHHH`

Number of operations: `6`

<br>
<br>

```python
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

<br>

```python
carrie@ubuntu:~/minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/minoperations$
```

<br>

</td>
</tr>
</table>