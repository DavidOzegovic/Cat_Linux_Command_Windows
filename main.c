#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    FILE *file;
    int lineCount = 1;
    char c;
    bool hasE = false;
    bool hasA = false;
    bool hasN = false;
    bool isStartOfLine = true;
    if(argc < 2){
        printf("Error: invalid usage\n");
        printf("USAGE %s + [file_name]\n", argv[0]);
        return 1;
    }
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-E") == 0){
            hasE = true;
            continue;
        }else if(strcmp(argv[i], "-A") == 0){
            hasA = true;
            continue;
        }else if(strcmp(argv[i], "-n") == 0){
            hasN = true;
            continue;
        }
    }
        for(int j = 1; j < argc; j++){
        if(strcmp(argv[j], "-E") == 0){
            hasE = true;
            continue;
        }else if(strcmp(argv[j], "-A") == 0){
            hasA = true;
            continue;
        }else if(strcmp(argv[j], "-n") == 0){
            hasN = true;
            continue;
        }else{
            file = fopen(argv[j], "r");
            if(file == NULL){
            printf("Error: text file can't be opened or it doesn't exist\n");
            return 1;
            }do{
                c = fgetc(file);
                if(feof(file)){
                    break;
                    }
                if(hasE == true && c == '\n'){
                    printf("$");
                    printf("%c", c);
                }else if(hasA == true && c == '\t'){
                    printf("^I");
                    continue;
                }else if(hasN == true && isStartOfLine == true){
                    printf("%d %c", lineCount, c);
                    isStartOfLine = false;
                }else{
                    printf("%c", c);
                }

                if (c == '\n'){
                    lineCount++;
                    isStartOfLine = true;
                }   
            }
            while(c != EOF);
            fclose(file);
    }     
}
    printf("\nTotal number of arguments passed (argc): %d\n", argc);
    return 0;
}