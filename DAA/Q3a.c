#include<stdio.h>
#include<stdlib.h>

void generate_data(const char *filename, int n_start, int n_end, int c1, int c2){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }
    for(int n = n_start; n <= n_end; n++){
        int f_n = (7*n*n) + (7*n) + 5;
        int g_n = (n*n);
        fprintf(file, "%d %d %d %d\n", n, f_n, c1*g_n, c2*g_n);
    }
    fclose(file);
}

void plot_graph(const char *filename){
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if(gnuplot == NULL){
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }
    fprintf(gnuplot,"set title 'Graph of f(n), c1g(n) and c2g(n)'\n");
    fprintf(gnuplot,"set xlabel 'n'\n");
    fprintf(gnuplot, "set ylabel 'Values'\n");
    fprintf(gnuplot,"plot '%s' using 1:2 with line title 'f(n) = 7n^2 + 7n + 5', '%s' using 1:3 with line title 'c1*g(n) = c1*n^2','%s' using 1:4 with line title 'c2*g(n) = c2*n^2'\n",filename,filename,filename);
    pclose(gnuplot);
}

int main(){
    int n_start = 10, n_end = 30;
    int c1 = 7, c2 = 8;
    const char *filename = "data3.dat";
    generate_data(filename, n_start, n_end, c1,c2);
    plot_graph(filename);
    return 0;

}