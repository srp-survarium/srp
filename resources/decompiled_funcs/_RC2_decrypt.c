void __cdecl RC2_decrypt(unsigned int *d, rc2_key_st *key)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // ecx
  unsigned int v6; // eax
  int v7; // edx
  unsigned int *v8; // ebp
  int v9; // ebx
  unsigned int *v10; // ebp
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // [esp+10h] [ebp-8h]

  v2 = d[1];
  v3 = (unsigned __int16)*d;
  v4 = (unsigned __int16)v2;
  v5 = HIWORD(*d);
  v6 = HIWORD(v2);
  v14 = 3;
  v7 = 5;
  v8 = &key->data[63];
  while ( 1 )
  {
    do
    {
      v9 = ((v6 >> 5) | (v6 << 11)) - (v3 & ~v4) - (v5 & v4) - *v8;
      v10 = v8 - 1;
      v6 = (unsigned __int16)v9;
      v11 = ((v4 >> 3) | (v4 << 13)) - ((unsigned __int16)v9 & ~v5) - (v3 & v5) - *v10--;
      v4 = (unsigned __int16)v11;
      v12 = ((v5 >> 2) | (v5 << 14)) - ((unsigned __int16)v11 & ~v3) - (v3 & v6) - *v10--;
      v5 = (unsigned __int16)v12;
      v13 = ((v3 >> 1) | (v3 << 15)) - ((unsigned __int16)v12 & ~v6) - (v4 & v6) - *v10;
      v8 = v10 - 1;
      --v7;
      v3 = (unsigned __int16)v13;
    }
    while ( v7 );
    if ( !--v14 )
      break;
    LOBYTE(v7) = v14 == 2;
    v6 = (unsigned __int16)(v6 - LOWORD(key->data[v4 & 0x3F]));
    v7 += 5;
    v4 = (unsigned __int16)(v4 - LOWORD(key->data[v5 & 0x3F]));
    v5 = (unsigned __int16)(v5 - LOWORD(key->data[v13 & 0x3F]));
    v3 = (unsigned __int16)(v13 - LOWORD(key->data[v6 & 0x3F]));
  }
  *d = (unsigned __int16)v13 | (v5 << 16);
  d[1] = (unsigned __int16)v4 | (v6 << 16);
}
