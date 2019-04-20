#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <signal.h>


/* flag: dc91120{hows_the_rush?} */



static void sig_trp(int sig);


char key[38];
char *joke = "dc91120dc91120dc91120dc91120dc91120dc91120dc91120";
char keymap[59];
char *wrong_flag = "dc91120{%s}";
void dontstragain(char *, char *);
char * dontstr(char *, const char *);
void gen_rsa_key(char *);
void encrypt_rsa(char *);


void dontstragain(char *s, char *t)
{
    while (*t)
    {
       *s = *t;
       s++;
       t++;
    }
    *s = *t;
}

char * dontstr(char * s1, const char * s2) 
{
  int a = 0, b = 0, d;

  while (s1[a] != '\0') 
    d = a;
    while (s2[b] != '\0')
    {
      if (s1[d] != s2[b])
        break;
      d++;
      b++;
    }
    if (s2[b] == '\0')
      return (char * ) s1 + a;
    else {
      a++;
      b = 0;
    }
    return NULL;
}

void gen_rsa_key(char *cipher)
{
    int lencipher = strlen(cipher);
    int lenkey = strlen(key);
    char badword[lencipher+1];
    for(int i = 0; i < strlen(key); i++)
    {
        if(isupper(key[i]))
        {
            key[i] = tolower(key[i]);
        }
    }
    for(int i=0, j=0 ; i < lencipher; i++)
    {
        if(isalpha(cipher[i]))
        {
             
            if(isupper(cipher[i]))
            {
                
                badword[i] = (((cipher[i] - 'A') + (toupper(key[j++ % lenkey])-'A')) % 26) + 'A';
            }
            else 
            {
                badword[i] = (((cipher[i] - 'a') + (key[j++ % lenkey]-'a')) % 26) + 'a';
            }

        }
        else
        {
            badword[i] = cipher[i];
        }
    }
    badword[lencipher] = '\0';
    dontstragain(keymap,badword);
  
    //printf("flag: %s\n",badword);

}

void encrypt_rsa(char *loo)
{
    int fd,r,j=0;
    FILE *file = fopen("lookagain","r");
    char temp,line[100];
    while (fgets(line, sizeof(line), file)) {
       if (strstr(line, loo)) {
        dontstragain(key,line);
       }
    }
    remove("lookagain");
}

static void sig_trp(int sig)
{
    printf("... AND THIS IS YOUR LAST BREAKPOINT!\n");
    exit(-1);
}


int main(int argc, char *argv[])
{
	
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		printf("so you wanna trace me?...\n");
		return(-1);
	}
    if(signal(SIGTRAP, sig_trp) == SIG_ERR) {
        perror("signal");
        exit(-1);
    }
    sleep(4);
    puts("Welcome To The Uncrackable Software!!!");
    puts("make a keygen and get rewarded!....");
    char flag[59] = "bf91120{vmcd_hie_csva?}";
    char c;
    int fSeekNum = 0;
    int printNum = 0;
    FILE * sfile = fopen(argv[0], "rb");
    FILE * dontlook = fopen("lookagain", "w");
    if (sfile == NULL) {
        printf("The file you input was not in the working directory or was not found");
        return 0;
        fseek(sfile, 0, SEEK_SET);
    }
    while (!feof(sfile)) {
        fread( & c, 1, 1, sfile);
        if (c >= 32 && c <= 126) {
            printNum++;
        } else if (printNum >= 3) {
            fSeekNum = 0 - printNum;
            fseek(sfile, fSeekNum, SEEK_CUR);
            while (printNum > 0) {
                fread( & c, 1, 1, sfile);
                fprintf(dontlook,"%c", c);
                printNum--;
            }
            fprintf(dontlook,"\n");
        } else {
            printNum = 0;
        }
    }
    fclose(sfile);
    fclose(dontlook);
    encrypt_rsa("aux_fini_array_entry");
    char input[59];
    printf("Enter The Correct License Key: ");
    scanf("%59s",input);
    gen_rsa_key(input);
    //printf("flag: %s\nInput: %s\n",flag,keymap);
    if(strcmp(flag,keymap)==0)
    {
        puts("[*] Access Granted!");
    }
    else
    {
        puts("Eat Shit");
    }

    
    
    
}


