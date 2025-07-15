void __cdecl floor1_pack(unsigned int *i, oggpack_buffer *opb)
{
  unsigned int v3; // edi
  signed int v4; // ebx
  unsigned int *v5; // edi
  unsigned int *v6; // edi
  _DWORD *v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int j; // edi
  int v11; // eax
  int v12; // edi
  unsigned int *v13; // ebx
  int v14; // [esp+Ch] [ebp-10h]
  _DWORD *v15; // [esp+Ch] [ebp-10h]
  int bits; // [esp+10h] [ebp-Ch]
  unsigned int bitsa; // [esp+10h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]
  signed int v20; // [esp+24h] [ebp+8h]
  _DWORD *v21; // [esp+24h] [ebp+8h]
  signed int v22; // [esp+24h] [ebp+8h]

  v18 = 0;
  v3 = i[210];
  bits = v3;
  v4 = -1;
  oggpack_write(opb, *i, 5u);
  v20 = 0;
  if ( (int)*i > 0 )
  {
    v5 = i + 1;
    do
    {
      oggpack_write(opb, *v5, 4u);
      if ( v4 < (int)*v5 )
        v4 = *v5;
      ++v20;
      ++v5;
    }
    while ( v20 < (int)*i );
    v3 = bits;
  }
  if ( v4 + 1 > 0 )
  {
    v21 = i + 80;
    v6 = i + 48;
    v14 = v4 + 1;
    do
    {
      oggpack_write(opb, *(v6 - 16) - 1, 3u);
      oggpack_write(opb, *v6, 2u);
      if ( *v6 )
        oggpack_write(opb, v6[16], 8u);
      v19 = 0;
      if ( 1 << *v6 > 0 )
      {
        v7 = v21;
        do
        {
          oggpack_write(opb, *v7 + 1, 8u);
          ++v19;
          ++v7;
        }
        while ( v19 < 1 << *v6 );
      }
      v21 += 8;
      ++v6;
      --v14;
    }
    while ( v14 );
    v3 = bits;
  }
  oggpack_write(opb, i[208] - 1, 2u);
  v8 = 0;
  if ( v3 )
  {
    v9 = v3 - 1;
    if ( v3 != 1 )
    {
      do
      {
        ++v8;
        v9 >>= 1;
      }
      while ( v9 );
    }
  }
  oggpack_write(opb, v8, 4u);
  bitsa = 0;
  if ( v3 )
  {
    for ( j = v3 - 1; j; j >>= 1 )
      ++bitsa;
  }
  v11 = 0;
  v22 = 0;
  if ( (int)*i > 0 )
  {
    v15 = i + 1;
    do
    {
      v18 += i[*v15 + 32];
      if ( v11 < v18 )
      {
        v12 = v18 - v11;
        v13 = &i[v11 + 211];
        do
        {
          oggpack_write(opb, *v13++, bitsa);
          --v12;
        }
        while ( v12 );
        v11 = v18;
      }
      ++v22;
      ++v15;
    }
    while ( v22 < (int)*i );
  }
}
