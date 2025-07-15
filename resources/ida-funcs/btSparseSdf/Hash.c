unsigned int __usercall btSparseSdf<3>::Hash@<eax>(int x@<eax>, int y, int z, btCollisionShape *shape)
{
  int v4; // ecx
  int v5; // edx
  unsigned __int16 *v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  _DWORD v11[4]; // [esp+0h] [ebp-10h] BYREF

  v11[0] = x;
  v4 = 16;
  v11[1] = y;
  v11[2] = z;
  v5 = 4;
  v11[3] = shape;
  v6 = (unsigned __int16 *)v11;
  do
  {
    v7 = (((32 * (*v6 + v4)) ^ v6[1]) << 11) ^ (*v6 + v4);
    v6 += 2;
    v4 = (v7 >> 11) + v7;
    --v5;
  }
  while ( v5 );
  v8 = (((8 * v4) ^ (unsigned int)v4) >> 5) + ((8 * v4) ^ v4);
  v9 = (((16 * v8) ^ v8) >> 17) + ((16 * v8) ^ v8);
  return ((v9 << 25) ^ v9) + (((v9 << 25) ^ v9) >> 6);
}
