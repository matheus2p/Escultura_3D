#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include "Sculptor.h"

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;
    r = g = b = a = 0.5;
    delta = 0;
    lado = 0.5 - delta;
    alocar();
}

void Sculptor::alocar(){
    m = new Voxel **[nx];
    for(x = 0; x < nx; x++){
        m[x] = new Voxel *[ny];
    }
    for(x = 0; x < nx; x++){
      for(y = 0; y < ny; y++){
        m[x][y] = new Voxel [nz];
     }
    }
    for(x = 0; x < nx; x++){
      for(y = 0; y < ny; y++){
        for(z = 0; z < nz; z++){
            m[x][y][z].isOn = false;
           // Colors of voxel
            m[x][y][z].r=r;
            m[x][y][z].g=g;
            m[x][y][z].b=b;
            m[x][y][z].a=a;
     }
    }
   }
  }

void Sculptor::liberar(){
    for(x = 0; x < nx; x++){
        for(y = 0; y < ny; y++){
            delete[] m[x][y];
        }
    }
      for(x = 0; x < nx; x++){
            delete[] m[x];
}
    delete[] m;
    nx = ny = nz = 0;
}

  Sculptor::~Sculptor(){
    liberar();
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r; g = _g; b = _b; a = _a;
}

   // Voxel
   void Sculptor::cutVoxel(int x0, int y0, int z0){
     m[x0][y0][z0].isOn = false;
   }

   void Sculptor::putVoxel(int x0, int y0, int z0){
     m[x0][y0][z0].isOn = true;
     m[x0][y0][z0].r=r;
     m[x0][y0][z0].b=b;
     m[x0][y0][z0].g=g;
     m[x0][y0][z0].a=a;
   }

   void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(i = x0; i < x1; i++){
      for(j = y0; j < y1; j++){
        for(k = z0; k < z1; k++){
            m[i][j][k].isOn = true;
            m[i][j][k].r=r;
            m[i][j][k].g=g;
            m[i][j][k].b=b;
            m[i][j][k].a=a;
      }
     }
    }
   }

   void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(i = x0; i < x1; i++){
      for(j = y0; j < y1; j++){
        for(k = z0; k < z1; k++){
            m[i][j][k].isOn = false;
       }
      }
     }
    }

  void Sculptor::putEllipsoid(int x0, int y0, int z0, int rx, int ry, int rz){
   double r1, r2, r3;
   for(i = 0; i < nx; i++){
      for(j = 0; j < ny; j++){
        for(k = 0; k < nz; k++){
            r1 = ((double)(i-x0)*(double)(i-x0))/(rx*rx);
            r2 = (double)(j-y0)*(double)(j-y0)/(ry*ry);
            r3 = ((double)(k-z0)*(double)(k-z0))/(rz*rz);
        if(r1 + r2 + r3 < 1){
            m[i][j][k].isOn = true;
            m[i][j][k].r=r;
            m[i][j][k].g=g;
            m[i][j][k].b=b;
            m[i][j][k].a=a;
      }
     }
    }
   }
  }

  void Sculptor::cutEllipsoid(int x0, int y0, int z0, int rx, int ry, int rz){
   double r1, r2, r3;
   for(i = 0; i < nx; i++){
      for(j = 0; j < ny; j++){
        for(k = 0; k < nz; k++){
            r1 = ((double)(i-x0)*(double)(i-x0))/(rx*rx);
            r2 = ((double)(j-y0)*(double)(j-y0))/(ry*ry);
            r3 = ((double)(k-z0)*(double)(k-z0))/(rz*rz);
        if(r1 + r2 + r3 < 1){
            m[i][j][k].isOn = false;
      }
     }
    }
   }
  }

   void Sculptor::putSphere(int x0, int y0, int z0, int rr){
       double r1, r2, r3;
       double raio;
       raio = (double)rr*(double)rr;
    for(i = 0; i < nx; i++){
      for(j = 0; j < ny; j++){
        for(k = 0; k < nz; k++){
            r1 = ((double)(i-x0)*(double)(i-x0));
            r2 = ((double)(j-y0)*(double)(j-y0));
            r3 = ((double)(k-z0)*(double)(k-z0));
         if(r1 + r2 + r3 < raio){
            m[i][j][k].isOn = true;
            m[i][j][k].r=r;
            m[i][j][k].g=g;
            m[i][j][k].b=b;
            m[i][j][k].a=a;
        }
       }
      }
     }
    }

    void Sculptor::cutSphere(int x0, int y0, int z0, int rr){
       double r1, r2, r3;
       double raio;
       raio = (double)rr*(double)rr;
    for(i = 0; i < nx; i++){
      for(j = 0; j < ny; j++){
        for(k = 0; k < nz; k++){
            r1 = ((double)(i-x0)*(double)(i-x0));
            r2 = ((double)(j-y0)*(double)(j-y0));
            r3 = ((double)(k-z0)*(double)(k-z0));
         if(r1 + r2 + r3 < raio){
            m[i][j][k].isOn = false;
         }
        }
      }
    }
    }

  void Sculptor::limpaVoxels(void) {
  queue<int> q;
  int lx, ly, lz;
  for (x = 1; x < nx - 1; x++) {
    for (y = 1; y < ny - 1; y++) {
      for (z = 1; z < nz - 1; z++) {
        if ((m[x][y][z].isOn == true) && (m[x + 1][y][z].isOn == true) &&
            (m[x - 1][y][z].isOn == true) && (m[x][y + 1][z].isOn == true) &&
            (m[x][y - 1][z].isOn == true) && (m[x][y][z + 1].isOn == true) &&
            (m[x][y][z - 1].isOn == true)) {
          q.push(x);
          q.push(y);
        }
      }
    }
   }
  }
// Para escrever no arquivo, temos:
    void Sculptor::writeOFF(char *filename){
        int v_f, ponto;
        ofstream arq;
        v_f = 0;
        arq.open(filename);
        arq << "OFF\n";
        for(x = 0; x < nx; x++){
         for(y = 0; y < ny; y++){
          for(z = 0; z < nz; z++){
            if(m[x][y][z].isOn == true){
                v_f++;
            }
         }
         }
         }
         arq << v_f*8 << " " << v_f*6 << " " << "0\n";
         for(x = 0; x < nx; x++){
          for(y = 0; y < ny; y++){
           for(z = 0; z < nz; z++){
            if(m[x][y][z].isOn == true){
            arq << x - lado << " " << y + lado << " " << z - lado << "\n";
            arq << x - lado << " " << y - lado << " " << z - lado << "\n";
            arq << x + lado << " " << y - lado << " " << z - lado << "\n";
            arq << x + lado << " " << y + lado << " " << z - lado << "\n";
            arq << x - lado << " " << y + lado << " " << z + lado << "\n";
            arq << x - lado << " " << y - lado << " " << z + lado << "\n";
            arq << x + lado << " " << y - lado << " " << z + lado << "\n";
            arq << x + lado << " " << y + lado << " " << z + lado << "\n";
            }
           }
          }
         }

         v_f = 0;
       for (x = 0; x < nx; x++){
        for (y = 0; y < ny; y++){
         for (z = 0; z < nz; z++){
          if(m[x][y][z].isOn == true){
            ponto = v_f*8;
            arq << fixed;

            arq << 4 << " " << ponto + 0 << " " << ponto + 3 << " " << ponto + 2 << " " << ponto + 1 << " ";
            arq << setprecision(2) << m[x][y][z].r << " " << setprecision(2) << m[x][y][z].g << " " << setprecision(2) << m[x][y][z].b << " " <<setprecision(2) << m[x][y][z].a << "\n" << flush;
            arq << 4 << " " << ponto + 4 << " " << ponto + 5 << " " << ponto + 6 << " " << ponto + 7 << " ";
            arq << setprecision(2) << m[x][y][z].r << " " << setprecision(2) << m[x][y][z].g << " " << setprecision(2) << m[x][y][z].b << " " <<setprecision(2) << m[x][y][z].a << "\n" << flush;
            arq << 4 << " " << ponto + 0 << " " << ponto + 1 << " " << ponto + 5 << " " << ponto + 4 << " ";
            arq << setprecision(2) << m[x][y][z].r << " " << setprecision(2) << m[x][y][z].g << " " << setprecision(2) << m[x][y][z].b << " " <<setprecision(2) << m[x][y][z].a << "\n" << flush;
            arq << 4 << " " << ponto + 0 << " " << ponto + 4 << " " << ponto + 7 << " " << ponto + 3 << " ";
            arq << setprecision(2) << m[x][y][z].r << " " << setprecision(2) << m[x][y][z].g << " " << setprecision(2) << m[x][y][z].b << " " <<setprecision(2) << m[x][y][z].a << "\n" << flush;
            arq << 4 << " " << ponto + 7 << " " << ponto + 6 << " " << ponto + 2 << " " << ponto + 3 << " ";
            arq << setprecision(2) << m[x][y][z].r << " " << setprecision(2) << m[x][y][z].g << " " << setprecision(2) << m[x][y][z].b << " " <<setprecision(2) << m[x][y][z].a << "\n" << flush;
            arq << 4 << " " << ponto + 1 << " " << ponto + 2 << " " << ponto + 6 << " " << ponto + 5 << " ";
            arq << setprecision(2) << m[x][y][z].r << " " << setprecision(2) << m[x][y][z].g << " " << setprecision(2) << m[x][y][z].b << " " <<setprecision(2) << m[x][y][z].a << "\n" << flush;

            v_f++;
         }
        }
       }
      }

    arq.close();
}
