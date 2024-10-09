#ifndef  HAVE_ZMAN_H
#define HAVE_ZMAN_H


char *caet() {
    time_t zman_hthala = time(NULL);
    char *caet = malloc(82);
    char *yom_bshavua; // לוקחים בחשבון שאות בעברית יכולה להיות בגודל שלוש תווים
            
    /*
    #include <locale.h>
    setlocale(LC_ALL, "");
    unsigned int rishon[] = {L'ר',L'א',L'ש',L'ו',L'ן', 0};
    printf("rishon=%ls\n", rishon);
    //unsigned int rishon1[] = {'ר','א','ש','ו','ן'}; // ניסוי
    rishon[0] = L'ב';
    printf("rishon=%ls\n", rishon);
    */
    /*
    #include <locale.h>
    setlocale(LC_ALL, "");
    int rishon[] = L"ראשון";
    int sheni[] = L"שני";
    printf("rishon[0]=%lc::%d\nsheni[0]=%lc::%d\n%ls,%ls\n", rishon[0], rishon[0], sheni[0], sheni[0], rishon, sheni);
    snprintf(rishon, sizeof(rishon), L"שלישי");
    printf("rishon-hasash=%ls\n", rishon);
    */

    switch(localtime(&zman_hthala)->tm_wday) {
        case 0:
            yom_bshavua = "ראשון";
            break;
        case 1:
            yom_bshavua = "שני";
            break;
        case 2:
            yom_bshavua = "שלישי";
            break;
        case 3:
            yom_bshavua = "רביעי";
            break;
        case 4:
            yom_bshavua = "חמישי";
            break;
        case 5:
            yom_bshavua = "שישי";
            break;
        default:
            yom_bshavua = "שבת";
    }
    
    sprintf(caet, "%02d:%02d:%02d  ,%02d.%02d.%d ,זמן התחלה: יום %s\n", localtime(&zman_hthala)->tm_hour, localtime(&zman_hthala)->tm_min, localtime(&zman_hthala)->tm_sec, localtime(&zman_hthala)->tm_mday, localtime(&zman_hthala)->tm_mon + 1,
            localtime(&zman_hthala)->tm_year + 1900, yom_bshavua);
        
    return caet;
}


#endif
