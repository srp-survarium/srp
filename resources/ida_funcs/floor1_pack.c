void __cdecl floor1_pack(_DWORD *i, oggpack_buffer *opb)
{
  int *v2; // ebp
  int v3; // esi
  int v4; // edi
  unsigned int *v5; // esi
  int v6; // eax
  unsigned int *v7; // esi
  int v8; // edi
  _DWORD *v9; // ebp
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  int v15; // esi
  unsigned int *v16; // edi
  int k; // [esp+10h] [ebp-10h]
  char *ka; // [esp+10h] [ebp-10h]
  int count; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  int ja; // [esp+18h] [ebp-8h]
  int maxposit; // [esp+1Ch] [ebp-4h]
  unsigned int maxposita; // [esp+1Ch] [ebp-4h]
  _DWORD *ia; // [esp+24h] [ebp+4h]

  v2 = i;
  v3 = i[210];
  v4 = 0;
  count = 0;
  maxposit = v3;
  k = -1;
  oggpack_write(opb, *i, 5u);
  if ( (int)*i > 0 )
  {
    v5 = i + 1;
    do
    {
      oggpack_write(opb, *v5, 4u);
      if ( k < (int)*v5 )
        k = *v5;
      ++v4;
      ++v5;
    }
    while ( v4 < *i );
    v3 = maxposit;
  }
  v6 = k + 1;
  if ( k + 1 > 0 )
  {
    ka = (char *)(i + 80);
    v7 = i + 48;
    j = v6;
    do
    {
      oggpack_write(opb, *(v7 - 16) - 1, 3u);
      oggpack_write(opb, *v7, 2u);
      if ( *v7 )
        oggpack_write(opb, v7[16], 8u);
      v8 = 0;
      if ( 1 << *v7 > 0 )
      {
        v9 = ka;
        do
        {
          oggpack_write(opb, *v9 + 1, 8u);
          ++v8;
          ++v9;
        }
        while ( v8 < 1 << *v7 );
        v2 = i;
      }
      ka += 32;
      ++v7;
      --j;
    }
    while ( j );
    v3 = maxposit;
  }
  oggpack_write(opb, v2[208] - 1, 2u);
  v10 = 0;
  if ( v3 )
  {
    v11 = v3 - 1;
    if ( v3 != 1 )
    {
      do
      {
        ++v10;
        v11 >>= 1;
      }
      while ( v11 );
    }
  }
  oggpack_write(opb, v10, 4u);
  v12 = 0;
  maxposita = 0;
  if ( v3 )
  {
    v13 = v3 - 1;
    if ( v3 != 1 )
    {
      do
      {
        ++v12;
        v13 >>= 1;
      }
      while ( v13 );
      maxposita = v12;
    }
  }
  v14 = 0;
  ja = 0;
  if ( *v2 > 0 )
  {
    ia = v2 + 1;
    do
    {
      count += v2[*ia + 32];
      if ( v14 < count )
      {
        v15 = count - v14;
        v16 = (unsigned int *)&v2[v14 + 211];
        do
        {
          oggpack_write(opb, *v16++, maxposita);
          --v15;
        }
        while ( v15 );
        v14 = count;
      }
      ++ia;
      ++ja;
    }
    while ( ja < *v2 );
  }
}
