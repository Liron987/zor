#ifndef HALEZ_SM_HTOCNA_H
#define HALEZ_SM_HTOCNA_H

char *halez_sm_htocna(char *nativ) {
    char *tocna = '\0';
    
    for (unsigned int h = strlen(nativ); h > 0; h--)
        if (nativ[h] == '/') {
            //snprintf(tocna, sizeof(tocna), "%s", nativ + (++h) );
            tocna = nativ + (++h);
            break;
        }
        
    return tocna;
}

#endif
