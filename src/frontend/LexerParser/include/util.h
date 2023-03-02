/*
    Lexer and Parser's util header of the Cobalt Compiler
    Copyright (C) 2023  Andy Shen

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef LP_UTIL_H
#define LP_UTIL_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* C_string;
C_string C_String(char* s);

typedef char C_bool;
#define TRUE 1
#define FALSE 0

/* Some macros for this project */
#define LP_DEBUG 1

void* checked_malloc(int);
#endif
