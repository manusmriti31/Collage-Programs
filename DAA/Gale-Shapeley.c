# include<stdio.h>
# include<stdbool.h>

# define N 3

void stableMarriage(int MenPref[N][N], int WomenPref[N][N]){
    int WomenPartner[N] = {-1,-1,-1};
    bool freeMen[N] = {true,true,true};
    int freeMenCount = N;

    while(freeMenCount > 0) {
        int man;
        for(man = 0; man < N; man++){
            if(freeMen[man]) break;
        }

        for(int i = 0; i < N && freeMen[man]; i++){
            int woman = MenPref[man][i];

            if(WomenPartner[woman] == -1){
                WomenPartner[woman] = man;
                freeMen[man] = false;
                freeMenCount--;
            }
            else{
                int currPartner = WomenPartner[woman];
                int currRank = -1, newRank = -1;
                for(int j = 0; j < N; j++){
                    if(WomenPref[woman][j] == currPartner) currRank = j;
                    if(WomenPref[woman][j] == man) newRank = j;
                }
                if(newRank < currRank){
                    WomenPartner[woman] == man;
                    freeMen[currPartner] = false;
                    freeMen[man] = false;
                }
            }
        }
    }
    printf("Stable Pairing: \n");
    for(int i = 0; i < N; i++){
        printf("Woman %d is paired with man %d\n", i+1, WomenPartner[i]+1);
    }

}

int main(){
    int menPref[N][N] = {
        {0,1,2},
        {1,0,2},
        {0,1,2},
    };

    int womenPref[N][N] = {
        {0,1,2},
        {1,2,0},
        {2,0,1},
    };

    stableMarriage(menPref,womenPref);

    return 0;
}
