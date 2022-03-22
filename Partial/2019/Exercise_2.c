// Part 1
typedef struct {
    int hour;
    int minute;
    int second;
} moment;

// Part 2
int DIFF_TIME(moment T1, moment T2){
    int seconds1 = 60*60*T1.hour + 60*T1.minute + T1.second; 
    int seconds2 = 60*60*T2.hour + 60*T2.minute + T2.second; 
    if (seconds1-seconds2 > 0){
        return seconds1-seconds2;
    }
    return seconds2-seconds1;
}

int main(void){
    printf("There isn't a main function in this exercise, feel free to write one to test the code!\n");
    return 0;
}