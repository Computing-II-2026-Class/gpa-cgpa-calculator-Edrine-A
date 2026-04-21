/*
Name: SSEKYANZI EDRINE ALLAN
Registration Number: 25/U/BIO/030/GV
*/
#include <stdio.h>
int main(void) {
    //Course codes
    char *codes1[8] = {"1. TEMB1101","2. TEMB1102","3. TEMB1103","4. TEMB1104","5. TEMB1105","6. TEMB1106","7. TEMB1107","8. TEMB1108"};
    char *codes2[8] = {"9. TEMB1201","10. TEMB1202","11. TEMB1203","12. TEMB1204","13. TEMB1205","14. TEMB1206","15. TEMB1207","16. TEMB1208"};
    //credit units
    int cu1[8] = {4, 3, 3, 3, 3, 3, 2, 3};
    int cu2[8] = {4, 3, 3, 3, 3, 3, 3, 3};
    //Mark, grade, grade point
    float mark1[8], mark2[8];
    char  grades1[8], grades2[8];
    int   gp1[8],     gp2[8];
    //GPA variables declaration and initialization    
    int i;
    float weighted;
    float wsum1 = 0, wsum2 = 0;
    int   totalCU1 = 0, totalCU2 = 0;
    float gpa1, gpa2, cgpa;
    //INPUT SEMESTER I
    printf("---------------------SEMESTER I - MARK ENTRY---------------------\n");

    for (i = 0; i < 8; i++) {
        printf("%s: ", codes1[i]);
        scanf("%f", &mark1[i]);
        // if: validate input
        if (mark1[i] < 0 || mark1[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
        // switch: convert mark to grade & grade point
        switch ((int)mark1[i] ) {
            case 80 ... 100:  grades1[i] = 'A'; gp1[i] = 5; break;
            case 70 ... 79:  grades1[i] = 'B'; gp1[i] = 4; break;
            case 60 ... 69:  grades1[i] = 'C'; gp1[i] = 3; break;
            case 50 ... 59:  grades1[i] = 'D'; gp1[i] = 2; break;
            default: grades1[i] = 'F'; gp1[i] = 0; break;
        }
    }
    //INPUT SEMESTER II
    printf("----------------------SEMESTER II - MARK ENTRY-----------------------\n");

    for (i = 0; i < 8; i++) {
        printf("%s: ", codes2[i]);
        scanf("%f", &mark2[i]);
        // if: validate input
        if (mark2[i] < 0 || mark2[i] > 100) {printf("Invalid score entered\n");
            return 1;}
        // switch: convert mark to grade & grade point
        switch ((int)mark2[i] ) {
            case 80 ... 100:  grades2[i] = 'A'; gp2[i] = 5; break;
            case 70 ... 79:  grades2[i] = 'B'; gp2[i] = 4; break;
            case 60 ... 69:  grades2[i] = 'C'; gp2[i] = 3; break;
            case 50 ... 59:  grades2[i] = 'D'; gp2[i] = 2; break;
            default: grades2[i] = 'F'; gp2[i] = 0; break;
        }
    }
    //GPA CALCULATIONS
    for (i = 0; i < 8; i++) {
        wsum1   += (gp1[i] * cu1[i]);
        totalCU1 += cu1[i];
    }
    for (i = 0; i < 8; i++) {
        wsum2   += (gp2[i] * cu2[i]);
        totalCU2 += cu2 [i];
    }

    gpa1 = wsum1 / totalCU1;
    gpa2 = wsum2 / totalCU2;
    cgpa = (wsum1 + wsum2) / (totalCU1 + totalCU2);
    // REPORT
    printf("================================YEAR ONE ACADEMIC REPORT===================================\n");
    //Semester I Table
    printf("\n-------------------------------------SEMESTER I------------------------------------------\n");
    printf("\t%s \t%s \t%s \t%s \t%s \t%s\n","Code","Score","Grade","Grade Pt.","C.U","Weights");
    printf("-------------------------------------------------------------------------------------------\n");
    for (i = 0; i < 8; i++) {
        weighted = (gp1[i] * cu1[i]);
        printf("%s \t%.1f \t%c \t%d \t\t%d \t%.1f\n",codes1[i],mark1[i], grades1[i],gp1[i], cu1[i], weighted);
    }
    //Semester II Table
    printf("\n-------------------------------------SEMESTER II------------------------------------------\n");
    printf("\t%s \t%s \t%s \t%s \t%s \t%s\n","Code","Score","Grade","Grade Pt.","C.U","Weights");
    printf("--------------------------------------------------------------------------------------------\n");

    for (i = 0; i < 8; i++) {
        weighted = (gp2[i] * cu2[i]);
        printf("%s \t%.1f \t%c \t%d \t\t%d \t%.1f\n",codes2[i],mark2[i], grades2[i],gp2[i], cu2[i], weighted);
    }
    //SUMMARY
    printf("\n_____________SUMMARY____________________\n");
    printf("Semester I GPA: %.2f\n",  gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n",            cgpa);
    //if...else
    printf("Classification: ");
    if (cgpa >= 4.40) {printf("First Class\n");} 
        else if (cgpa >= 3.60) {printf("Second Class Upper\n");} 
        else if (cgpa >= 2.80) {printf("Second Class Lower\n");}
        else if (cgpa >= 2.00) {printf("Pass\n");} 
    else {printf("Fail\n");}
    printf("___________________________________________\n");

    return 0;
}