#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "program.h"
#include "status.h"
#include "struct.h"

int main(int argc, char *argv[]){
    PROGRAM p;
    FILE *fp;
    LINE *line, *temp;

    openFile(&fp, argv[1]);
    initProg(&p);

    while(readLine(&fp, &line)){
        printStatus(getHeader(&p, line));

        if(line -> line == 0){
            printStatus(getTimeSig(&p, line));
        }
        temp = getLine(&p, line -> header -> clef);
        if(temp != NULL){
            addToLine(temp, line);
        }
        else{
            addLine(&p, line);
        }
    }
    printStatus(playProgram(&p));

    fclose(fp);
    return 1;
}
