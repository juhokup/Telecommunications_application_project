#include <zephyr/kernel.h>
#include <math.h>
#include "adc.h"
#include "keskipisteet.h"
#include <time.h>
#include <stdlib.h>
#include "neuroverkonKertoimet.h"
#include "confusion.h"

/* 
  K-means algorithm should provide 6 center points with
  3 values x,y,z. Let's test measurement system with known
  center points. I.e. x,y,z are supposed to have only values
  1 = down and 2 = up
  
  CP matrix is thus the 6 center points got from K-means algoritm
  teaching process. This should actually come from include file like
  #include "KmeansCenterPoints.h"
  
  And measurements matrix is just fake matrix for testing purpose
  actual measurements are taken from ADC when accelerator is connected.
*/ 

int CP[6][3]={
   {1980,1668,1695},
   {1321,1688,1710},
   {1668,2001,1695},
   {1649,1333,1646},
   {1653,1662,2025},
   {1648,1694,1376},
};

int measurements[6][3]={
	               {1,0,0},
						{2,0,0},
						{0,1,0},
						{0,2,0},
						{0,0,1},
						{0,0,2}
};

int CM[6][6] = {0};

void printConfusionMatrix(void)
{
	printk("Confusion matrix = \n");
	printk("   cp1 cp2 cp3 cp4 cp5 cp6\n");
	for(int i = 0;i<6;i++)
	{
		printk("cp%d %d   %d   %d   %d   %d   %d\n",i+1,CM[i][0],CM[i][1],CM[i][2],CM[i][3],CM[i][4],CM[i][5]);
	}
}

void makeHundredFakeClassifications(void)
{
   /*******************************************
   Jos ja toivottavasti kun teet toteutuksen paloissa eli varmistat ensin,
   että etäisyyden laskenta 6 keskipisteeseen toimii ja osaat valita 6 etäisyydestä
   voittajaksi sen lyhyimmän etäisyyden, niin silloin voit käyttää tätä aliohjelmaa
   varmistaaksesi, että etäisuuden laskenta ja luokittelu toimii varmasti tunnetulla
   itse keksimälläsi sensoridatalla ja itse keksimilläsi keskipisteillä.
   *******************************************/
   int min = 1320, max = 2000;
   for (int i=0; i<100; i++){
      int rd_x = rand() % (max - min + 1) + min;
      int rd_y = rand() % (max - min + 1) + min;
      int rd_z = rand() % (max - min + 1) + min;
      //printk("\n%d, %d, %d\n",rd_x,rd_y,rd_z);

      calculateDistanceToAllCentrePointsAndSelectWinner(rd_x,rd_y,rd_z);
   }

   //printf("Make your own implementation for this function if you need this\n");
}

int makeOneClassificationAndUpdateConfusionMatrix(int x, int y, int z)
{
   /**************************************
   Tee toteutus tälle ja voit tietysti muuttaa tämän aliohjelman sellaiseksi,
   että se tekee esim 100 CPl mittauksia tai sitten niin, että tätä funktiota
   kutsutaan 100 kertaa yhden mittauksen ja sen luokittelun tekemiseksi.
   **************************************/
   
   int shortestDistance = 0;
   int curDistance = 0;
   int closestCentrePoint[1][3];
   int direction = 0;
   
   for (int i=0; i<6; i++){
      int square_difference_x = (CP[i][0] - x) * (CP[i][0] - x);
      int square_difference_y = (CP[i][1] - y) * (CP[i][1] - y);
      int square_difference_z = (CP[i][2] - z) * (CP[i][2] - z);
      int sum = square_difference_x + square_difference_y + square_difference_z;
      curDistance = sqrt(sum);

      if (i == 0) shortestDistance = curDistance;

      if (curDistance <= shortestDistance) {
         shortestDistance = curDistance;
         closestCentrePoint[0][0] = CP[i][0];
         closestCentrePoint[0][1] = CP[i][1];
         closestCentrePoint[0][2] = CP[i][2];
      }
   }
   for (int i=0; i<6; i++){
      if (closestCentrePoint[0][0] == CP[i][0]){
         direction = i;
      }
   }

   //printk("Make your own implementation for this function if you need this\n");
   return direction;
}

int calculateDistanceToAllCentrePointsAndSelectWinner(int x,int y,int z)
{
   /***************************************
   Tämän aliohjelma ottaa yhden kiihtyvyysanturin mittauksen x,y,z,
   laskee etäisyyden kaikkiin 6 K-means keskipisteisiin ja valitsee
   sen keskipisteen, jonka etäisyys mittaustulokseen on lyhyin.
   ***************************************/
   int shortestDistance = 0;
   int curDistance = 0;
   int closestCentrePoint[1][3];
   
   for (int i=0; i<6; i++){
      int square_difference_x = (CP[i][0] - x) * (CP[i][0] - x);
      int square_difference_y = (CP[i][1] - y) * (CP[i][1] - y);
      int square_difference_z = (CP[i][2] - z) * (CP[i][2] - z);
      int sum = square_difference_x + square_difference_y + square_difference_z;
      curDistance = sqrt(sum);

      if (i == 0) shortestDistance = curDistance;

      if (curDistance <= shortestDistance) {
         shortestDistance = curDistance;
         closestCentrePoint[0][0] = CP[i][0];
         closestCentrePoint[0][1] = CP[i][1];
         closestCentrePoint[0][2] = CP[i][2];
         resetConfusionMatrix();
         CM[i][i] = 1;
         printk("CM = %d\n",CM[i][i]);
      }
     
   }
/*
   for (int i=0; i<6; i++){
      if (closestCentrePoint[0][0] == CP[i][0]){
         CM[i][i] += 1;
      }
   }
   */
   //printf("%d, ",closestCentrePoint[0][0]);
   //printf("%d, ",closestCentrePoint[0][1]);
   //printf("%d\n",closestCentrePoint[0][2]);

   //printf("lahin centerpoint on = %d",closestCentrePoint);
   return 0;
}

void resetConfusionMatrix(void)
{
	for(int i=0;i<6;i++)
	{ 
		for(int j = 0;j<6;j++)
		{
			CM[i][j]=0;
		}
	}
}


float oma_relu(float x){
    float jau = 0;
    if (x > 0) jau = x;
    else if (x <= 0) jau = 0;
    return jau;
}

void oma_softmax(double output_layer[], double tulos[], int num){
    double expo[num];
    double sum_expo = 0.0;

    // Eksponentiaalit ja niiden summa
    //printf("sum_expo:\n");
    for (int i = 0; i < num; i++) {
        expo[i] = exp(output_layer[i]);
        sum_expo += expo[i];
        //printf("%d. %f\n",i+1,sum_expo);
    }

    // Softmax-arvot
    //printf("Softmax:\n");
    for (int i = 0; i < num; i++) {
        tulos[i] = expo[i] / sum_expo;
        //printf("%d. %f\n",i+1,tulos[i]);

    }
}

int oma_aktivointi(double data[], int data_size){
    double summa=0;
    double hidden_layer[16]={0};
    int hl_size = (sizeof(hidden_layer) / sizeof(hidden_layer[0]));
    double output_layer[6]={0};
    int suunta_paatos = 0;

    //Dense 1 ReLu aktivoinnilla
    for (int i=0; i<bh_size; i++){      //16 = b_hidden määrä
        summa = b_hidden[i];
        for (int j=0; j<data_size; j++){ //3 = testidatan pituus
            summa = summa + data[j] *  w_hidden[j][i];
        }
        hidden_layer[i]=oma_relu(summa);
    }
//    printf("hidden layer:\n");
//    for (int i=0; i<bh_size; i++){
//        printf("%d = %f\n",i+1,hidden_layer[i]);
//    }

    //Dense 2 Softmax aktivoinnilla
    for (int i=0; i<bo_size; i++){      //6 = b_output pituus
        summa = b_output[i];
        for (int j=0; j<hl_size; j++){ //16 = hidden_layer pituus
            summa = summa + hidden_layer[j] * w_output[j][i];
        }
        output_layer[i]=summa;
    }

//    printf("output layer:\n");
//    for (int i=0; i<bo_size; i++){
//        printf("%d: %f\n",i+1,output_layer[i]);
//    }

    //Syötetään data Softmaxiin
    int n = sizeof(output_layer) / sizeof(output_layer[0]);
    double tulos[n];
    oma_softmax(output_layer, tulos, n);

//    printf("Softmax-tulokset:\n");
    for (int i = 0; i < n; i++) {
        //printf("%.0f. ", tulos[i]);
        if (tulos[i]>0.9) suunta_paatos = i;
    }
    CM[suunta_paatos][suunta_paatos] = 1;
    //printk("\nLaitteen suunta = %d\n",suunta_paatos);
    return suunta_paatos+1;
}
