int __usercall RSA_padding_check_PKCS1_OAEP@<eax>(
        int a1@<ebx>,
        unsigned __int8 *to,
        int tlen,
        const __m128i *from,
        unsigned int flen,
        int num,
        unsigned __int8 *param,
        unsigned int plen)
{
  unsigned __int8 *v8; // edi
  int v9; // eax
  int v10; // ebx
  int v11; // ebp
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // esi
  const env_md_st *v14; // eax
  int i; // ecx
  unsigned __int8 *v16; // eax
  const env_md_st *v17; // eax
  unsigned __int8 *v18; // eax
  int v19; // esi
  const env_md_st *v20; // eax
  unsigned __int8 *v21; // eax
  unsigned int v22; // ecx
  int v23; // eax
  bool v24; // zf
  int v25; // eax
  signed int v26; // ebp
  unsigned __int8 *src; // [esp+10h] [ebp-3Ch]
  int v29; // [esp+14h] [ebp-38h]
  unsigned __int8 v30[20]; // [esp+20h] [ebp-2Ch] BYREF
  unsigned __int8 v31[20]; // [esp+34h] [ebp-18h] BYREF

  v8 = 0;
  v9 = num - 1;
  v29 = 0;
  if ( num - 1 < 41 )
    goto decoding_err;
  v10 = v9 - flen;
  if ( (int)(v9 - flen) < 0 )
  {
    v29 = 1;
    v10 = 0;
    flen = num - 1;
  }
  v11 = num - 21;
  v12 = (unsigned __int8 *)CRYPTO_malloc(num - 21 + num - 1, ".\\crypto\\rsa\\rsa_oaep.c", 123);
  v8 = v12;
  if ( v12 )
  {
    v13 = &v12[v11];
    memset((int)&v12[v11], 0, v10);
    memcpy((int)&v13[v10], from, flen);
    src = v13 + 20;
    v14 = EVP_sha1();
    if ( PKCS1_MGF1((int)v8, (int)(v13 + 20), v30, 20, v13 + 20, v11, v14) )
      return -1;
    for ( i = 0; i < 20; i += 5 )
    {
      v16 = &v30[i];
      *v16 ^= v16[v13 - v30];
      v16[1] ^= v13[i + 1];
      v16[2] ^= v13[i + 2];
      v16[3] ^= v13[i + 3];
      a1 = v13[i + 4];
      v16[4] ^= a1;
    }
    v17 = EVP_sha1();
    if ( PKCS1_MGF1((int)v8, a1, v8, v11, v30, 20, v17) )
      return -1;
    if ( v11 > 0 )
    {
      v18 = v8;
      v19 = num - 21;
      do
      {
        *v18 ^= v18[src - v8];
        ++v18;
        --v19;
      }
      while ( v19 );
    }
    v20 = EVP_sha1();
    EVP_Digest((int)v8, (engine_st *)a1, param, plen, v31, 0, v20, 0);
    v21 = v31;
    v22 = 20;
    while ( *(_DWORD *)&v21[v8 - v31] == *(_DWORD *)v21 )
    {
      v22 -= 4;
      v21 += 4;
      if ( v22 < 4 )
      {
        if ( !v29 )
        {
          v23 = 20;
          v24 = v11 == 20;
          if ( v11 > 20 )
          {
            do
            {
              if ( v8[v23] )
                break;
              ++v23;
            }
            while ( v23 < v11 );
            v24 = v23 == v11;
          }
          if ( !v24 && v8[v23] == 1 )
          {
            v25 = v23 + 1;
            v26 = v11 - v25;
            if ( tlen >= v26 )
            {
              memcpy((int)to, (const __m128i *)&v8[v25], v26);
              CRYPTO_free(v8);
              return v26;
            }
            else
            {
              ERR_put_error(a1, 4u, 122, 109, ".\\crypto\\rsa\\rsa_oaep.c", 166);
              CRYPTO_free(v8);
              return -1;
            }
          }
        }
        break;
      }
    }
decoding_err:
    ERR_put_error(a1, 4u, 122, 121, ".\\crypto\\rsa\\rsa_oaep.c", 179);
    if ( v8 )
      CRYPTO_free(v8);
    return -1;
  }
  ERR_put_error(v10, 4u, 122, 65, ".\\crypto\\rsa\\rsa_oaep.c", 126);
  return -1;
}
