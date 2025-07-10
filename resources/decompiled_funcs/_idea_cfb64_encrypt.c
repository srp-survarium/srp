void __cdecl idea_cfb64_encrypt(
        unsigned __int8 *in,
        unsigned __int8 *out,
        int length,
        idea_key_st *schedule,
        unsigned __int8 *ivec,
        int *num,
        int encrypt)
{
  int *v7; // eax
  int v8; // ebp
  int v9; // esi
  int v10; // edx
  unsigned int v11; // ecx
  int v12; // ecx
  unsigned __int8 v13; // al
  int v14; // edx
  unsigned int v15; // ecx
  int v16; // ecx
  unsigned __int8 v17; // al
  unsigned __int8 v18; // cl
  unsigned int d; // [esp+10h] [ebp-8h] BYREF
  int v20; // [esp+14h] [ebp-4h]

  v7 = num;
  v8 = length;
  v9 = *num;
  if ( !encrypt )
  {
    if ( length )
    {
      do
      {
        --v8;
        if ( !v9 )
        {
          v14 = ivec[5];
          d = _byteswap_ulong(*(_DWORD *)ivec);
          v20 = (v14 << 16) | (ivec[4] << 24) | ivec[7] | (ivec[6] << 8);
          idea_encrypt(&d, schedule);
          v15 = d;
          *ivec = HIBYTE(d);
          ivec[1] = BYTE2(v15);
          ivec[2] = BYTE1(v15);
          ivec[3] = v15;
          v16 = v20;
          ivec[4] = HIBYTE(v20);
          ivec[5] = BYTE2(v16);
          ivec[6] = BYTE1(v16);
          ivec[7] = v16;
        }
        v17 = *in++;
        v18 = ivec[v9];
        ivec[v9] = v17;
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
      v10 = ivec[5];
      d = _byteswap_ulong(*(_DWORD *)ivec);
      v20 = (v10 << 16) | (ivec[4] << 24) | ivec[7] | (ivec[6] << 8);
      idea_encrypt(&d, schedule);
      v11 = d;
      *ivec = HIBYTE(d);
      ivec[1] = BYTE2(v11);
      ivec[2] = BYTE1(v11);
      ivec[3] = v11;
      v12 = v20;
      ivec[4] = HIBYTE(v20);
      ivec[5] = BYTE2(v12);
      ivec[6] = BYTE1(v12);
      ivec[7] = v12;
    }
    v13 = ivec[v9] ^ *in++;
    *out = v13;
    ivec[v9] = v13;
    v9 = ((_BYTE)v9 + 1) & 7;
    ++out;
  }
  while ( v8 );
  *num = v9;
}
