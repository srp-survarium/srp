int __cdecl RSA_verify_PKCS1_PSS(
        rsa_st *rsa,
        const unsigned __int8 *mHash,
        const env_md_st *Hash,
        const unsigned __int8 *EM,
        int sLen)
{
  const unsigned __int8 *v5; // esi
  int v6; // ebx
  int v7; // ebp
  int v8; // eax
  int v10; // edi
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // esi
  unsigned __int8 v16; // cl
  int v17; // esi
  unsigned int v18; // edi
  unsigned __int8 *v19; // esi
  unsigned int v20; // eax
  unsigned __int8 *v21; // edi
  int v22; // [esp+10h] [ebp-70h]
  unsigned __int8 *seed; // [esp+14h] [ebp-6Ch]
  unsigned int seedlen; // [esp+18h] [ebp-68h]
  env_md_ctx_st ctx; // [esp+24h] [ebp-5Ch] BYREF
  unsigned __int8 v26[64]; // [esp+3Ch] [ebp-44h] BYREF

  v5 = EM;
  v22 = 0;
  v6 = EVP_MD_size(Hash);
  seedlen = v6;
  if ( v6 < 0 )
    return 0;
  if ( sLen == -1 )
  {
    sLen = v6;
    goto LABEL_4;
  }
  if ( sLen == -2 )
  {
    sLen = -2;
    goto LABEL_4;
  }
  if ( sLen < -2 )
  {
    ERR_put_error(4u, 126, 136, ".\\crypto\\rsa\\rsa_pss.c", 97);
    return 0;
  }
LABEL_4:
  v7 = ((unsigned __int8)BN_num_bits(rsa->n) - 1) & 7;
  v8 = RSA_size(rsa);
  if ( ((unsigned __int8)(255 << v7) & *EM) != 0 )
  {
    ERR_put_error(4u, 126, 133, ".\\crypto\\rsa\\rsa_pss.c", 105);
    return v22;
  }
  if ( !v7 )
  {
    v5 = EM + 1;
    --v8;
  }
  if ( v8 < v6 + sLen + 2 )
  {
    ERR_put_error(4u, 126, 109, ".\\crypto\\rsa\\rsa_pss.c", 115);
    return 0;
  }
  if ( v5[v8 - 1] != 0xBC )
  {
    ERR_put_error(4u, 126, 134, ".\\crypto\\rsa\\rsa_pss.c", 120);
    return 0;
  }
  v10 = v8 - v6 - 1;
  seed = (unsigned __int8 *)&v5[v10];
  v11 = (unsigned __int8 *)CRYPTO_malloc(v10, ".\\crypto\\rsa\\rsa_pss.c", 125);
  if ( v11 )
  {
    if ( PKCS1_MGF1(v11, v10, seed, seedlen, Hash) >= 0 )
    {
      if ( v10 > 0 )
      {
        v12 = v11;
        v13 = v5 - v11;
        v14 = v10;
        do
        {
          *v12 ^= v12[v13];
          ++v12;
          --v14;
        }
        while ( v14 );
      }
      if ( v7 )
        *v11 &= 255 >> (8 - v7);
      v15 = 0;
      if ( !*v11 )
      {
        do
        {
          if ( v15 >= v10 - 1 )
            break;
          ++v15;
        }
        while ( !v11[v15] );
      }
      v16 = v11[v15];
      v17 = v15 + 1;
      if ( v16 == 1 )
      {
        if ( sLen < 0 || v10 - v17 == sLen )
        {
          EVP_MD_CTX_init(&ctx);
          EVP_DigestInit_ex(&ctx, Hash, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          v18 = v10 - v17;
          if ( v18 )
            EVP_DigestUpdate(&ctx);
          EVP_DigestFinal(v18, &ctx, v26, 0);
          EVP_MD_CTX_cleanup(v18, &ctx);
          v19 = seed;
          v20 = seedlen;
          v21 = v26;
          if ( seedlen < 4 )
          {
LABEL_39:
            if ( !v20 || *v19 == *v21 && (v20 <= 1 || v19[1] == v21[1] && (v20 <= 2 || v19[2] == v21[2])) )
            {
              v22 = 1;
              goto err_149;
            }
          }
          else
          {
            while ( *(_DWORD *)v21 == *(_DWORD *)v19 )
            {
              v20 -= 4;
              v19 += 4;
              v21 += 4;
              if ( v20 < 4 )
                goto LABEL_39;
            }
          }
          ERR_put_error(4u, 126, 104, ".\\crypto\\rsa\\rsa_pss.c", 158);
          v22 = 0;
        }
        else
        {
          ERR_put_error(4u, 126, 136, ".\\crypto\\rsa\\rsa_pss.c", 145);
        }
      }
      else
      {
        ERR_put_error(4u, 126, 135, ".\\crypto\\rsa\\rsa_pss.c", 140);
      }
    }
  }
  else
  {
    ERR_put_error(4u, 126, 65, ".\\crypto\\rsa\\rsa_pss.c", 128);
  }
err_149:
  if ( !v11 )
    return v22;
  CRYPTO_free(v11);
  return v22;
}
