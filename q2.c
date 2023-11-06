#include <stdio.h>
#include <string.h>

int copiarstring(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

float calcularForca(char Forca[11][2][30]) {
    float valor1 = 0, valor2 = 0, valor5 = 0, valor6 = 0, valor8 = 0, valor10 = 0;

    for (int i = 0; i < 11; i++) {
        if (copiarstring(Forca[i][0], "G")) {
            valor1 += 8 * atoi(Forca[i][1]);
        } else if (copiarstring(Forca[i][0], "L")) {
            valor2 += 10 * atoi(Forca[i][1]);
        } else if (copiarstring(Forca[i][0], "Z")) {
            valor6 += 5 * atoi(Forca[i][1]);
        } else if (copiarstring(Forca[i][0], "V")) {
            valor5 += 8 * atoi(Forca[i][1]);
        } else if (copiarstring(Forca[i][0], "M")) {
            valor8 += 11 * atoi(Forca[i][1]);
        } else if (copiarstring(Forca[i][0], "A")) {
            valor10 += 12 * atoi(Forca[i][1]);
        }
    }

    return (valor1 + valor2 + valor5 + valor6 + valor8 + valor10) / 100;
}

int main() {
    char t1[30], t2[30];
    char ForcaT1[11][2][30];
    char ForcaT2[11][2][30];
    char *token;

    fgets(t1, 30, stdin);
    t1[strcspn(t1, "\n")] = 0;
    for (int i = 0; i < 11; i++) {
        fgets(ForcaT1[i][0], 30, stdin);
        token = strtok(ForcaT1[i][0], ";");
        for (int j = 0; j < 2; j++) {
            token = strtok(NULL, ";");
            strcpy(ForcaT1[i][j], token);
        }
    }

    fgets(t2, 30, stdin);
    t2[strcspn(t2, "\n")] = 0;
    for (int i = 0; i < 11; i++) {
        fgets(ForcaT2[i][0], 30, stdin);
        token = strtok(ForcaT2[i][0], ";");
        for (int j = 0; j < 2; j++) {
            token = strtok(NULL, ";");
            strcpy(ForcaT2[i][j], token);
        }
    }

    float m1 = calcularForca(ForcaT1);
    float m2 = calcularForca(ForcaT2);

    printf("%s: %.2f de forca\n", t1, m1);
    printf("%s: %.2f de forca\n", t2, m2);

    if (m1 > m2) {
        printf("%s eh mais forte\n", t1);
    } else {
        printf("%s eh mais forte\n", t2);
    }

    return 0;
}