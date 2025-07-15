int __usercall RSA_padding_add_PKCS1_PSS@<eax>(
        int a1@<ebx>,
        rsa_st *rsa,
        unsigned __int8 *EM,
        const unsigned __int8 *mHash,
        const env_md_st *Hash,
        int sLen)
{
  int v6; // eax
  engine_st *v7; // ebx
  int v8; // esi
  int v9; // edi
  _BYTE *v10; // ebp
  int v12; // edi
  int v13; // ebp
  int v14; // edi
  unsigned __int8 *v15; // eax
  int i; // ecx
  _BYTE *v17; // [esp+8h] [ebp-28h]
  int v18; // [esp+Ch] [ebp-24h]
  int v19; // [esp+10h] [ebp-20h]
  int v20; // [esp+14h] [ebp-1Ch]
  env_md_ctx_st ctx; // [esp+18h] [ebp-18h] BYREF

  v18 = 0;
  v17 = 0;
  v6 = EVP_MD_size(a1, Hash);
  v7 = (engine_st *)v6;
  if ( v6 >= 0 )
  {
    v8 = sLen;
    if ( sLen == -1 )
    {
      v8 = v6;
    }
    else if ( sLen <= -3 )
    {
      ERR_put_error(v6, 4u, 125, 136, ".\\crypto\\rsa\\rsa_pss.c", 195);
      return 0;
    }
    v20 = ((unsigned __int8)BN_num_bits(rsa->n) - 1) & 7;
    v9 = RSA_size(rsa);
    v19 = v9;
    if ( !v20 )
    {
      *EM = 0;
      --v9;
      ++EM;
      v19 = v9;
    }
    if ( v8 == -2 )
    {
      v8 = v9 - (_DWORD)v7 - 2;
    }
    else if ( v9 < (int)&v7->id + v8 + 2 )
    {
      ERR_put_error((int)v7, 4u, 125, 110, ".\\crypto\\rsa\\rsa_pss.c", 213);
      return v18;
    }
    if ( v8 <= 0 )
      goto LABEL_17;
    v10 = CRYPTO_malloc(v8, ".\\crypto\\rsa\\rsa_pss.c", 218);
    v17 = v10;
    if ( !v10 )
    {
      ERR_put_error((int)v7, 4u, 125, 65, ".\\crypto\\rsa\\rsa_pss.c", 222);
      goto err_152;
    }
    if ( RAND_bytes(v9) > 0 )
    {
LABEL_17:
      v12 = v9 - (_DWORD)v7;
      v13 = v12 - 1;
      EVP_MD_CTX_init(&ctx);
      EVP_DigestInit_ex(v7, &ctx, Hash, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( v8 )
        EVP_DigestUpdate(&ctx);
      EVP_DigestFinal(v12, (int)v7, &ctx, &EM[v13], 0);
      EVP_MD_CTX_cleanup(v12, (int)v7, &ctx);
      if ( !PKCS1_MGF1(v12, EM, v12 - 1, &EM[v13], (int)v7, Hash) )
      {
        v14 = v12 - v8;
        EM[v14 - 2] ^= 1u;
        v15 = &EM[v14 - 1];
        if ( v8 > 0 )
        {
          for ( i = 0; i < v8; ++i )
            *v15++ ^= v17[i];
        }
        if ( v20 )
          *EM &= 255 >> (8 - v20);
        EM[v19 - 1] = -68;
        v18 = 1;
      }
    }
    v10 = v17;
err_152:
    if ( v10 )
    {
      CRYPTO_free(v10);
      return v18;
    }
    return v18;
  }
  return 0;
}
