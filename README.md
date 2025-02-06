# Secured - Elementary Programming in C

## Project Overview

Secured is a project focused on implementing hash tables in C, serving as an introduction to data structures and hashing techniques. The goal is to create a secure storage system for important data, such as robot blueprints, by developing a custom hash function and handling collisions effectively.
Features

    Custom hash function implementation
    Creation and management of hash tables
    Support for insertion, deletion, and searching of key-value pairs
    Collision handling using separate chaining
    Implementation of a library (libhashtable.a)

## Installation

To build the project, use the provided Makefile:

    make

To clean up object files:

    make clean

To remove compiled binaries and object files:

    make fclean

## Usage

Creating a Hash Table

    hashtable_t *ht = new_hashtable(&hash, 10);

Inserting Data

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");

Searching for Data

    char *value = ht_search(ht, "Vision");
    printf("Value: %s\n", value);

Deleting Data

    ht_delete(ht, "Vision");

Dumping the Hash Table

    ht_dump(ht);

## File Structure

    src/ - Contains source code for the hash table functions
    include/ - Header files
    Makefile - Compilation rules
    lib/ - Compiled static library (libhashtable.a)

## Compilation Rules

    The project is compiled with Makefile
    Uses only write, malloc, free as authorized functions
    The executable should return 84 on errors

## Requirements

    C Compiler (gcc/clang)
    Make

## License

This project is developed as part of **the Elementary Programming** in C module at **Epitech**.
