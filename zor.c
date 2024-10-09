#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "./globali.h"
#include "./have_zman.h"
#include "./have_tikya.h"
#include "./halez_sm_htocna.h"
#include "./bne_hpkuda.h"

#define NATIV_MERAVI 1024

int main(int argc, char *argv[]) {
    // הדפס זמן התחלת התוכנה
    char *aata = caet();
    if (aata == NULL)
        exit(1);
    printf("%s", aata);
    free(aata);

    // הכן מצביע שם תיקייה למקרה שמדובר ביצירת מיזם חדש
    char *hivuy = argc == 3 ? argv[2] : NULL;
    
    // הבא נתיב תיקייה נוכחי
    char *tikya_nocahit = have_htikya_hnocahit(NATIV_MERAVI);
    if (tikya_nocahit == 0)
        exit(1);
    printf("%s =  תיקייה נוכחית\n", tikya_nocahit);
    
    // חלץ את שם התוכנה
    char tocna[512];
    snprintf(tocna, sizeof(tocna), "%s", halez_sm_htocna(tikya_nocahit) );
    if (tocna[0] == '\0')
        exit(1);
    if (hivuy == NULL)
        printf("%s = תוכנה\n", tocna);

    free(tikya_nocahit);
    
    // בנה את הפקודה
    mivne_pkuda = bne_hpkuda(argc, argv[1], tocna, hivuy);
    fprintf(stderr, "%s\n", mivne_pkuda.pkuda_lhadpasa);
    if (mivne_pkuda.pkuda[0] == 0)
        exit(1);
    
    // הוצא הפקודה לפועל
    if (system(mivne_pkuda.pkuda) == -1) {
        perror("לא הצלחתי להוציא פקודה לפועל:\n");
        exit(1);
    }
    
    printf("\n!פקודה הוצאה לפועל בהצלחה\n");
    
    return 0;
}
