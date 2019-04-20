#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <stdlib.h>

/*  Flag : dc91120{n0_one_c4n_reverse_m3} */

#define INVALID_KEY "ERRRRR Wrong KEY!"
#define CORRECT_KEY "WOOOOO Correct KEY"

int main(int, char ** ); // for some reason this was important to avoid warnings
int cstrchk(char, char);
char fake_key_[30]; // <--+
                    //    |------ both of these strings are essentially checking for debugger
char check_key[30]; // <--+

int cstrchk(char a, char b) {
  if (a != b) {
    return -1;
  } else {
    return 1;
  }

}

/* here is a function that will execute before main() */

__attribute__((__constructor__))
void func013(int argc, char ** argv) {
  //code here
  puts("\n\n\t\tCRACKME\n\n");
  int fortune = 0;
  printf("Enter Key: ");
  scanf("%30s", fake_key_);
  if (argc < 2) {
    main(3, argv);

  } else {
    int xor_key = ptrace(PTRACE_TRACEME, 0, 0, 0); // if debugger is attatched then this will return 0
    int forutne = 0;
    for (int i = 0; i < strlen(fake_key_); i++) {
      fortune += fake_key_[i];
      check_key[i] = fake_key_[i];
      fake_key_[i] = fake_key_[i] ^ xor_key; // a^0=a so if its not already debugged then fake_key_ and check_key will be same
    }
    for (int i = 0; i <= strlen(check_key); i++) {
      if (cstrchk(fake_key_[i], check_key[i]) != 1) {
        exit(-1);
      }
      if (fortune == (2745)) {
        int check = main(1, argv);
        if (check == 348) {
          if ((argv[1][0]) - (argv[1][29]) != -25) {
            main(3, argv);

          } else if ((argv[1][1]) - (argv[1][28]) != 48 && argv[1][1] ^ argv[1][28] != 80) {
            main(3, argv);

          } else if ((argv[1][2]) - (argv[1][27]) != -52 && argv[1][2] ^ argv[1][27] != 84) {
            main(3, argv);

          } else if ((argv[1][3]) - (argv[1][26]) != -46 && argv[1][3] ^ argv[1][26] != 110) {
            main(3, argv);

          } else if ((argv[1][4]) - (argv[1][25]) != -52 && argv[1][4] ^ argv[1][25] != 84) {
            main(3, argv);

          } else if ((argv[1][5]) - (argv[1][24]) != -65 && argv[1][5] ^ argv[1][24] != 65) {
            main(3, argv);

          } else if ((argv[1][6]) - (argv[1][23]) != -66 && argv[1][6] ^ argv[1][23] != 66) {
            main(3, argv);

          } else if ((argv[1][7]) - (argv[1][22]) != 22) {
            main(3, argv);

          } else if ((argv[1][8]) - (argv[1][21]) != -8 && argv[1][8] ^ argv[1][21] != 24) {
            main(3, argv);

          } else if ((argv[1][9]) - (argv[1][20]) != -53 && argv[1][9] ^ argv[1][20] != 85) {
            main(3, argv);

          } else if ((argv[1][10]) - (argv[1][19]) != -19 && argv[1][10] ^ argv[1][19] != 45) {
            main(3, argv);

          } else if ((argv[1][11]) - (argv[1][18]) != 16 && argv[1][11] ^ argv[1][18] != 48) {
            main(3, argv);

          } else if ((argv[1][12]) - (argv[1][17]) != 0) {
            main(3, argv);

          } else if ((argv[1][13]) - (argv[1][16]) != 49 && argv[1][13] ^ argv[1][16] != 81) {
            main(3, argv);

          } else if ((argv[1][14]) - (argv[1][15]) != -4 && argv[1][14] ^ argv[1][15] != 60) {
            main(3, argv);

          } else if ((argv[1][15]) - (argv[1][14]) != 4) {
            main(3, argv);

          } else if ((argv[1][16]) - (argv[1][13]) != -49 && argv[1][16] ^ argv[1][13] != 81) {
            main(3, argv);

          } else if ((argv[1][17]) - (argv[1][12]) != 0 && argv[1][17] ^ argv[1][12] != 0) {
            main(3, argv);

          } else if ((argv[1][18]) - (argv[1][11]) != -16 && argv[1][18] ^ argv[1][11] != 48) {
            main(3, argv);

          } else if ((argv[1][19]) - (argv[1][10]) != 19 && argv[1][19] ^ argv[1][10] != 45) {
            main(3, argv);

          } else if ((argv[1][20]) - (argv[1][9]) != 53 && argv[1][20] ^ argv[1][9] != 85) {
            main(3, argv);

          } else if ((argv[1][21]) - (argv[1][8]) != 8) {
            main(3, argv);

          } else if ((argv[1][22]) - (argv[1][7]) != -22 && argv[1][22] ^ argv[1][7] != 30) {
            main(3, argv);

          } else if ((argv[1][23]) - (argv[1][6]) != 66 && argv[1][23] ^ argv[1][6] != 66) {
            main(3, argv);

          } else if ((argv[1][24]) - (argv[1][5]) != 65 && argv[1][24] ^ argv[1][5] != 65) {
            main(3, argv);

          } else if ((argv[1][25]) - (argv[1][4]) != 52 && argv[1][25] ^ argv[1][4] != 84) {
            main(3, argv);

          } else if ((argv[1][26]) - (argv[1][3]) != 46 && argv[1][26] ^ argv[1][3] != 110) {
            main(3, argv);

          } else if ((argv[1][27]) - (argv[1][2]) != 52 && argv[1][27] ^ argv[1][2] != 84) {
            main(3, argv);

          } else if ((argv[1][28]) - (argv[1][1]) != -48) {
            main(3, argv);

          } else if ((argv[1][29]) - (argv[1][0]) != 25) {
            main(3, argv);

          } else {
            puts(CORRECT_KEY);
          }
        } else {
          puts(INVALID_KEY);
        }

      } else {
        puts(INVALID_KEY);
      }

      main(1, argv);
      exit(0);
    }

  }

}

int main(int argc, char ** argv) {

  if (argc != 3) {
    int token = 0;
    for (int i = 0; i < 5; i++) {
      token += argv[1][i] ^ (i * i);
    }
    return token;
  } else {
    puts(INVALID_KEY);
    exit(-1);
  }
}
