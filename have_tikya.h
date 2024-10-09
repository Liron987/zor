#ifndef HAVE_TIKYA_H
#define HAVE_TIKYA_H

char *have_htikya_hnocahit(const unsigned int orec) {
    
    char *tikya_nocahit = malloc(orec);
    
    if (getcwd(tikya_nocahit, orec) != NULL) {
        return tikya_nocahit;
    } else {
        perror("getcwd() error");
        return 0;
    }
}

#endif

