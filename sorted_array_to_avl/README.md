<div align="center">
<br>

![Array_to_AVL.png](README-image/array_to_avl.png)

</div>


<p align="center">
<img src="https://img.shields.io/badge/-C-yellow">
<img src="https://img.shields.io/badge/-Linux-lightgrey">
<img src="https://img.shields.io/badge/-WSL-brown">
<img src="https://img.shields.io/badge/-Ubuntu%2020.04.4%20LTS-orange">
<img src="https://img.shields.io/badge/-JetBrains-blue">
<img src="https://img.shields.io/badge/-Holberton%20School-red">
<img src="https://img.shields.io/badge/License-not%20specified-brightgreen">
</p>


<h1 align="center"> Array to AVL </h1>


<h3 align="center">
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/sorted_array_to_avl#eye-about">About</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/sorted_array_to_avl#computer-requirements">Requirements</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/sorted_array_to_avl#keyboard-more-info">More Info</a> •
<a href="https://github.com/RazikaBengana/holbertonschool-interview/tree/main/sorted_array_to_avl#hammer_and_wrench-task">Task</a>
</h3>

---

<!-- ------------------------------------------------------------------------------------------------- -->

<br>
<br>

## :eye: About

<br>

<div align="center">

**`Array to AVL`** project involves converting a sorted array into an AVL tree.
<br>
The project demonstrates tree construction and balancing.
<br>
<br>
This project has been created by **[Holberton School](https://www.holbertonschool.com/about-holberton)** to enable every student to understand how tree construction in `C` works.

</div>

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :computer: Requirements

<br>

```diff

General

+ Allowed editors: vi, vim, emacs

+ All your files will be compiled on Ubuntu 14.04 LTS

+ Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

+ All your files should end with a new line

+ A README.md file, at the root of the folder of the project, is mandatory

+ Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

- You are not allowed to use global variables

+ No more than 5 functions per file

+ You are allowed to use the standard library

+ In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples

+ The prototypes of all your functions should be included in your header file called binary_trees.h

+ Don’t forget to push your header file

+ All your header files should be include guarded

```

<br>

**_Why all your files should end with a new line? See [HERE](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file/18789)_**

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

## :keyboard: More Info

<br>

### Data structures:

<br>

Please use the following data structures and types for `binary trees`. <br>
Don’t forget to include them in your header file:

<br>

#### Basic Binary Tree:

<br>

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

<br>
<br>

#### AVL Tree:

<br>

```c
typedef struct binary_tree_s avl_t;
```

<br>
<br>

#### Print function:

<br>

- To match the examples in the tasks, you are given [this function](https://github.com/hs-hq/0x1C.c).

    - This function is used only for visualisation purpose. <br>
      You don’t have to push it to your repo. <br>
      It may not be used during the correction.

<br>
<br>

<!-- ------------------------------------------------------------------------------------------------- -->

### :hammer_and_wrench: Task

<br>

<table align="center">
<tr>
<td>

### **`0. AVL - From sorted array`**

---

<br>

- Write a function that builds an `AVL tree` from an array

    - Prototype: `avl_t *sorted_array_to_avl(int *array, size_t size);`

    - Where `array` is a pointer to the first element of the array to be converted

    - And `size` is the number of element in the array

    - Your function must return a pointer to the root node of the created AVL tree, or `NULL` on failure

    - You can assume there will be no duplicate value in the array

    - You are not allowed to rotate

    - You can only have **3 functions** in your file

<br>
<br>

```c
alex@~/sorted_array_to_avl$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; ++i)
        printf("(%03d)", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
        1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
        79, 84, 87, 91, 95, 98
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = sorted_array_to_avl(array, n);
    if (!tree)
        return (1);
    print_array(array, n);
    binary_tree_print(tree);
    return (0);
}
```

<br>

```c
alex@~/sorted_array_to_avl$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
alex@~/sorted_array_to_avl$ ./0-sorted_array_to_avl
(001)(002)(020)(021)(022)(032)(034)(047)(062)(068)(079)(084)(087)(091)(095)(098)
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
alex@~/sorted_array_to_avl$
```

<br>

</td>
</tr>
</table>