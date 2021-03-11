/*
Program to implement a Caesar Cipher
***************************************************************
* Author	Dept		Date		Notes
***************************************************************
* Belle P	Science		Feb 19 2020 	Iinitial version
* Belle P	Science		Feb 19 2020	Added '/0' at end of array
* Belle P	Science		Feb 20 2020	Addition of 26 instea of 'a'
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char line[100], letter;
	if (argc==2) {
		int key=atoi(argv[1]);
		if (abs(key)>26) {
			key=key%26;
		}
		while (fgets(line, 200, stdin)) {
			//int key=atoi(argv[0]);
			int i, len;
			len=strlen(line);
			char new[100]={'\0'};
			line[len]='\0';
			for (i=0;i<len;i++) {
				letter=line[i];
				if (letter!=EOF) {
					if (letter>96 && letter<123) {
						if ((letter+key)<'a') {
							new[i]=letter+key+26;
						}
						else if ((letter+key)>'z') {
							new[i]=letter+key-26;
						}
						else {
							new[i]=letter+key;
						}
					}
					else {
						new[i]=letter;
					}
				}
			}
		printf("%s", new);
		}
		return 0;
	}
	else {
		puts("Error: usage is caesarcipher <offset>\n");
		return 1;
	}
}
