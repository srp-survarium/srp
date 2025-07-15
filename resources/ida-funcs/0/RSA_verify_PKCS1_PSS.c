int __usercall RSA_verify_PKCS1_PSS@<eax>(
        int a1@<ebx>,
        rsa_st *rsa,
        const unsigned __int8 *mHash,
        const env_md_st *Hash,
        const unsigned __int8 *EM,
        int sLen)
{
  const unsigned __int8 *v6; // esi
  int v7; // ebx
  int v8; // ebp
  int v9; // eax
  int v11; // edi
  engine_st *v12; // ebx
  engine_st *v13; // eax
  int v14; // esi
  int v15; // ecx
  int v16; // esi
  char v17; // cl
  int v18; // esi
  int v19; // edi
  unsigned __int8 *v20; // esi
  unsigned int v21; // eax
  unsigned __int8 *v22; // edi
  int v23; // [esp+10h] [ebp-70h]
  unsigned __int8 *seed; // [esp+14h] [ebp-6Ch]
  unsigned int seedlen; // [esp+18h] [ebp-68h]
  env_md_ctx_st ctx; // [esp+24h] [ebp-5Ch] BYREF
  unsigned __int8 v27[64]; // [esp+3Ch] [ebp-44h] BYREF

  v6 = EM;
  v23 = 0;
  v7 = EVP_MD_size(a1, Hash);
  seedlen = v7;
  if ( v7 < 0 )
    return 0;
  if ( sLen == -1 )
  {
    sLen = v7;
    goto LABEL_4;
  }
  if ( sLen == -2 )
  {
    sLen = -2;
    goto LABEL_4;
  }
  if ( sLen < -2 )
  {
    ERR_put_error(v7, 4u, 126, 136, ".\\crypto\\rsa\\rsa_pss.c", 97);
    return 0;
  }
LABEL_4:
  v8 = ((unsigned __int8)BN_num_bits(rsa->n) - 1) & 7;
  v9 = RSA_size(rsa);
  if ( ((unsigned __int8)(255 << v8) & *EM) != 0 )
  {
    ERR_put_error(v7, 4u, 126, 133, ".\\crypto\\rsa\\rsa_pss.c", 105);
    return v23;
  }
  if ( !v8 )
  {
    v6 = EM + 1;
    --v9;
  }
  if ( v9 < v7 + sLen + 2 )
  {
    ERR_put_error(v7, 4u, 126, 109, ".\\crypto\\rsa\\rsa_pss.c", 115);
    return 0;
  }
  if ( v6[v9 - 1] != 0xBC )
  {
    ERR_put_error(v7, 4u, 126, 134, ".\\crypto\\rsa\\rsa_pss.c", 120);
    return 0;
  }
  v11 = v9 - v7 - 1;
  seed = (unsigned __int8 *)&v6[v11];
  v12 = (engine_st *)CRYPTO_malloc(v11, ".\\crypto\\rsa\\rsa_pss.c", 125);
  if ( v12 )
  {
    if ( PKCS1_MGF1(v11, (unsigned __int8 *)v12, v11, seed, seedlen, Hash) >= 0 )
    {
      if ( v11 > 0 )
      {
        v13 = v12;
        v14 = v6 - (const unsigned __int8 *)v12;
        v15 = v11;
        do
        {
          LOBYTE(v13->id) ^= *((_BYTE *)&v13->id + v14);
          v13 = (engine_st *)((char *)v13 + 1);
          --v15;
        }
        while ( v15 );
      }
      if ( v8 )
        LOBYTE(v12->id) &= 255 >> (8 - v8);
      v16 = 0;
      if ( !LOBYTE(v12->id) )
      {
        do
        {
          if ( v16 >= v11 - 1 )
            break;
          ++v16;
        }
        while ( !*((_BYTE *)&v12->id + v16) );
      }
      v17 = *((_BYTE *)&v12->id + v16);
      v18 = v16 + 1;
      if ( v17 == 1 )
      {
        if ( sLen < 0 || v11 - v18 == sLen )
        {
          EVP_MD_CTX_init(&ctx);
          EVP_DigestInit_ex(v12, &ctx, Hash, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          v19 = v11 - v18;
          if ( v19 )
            EVP_DigestUpdate(&ctx);
          EVP_DigestFinal(v19, (int)v12, &ctx, v27, 0);
          EVP_MD_CTX_cleanup(v19, (int)v12, &ctx);
          v20 = seed;
          v21 = seedlen;
          v22 = v27;
          if ( seedlen < 4 )
          {
LABEL_39:
            if ( !v21 || *v20 == *v22 && (v21 <= 1 || v20[1] == v22[1] && (v21 <= 2 || v20[2] == v22[2])) )
            {
              v23 = 1;
              goto err_151;
            }
          }
          else
          {
            while ( *(_DWORD *)v22 == *(_DWORD *)v20 )
            {
              v21 -= 4;
              v20 += 4;
              v22 += 4;
              if ( v21 < 4 )
                goto LABEL_39;
            }
          }
          ERR_put_error((int)v12, 4u, 126, 104, ".\\crypto\\rsa\\rsa_pss.c", 158);
          v23 = 0;
        }
        else
        {
          ERR_put_error((int)v12, 4u, 126, 136, ".\\crypto\\rsa\\rsa_pss.c", 145);
        }
      }
      else
      {
        ERR_put_error((int)v12, 4u, 126, 135, ".\\crypto\\rsa\\rsa_pss.c", 140);
      }
    }
  }
  else
  {
    ERR_put_error(0, 4u, 126, 65, ".\\crypto\\rsa\\rsa_pss.c", 128);
  }
err_151:
  if ( !v12 )
    return v23;
  CRYPTO_free(v12);
  return v23;
}
