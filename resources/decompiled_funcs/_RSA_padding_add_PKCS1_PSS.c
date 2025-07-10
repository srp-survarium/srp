int __cdecl RSA_padding_add_PKCS1_PSS(
        rsa_st *rsa,
        unsigned __int8 *EM,
        const unsigned __int8 *mHash,
        const env_md_st *Hash,
        int sLen)
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  int v8; // edi
  _BYTE *v9; // ebp
  unsigned int v11; // edi
  unsigned int v12; // ebp
  unsigned int v13; // edi
  unsigned __int8 *v14; // eax
  int i; // ecx
  _BYTE *v16; // [esp+8h] [ebp-28h]
  int v17; // [esp+Ch] [ebp-24h]
  int v18; // [esp+10h] [ebp-20h]
  int v19; // [esp+14h] [ebp-1Ch]
  env_md_ctx_st ctx; // [esp+18h] [ebp-18h] BYREF

  v17 = 0;
  v16 = 0;
  v5 = EVP_MD_size(Hash);
  v6 = v5;
  if ( v5 >= 0 )
  {
    v7 = sLen;
    if ( sLen == -1 )
    {
      v7 = v5;
    }
    else if ( sLen <= -3 )
    {
      ERR_put_error(4u, 125, 136, ".\\crypto\\rsa\\rsa_pss.c", 195);
      return 0;
    }
    v19 = ((unsigned __int8)BN_num_bits(rsa->n) - 1) & 7;
    v8 = RSA_size(rsa);
    v18 = v8;
    if ( !v19 )
    {
      *EM = 0;
      --v8;
      ++EM;
      v18 = v8;
    }
    if ( v7 == -2 )
    {
      v7 = v8 - v6 - 2;
    }
    else if ( v8 < v6 + v7 + 2 )
    {
      ERR_put_error(4u, 125, 110, ".\\crypto\\rsa\\rsa_pss.c", 213);
      return v17;
    }
    if ( v7 <= 0 )
      goto LABEL_17;
    v9 = CRYPTO_malloc(v7, ".\\crypto\\rsa\\rsa_pss.c", 218);
    v16 = v9;
    if ( !v9 )
    {
      ERR_put_error(4u, 125, 65, ".\\crypto\\rsa\\rsa_pss.c", 222);
      goto err_150;
    }
    if ( RAND_bytes() > 0 )
    {
LABEL_17:
      v11 = v8 - v6;
      v12 = v11 - 1;
      EVP_MD_CTX_init(&ctx);
      EVP_DigestInit_ex(&ctx, Hash, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( v7 )
        EVP_DigestUpdate(&ctx);
      EVP_DigestFinal(v11, &ctx, &EM[v12], 0);
      EVP_MD_CTX_cleanup(v11, &ctx);
      if ( !PKCS1_MGF1(EM, v11 - 1, &EM[v12], v6, Hash) )
      {
        v13 = v11 - v7;
        EM[v13 - 2] ^= 1u;
        v14 = &EM[v13 - 1];
        if ( v7 > 0 )
        {
          for ( i = 0; i < v7; ++i )
            *v14++ ^= v16[i];
        }
        if ( v19 )
          *EM &= 255 >> (8 - v19);
        EM[v18 - 1] = -68;
        v17 = 1;
      }
    }
    v9 = v16;
err_150:
    if ( v9 )
    {
      CRYPTO_free(v9);
      return v17;
    }
    return v17;
  }
  return 0;
}
