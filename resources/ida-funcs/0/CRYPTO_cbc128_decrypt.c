void __cdecl CRYPTO_cbc128_decrypt(
        unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const void *key,
        unsigned __int8 *ivec,
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  unsigned __int8 *v6; // ebx
  unsigned int v7; // ebp
  const unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned int v11; // eax
  unsigned __int8 *v12; // eax
  unsigned int v13; // eax
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // edx
  unsigned __int8 v16; // bl
  int v17; // esi
  unsigned __int8 *v18; // ecx
  unsigned int v19; // edx
  unsigned __int8 v20; // [esp+13h] [ebp-39h]
  unsigned __int8 v21; // [esp+13h] [ebp-39h]
  unsigned __int8 v22; // [esp+13h] [ebp-39h]
  unsigned __int8 *v23; // [esp+14h] [ebp-38h]
  int v24; // [esp+14h] [ebp-38h]
  unsigned __int8 *v25; // [esp+14h] [ebp-38h]
  unsigned int v26; // [esp+18h] [ebp-34h]
  int v27; // [esp+18h] [ebp-34h]
  int v28; // [esp+18h] [ebp-34h]
  int v29; // [esp+1Ch] [ebp-30h]
  unsigned int v30; // [esp+1Ch] [ebp-30h]
  int v31; // [esp+1Ch] [ebp-30h]
  int v32; // [esp+20h] [ebp-2Ch]
  int v33; // [esp+20h] [ebp-2Ch]
  unsigned int v34; // [esp+24h] [ebp-28h]
  int v35; // [esp+2Ch] [ebp-20h]
  unsigned __int8 v36[16]; // [esp+38h] [ebp-14h] BYREF

  v6 = out;
  v7 = len;
  v8 = in;
  if ( in == out )
  {
    if ( len >= 0x10 )
    {
      v32 = ivec - v36;
      v27 = out - v36;
      v24 = in - v36;
      v34 = len >> 4;
      v6 = &out[16 * (len >> 4)];
      do
      {
        block(v8, v36, key);
        v11 = 0;
        v30 = 0;
        do
        {
          v12 = &v36[v11];
          v35 = *(_DWORD *)&v12[v24];
          *(_DWORD *)&v12[v27] = *(_DWORD *)v12 ^ *(_DWORD *)&v12[v32];
          *(_DWORD *)&v12[v32] = v35;
          v11 = v30 + 4;
          v30 = v11;
        }
        while ( v11 < 0x10 );
        v24 += 16;
        v27 += 16;
        v7 -= 16;
        v8 += 16;
        --v34;
      }
      while ( v34 );
    }
  }
  else
  {
    v9 = ivec;
    v23 = ivec;
    if ( len >= 0x10 )
    {
      v26 = len >> 4;
      do
      {
        block(v8, v6, key);
        v10 = v6;
        v29 = 4;
        do
        {
          *(_DWORD *)v10 ^= *(_DWORD *)&v10[v23 - v6];
          v10 += 4;
          --v29;
        }
        while ( v29 );
        v23 = (unsigned __int8 *)v8;
        v7 -= 16;
        v8 += 16;
        v6 += 16;
        --v26;
      }
      while ( v26 );
      v9 = v23;
    }
    *(_DWORD *)ivec = *(_DWORD *)v9;
    *((_DWORD *)ivec + 1) = *((_DWORD *)v9 + 1);
    *((_DWORD *)ivec + 2) = *((_DWORD *)v9 + 2);
    *((_DWORD *)ivec + 3) = *((_DWORD *)v9 + 3);
  }
  if ( v7 )
  {
    v33 = ivec - v36;
    v25 = v6 + 2;
    v31 = v6 - v36;
    v28 = v8 - v36;
    while ( 1 )
    {
      block(v8, v36, key);
      v13 = 0;
      while ( 1 )
      {
        if ( v13 >= v7 )
          goto LABEL_22;
        v14 = &v36[v13];
        v20 = v36[v13 + v28];
        v14[v31] = *v14 ^ v14[v33];
        v14[v33] = v20;
        if ( (unsigned int)&v36[v13 + 1 - (_DWORD)v36] >= v7 )
        {
          ++v13;
LABEL_22:
          v15 = v25;
          goto LABEL_23;
        }
        v21 = v8[v13 + 1];
        v15 = v25;
        v25[v13 - 1] = ivec[v13 + 1] ^ v14[1];
        ivec[v13 + 1] = v21;
        if ( (unsigned int)&v14[2 - (_DWORD)v36] >= v7 )
        {
          v13 += 2;
          goto LABEL_23;
        }
        v22 = v8[v13 + 2];
        v25[v13] = ivec[v13 + 2] ^ v14[2];
        ivec[v13 + 2] = v22;
        if ( (unsigned int)&v14[3 - (_DWORD)v36] >= v7 )
          break;
        v16 = v8[v13 + 3];
        v25[v13 + 1] = ivec[v13 + 3] ^ v14[3];
        ivec[v13 + 3] = v16;
        v13 += 4;
        if ( v13 >= 0x10 )
          goto LABEL_22;
      }
      v13 += 3;
LABEL_23:
      if ( v7 <= 0x10 )
        break;
      v28 += 16;
      v31 += 16;
      v7 -= 16;
      v8 += 16;
      v25 = v15 + 16;
      if ( !v7 )
        return;
    }
    if ( v13 < 0x10 )
    {
      v17 = v8 - ivec;
      v18 = &ivec[v13];
      v19 = 16 - v13;
      do
      {
        *v18 = v18[v17];
        ++v18;
        --v19;
      }
      while ( v19 );
    }
  }
}
