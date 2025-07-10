void __cdecl idea_ofb64_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        int length,
        idea_key_st *schedule,
        unsigned __int8 *ivec,
        int *num)
{
  int v6; // esi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // ecx
  int v10; // edx
  int v11; // ebx
  int v13; // edx
  unsigned __int8 *v15; // eax
  int v16; // [esp+10h] [ebp-28h]
  int v17; // [esp+18h] [ebp-20h]
  unsigned int d; // [esp+1Ch] [ebp-1Ch] BYREF
  int v19; // [esp+20h] [ebp-18h]
  idea_key_st *key; // [esp+24h] [ebp-14h]
  unsigned __int8 *v21; // [esp+28h] [ebp-10h]
  char v22; // [esp+2Ch] [ebp-Ch]
  char v23; // [esp+2Dh] [ebp-Bh]
  char v24; // [esp+2Eh] [ebp-Ah]
  char v25; // [esp+2Fh] [ebp-9h]
  char v26; // [esp+30h] [ebp-8h]
  char v27; // [esp+31h] [ebp-7h]
  char v28; // [esp+32h] [ebp-6h]
  char v29; // [esp+33h] [ebp-5h]

  key = schedule;
  v6 = *num;
  v7 = ivec[1];
  v17 = length;
  v8 = *ivec;
  v21 = ivec + 1;
  v9 = ivec[3] | (ivec[2] << 8) | (v7 << 16) | (v8 << 24);
  v10 = (ivec[5] << 16) | (ivec[4] << 24);
  v11 = ivec[7] | (ivec[6] << 8);
  v22 = HIBYTE(v9);
  v23 = BYTE2(v9);
  v13 = v11 | v10;
  v24 = BYTE1(v9);
  v26 = HIBYTE(v13);
  v27 = BYTE2(v13);
  v16 = 0;
  d = v9;
  v19 = v13;
  v25 = v9;
  v28 = BYTE1(v13);
  v29 = v13;
  if ( length )
  {
    do
    {
      --v17;
      if ( !v6 )
      {
        idea_encrypt(&d, key);
        v9 = d;
        v22 = HIBYTE(d);
        v23 = BYTE2(d);
        v24 = BYTE1(d);
        v13 = v19;
        v26 = HIBYTE(v19);
        v27 = BYTE2(v19);
        ++v16;
        v25 = d;
        v28 = BYTE1(v19);
        v29 = v19;
      }
      *out++ = *in++ ^ *(&v22 + v6);
      v6 = ((_BYTE)v6 + 1) & 7;
    }
    while ( v17 );
    if ( v16 )
    {
      *ivec = HIBYTE(v9);
      v15 = v21;
      *v21 = BYTE2(v9);
      *++v15 = BYTE1(v9);
      v15[1] = v9;
      v15 += 2;
      *v15++ = HIBYTE(v13);
      *v15++ = BYTE2(v13);
      *v15 = BYTE1(v13);
      v15[1] = v13;
    }
    *num = v6;
  }
  else
  {
    *num = v6;
  }
}
