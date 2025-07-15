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
  int v23; // [esp+28h] [ebp+4h]
  float v24; // [esp+2Ch] [ebp+8h]
  float v25; // [esp+2Ch] [ebp+8h]
  float v26; // [esp+2Ch] [ebp+8h]
  float v27; // [esp+2Ch] [ebp+8h]
  float v28; // [esp+2Ch] [ebp+8h]
  float v29; // [esp+2Ch] [ebp+8h]
  float v30; // [esp+2Ch] [ebp+8h]
  float v31; // [esp+2Ch] [ebp+8h]
  float v32; // [esp+2Ch] [ebp+8h]
  float v33; // [esp+2Ch] [ebp+8h]
  float v34; // [esp+2Ch] [ebp+8h]
  float v35; // [esp+2Ch] [ebp+8h]

  v3 = x + this->PrimeSet.primes[0] * (y + 1);
  v18 = this->PrimeSet.primes[0] * (y - 1) + x;
  v4 = ((v3 - 1) << 13) ^ (v3 - 1);
  v20 = ((v3 + 1) << 13) ^ (v3 + 1);
  v5 = x + y * this->PrimeSet.primes[0];
  v21 = ((v5 - 1) << 13) ^ (v5 - 1);
  v23 = ((v5 + 1) << 13) ^ (v5 + 1);
  v19 = (v3 << 13) ^ v3;
  v6 = this->PrimeSet.primes[2];
  v22 = (v5 << 13) ^ v5;
  v7 = this->PrimeSet.primes[1];
  v8 = this->PrimeSet.primes[3];
  v24 = 1.0
      - (double)((v8
                + (((v18 + 1) << 13) ^ (v18 + 1))
                * (v6 + (((v18 + 1) << 13) ^ (v18 + 1)) * (((v18 + 1) << 13) ^ (v18 + 1)) * v7))
               & 0x7FFFFFFF)
      * 9.313225746154785e-10;
  v9 = v24;
  v25 = 1.0
      - (double)((v8
                + (((v18 - 1) << 13) ^ (v18 - 1))
                * (v6 + (((v18 - 1) << 13) ^ (v18 - 1)) * (((v18 - 1) << 13) ^ (v18 - 1)) * v7))
               & 0x7FFFFFFF)
      * 9.313225746154785e-10;
  v10 = v9 + v25;
  v26 = 1.0 - (double)((v8 + v4 * (v6 + v4 * v4 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v11 = v10 + v26;
  v27 = 1.0 - (double)((v8 + v20 * (v6 + v20 * v20 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v28 = (v11 + v27) * 0.0625;
  v12 = v28;
  v29 = 1.0 - (double)((v8 + v23 * (v6 + v23 * v23 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v13 = v29;
  v30 = 1.0 - (double)((v8 + v21 * (v6 + v21 * v21 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v14 = v13 + v30;
  v31 = 1.0
      - (double)((v8 + ((v18 << 13) ^ v18) * (v6 + ((v18 << 13) ^ v18) * ((v18 << 13) ^ v18) * v7)) & 0x7FFFFFFF)
      * 9.313225746154785e-10;
  v15 = v14 + v31;
  v32 = 1.0 - (double)((v8 + v19 * (v6 + v19 * v19 * v7)) & 0x7FFFFFFF) * 9.313225746154785e-10;
  v33 = (v15 + v32) * 0.125;
  v16 = v12 + v33;
  v34 = 1.0 - 9.313225746154785e-10 * (double)((v8 + v22 * (v6 + v22 * v22 * v7)) & 0x7FFFFFFF);
  v35 = v34 * 0.25;
  return (float)(v16 + v35);
}
