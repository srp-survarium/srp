void __cdecl RC2_encrypt(unsigned int *d, rc2_key_st *key)
{
  unsigned int v2; // edx
  rc2_key_st *v3; // ebp
  int v4; // esi
  unsigned int v5; // ecx
  int v6; // edi
  unsigned int v7; // edx
  unsigned int v8; // esi
  int v9; // eax
  unsigned int *v10; // ebp
  int v11; // eax
  int v12; // eax
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v2 = d[1];
  v3 = key;
  LOWORD(v4) = *d;
  v5 = HIWORD(*d);
  v6 = (unsigned __int16)v2;
  v7 = HIWORD(v2);
  v13 = 3;
  v14 = 5;
  while ( 1 )
  {
    do
    {
      v8 = (unsigned __int16)(v4 + LOWORD(v3->data[0]) + (v6 & v7) + (v5 & ~(_WORD)v7));
      v4 = (2 * v8) | (v8 >> 15);
      v9 = v3->data[1] + (v4 & v7) + (v6 & ~v4);
      v10 = &v3->data[1];
      v5 = (4 * (unsigned __int16)(v5 + v9)) | ((unsigned __int16)(v5 + v9) >> 14);
      v11 = v10[1] + (v4 & v5) + (v7 & ~v5);
      ++v10;
      v6 = (8 * (unsigned __int16)(v6 + v11)) | ((unsigned __int16)(v6 + v11) >> 13);
      v12 = v10[1] + (v5 & v6) + (v4 & ~v6);
      v7 = (32 * (unsigned __int16)(v7 + v12)) | ((unsigned __int16)(v7 + v12) >> 11);
      v3 = (rc2_key_st *)(v10 + 2);
      --v14;
    }
    while ( v14 );
    if ( !--v13 )
      break;
    v14 = (v13 == 2) + 5;
    v4 += key->data[v7 & 0x3F];
    v5 += key->data[v4 & 0x3F];
    v6 += key->data[v5 & 0x3F];
    v7 += key->data[v6 & 0x3F];
  }
  *d = (unsigned __int16)v4 | (v5 << 16);
  d[1] = (unsigned __int16)v6 | (v7 << 16);
}
