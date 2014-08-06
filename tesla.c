#include "tesla.h"

int does_match_regex(uchar *mac, const char *regex) {
	regex_t mac_regex;
	int reti;
	reti = regcomp(&mac_regex, regex, 0);
	if (reti) {
		fprintf(stderr, "[!] Regular expression: %s failed to compile! Please check your regex syntax and not the this program uses POSIX regexes\n", regex);
		exit(1);
	}
	reti = regexec(&mac_regex, (const char*)mac, 0, NULL, 0);
	if (reti == REG_NOMATCH) return 0;
	return 1;
}

