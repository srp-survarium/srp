int __cdecl RSA_padding_add_PKCS1_OAEP(
        unsigned __int8 *to,
        int tlen,
        unsigned __int8 *from,
        int flen,
        unsigned __int8 *param,
        unsigned int plen)
{
  int v6; // ebp
  const unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // edi
  const env_md_st *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // ebp
  unsigned __int8 *v13; // ebx
  const env_md_st *v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // edx
  const env_md_st *v17; // eax
  unsigned __int8 *v18; // ecx
  int v19; // edi
  _BYTE *v20; // ebp
  int v21; // edx
  unsigned __int8 *v22; // eax
  int v23; // esi
  unsigned __int8 *src; // [esp+Ch] [ebp-20h]
  unsigned __int8 mask; // [esp+14h] [ebp-18h] BYREF
  char v26; // [esp+15h] [ebp-17h] BYREF
  char v27; // [esp+16h] [ebp-16h] BYREF
  char v28; // [esp+17h] [ebp-15h] BYREF
  _BYTE v29[16]; // [esp+18h] [ebp-14h] BYREF

  v6 = tlen - 1;
  if ( flen > tlen - 42 )
  {
    ERR_put_error(4u, 121, 110, ".\\crypto\\rsa\\rsa_oaep.c", 45);
    return 0;
  }
  if ( v6 < 41 )
  {
    ERR_put_error(4u, 121, 120, ".\\crypto\\rsa\\rsa_oaep.c", 51);
    return 0;
  }
  *to = 0;
  v8 = to + 1;
  v9 = to + 21;
  v10 = EVP_sha1();
  EVP_Digest((unsigned int)v9, param, plen, v9, 0, v10, 0);
  memset((int)(to + 41), 0, v6 - flen - 41);
  v11 = &to[v6 + 21 - flen];
  *(v11 - 21) = 1;
  memcpy(v11 - 20, from, flen);
  if ( RAND_bytes() <= 0 )
    return 0;
  v12 = tlen - 21;
  v13 = (unsigned __int8 *)CRYPTO_malloc(tlen - 21, ".\\crypto\\rsa\\rsa_oaep.c", 72);
  if ( !v13 )
  {
    ERR_put_error(4u, 121, 65, ".\\crypto\\rsa\\rsa_oaep.c", 75);
    return 0;
  }
  v14 = EVP_sha1();
  if ( PKCS1_MGF1((unsigned int)v9, v13, v12, v8, 0x14u, v14) < 0 )
    return 0;
  if ( v12 > 0 )
  {
    v15 = to + 21;
    v16 = tlen - 21;
    do
    {
      *v15 ^= v15[v13 - v9];
      ++v15;
      --v16;
    }
    while ( v16 );
  }
  v17 = EVP_sha1();
  if ( PKCS1_MGF1((unsigned int)v9, &mask, 20, v9, v12, v17) < 0 )
    return 0;
  v18 = (unsigned __int8 *)(&mask - v8);
  v19 = &v26 - (char *)v8;
  v20 = (_BYTE *)(&v27 - (char *)v8);
  v21 = &v28 - (char *)v8;
  v22 = to + 1;
  src = (unsigned __int8 *)(v29 - v8);
  v23 = 4;
  do
  {
    *v22 ^= v22[(_DWORD)v18];
    v22[1] ^= v22[v19];
    v22[2] ^= v20[(_DWORD)v22];
    v22[3] ^= v22[v21];
    v22[4] ^= v22[(_DWORD)src];
    v22 += 5;
    --v23;
  }
  while ( v23 );
  CRYPTO_free(v13);
  return 1;
}
