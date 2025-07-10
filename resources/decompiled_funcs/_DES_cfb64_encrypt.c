void __cdecl DES_cfb64_encrypt(
        unsigned __int8 *in,
        unsigned __int8 *out,
        int length,
        DES_ks *schedule,
        unsigned __int8 (*ivec)[8],
        int *num,
        int enc)
{
  int *v7; // eax
  int v8; // ebp
  int v9; // esi
  int v10; // edx
  __int16 v11; // ecx^2
  __int16 v12; // ecx^2
  unsigned __int8 v13; // al
  int v14; // edx
  __int16 v15; // ecx^2
  __int16 v16; // ecx^2
  unsigned __int8 v17; // al
  unsigned __int8 v18; // cl
  int v19; // [esp+10h] [ebp-8h] BYREF
  int v20; // [esp+14h] [ebp-4h]

  v7 = num;
  v8 = length;
  v9 = *num;
  if ( !enc )
  {
    if ( length )
    {
      do
      {
        --v8;
        if ( !v9 )
        {
          v14 = (*ivec)[5];
          v19 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | *(unsigned __int16 *)ivec;
          v20 = (v14 << 8) | (*ivec)[4] | (*(unsigned __int16 *)&(*ivec)[6] << 16);
          DES_encrypt1(&v19, schedule, 1);
          v15 = HIWORD(v19);
          *(_WORD *)ivec = v19;
          *(_WORD *)&(*ivec)[2] = v15;
          v16 = HIWORD(v20);
          *(_WORD *)&(*ivec)[4] = v20;
          *(_WORD *)&(*ivec)[6] = v16;
        }
        v17 = *in++;
        v18 = (*ivec)[v9];
        (*ivec)[v9] = v17;
        *out = v18 ^ v17;
        v9 = ((_BYTE)v9 + 1) & 7;
        ++out;
      }
      while ( v8 );
      v7 = num;
    }
    goto LABEL_12;
  }
  if ( !length )
  {
LABEL_12:
    *v7 = v9;
    return;
  }
  do
  {
    --v8;
    if ( !v9 )
    {
      v10 = (*ivec)[5];
      v19 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | *(unsigned __int16 *)ivec;
      v20 = (v10 << 8) | (*ivec)[4] | (*(unsigned __int16 *)&(*ivec)[6] << 16);
      DES_encrypt1(&v19, schedule, 1);
      v11 = HIWORD(v19);
      *(_WORD *)ivec = v19;
      *(_WORD *)&(*ivec)[2] = v11;
      v12 = HIWORD(v20);
      *(_WORD *)&(*ivec)[4] = v20;
      *(_WORD *)&(*ivec)[6] = v12;
    }
    v13 = (*ivec)[v9] ^ *in++;
    *out = v13;
    (*ivec)[v9] = v13;
    v9 = ((_BYTE)v9 + 1) & 7;
    ++out;
  }
  while ( v8 );
  *num = v9;
}
