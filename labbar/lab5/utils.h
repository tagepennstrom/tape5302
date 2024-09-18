#ifndef __UTILS_H__
#define __UTILS_H__
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef union { 
int   int_value;
float float_value;
char *string_value;
char char_value;
} answer_t;

typedef bool check_func(char * str);
typedef answer_t convert_func(char * str);

extern char *strdup(const char*);
bool is_number(char *str);
bool is_float(char *str);
bool not_empty(char *str);
void clear_input_buffer(void);
answer_t make_float(char *str);
answer_t ask_question(char *question, check_func *check, convert_func *convert);
int ask_question_int(char *question); // från studium
int read_string(char *buf, int buf_siz);
char *ask_question_string(char *question);
char* ask_question_shelf(char *question);
void print(char *str);
void println(char *str);
void print_menu(void);
char ask_question_menu(char *question);
#endif

