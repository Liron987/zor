#ifndef GLOBALI_H
#define GLOBALI_H

struct Zman {
    int shnya;
    int daka;
    int shaa;
    int yom_bhodesh;
    int hodesh;
    int shana;
};

struct MivnePkuda {
    char pkuda[1536];
    char pkuda_lhadpasa[1536];
} mivne_pkuda = {0}, mivne_pkuda1 = {0};

#endif
