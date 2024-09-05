#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>

void clear_input_buffer(void);
int ask_question_int(char *question);
int read_string(char *buf, int buf_siz);
char *ask_question_string(char *question, char *buf, int buf_siz);
#endif

