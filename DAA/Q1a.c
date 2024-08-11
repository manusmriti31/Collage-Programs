#include <stdio.h>
#include <stdlib.h>

void generate_data_file(const char *filename, int n_start, int n_end, int c) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    for (int n = n_start; n <= n_end; n++) {
        int f_n = 7 * n + 5;
        int g_n = c * n;
        fprintf(file, "%d %d %d\n", n, f_n, g_n);
    }
    
    fclose(file);
}

void plot_graph(const char *filename) {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        perror("Error opening pipe to gnuplot");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplotPipe, "set title 'Graph of f(n) and c*g(n)'\n");
    fprintf(gnuplotPipe, "set xlabel 'n'\n");
    fprintf(gnuplotPipe, "set ylabel 'Values'\n");
    fprintf(gnuplotPipe, "plot '%s' using 1:2 with lines title 'f(n) = 7n + 5', '%s' using 1:3 with lines title 'c * g(n) = 8 * n'\n", filename, filename);
    
    pclose(gnuplotPipe);
}

int main() {
    int n_start = 10, n_end = 30;
    int c = 8;
    const char *data_filename = "data.dat";

    generate_data_file(data_filename, n_start, n_end, c);
    plot_graph(data_filename);

    return 0;
}
