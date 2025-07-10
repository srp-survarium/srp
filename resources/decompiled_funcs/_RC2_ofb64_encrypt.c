void __cdecl RC2_ofb64_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        int length,
        rc2_key_st *schedule,
        unsigned __int8 *ivec,
        int *num)
{
  int v6; // esi
  int v7; // ecx
  int v8; // edx
  unsigned int v9; // ecx
  int v11; // edx
  unsigned int v12; // ebx
  unsigned __int8 *v13; // eax
  int v14; // ecx
  int v15; // [esp+10h] [ebp-28h]
  int v16; // [esp+18h] [ebp-20h]
  unsigned int d; // [esp+1Ch] [ebp-1Ch] BYREF
  int v18; // [esp+20h] [ebp-18h]
  rc2_key_st *key; // [esp+24h] [ebp-14h]
  unsigned __int8 *v20; // [esp+28h] [ebp-10h]
  unsigned int v21; // [esp+2Ch] [ebp-Ch]
  int v22; // [esp+30h] [ebp-8h]

  key = schedule;
  v6 = *num;
  v16 = length;
  v7 = *(unsigned __int16 *)ivec;
  v8 = ivec[2];
  v20 = ivec + 1;
  v9 = (ivec[3] << 24) | (v8 << 16) | v7;
  v11 = *((_DWORD *)ivec + 1);
  v12 = v9;
  v21 = v9;
  v18 = v11;
  v22 = v11;
  v15 = 0;
  d = v9;
  if ( length )
  {
    do
    {
      --v16;
      if ( !v6 )
      {
        RC2_encrypt(&d, key);
        v12 = d;
        v22 = v18;
        ++v15;
        v21 = d;
      }
      *out++ = *in ^ *((_BYTE *)&v21 + v6);
      v6 = ((_BYTE)v6 + 1) & 7;
      ++in;
    }
    while ( v16 );
    if ( v15 )
    {
      v13 = v20;
      *ivec = v12;
      *v13++ = BYTE1(v12);
      *v13 = BYTE2(v12);
      v14 = v18;
      *++v13 = HIBYTE(v12);
      v13[1] = v14;
      v13 += 2;
      *v13++ = BYTE1(v14);
      *v13 = BYTE2(v14);
      v13[1] = HIBYTE(v14);
    }
    *num = v6;
  }
  else
  {
    *num = v6;
  }
}
