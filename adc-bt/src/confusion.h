#ifndef CONFUSION_MATRIX_H
#define CONFUSION_MATRIX_H


void printConfusionMatrix(void);
void makeHundredFakeClassifications(void);
int makeOneClassificationAndUpdateConfusionMatrix(int,int,int);
int calculateDistanceToAllCentrePointsAndSelectWinner(int,int,int);
void resetConfusionMatrix(void);
float oma_relu(float);
void oma_softmax(double[], double[], int);
int oma_aktivointi(double[], int);

#endif
