<div align="center">
<br>

![Count_it.png](README-image/count_it.png)

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


<h1 align="center"> Count it! </h1>


<h3 align="center">
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/count_it#eye-about">About</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/count_it#mag_right-resources">Resources</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/count_it#computer-requirements">Requirements</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/count_it#hammer_and_wrench-task">Task</a>
</h3>

---

<!-- ------------------------------------------------------------------------------------------------- -->

<br>
<br>

## :eye: About

<br>

<div align="center">

**`Count it!`** project is about counting specific elements or occurrences within data structures.
<br>
The project emphasizes efficient counting techniques.
<br>
<br>
This project has been created by **[Holberton School](https://www.holbertonschool.com/about-holberton)** to enable every student to understand how counting algorithms in `Python` work.

</div>

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :mag_right: Resources

<br>

**_Do you need some help?_**

<br>

**Read or watch:**

* [Reddit API Documentation](https://www.reddit.com/dev/api/)

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

+ Libraries imported in your Python files must be organized in alphabetical order

+ A README.md file, at the root of the folder of the project, is mandatory

+ Your code should use the PEP 8 style

+ All your files must be executable

+ The length of your files will be tested using wc

+ All your modules should have a documentation (python3 -c 'print(__import__("my_module").__doc__)')

+ You must use the Requests module for sending HTTP requests to the Reddit API

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

### **`0. Count it!`**

---

<br>

Write a **recursive function** that queries the [Reddit API](https://www.reddit.com/dev/api/), parses the title of all hot articles, and prints a sorted count of given  <br>
(case-insensitive, delimited by spaces. `Javascript` should count as `javascript`, but `java` should not).

<br>

- Requirements:

    - Prototype: `def count_words(subreddit, word_list)`

    - You may change the prototype, but it must be able to be called with just a subreddit supplied and a list of keywords. <br>
      AKA you can add a counter or anything else, but the function must work without supplying a starting value in the main.

    - If `word_list` contains the same word (case-insensitive), the final count should be the sum of each duplicate <br>
      (example below with `java`)

    - Results should be printed in descending order, by the count, and if the count is the same for separate keywords, they should then be sorted alphabetically (ascending, from A to Z). <br>
      Words with no matches should be skipped and not printed. <br>
      Words must be printed in lowercase.

    - Results are based on the number of times a keyword appears, not titles it appears in. <br>
      `java java java` counts as 3 separate occurrences of `java`.

    - To make life easier, `java.` or `java!` or `java_` should not count as `java`

    - If no posts match or the subreddit is invalid, print nothing.

    - Invalid subreddits may return a redirect to search results. <br>
      Ensure that you are **NOT** following redirects.

<br>

- Your code will **NOT** pass if you are using a loop and not recursively calling the function! <br>
  This /can/ be done with a loop but the point is to use a recursive function. :smiley:

<br>

:loudspeaker: **Disclaimer**:

number presented in this example cannot be accurate now - `Reddit` is hot articles are always changing.

<br>
<br>

```python
bob@dylan $ cat 0-main.py 
#!/usr/bin/python3
"""
0-main
"""
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
bob@dylan $             
```

<br>

```python
bob@dylan $ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
bob@dylan $ python3 0-main.py programming 'JavA java'
java: 54
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java'
bob@dylan $ 
```

<br>

</td>
</tr>
</table>