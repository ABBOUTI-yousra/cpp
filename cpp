#include <cstdio>

int main() {
    FILE *f = fopen("programe.cpp", "w");

    if (!f) {
        printf("erreur\n");
        return 1;
    }

    fprintf(f, "#include <iostream>\n\n");

    int nbr_params = 6000000;

    fprintf(f, "void test_function(");
    
    for (int i = 1; i <= nbr_params; ++i) {
        fprintf(f, "int param%d", i);
        if (i < nbr_params) {
            fprintf(f, ", ");
        }
    }

    fprintf(f, ") {\n");
    fprintf(f, "    std::cout << \"La fonction a utilise %d parametres.\" << std::endl;\n", nbr_params);
    fprintf(f, "}\n\n");

    fprintf(f, "int main() {\n");
    fprintf(f, "    test_function(");

    for (int i = 1; i <= nbr_params; ++i) {
        fprintf(f, "%d", i);
        if (i < nbr_params) {
            fprintf(f, ", ");
        }
    }

    fprintf(f, ");\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");

    fclose(f);

    return 0;
}
