//Author: Uður ÜN
//Date:   20.10.24

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

int acmp(const void* a1, const void* a2)
{   
    if (strcmp(*(const char**)a1, *(const char**)a2) > 0)
        return 1;

    if (strcmp(*(const char**)a1, *(const char**)a2) < 0)
        return -1;

    return 0;
}


int main(void)
{
    const char* p[] = {
"ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", "emrecan", "celik", "zahide",
"dost", "lale", "baran", "saniye", "poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem",
"melih", "necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", "haldun", "hulusi",
"yelda", "billur", "yasemin", "tarcan", "yasar", "tarkan", "refik", "berk", "kenan", "izzet",
"adnan", "sefa", "kazim", "gursel", "huseyin", "suheyla", "binnaz", "nusret", "aykut", "efecan",
"esra", "tonguc", "kunter", "yurdanur", "abdi", "fugen", "ayse", "aydan", "edip", "nazli",
"nucahit", "onat", "cumhur", "yalcin", "ziya", "ali", "ismail", "recep", "sarp", "yilmaz",
"hilal", "atakan", "cemre", "emirhan", "ceylan", "sabriye", "necmettin", "nagehan", "muhsin", "perihan",
"suleyman", "zeliha", "cahide", "beril", "askin", "zahit", "sevim", "ege", "utku", "ercument",
"seyhan", "sadegul", "enes", "sadi", "candan", "cemile", "tansel", "turgut", "sumeyye", "aylin",
"hakan", "ferhunde", "cebrail", "nihat", "alparslan", "osman", "efe", "ece", "soner", "necmi",
"polat", "naci", "pelinsu", "kerim", "eylul", "beste", "mert", "akin", "kamile", "kerem",
"bekir", "nalan", "bulent", "tijen", "durmus", "cansu", "sadri", "atil", "yesim", "sevilay",
"furkan", "ediz", "helin", "sadettin", "gulden", "samet", "binnur", "celal", "murat", "sezer",
"bilge", "yunus", "cem", "temel", "sefer", "petek", "haluk", "teoman", "aslican", "aycan",
"azmi", "nazife", "nurullah", "yasin", "nedim", "abdulmuttalip", "gulsen", "devlet", "mahir", "tarik",
"yurdagul", "nisan", "derya", "emre", "sade", "leyla", "fadime", "tamer", "julide", "busra",
"feramuz", "dilek", "dilber", "tansu", "abdullah", "mehmet", "nuri", "gizem", "nefes", "yavuz",
"demet", "zekai", "zerrin", "umit", "gul", "emine", "sezen", "ugur", "turhan", "aziz",
"tuncer", "handan", "okan", "irmak", "lamia", "can", "kelami", "ceyhan", "cahit", "gazi",
"bilgin", "su", "tayyar", "ferhat", "nuriye", "cemal", "engin", "pelin", "yusuf", "garo",
"iffet", "galip", "deniz", "belgin", "muzaffer", "niyazi", "kayahan", "hulki", "kaya", "necmiye",
"kasim", "hulya", "sidre", "esin", "suphi", "cengiz", "olcay", "rumeysa", "tugay", "asim",
"yurdakul", "feraye", "derin", "cuneyt", "keriman", "naciye", "esen", "tevfik", "naz", "gurbuz",
"cetin", "bora", "taci", "sadullah", "gulsah", "menekse", "semsit", "burak", "fikret", "cihan",
"ceyda", "selenay", "alican", "figen", "nasrullah", "cesim", "zubeyde", "sezai", "melike", "nurdan",
"arda", "nazif", "fuat", "gunay", "tufan", "fahri", "handesu", "kezban", "halime", "beyhan",
"ciler", "tayyip", "afacan", "mustafa", "kurthan", "tugra", "ahmet", "hasan", "hakki", "metin",
"aytac", "pinat", "selin", "kaan", "melisa", "sevda", "nihal", "nevsin", "pakize", "teslime",
"tunc", "nahit", "ceyhun", "hikmet", "eda", "malik", "anil", "canan", "egemen", "hande",
"hilmi", "muruvvet", "cemil", "diana", "tayfun", "zarife", "tekin", "murathan", "caner", "devrim",
"agah", "kamil", "ayla", "papatya", "kayhan", "durriye", "melek", "tanju", "sinem", "jade",
"sadiye", "refika", "birhan", "sami", "orkun", "erdem", "ufuk", "dogan", "atalay", "fazilet",
"taner", "polathan", "bennur", "aslihan", "cihat", };

    printf("%zu\n", sizeof p);

    for (size_t i = 0; i < asize(p);++i)
        printf("%s ", p[i]);
    printf("\n-----------------------------------------------------------------------------------------\n");



    qsort(p, asize(p), sizeof *p, &acmp);


    for (size_t i = 0; i < asize(p);++i)
        printf("%s ", p[i]);
    printf("\n-----------------------------------------------------------------------------------------\n");

}


