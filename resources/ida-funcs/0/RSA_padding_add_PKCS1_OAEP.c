int __cdecl RSA_padding_add_PKCS1_OAEP(
        unsigned __int8 *to,
        int tlen,
        const __m128i *from,
        engine_st *flen,
        unsigned __int8 *param,
        unsigned int plen)
{
  int v6; // ebp
  const unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // edi
  const env_md_st *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // ebp
  int v13; // ebx
  const env_md_st *v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // ecx
  int v17; // edx
  const env_md_st *v18; // eax
  unsigned __int8 *v19; // ecx
  int v20; // edi
  _BYTE *v21; // ebp
  int v22; // edx
  unsigned __int8 *v23; // eax
  int v24; // esi
  unsigned __int8 *src; // [esp+Ch] [ebp-20h]
  void *str; // [esp+10h] [ebp-1Ch]
  unsigned __int8 v27; // [esp+14h] [ebp-18h] BYREF
  char v28; // [esp+15h] [ebp-17h] BYREF
  char v29; // [esp+16h] [ebp-16h] BYREF
  char v30; // [esp+17h] [ebp-15h] BYREF
  _BYTE v31[16]; // [esp+18h] [ebp-14h] BYREF

  v6 = tlen - 1;
  if ( (int)flen > tlen - 42 )
  {
    ERR_put_error((int)flen, 4u, 121, 110, ".\\crypto\\rsa\\rsa_oaep.c", 45);
    return 0;
  }
  if ( v6 < 41 )
  {
    ERR_put_error((int)flen, 4u, 121, 120, ".\\crypto\\rsa\\rsa_oaep.c", 51);
    return 0;
  }
  *to = 0;
  v8 = to + 1;
  v9 = to + 21;
  v10 = EVP_sha1();
  EVP_Digest((int)v9, flen, param, plen, v9, 0, v10, 0);
  memset((int)(to + 41), 0, v6 - (_DWORD)flen - 41);
  v11 = (unsigned __int8 *)(to + 21 - (unsigned __int8 *)flen + v6);
  *(v11 - 21) = 1;
  memcpy((int)(v11 - 20), from, (unsigned int)flen);
  if ( RAND_bytes((int)(to + 21)) <= 0 )
    return 0;
  v12 = tlen - 21;
  v13 = (int)CRYPTO_malloc(tlen - 21, ".\\crypto\\rsa\\rsa_oaep.c", 72);
  str = (void *)v13;
  if ( !v13 )
  {
    ERR_put_error(0, 4u, 121, 65, ".\\crypto\\rsa\\rsa_oaep.c", 75);
    return 0;
  }
  v14 = EVP_sha1();
  if ( PKCS1_MGF1((int)v9, v13, (unsigned __int8 *)v13, v12, v8, 20, v14) < 0 )
    return 0;
  if ( v12 > 0 )
  {
    v15 = to + 21;
    v16 = v13 - (_DWORD)v9;
    v17 = tlen - 21;
    do
    {
      LOBYTE(v13) = v15[v16];
      *v15++ ^= v13;
      --v17;
    }
    while ( v17 );
  }
  v18 = EVP_sha1();
  if ( PKCS1_MGF1((int)v9, v13, &v27, 20, v9, v12, v18) < 0 )
    return 0;
  v19 = (unsigned __int8 *)(&v27 - v8);
  v20 = &v28 - (char *)v8;
  v21 = (_BYTE *)(&v29 - (char *)v8);
  v22 = &v30 - (char *)v8;
  v23 = to + 1;
  src = (unsigned __int8 *)(v31 - v8);
  v24 = 4;
  do
  {
    *v23 ^= v23[(_DWORD)v19];
    v23[1] ^= v23[v20];
    v23[2] ^= v21[(_DWORD)v23];
    v23[3] ^= v23[v22];
    v23[4] ^= v23[(_DWORD)src];
    v23 += 5;
    --v24;
  }
  while ( v24 );
  CRYPTO_free(str);
  return 1;
}
