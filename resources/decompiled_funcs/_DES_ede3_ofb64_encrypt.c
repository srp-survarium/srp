void __cdecl DES_ede3_ofb64_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        int length,
        DES_ks *k1,
        DES_ks *k2,
        DES_ks *k3,
        unsigned __int8 (*ivec)[8],
        int *num)
{
  int v8; // edx
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  unsigned __int8 v14; // al
  unsigned __int8 *v15; // ebp
  unsigned __int8 *v16; // esi
  int v17; // [esp+14h] [ebp-30h]
  int v18; // [esp+18h] [ebp-2Ch]
  int v19; // [esp+1Ch] [ebp-28h] BYREF
  int v20; // [esp+20h] [ebp-24h]
  unsigned __int8 *v21; // [esp+24h] [ebp-20h]
  DES_ks *v22; // [esp+28h] [ebp-1Ch]
  unsigned __int8 *v23; // [esp+2Ch] [ebp-18h]
  DES_ks *v24; // [esp+30h] [ebp-14h]
  DES_ks *v25; // [esp+34h] [ebp-10h]
  int v26; // [esp+38h] [ebp-Ch]
  int v27; // [esp+3Ch] [ebp-8h]

  v21 = out;
  v22 = k3;
  v24 = k2;
  v8 = (*ivec)[1];
  v9 = *num;
  v23 = &(*ivec)[1];
  v25 = k1;
  v10 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | (v8 << 8) | (*ivec)[0];
  v11 = *(unsigned __int16 *)&(*ivec)[4];
  v12 = *(unsigned __int16 *)&(*ivec)[6];
  v26 = v10;
  v13 = (v12 << 16) | v11;
  v27 = v13;
  v17 = length;
  v18 = 0;
  v19 = v10;
  v20 = v13;
  if ( length )
  {
    do
    {
      --v17;
      if ( !v9 )
      {
        DES_encrypt3(&v19, v25, v24, v22);
        v13 = v20;
        v10 = v19;
        v26 = v19;
        v27 = v20;
        ++v18;
      }
      v14 = *in ^ *((_BYTE *)&v26 + v9);
      v15 = v21;
      ++in;
      *v21 = v14;
      v9 = ((_BYTE)v9 + 1) & 7;
      v21 = v15 + 1;
    }
    while ( v17 );
    if ( v18 )
    {
      (*ivec)[0] = v10;
      v16 = v23;
      *v23 = BYTE1(v10);
      *++v16 = BYTE2(v10);
      *++v16 = HIBYTE(v10);
      v16[1] = v13;
      v16 += 2;
      *v16++ = BYTE1(v13);
      *v16 = BYTE2(v13);
      v16[1] = HIBYTE(v13);
    }
    *num = v9;
  }
  else
  {
    *num = v9;
  }
}
