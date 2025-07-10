int __cdecl RSA_padding_check_PKCS1_OAEP(
        unsigned __int8 *to,
        int tlen,
        unsigned __int8 *from,
        unsigned int flen,
        int num,
        unsigned __int8 *param,
        unsigned int plen)
{
  unsigned __int8 *v7; // edi
  int v8; // eax
  unsigned int v9; // ebx
  int v10; // ebp
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // esi
  const env_md_st *v13; // eax
  int i; // ecx
  unsigned __int8 *v15; // eax
  const env_md_st *v16; // eax
  unsigned __int8 *v17; // eax
  int v18; // esi
  const env_md_st *v19; // eax
  unsigned __int8 *v20; // eax
  unsigned int v21; // ecx
  int v22; // eax
  bool v23; // zf
  int v24; // eax
  signed int v25; // ebp
  unsigned __int8 *src; // [esp+10h] [ebp-3Ch]
  int v28; // [esp+14h] [ebp-38h]
  unsigned __int8 mask[20]; // [esp+20h] [ebp-2Ch] BYREF
  unsigned __int8 md[20]; // [esp+34h] [ebp-18h] BYREF

  v7 = 0;
  v8 = num - 1;
  v28 = 0;
  if ( num - 1 < 41 )
    goto decoding_err;
  v9 = v8 - flen;
  if ( (int)(v8 - flen) < 0 )
  {
    v28 = 1;
    v9 = 0;
    flen = num - 1;
  }
  v10 = num - 21;
  v11 = (unsigned __int8 *)CRYPTO_malloc(num - 21 + num - 1, ".\\crypto\\rsa\\rsa_oaep.c", 123);
  v7 = v11;
  if ( v11 )
  {
    v12 = &v11[v10];
    memset((int)&v11[v10], 0, v9);
    memcpy(&v12[v9], from, flen);
    src = v12 + 20;
    v13 = EVP_sha1();
    if ( PKCS1_MGF1((unsigned int)v7, mask, 20, v12 + 20, v10, v13) )
      return -1;
    for ( i = 0; i < 20; i += 5 )
    {
      v15 = &mask[i];
      *v15 ^= v15[v12 - mask];
      v15[1] ^= v12[i + 1];
      v15[2] ^= v12[i + 2];
      v15[3] ^= v12[i + 3];
      v15[4] ^= v12[i + 4];
    }
    v16 = EVP_sha1();
    if ( PKCS1_MGF1((unsigned int)v7, v7, v10, mask, 0x14u, v16) )
      return -1;
    if ( v10 > 0 )
    {
      v17 = v7;
      v18 = num - 21;
      do
      {
        *v17 ^= v17[src - v7];
        ++v17;
        --v18;
      }
      while ( v18 );
    }
    v19 = EVP_sha1();
    EVP_Digest((unsigned int)v7, param, plen, md, 0, v19, 0);
    v20 = md;
    v21 = 20;
    while ( *(_DWORD *)&v20[v7 - md] == *(_DWORD *)v20 )
    {
      v21 -= 4;
      v20 += 4;
      if ( v21 < 4 )
      {
        if ( !v28 )
        {
          v22 = 20;
          v23 = v10 == 20;
          if ( v10 > 20 )
          {
            do
            {
              if ( v7[v22] )
                break;
              ++v22;
            }
            while ( v22 < v10 );
            v23 = v22 == v10;
          }
          if ( !v23 && v7[v22] == 1 )
          {
            v24 = v22 + 1;
            v25 = v10 - v24;
            if ( tlen >= v25 )
            {
              memcpy(to, &v7[v24], v25);
              CRYPTO_free(v7);
              return v25;
            }
            else
            {
              ERR_put_error(4u, 122, 109, ".\\crypto\\rsa\\rsa_oaep.c", 166);
              CRYPTO_free(v7);
              return -1;
            }
          }
        }
        break;
      }
    }
decoding_err:
    ERR_put_error(4u, 122, 121, ".\\crypto\\rsa\\rsa_oaep.c", 179);
    if ( v7 )
      CRYPTO_free(v7);
    return -1;
  }
  ERR_put_error(4u, 122, 65, ".\\crypto\\rsa\\rsa_oaep.c", 126);
  return -1;
}
