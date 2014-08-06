#define TESLA

#include <regex.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define uchar unsigned char

int does_match_regex(uchar *mac, const char *regex);