#ifndef LIBS_H
#define LIBS_H

#define MAX_INPUT 1024
#define MAX_ARGS 10
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>

void prompt(void);
void read_input(char *input);
void parse_input(char *, char **);
void execute_command(char *command, char **args);
void sigint_handler(int sig);
void sigquit_handler(int sig);
void _puts(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *find_path();
char *_combine_path(const char *s1, const char *s2);
char **split(char *path, char *del);
int run_cmd(char *line);
char *_strdup(char *str);
int cmd_helper(char **pathsp, char **splitted);
void free_2d_array(char **ptr);
int exit_status(int action, int new_status);
void my_exit(char *input, char *command);
void env(void);

int _printf(int fd, const char *format, ...);
int _putchar(int fd, char c);
int _print_string(int fd, char *s);
int _strlen(char *s);
int _strlenc(const char *s);
int _print_int(int fd, int num);
int _print_unsigned_int(int fd, unsigned int num);

#endif
