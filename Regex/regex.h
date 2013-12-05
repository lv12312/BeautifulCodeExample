#ifndef REGEX_H_
#define REGEX_H_

int match(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);
int matchhere(char *regexp, char *text);
#endif /* REGEX_H_ */
