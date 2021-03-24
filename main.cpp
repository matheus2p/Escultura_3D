#include <iostream>
#include <fstream>
#include <queue>
#include "Sculptor.h"
#include "Voxel.h"

int main(void){

    Sculptor d1(25, 25, 25);
    // Cabeça do Pato
    d1.setColor(0,0.83,0,1);
    d1.putBox(4,12,4,10,4,12);
    // Nariz do Pato
    d1.setColor(0.91,0.97,0.52,0.7);
    d1.putVoxel(8,6,12); d1.putVoxel(7,6,12); d1.putVoxel(9,6,12); d1.putVoxel(6,6,12);
    d1.putVoxel(8,7,12); d1.putVoxel(7,7,12); d1.putVoxel(9,7,12); d1.putVoxel(6,7,12);
    d1.putVoxel(9,6,13); d1.putVoxel(8,6,13); d1.putVoxel(6,6,13); d1.putVoxel(7,6,13);
    d1.putVoxel(9,7,13); d1.putVoxel(8,7,13); d1.putVoxel(6,7,13); d1.putVoxel(7,7,13);
    // Branco do Olho do Pato
    d1.setColor(1,1,1,1);
    d1.putBox(12,13,5,8,7,10);
    d1.putBox(3,4,5,8,7,10);
    // Olho do Pato
    d1.setColor(0,0,0,1);
    d1.putVoxel(12,6,8);
    d1.putVoxel(3,6,8);
    // Pescoço do Pato (Linha branca)
    d1.setColor(1,1,1,1);
    d1.putBox(4,12,10,11,4,12);
    // Barriga do Pato
    d1.setColor(0.34,0.12,0.12,0.7);
    d1.putBox(4,12,11,15,4,12);
    // Pena de trás do Pato
    d1.setColor(0.34,0.12,0.12,0.7);
    d1.putBox(6,10,11,14,3,6);
    d1.cutVoxel(6,11,3);
    d1.cutVoxel(9,11,3);
    d1.cutVoxel(6,13,3);
    d1.cutVoxel(9,13,3);
    // Asa do Pato
    d1.setColor(0.34,0.12,0.12,0.7);
    d1.putBox(12,15,12,15,4,10);
    d1.putBox(1,4,12,15,4,10);
    // Resto do Corpo do Pato (Perna)
    d1.setColor(1,0.5,0,0.8);
    d1.putBox(4,12,15,17,4,12);
    // Perninhas do Pato + Pézin do Pato
    d1.setColor(1,0.36,0,0.8);
    d1.putVoxel(10,17,8); d1.putVoxel(10,18,8); d1.putVoxel(10,19,8);
    d1.putVoxel(5,17,8); d1.putVoxel(5,18,8); d1.putVoxel(5,19,8);
    d1.putBox(9,12,20,21,7,11);
    d1.putBox(4,7,20,21,7,11);
    // Chão
    d1.setColor(0.46,0.46,0.46,0.5);
    d1.putBox(0,16,21,22,2,16);
    d1.limpaVoxels();
    d1.writeOFF((char*)"Patin.off");



    // TESTE DAS FUNCIONALIDADES IMPLEMENTADAS

    Sculptor E(31,31,31);
    E.putSphere(15,15,15,10);
    E.writeOFF((char*)"Esfera.off");

    Sculptor E2(31,31,31);
    E2.putSphere(15,15,15,10);
    E2.cutSphere(15,19,15,11);
    E2.writeOFF((char*)"Esfera1.off");

    Sculptor El(31,31,31);
    El.putEllipsoid(15,15,15,10,7,5);
    El.writeOFF((char*)"Elipsoide.off");

    Sculptor E1(31,31,31);
    E1.putEllipsoid(15,15,15,10,7,5);
    E1.cutEllipsoid(15,15,17,7,5,3);
    E1.writeOFF((char*)"Elipsoide1.off");

    return 0;

}
