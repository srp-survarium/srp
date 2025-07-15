void __thiscall Scaleform::Alg::Random::Generator::SeedRandom(
        Scaleform::Alg::Random::Generator *this,
        unsigned int seed)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // eax

  v2 = (32 * (((seed ^ (seed << 13)) >> 17) ^ seed ^ (seed << 13)))
     ^ ((seed ^ (seed << 13)) >> 17)
     ^ seed
     ^ (seed << 13);
  this->Q[0] = v2;
  v3 = (32 * ((((v2 << 13) ^ v2) >> 17) ^ (v2 << 13) ^ v2)) ^ (((v2 << 13) ^ v2) >> 17) ^ (v2 << 13) ^ v2;
  this->Q[1] = v3;
  v4 = (((v3 << 13) ^ v3) >> 17) ^ (v3 << 13) ^ v3;
  v5 = (32 * v4) ^ v4;
  this->Q[2] = v5;
  v6 = (((v5 << 13) ^ (unsigned int)v5) >> 17) ^ (v5 << 13) ^ v5;
  v7 = (32 * v6) ^ v6;
  this->Q[3] = v7;
  v8 = (((v7 << 13) ^ (unsigned int)v7) >> 17) ^ (v7 << 13) ^ v7;
  v9 = (32 * v8) ^ v8;
  this->Q[4] = v9;
  v10 = (((v9 << 13) ^ (unsigned int)v9) >> 17) ^ (v9 << 13) ^ v9;
  v11 = (32 * v10) ^ v10;
  this->Q[5] = v11;
  v12 = (((v11 << 13) ^ (unsigned int)v11) >> 17) ^ (v11 << 13) ^ v11;
  v13 = (32 * v12) ^ v12;
  this->Q[6] = v13;
  v14 = (((v13 << 13) ^ (unsigned int)v13) >> 17) ^ (v13 << 13) ^ v13;
  this->Q[7] = v14 ^ (32 * v14);
  this->C = (unsigned int)&loc_587C4;
  this->I = 7;
}
