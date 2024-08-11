#include<stdio.h>
#include<stdlib.h>

void generate_data(const char *filename, int n_start, int n_end, int c){
    FILE *file = fopen(filename,"w");
    if(file == NULL){
        perror("Error opening the file\n");
        exit(EXIT_FAILURE);
    }
    for(int n = n_start; n <= n_end; n++){
        int f_n = 4*n + 3;
        int g_n = c*n;
        fprintf(file, "%d %d %d\n", n, f_n, g_n);
    }
    fclose(file);
}

void plot_graph(const char *filename){
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if(gnuplot == NULL){
        perror("Error plotting the graph");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplot, "set title 'Graph between f(n) and g(n)'\n");
    fprintf(gnuplot, "set xlabel 'n'\n");
    fprintf(gnuplot, "set ylabel 'Values'\n");
    fprintf(gnuplot, "plot '%s' using 1:2 with line title 'f(n) = 4n +3', '%s' using 1:3 with line title 'g(n) = 3n'\n",filename,filename);

    pclose(gnuplot);
}

int main(){
    int n_start = 10, n_end = 30;
    int c = 3;
    const char *filename = "data4.dat";
    generate_data(filename,n_start,n_end,c);
    plot_graph(filename);
    return 0;
}