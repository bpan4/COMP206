/*
***************************************************************
* Author        Dept            Date            Notes
***************************************************************
* Belle P       Science         Mar 9  2020     Iinitial version
* Belle P       Science		Mar 10 2020	Debugged, fixed several indexing issues
* Belle P       Science		Mar 11 2020	Debugged, made separate functions
* Belle P	Science		Mar 12 2020	Final debugging, fixed issue with findacc logic
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findacc(char *accnum){
	FILE *read = fopen("bankdata.csv", "r");
	char buf[100];
	fgets(buf,99,read);
	while(!feof(read)){
		if(strstr(buf,accnum)!=0){
			return(0);
		}
		fgets(buf,99,read);
	}
	fclose(read);
	return(1);
}

void add(char *accnum, char *name) {
	FILE *data = fopen("bankdata.csv","a+");
	if (findacc(accnum)==0){
		fprintf(stderr, "Error,account number %s already exists\n", accnum);
		exit(50);
	}
	fprintf(data,"AC,%s,%s\n",accnum,name);
	fclose(data);
}

void deposit(char *accnum, char *date, char *amount){
	FILE *data = fopen("bankdata.csv","a+");
	if (findacc(accnum)!=0){
		fprintf(stderr, "Error, account number %s does not exist\n", accnum);
                exit(50);
	}
	float deposit_amount = strtof(amount,NULL);
	fprintf(data,"TX,%s,%s,%.2f\n",accnum,date,deposit_amount);
        fclose(data);
}

void withdrawal(char *accnum, char *date, char *amount){
	FILE *data = fopen("bankdata.csv", "a+");
	float sum=0;
	if(findacc(accnum)!=0){
		fprintf(stderr,"Error, account number %s does not exist\n",accnum);
		exit(50);
	}
	char buf[100];
	fgets(buf,99,data);
	//printf("buf1: %s\n", buf);
	while(!feof(data)){
		char *tmp = strtok(buf,",");
		if(strcmp(tmp,"TX")==0){
			tmp = strtok(NULL,",");
			if(strcmp(tmp,accnum)==0){
				strtok(NULL,",");
				float amount1 = strtof(strtok(NULL,","),NULL);
				//printf("amount1: %f\n",amount1);
				//printf("og sum: %f\n",sum);
				sum = sum + amount1;
				//printf("new sum: %f\n",sum);
			}
		}
		fgets(buf,99,data);
		//printf("bufs: %s\n", buf);
	}
	float withdraw=strtof(amount,NULL);
	if((sum-withdraw)<0){
		fprintf(stderr,"Error, account number %s has only %.2f\n",accnum,sum);
		exit(60);
	}
	sum = sum - withdraw;
	fprintf(data,"TX,%s,%s,-%.2f\n",accnum,date,withdraw);
	fclose(data);
}

void main(int argc, char *argv[]){
	FILE *opendata = fopen("bankdata.csv", "r");
	if (opendata == NULL) {
		fprintf(stderr, "Error, unable to locate the data file bankdata.csv\n");
		exit(100);
	}
	fclose(opendata);
	FILE *data = fopen("bankdata.csv", "a+");
	if (argc==1){
		fprintf(stderr, "Error, incorrect usage!\n -a ACCTNUM NAME\n -d ACCTNUM DATE AMOUNT\n -w ACCNUM DATE AMOUNT\n");
                exit(1);
	}
	fclose(data);
	if (strcmp(argv[1], "-a")==0){
		if (argc<4){
			fprintf(stderr, "Error, incorrect usage! \n -a ACCTNUM NAME\n");
                        exit(1);
		}
		add(argv[2],argv[3]);
	}
	else if (strcmp(argv[1], "-d")==0){
		if (argc<5){
			fprintf(stderr, "Error, incorrect usage! \n -d ACCTNUM DATE AMOUNT\n");
                        exit(1);
		}
		deposit(argv[2],argv[3],argv[4]);
	}
	else if (strcmp(argv[1], "-w")==0)
	{
		if (argc<5)
		{
			fprintf(stderr, "Error, incorrect usage!\n -w ACCNUM DATE AMOUNT\n");
			exit(1);
		}
		withdrawal(argv[2], argv[3], argv[4]);
	}
	else
	{
		fprintf(stderr, "Error, incorrect usage!\n -a ACCTNUM NAME\n -d ACCTNUM DATE AMOUNT\n -w ACCNUM DATE AMOUNT\n");
		exit(1);
	}
	exit(0);
}
