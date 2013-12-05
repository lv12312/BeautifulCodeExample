/*
 * regex.c
 * Author: Lemon
 *
 *  正则表达式的规则：
 *  字母 ——匹配单个字母
 *  . —— 匹配任意的单个字符
 *  ^ —— 匹配输入字符串的开头
 *  $ —— 匹配输入字符串的结尾
 *  * —— 匹配前一个字符的0个或者多个出现
 */
#include <stdio.h>
#include <stdlib.h>
#include "regex.h"

int match(char *regexp, char *text) {
	if (regexp[0] == '^') {
		return matchhere(regexp + 1, text);
	}
	do {
		if (matchhere(regexp, text)) {
			return 1;
		}
	} while (*text++ != '\0');
	return 0;
}
int matchhere(char *regexp, char *text) {
	if (regexp[0] == '\0') {
		return 1; //如果是空字符串，直接匹配上了
	}
	if (regexp[1] == '*') {
		// * 是匹配多个任意字符
		return matchstar(regexp[0], regexp + 2, text);
	}
	if (regexp[0] == '$' && regexp[1] == '\0') {
		// $ 匹配输入字符串的结尾
		return *text == '\0';
	}
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)) {
		// . 匹配任意的单个字符，
		return matchhere(regexp + 1, text + 1);
	}
	return 0;
}
int matchstar(int c, char *regexp, char *text) {
	do {
		if (matchhere(regexp, text))
			return 1;
	} while (*text != '\0' && (*text++ == c || c == '.'));
	return 0;
}
