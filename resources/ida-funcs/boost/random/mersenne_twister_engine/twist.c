void __fastcall boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253>::twist(
        boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253> *this,
        int *a2)
{
  int *v2; // ecx
  int v3; // edi
  int v4; // eax
  unsigned int v5; // ebx
  int *v6; // ecx
  int v7; // edi
  int v8; // eax
  unsigned int v9; // ebx
  int *v10; // ecx
  int v11; // edi
  int v12; // eax
  unsigned int v13; // ebx
  int v14; // eax
  int v15; // ecx

  v2 = a2 + 1;
  v3 = 222;
  do
  {
    v4 = -1727483681 * (*v2 & 1);
    v5 = *(v2 - 1) ^ (*v2 ^ *(v2 - 1)) & 0x7FFFFFFE;
    ++v2;
    --v3;
    *(v2 - 2) = v2[395] ^ v4 ^ (v5 >> 1);
  }
  while ( v3 );
  v6 = a2 + 223;
  v7 = 5;
  do
  {
    v8 = -1727483681 * (*v6 & 1);
    v9 = *(v6 - 1) ^ (*v6 ^ *(v6 - 1)) & 0x7FFFFFFE;
    ++v6;
    --v7;
    *(v6 - 2) = v6[395] ^ v8 ^ (v9 >> 1);
  }
  while ( v7 );
  v10 = a2 + 228;
  v11 = 396;
  do
  {
    v12 = -1727483681 * (*v10 & 1);
    v13 = *(v10 - 1) ^ (*v10 ^ *(v10 - 1)) & 0x7FFFFFFE;
    ++v10;
    --v11;
    *(v10 - 2) = *(v10 - 229) ^ v12 ^ (v13 >> 1);
  }
  while ( v11 );
  v14 = *a2;
  v15 = a2[623];
  a2[624] = 0;
  a2[623] = a2[396] ^ (-1727483681 * (v14 & 1)) ^ ((a2[623] ^ (v14 ^ v15) & 0x7FFFFFFEu) >> 1);
}
