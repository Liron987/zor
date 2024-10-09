#ifndef BNE_HAPKUDA_H
#define BNE_HAPKUDA_H

#include "./have_clalim/have_clalim.h"

#define ANSI_COLOR_ADOM     "\x1b[31m"
#define ANSI_COLOR_ADOM_BHIR     "\x1b[1;31m"
#define ANSI_COLOR_YAROK     "\x1b[32m"
#define ANSI_COLOR_ZHOV_BHIR     "\x1b[1;33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct MivnePkuda bne_hpkuda(int mispar_tiunim, char* tiun, char* tocna, char *hivuy) {
    //printf("hivuy = %s\n", hivuy);
    
    
    if (mispar_tiunim > 1) {
        char mituv[32],
             zicron[128] = { 0 };
        if (strcmp(tiun, "bdk") == 0 || strcmp(tiun, "0") == 0)
        {
            snprintf(mituv, (sizeof mituv), "0 -g");
            memcpy(zicron, "-fsanitize=address,undefined -fsanitize-address-use-after-scope\0", 64);
        }
        else if (strcmp(tiun, "bdm") == 0 || strcmp(tiun, "1") == 0)
        {
            snprintf(mituv, (sizeof mituv), "0 -g");
            memcpy(zicron, "-fsanitize=address,undefined -fsanitize-address-use-after-scope -fanalyzer\0", 75);
        }
        else if (strcmp(tiun, "sof") == 0 || strcmp(tiun, "2") == 0)
        {
            memcpy(mituv, "3\0", 2);
            memcpy(zicron, "-fanalyzer\0", 11);
        }
        else if (strcmp(tiun, "s+b") == 0 || strcmp(tiun, "3") == 0)
        {
            memcpy(mituv, "3\0", 2);
            memcpy(zicron, "-fanalyzer\0", 11);
        }
        else if (strcmp(tiun, "srt") == 0 || strcmp(tiun, "4") == 0)
        {
            memcpy(mituv, "3 -march='cascadelake'\0", 23);
            memcpy(zicron, "-fanalyzer\0", 11);
        }
        else if (strcmp(tiun, "ruz") == 0 || strcmp(tiun, "5") == 0)
        {

            snprintf(mivne_pkuda1.pkuda, sizeof(mivne_pkuda1.pkuda), "./%s", tocna);
            snprintf(mivne_pkuda1.pkuda_lhadpasa, sizeof(mivne_pkuda1.pkuda_lhadpasa), ":פקודה\n%s\n", tocna);
            
            return mivne_pkuda1;
        }
        else if (strcmp(tiun, "hds") == 0 || strcmp(tiun, "6") == 0)
        {
            if (hivuy == NULL) {
                mivne_pkuda1.pkuda[0] = 0;
                snprintf(mivne_pkuda1.pkuda_lhadpasa, sizeof(mivne_pkuda1.pkuda_lhadpasa),
                         ANSI_COLOR_ADOM_BHIR
                         "\n"
                         "חייב לציין שם עבור המיזם אותו אתה מעוניין ליצור"
                         ANSI_COLOR_RESET
                         "\n\n"
                         );
            } else if (hivuy[0] < 47) {
                mivne_pkuda1.pkuda[0] = 0;
                snprintf(mivne_pkuda1.pkuda_lhadpasa, sizeof(mivne_pkuda1.pkuda_lhadpasa),
                         ANSI_COLOR_ADOM_BHIR
                         "\n"
                         "השם שצויין אינו תקין (שים לב לתו הראשון)"
                         ANSI_COLOR_RESET
                         "\n\n"
                );
            } else {
                snprintf(mivne_pkuda1.pkuda, sizeof(mivne_pkuda1.pkuda), "mkdir %s && echo '"
                    "#include <stdlib.h>\n"
                    "#include <stdio.h>\n\n"
                    "int main() {\n\n\n"
                    "\treturn 0;\n"
                    "}\n"
                    "' > %s/%s.c"
                , hivuy, hivuy, hivuy);
/*
                char ntiv_kovz[512];
                snprintf(ntiv_kovz, sizeof(ntiv_kovz), "%s/%s.c", hivuy, hivuy);
                FILE *mk;
                mk = fopen(ntiv_kovz, "w");
                if (mk) {
                    char *tocn = "#include <stdlib.h>\n"
                                 "#include <stdio.h>\n\n"
                                 "int main() {\n\n\n"
                                 "return 0;\n"
                                 "}\n";
                    fwrite(tocn, 1, strlen(tocn), mk);

                    fclose(mk);

                } else {
                    snprintf(mivne_pkuda1.pkuda_lhadpasa, sizeof(mivne_pkuda1.pkuda_lhadpasa),
                         ANSI_COLOR_ADOM_BHIR
                         "\n"
                         "לא הצלחתי לפתוח קובץ התחלתי חדש עבור המיזם"
                         ANSI_COLOR_RESET
                         "\n\n"
                    );

                    return mivne_pkuda1;
                }
*/
                snprintf(mivne_pkuda1.pkuda_lhadpasa, sizeof(mivne_pkuda1.pkuda_lhadpasa),
                         ANSI_COLOR_ZHOV_BHIR
                         ":פקודה\n"
                         "mkdir %s && echo '...' > %s/%s.c"
                         ANSI_COLOR_RESET
                         "\n\n"
                         , hivuy, hivuy, hivuy);
            }

            return mivne_pkuda1;

        }
        else
        {
            goto HZG_EFSRUYOT;
        }

        // בדיקה שיש בתיקייה קובץ להידור:
        FILE *mk;
        char *sm_kovez = malloc(strlen(tocna) + 3);
        snprintf(sm_kovez, strlen(tocna) + 3, "%s.c", tocna);
        if ( (mk = fopen(sm_kovez, "r") ) == NULL) {
            printf(ANSI_COLOR_ADOM "(%s) נראה שאין קובץ להרכבה" ANSI_COLOR_RESET "\n", sm_kovez);
            exit(1);
        }
        free(sm_kovez);
        fclose(mk);
        
        // בדוק אם יש כללים נוספים והבא אותם
        #define MRV_SHURA 1024
        char cllim[MRV_SHURA] ={ 0 };

        bdok_vhave_clalim(cllim);
        
        /*if (cllim[0] != 0)
            printf(":כללים\n%s\n", cllim);*/
        
        snprintf(
            mivne_pkuda1.pkuda, sizeof(mivne_pkuda1.pkuda), "gcc %s.c -o %s -O%s -Wall -Wextra %s %s",
            tocna, tocna, mituv, zicron, cllim
        );
        
        snprintf(
            mivne_pkuda1.pkuda_lhadpasa, sizeof(mivne_pkuda1.pkuda_lhadpasa), ":פקודה\ngcc %s.c -o %s -O%s -Wall -Wextra %s " ANSI_COLOR_YAROK "%s" ANSI_COLOR_RESET "\n",
            tocna, tocna, mituv, zicron, cllim
        );


        return mivne_pkuda1;
    }

    HZG_EFSRUYOT:
        snprintf(
                mivne_pkuda1.pkuda_lhadpasa
                , sizeof(mivne_pkuda1.pkuda_lhadpasa)
                , ANSI_COLOR_ZHOV_BHIR
                "חייב לציין את אחד הפרמטרים הבאים:\n"
            "0. bdk = להרכיב התוכנה לבדיקה (מיטוב 0, -ג, ומחטא)\n"
            "1. bdm = להרכיב התוכנה לבדיקה מלאה (מיטוב 0, -ג, ומחטא ומנתח)\n"
            "2. sof = להרכיב את התוכנה עם מיטוב 3\n"
            "3. s+b = להרכיב את התוכנה עם מיטוב 3 ומחטא כתובות\n"
            "4. srt = להרכיב את התוכנה עם מיטוב 3 והתאמה לשרת\n"
            "5. ruz = להריץ את התוכנה\n"
            "6. hds = ליצור מיזם חדש\n"
            "?. - פשוט מציג המידע הזה"
            ANSI_COLOR_RESET
                         "\n\n"
        );

        mivne_pkuda1.pkuda[0] = 0;


        return mivne_pkuda1;
}

#endif
