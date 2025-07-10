double __thiscall Scaleform::Render::PerlinGenerator::SmoothNoise(
        Scaleform::Render::PerlinGenerator *this,
        int x,
        int y)
{
  int v3; // edx
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  double v9; // st5
  double v10; // st5
  double v11; // st5
  double v12; // st5
  double v13; // st4
  double v14; // st4
  double v15; // st4
  double v16; // st5
  int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]
  int xa; // [esp+28h] [ebp+4h]
  float ya; // [esp+2Ch] [ebp+8h]
  float yb; // [esp+2Ch] [ebp+8h]
  float yc; // [esp+2Ch] [ebp+8h]
  float yd; // [esp+2Ch] [ebp+8h]
  float ye; // [esp+2Ch] [ebp+8h]
  float yf; // [esp+2Ch] [ebp+8h]
  float yg; // [esp+2Ch] [ebp+8h]
  float yh; // [esp+2Ch] [ebp+8h]
  float yi; // [esp+2Ch] [ebp+8h]
  float yj; // [esp+2Ch] [ebp+8h]
  float yk; // [esp+2Ch] [ebp+8h]
  float yl; // [esp+2Ch] [ebp+8h]

  v3 = x + this->PrimeSet.primes[0] * (y + 1);
  v18 = this->PrimeSet.primes[0] * (y - 1) + x;
  v4 = ((v3 - 1) << 13) ^ (v3 - 1);
  v20 = ((v3 + 1) << 13) ^ (v3 + 1);
  v5 = x + y * this->PrimeSet.primes[0];
  v21 = ((v5 - 1) << 13) ^ (v5 - 1);
  xa = ((v5 + 1) << 13) ^ (v5 + 1);
  v19 = (v3 << 13) ^ v3;
  v6 = this->PrimeSet.primes[2];
  v22 = (v5 << 13) ^ v5;
  v7 = this->PrimeSet.primes[1];
  v8 = this->PrimeSet.primes[3];
  ya = 1.0
     - (double)((v8
               + (((v18 + 1) << 13) ^ (v18 + 1))
               * (v6 + (((v18 + 1) << 13) ^ (v18 + 1)) * (((v18 + 1) << 13) ^ (v18 + 1)) * v7))
              & 0x7FFFFFFF)
     * 9.313225746154785e-10;
  v9 = ya;
  yb = 1.0
     - (double)((v8
               + (((v18 - 1) << 13) ^ (v18 - 1))
               * (v6 + (((v18 - 1) << 13) ^ (v18 - 1)) * (((v18 - 1) << 13) ^ (v18 - 1)) * v7))
              & 0x7FFFFFFF)
     * 9.313225746154785e-10;
  v10 = v9 + yb;
  yc = 1.0 - (double)((v8 + v4 * (v6 + v4 * v4 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v11 = v10 + yc;
  yd = 1.0 - (double)((v8 + v20 * (v6 + v20 * v20 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  ye = (v11 + yd) * 0.0625;
  v12 = ye;
  yf = 1.0 - (double)((v8 + xa * (v6 + xa * xa * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v13 = yf;
  yg = 1.0 - (double)((v8 + v21 * (v6 + v21 * v21 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v14 = v13 + yg;
  yh = 1.0
     - (double)((v8 + ((v18 << 13) ^ v18) * (v6 + ((v18 << 13) ^ v18) * ((v18 << 13) ^ v18) * v7)) & 0x7FFFFFFF)
     * 9.313225746154785e-10;
  v15 = v14 + yh;
  yi = 1.0 - (double)((v8 + v19 * (v6 + v19 * v19 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  yj = (v15 + yi) * 0.125;
  v16 = v12 + yj;
  yk = 1.0 - 9.313225746154785e-10 * (double)((v8 + v22 * (v6 + v22 * v22 * v7)) & 0x7FFFFFFF);
  yl = yk * 0.25;
  return (float)(v16 + yl);
}
