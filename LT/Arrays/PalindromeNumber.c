/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Author : Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 * https://leetcode.com/problems/palindrome-number/
 */

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	int rev = 0;
	int num = x;
	while (x > 0) {
		rev = rev * 10 + (x % 10);
		if (rev > num)
			return false;
		x = x/10;
	}
	return rev == num;
}

