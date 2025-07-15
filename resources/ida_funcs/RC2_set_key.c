void __cdecl RC2_set_key(rc2_key_st *key, int len, const unsigned __int8 *data, int bits)
{
  int v4; // eax
  int v5; // ecx
  rc2_key_st *v6; // edx
  int v7; // ebp
  unsigned __int8 v8; // dl
  char *v9; // esi
  int v10; // edx
  int v11; // eax
  _BYTE *v12; // esi
  int v13; // ecx
  int v14; // ebx
  unsigned int *v15; // ecx
  unsigned __int16 *v16; // eax
  int v17; // edx

  v4 = len;
  LOBYTE(key->data[0]) = 0;
  if ( len > 128 )
    v4 = 128;
  v5 = bits;
  if ( bits <= 0 || bits > 1024 )
    v5 = 1024;
  if ( v4 > 0 )
  {
    v6 = key;
    v7 = v4;
    do
    {
      LOBYTE(v6->data[0]) = *((_BYTE *)v6->data + data - (const unsigned __int8 *)key);
      v6 = (rc2_key_st *)((char *)v6 + 1);
      --v7;
    }
    while ( v7 );
  }
  v8 = *((_BYTE *)key->data + v4 - 1);
  if ( v4 < 128 )
  {
    v9 = (char *)key - v4;
    do
    {
      v8 = key_table[(unsigned __int8)(v8 + v9[v4])];
      *((_BYTE *)key->data + v4++) = v8;
    }
    while ( v4 < 128 );
  }
  v10 = (v5 + 7) >> 3;
  v11 = 128 - v10;
  v12 = (char *)key + 128 - v10;
  v13 = key_table[(unsigned __int8)*v12 & (255 >> (-(char)v5 & 7))];
  *v12 = v13;
  if ( v10 != 128 )
  {
    do
    {
      v14 = (unsigned __int8)v12[v10 - 1];
      --v12;
      LOBYTE(v13) = key_table[v13 ^ v14];
      --v11;
      *v12 = v13;
    }
    while ( v11 );
  }
  v15 = &key->data[63];
  v16 = (unsigned __int16 *)&key->data[31] + 1;
  v17 = 64;
  do
  {
    *v15-- = *v16--;
    --v17;
  }
  while ( v17 );
}
