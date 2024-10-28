<div align="center">
<br>

![Starwars_API.png](README-image/starwars_api.png)

</div>


<p align="center">
<img src="https://img.shields.io/badge/-JAVASCRIPT-yellow">
<img src="https://img.shields.io/badge/-Linux-lightgrey">
<img src="https://img.shields.io/badge/-WSL-brown">
<img src="https://img.shields.io/badge/-Ubuntu%2020.04.4%20LTS-orange">
<img src="https://img.shields.io/badge/-JetBrains-blue">
<img src="https://img.shields.io/badge/-Holberton%20School-red">
<img src="https://img.shields.io/badge/License-not%20specified-brightgreen">
</p>


<h1 align="center"> Star Wars API </h1>


<h3 align="center">
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/starwars_api#eye-about">About</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/starwars_api#computer-requirements">Requirements</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/starwars_api#keyboard-more-info">More Info</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/starwars_api#hammer_and_wrench-task">Task</a>
</h3>

---

<!-- ------------------------------------------------------------------------------------------------- -->

<br>
<br>

## :eye: About

<br>

<div align="center">

**`Star Wars API`** project is about interacting with the Star Wars API.
<br>
The project explores API requests and data handling.
<br>
<br>
This project has been created by **[Holberton School](https://www.holbertonschool.com/about-holberton)** to enable every student to understand how APIs in `Javascript` work.

</div>

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :computer: Requirements

<br>

```diff

General

+ Allowed editors: vi, vim, emacs

+ All your files will be interpreted on Ubuntu 14.04 LTS using node (version 10.14.x)

+ All your files should end with a new line

+ The first line of all your files should be exactly #!/usr/bin/node

+ A README.md file, at the root of the folder of the project, is mandatory

+ Your code should be semistandard compliant. Rules of Standard + semicolons on top. Also as reference: AirBnB style

+ All your files must be executable

+ The length of your files will be tested using wc

- You are not allowed to use var

```

<br>

**_Why all your files should end with a new line? See [HERE](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file/18789)_**

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :keyboard: More Info

<br>

### Install `Node 10`:

<br>

```bash
$ curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```

<br>
<br>

### Install `semi-standard`:

<br>

[Documentation - semi-standard](https://github.com/standard/semistandard)

<br>

```bash
$ sudo npm install semistandard --global
```

<br>
<br>

### Install `request` module and use it:

<br>

[Documentation - request](https://github.com/request/request)

<br>

```bash
$ sudo npm install request --global
$ export NODE_PATH=/usr/lib/node_modules
```

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

### :hammer_and_wrench: Task

<br>

<table align="center">
<tr>
<td>

### **`0. Star Wars Characters`**

---

<br>

- Write a script that prints all characters of a `Star Wars` movie:

    - The first positional argument passed is the Movie ID - example: `3` = “Return of the Jedi”

    - Display one character name per line **in the same order as the “characters” list in the `/films/` endpoint**

    - You must use the [Star wars API](https://swapi-api.hbtn.io/)

    - You must use the `request` module

<br>
<br>

```javascript
alexa@ubuntu:~/$ ./0-starwars_characters.js 3
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
alexa@ubuntu:~/$ 
```

<br>

</td>
</tr>
</table>