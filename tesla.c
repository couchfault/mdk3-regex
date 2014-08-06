#include "tesla.h"

int does_match_regex(uchar *mac, const char *regex) {
	regex_t mac_regex;
	int reti;
	reti = regcomp(&mac_regex, regex, 0);
	if (reti) {
		exit(1);
	}
	reti = regexec(&mac_regex, (const char*)mac, 0, NULL, 0);
	if (reti == REG_NOMATCH) return 0;
	return 1;
}

