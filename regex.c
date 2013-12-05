/*
 * regex.c
 *
 *  Created on: 2013��12��5��
 *      Author: Lemon
 *  ������ʽ�Ĺ���
 *  ��ĸ ����ƥ�䵥����ĸ
 *  . ���� ƥ������ĵ����ַ�
 *  ^ ���� ƥ�������ַ����Ŀ�ͷ
 *  $ ���� ƥ�������ַ����Ľ�β
 *  * ���� ƥ��ǰһ���ַ���0�����߶������
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
		return 1; //����ǿ��ַ�����ֱ��ƥ������
	}
	if (regexp[1] == '*') {
		// * ��ƥ���������ַ�
		return matchstar(regexp[0], regexp + 2, text);
	}
	if (regexp[0] == '$' && regexp[1] == '\0') {
		// $ ƥ�������ַ����Ľ�β
		return *text == '\0';
	}
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)) {
		// . ƥ������ĵ����ַ���
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
