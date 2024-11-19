#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <random>

using namespace std;
int mat[21][21];


void RndMap(int mat[21][21], int &L, int &I)
{
  srand(time(NULL));
  L = rand() % 5 + 4;
  I = rand() % 14 + 7;
}
// nimic = 0
// om = 1
// foc = 2
// copac = 3
// stop = 4
void harta(int mat[21][21], int &L, int &I)
{
   for(int i = 1; i <= L; ++i)
    {
      for(int j = 1; j <= I; ++j)
        mat[i][j] = 0;
    }
}

void Rnd(int mat[21][21],int L, int I, int cod, int &pozi, int &pozj)
{
  int generate = 0; // momentan nu am generat nimic
  while(generate == 0)
    {
      pozi = rand() % L + 1;
      pozj = rand() % I + 1;
      if(mat[pozi][pozj] == 0)
      {
        generate = 1;
        mat[pozi][pozj] = cod;
      }
    }
  
}

void GenerateMap(int mat[21][21], int L, int I, int cod, int &LPlayer, int &CPlayer)
{
  srand(time(NULL));
  int pozi, pozj;
  for(int i = 1; i <= L / 2 + L / 3 + L / 3; i++)
    {
      cod = 2;
      Rnd(mat, L, I, cod, pozi, pozj);
    }
  for(int i = 1; i <= L + 1; i++)
    {
      cod = 3;
      Rnd(mat, L, I, cod, pozi, pozj);
    }
  for(int i = 1; i <= 1; i++)
    {
      cod = 4;
      Rnd(mat, L, I, cod, pozi, pozj);
    }
  for(int i = 1; i <= 1; i++)
    {
      cod = 1;
      Rnd(mat, L, I, cod, pozi, pozj);
      LPlayer = pozi;
      CPlayer = pozj;
    }

}
void RestartGame(int &);
void Run(int mat[21][21], int L, int I, int &cod, int LPlayer, int CPlayer, int &score )
{
  int life = 1;
  //life  = 1 inca in joc
  // life = -1, am murit
  // life = 0, restart game
  while(life == 1)
  {
    for(int i = 1; i <= I * 4 + 2; ++i)
      cout << "_";
    cout << "\n";
  for(int i = 1; i <= L; ++i)
    {
      for(int j = 0; j <= I + 1; ++j)
        if(j == 0 || j == I + 1)
          cout << "|";
        else
          {
            if(mat[i][j] == 1)
              cout << " 👨 ";
            else if(mat[i][j] == 2)
              cout << " 🔥 ";
            else if(mat[i][j] == 3)
              cout << " 🌲 ";
            else if(mat[i][j] == 4)
              cout << " 💎 ";
                else 
                  cout << "    ";
          }
              cout << "\n";
    }
    for(int i = 1; i <= I * 4 + 2; ++i)
      cout << "-";
    cout << "\n";
  cout << "Apasa in directia in care vrei sa te misti: ";
  char pmove;
  cin >> pmove;
  // Playerul se afla pe pozitia LPLayer CPlayer
  switch(pmove)
  {
    case 'w':
    if((LPlayer - 1 >= 1 && mat[LPlayer - 1][CPlayer] == 0) || mat[LPlayer - 1][CPlayer] == 4 || mat[LPlayer - 1][CPlayer] == 2)
    {
      for(int i = 1; i <= 5; ++i)
        cout << "\n\n\n\n\n\n\n\n\n\n";
      if(mat[LPlayer - 1][CPlayer] == 4)
       life = 0;
      if(mat[LPlayer - 1][CPlayer] == 2)
        life = -1;
      mat[LPlayer][CPlayer] = 0;
      mat[LPlayer - 1][CPlayer] = 1;
      LPlayer = LPlayer - 1;
    }
    break;
    case 'd':
    if((CPlayer + 1 <= I && mat[LPlayer][CPlayer + 1] == 0) || mat[LPlayer][CPlayer + 1] == 4)
    {
      for(int i = 1; i <= 5; ++i)
        cout << "\n\n\n\n\n\n\n\n\n\n";
      if(mat[LPlayer][CPlayer + 1] == 4)
        life = 0;
      if(mat[LPlayer][CPlayer + 1] == 2)
        life = -1;
      mat[LPlayer][CPlayer] = 0;
      mat[LPlayer][CPlayer + 1] = 1;
      CPlayer = CPlayer + 1;
    }
    break;
    case 'a':
    if((CPlayer - 1 >= 1 && mat[LPlayer][CPlayer - 1] == 0) || mat[LPlayer][CPlayer - 1] == 4)
    {
      for(int i = 1; i <= 5; ++i)
        cout << "\n\n\n\n\n\n\n\n\n\n";
      if(mat[LPlayer][CPlayer - 1] == 4)
        life = 0;
      if(mat[LPlayer][CPlayer - 1] == 2)
        life = -1;
      mat[LPlayer][CPlayer] = 0;
      mat[LPlayer][CPlayer - 1] = 1;
    CPlayer = CPlayer - 1;
    }
    break;
    case 's':
    if((LPlayer + 1 <= L && mat[LPlayer + 1][CPlayer] == 0) || mat[LPlayer + 1][CPlayer] == 4)
    {
      for(int i = 1; i <= 5; ++i)
        cout << "\n\n\n\n\n\n\n\n\n\n";
      if(mat[LPlayer + 1][CPlayer] == 4)
        life = 0;
      if(mat[LPlayer + 1][CPlayer] == 2)
        life = -1;
      mat[LPlayer][CPlayer] = 0;
      mat[LPlayer + 1][CPlayer] = 1;
      LPlayer = LPlayer + 1;
    }
    break;
  }
}
  if(life == 0)
  {
    for(int i = 1; i <= 5; ++i)
      cout << "\n\n\n\n\n\n\n\n\n\n";
    score++;
    cout << "Felicitari, ai avansat la nivelul urmator! Scorul tau este: " << score << endl;
    RestartGame(score);
  }
  else
  {
    for(int i = 1; i <= 5; ++i)
      cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "Ai murit! Jocul s-a incheiat!";
  }
  
}



int main() 
{
  int score = 0;
  RestartGame(score);
  return 0;
}
void RestartGame(int &score)
{
  int L, I, cod, LPlayer, CPlayer;
  RndMap(mat, L, I);
  harta(mat, L,I);
  GenerateMap(mat, L, I, cod, LPlayer, CPlayer);
  Run(mat, L, I, cod, LPlayer, CPlayer, score);
}