#ifndef HAVE_CLALIM_H
#define HAVE_CLALIM_H

//#include <dirent.h>

#define MRV_SHURA 1024

char bdok_vhave_clalim(char *cllim) {
    
    FILE *mk;
    if ( (mk = fopen("zor.txt", "r") ) == NULL) {
        //printf("(zor.txt) נראה שאין קובץ כללים\n");

        return 0;
    }


    if (fgets(cllim, MRV_SHURA-1, mk) == 0)
        perror("לא הצלחתי לקרוא שורה\n");

    fclose(mk);


    return 1;
    
}

#endif
