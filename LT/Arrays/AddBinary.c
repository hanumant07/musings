/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 * https://leetcode.com/problems/add-binary/
 */

void shiftResult(char *result, int strStart)
{
	int i = 0;
	while (result[strStart] != '\0') {
		result[i] = result[strStart];
		i++;
		strStart++;
	}
	result[i] = '\0';
}

char* addBinary(char* a, char* b) {
	char *result;
	int resultVal = 0;
	int carryBit = 0;
	int pos1 = strlen(a) - 1;
	int pos2 = strlen(b) - 1;
	int resLen = strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2;
	result = malloc(sizeof(char)*resLen);
	resLen--;
	result[resLen] = '\0';
	resLen--;
	while (pos1 >= 0 && pos2 >= 0) {
		resultVal = (a[pos1] - '0' + b[pos2] - '0' + carryBit) % 2;
		carryBit = (a[pos1] - '0' + b[pos2] - '0' + carryBit) / 2;
		result[resLen] = (resultVal == 0 ? '0' : '1');
		pos1--;
		pos2--;
		resLen--;
	}
	while (pos1 >= 0) {
		resultVal = (a[pos1] - '0' + carryBit) % 2;
		carryBit = (a[pos1] - '0' + carryBit) / 2;
		result[resLen] = (resultVal == 0 ? '0' : '1');
		pos1--;
		resLen--;
	}
	while (pos2 >= 0) {
		resultVal = (b[pos2] - '0' + carryBit) % 2;
		carryBit = (b[pos2] - '0' + carryBit) / 2;
		result[resLen] = (resultVal == 0 ? '0' : '1');
		pos2--;
		resLen--;
	}
	if (carryBit != 0) {
		result[resLen] = '1';
		resLen--;
	}
	if (resLen >= 0)
		shiftResult(result, resLen + 1);
	return result;
}
