void __cdecl DES_ede3_cfb64_encrypt(
        unsigned __int8 *in,
        unsigned __int8 *out,
        int length,
        DES_ks *ks1,
        DES_ks *ks2,
        DES_ks *ks3,
        unsigned __int8 (*ivec)[8],
        int *num,
        int enc)
{
  int *v9; // eax
  int v10; // ecx
  int v11; // esi
  int v13; // edx
  int v14; // ebp
  __int16 v15; // ecx^2
  __int16 v16; // ecx^2
  unsigned __int8 v17; // al
  int v19; // edx
  int v20; // ebp
  __int16 v21; // ecx^2
  __int16 v22; // ecx^2
  unsigned __int8 v23; // al
  unsigned __int8 v24; // dl
  int v25; // [esp+10h] [ebp-8h] BYREF
  int v26; // [esp+14h] [ebp-4h]
  int v27; // [esp+34h] [ebp+1Ch]
  int v28; // [esp+34h] [ebp+1Ch]

  v9 = num;
  v10 = length;
  v11 = *num;
  if ( !enc )
  {
    if ( length )
    {
      do
      {
        v28 = --v10;
        if ( !v11 )
        {
          v19 = (*ivec)[4];
          v20 = (*ivec)[5];
          v25 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | *(unsigned __int16 *)ivec;
          v26 = (v20 << 8) | v19 | (*(unsigned __int16 *)&(*ivec)[6] << 16);
          DES_encrypt3(&v25, ks1, ks2, ks3);
          v21 = HIWORD(v25);
          *(_WORD *)ivec = v25;
          *(_WORD *)&(*ivec)[2] = v21;
          v22 = HIWORD(v26);
          *(_WORD *)&(*ivec)[4] = v26;
          *(_WORD *)&(*ivec)[6] = v22;
          v10 = v28;
        }
        v23 = *in++;
        v24 = (*ivec)[v11];
        (*ivec)[v11] = v23;
        *out = v24 ^ v23;
        v11 = ((_BYTE)v11 + 1) & 7;
        ++out;
      }
      while ( v10 );
      v9 = num;
    }
    goto LABEL_12;
  }
  if ( !length )
  {
LABEL_12:
    *v9 = v11;
    return;
  }
  do
  {
    v27 = --v10;
    if ( !v11 )
    {
      v13 = (*ivec)[4];
      v14 = (*ivec)[5];
      v25 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | *(unsigned __int16 *)ivec;
      v26 = (v14 << 8) | v13 | (*(unsigned __int16 *)&(*ivec)[6] << 16);
      DES_encrypt3(&v25, ks1, ks2, ks3);
      v15 = HIWORD(v25);
      *(_WORD *)ivec = v25;
      *(_WORD *)&(*ivec)[2] = v15;
      v16 = HIWORD(v26);
      *(_WORD *)&(*ivec)[4] = v26;
      *(_WORD *)&(*ivec)[6] = v16;
      v10 = v27;
    }
    v17 = *in++ ^ (*ivec)[v11];
    *out = v17;
    (*ivec)[v11] = v17;
    v11 = ((_BYTE)v11 + 1) & 7;
    ++out;
  }
  while ( v10 );
  *num = v11;
}
