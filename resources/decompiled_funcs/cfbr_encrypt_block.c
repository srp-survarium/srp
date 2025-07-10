void __fastcall cfbr_encrypt_block(
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *),
        const unsigned __int8 *in,
        unsigned __int8 *out,
        int nbits,
        const void *key,
        unsigned __int8 *ivec,
        int enc)
{
  int v8; // esi
  const unsigned __int8 *v9; // ecx
  unsigned __int8 v10; // al
  int v11; // ebp
  int v12; // ebx
  int i; // edx
  _BYTE *v14; // ecx
  char v15; // al
  char v16; // dl
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  char *v21; // eax
  int v22; // ecx
  int v23; // edx
  unsigned __int8 *v24; // edi
  unsigned __int8 *v25; // esi
  int v26; // ebp
  char v27; // al
  char v28; // dl
  unsigned __int8 v29; // al
  unsigned __int8 v30; // dl
  char v31; // [esp+Fh] [ebp-31h]
  int v32; // [esp+10h] [ebp-30h]
  int v33; // [esp+18h] [ebp-28h] BYREF
  _DWORD v34[3]; // [esp+1Ch] [ebp-24h]
  _BYTE v35[20]; // [esp+28h] [ebp-18h] BYREF

  if ( (unsigned int)(nbits - 1) <= 0x7F )
  {
    v33 = *(_DWORD *)ivec;
    v34[0] = *((_DWORD *)ivec + 1);
    v34[1] = *((_DWORD *)ivec + 2);
    v34[2] = *((_DWORD *)ivec + 3);
    block(ivec, ivec, key);
    v8 = (nbits + 7) / 8;
    if ( enc )
    {
      if ( v8 > 0 )
      {
        v9 = in;
        do
        {
          v10 = *v9 ^ v9[ivec - in];
          v9[v35 - in] = v10;
          (v9++)[out - in] = v10;
          --v8;
        }
        while ( v8 );
      }
    }
    else
    {
      v11 = 0;
      if ( v8 > 0 )
      {
        v12 = in - v35;
        for ( i = ivec - v35; ; i = ivec - v35 )
        {
          v14 = &v35[v11];
          v15 = v35[v11 + v12];
          v16 = v15 ^ v35[v11 + i];
          *v14 = v15;
          ++v11;
          v14[out - v35] = v16;
          if ( v11 >= v8 )
            break;
        }
      }
    }
    v17 = nbits % 8;
    v18 = nbits / 8;
    v32 = nbits % 8;
    if ( nbits % 8 )
    {
      v31 = 8 - v17;
      v24 = ivec + 1;
      v25 = (unsigned __int8 *)&v33 + v18 + 1;
      v26 = 4;
      do
      {
        v27 = *v25 << v32;
        *(v24 - 1) = (*v25 >> v31) | (*(v25 - 1) << v17);
        v28 = v25[1] << v32;
        *v24 = (v25[1] >> v31) | v27;
        v29 = v25[2];
        v24[1] = (v29 >> v31) | v28;
        v30 = v25[3];
        LOBYTE(v17) = nbits % 8;
        v25 += 4;
        v24 += 4;
        --v26;
        *(v24 - 2) = (v29 << v32) | (v30 >> v31);
      }
      while ( v26 );
    }
    else
    {
      v19 = *(_DWORD *)((char *)&v34[-1] + v18);
      v20 = *(_DWORD *)((char *)v34 + v18);
      v21 = (char *)&v34[-1] + v18;
      *(_DWORD *)ivec = v19;
      v22 = *((_DWORD *)v21 + 2);
      *((_DWORD *)ivec + 1) = v20;
      v23 = *((_DWORD *)v21 + 3);
      *((_DWORD *)ivec + 2) = v22;
      *((_DWORD *)ivec + 3) = v23;
    }
  }
}
