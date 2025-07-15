int __usercall PKCS12_key_gen_uni@<eax>(
        int a1@<ebx>,
        unsigned __int8 *pass,
        int passlen,
        unsigned __int8 *salt,
        int saltlen,
        int id,
        int iter,
        int n,
        unsigned __int8 *out,
        const env_md_st *md_type)
{
  int v10; // esi
  int v11; // edi
  void *v13; // ebx
  int v14; // edi
  int v15; // eax
  bignum_st *v16; // ebp
  bignum_st *v17; // eax
  unsigned __int8 *v18; // ecx
  int i; // ebx
  int v20; // edx
  int j; // edi
  int v22; // edx
  unsigned int v23; // eax
  int k; // ecx
  int v25; // edx
  unsigned __int8 *v26; // ebx
  int v27; // kr00_4
  unsigned __int8 *s; // [esp+Ch] [ebp-3Ch]
  unsigned __int8 *to; // [esp+10h] [ebp-38h]
  int v30; // [esp+14h] [ebp-34h]
  int v31; // [esp+14h] [ebp-34h]
  int v32; // [esp+14h] [ebp-34h]
  bignum_st *ret; // [esp+18h] [ebp-30h]
  int v34; // [esp+1Ch] [ebp-2Ch]
  int v35; // [esp+20h] [ebp-28h]
  void *str; // [esp+24h] [ebp-24h]
  __m128i *src; // [esp+28h] [ebp-20h]
  int v38; // [esp+2Ch] [ebp-1Ch]
  env_md_ctx_st ctx; // [esp+30h] [ebp-18h] BYREF

  v38 = 0;
  EVP_MD_CTX_init(&ctx);
  v10 = EVP_MD_block_size(md_type);
  v11 = EVP_MD_size(a1, md_type);
  v34 = v11;
  if ( v11 < 0 )
    return 0;
  v13 = CRYPTO_malloc(v10, ".\\crypto\\pkcs12\\p12_key.c", 138);
  str = v13;
  src = (__m128i *)CRYPTO_malloc(v11, ".\\crypto\\pkcs12\\p12_key.c", 139);
  s = (unsigned __int8 *)CRYPTO_malloc(v10 + 1, ".\\crypto\\pkcs12\\p12_key.c", 140);
  v14 = v10 * ((v10 + saltlen - 1) / v10);
  if ( passlen )
  {
    v15 = v10 * ((v10 + passlen - 1) / v10);
    v30 = v15;
  }
  else
  {
    v30 = 0;
    v15 = 0;
  }
  v35 = v14 + v15;
  to = (unsigned __int8 *)CRYPTO_malloc(v14 + v15, ".\\crypto\\pkcs12\\p12_key.c", 145);
  v16 = BN_new((int)v13);
  v17 = BN_new((int)v13);
  ret = v17;
  if ( v13 && src && s && to && v16 && v17 )
  {
    if ( v10 > 0 )
      memset((int)v13, id, v10);
    v18 = to;
    for ( i = 0; i < v14; *(v18 - 1) = salt[v20] )
    {
      v20 = i % saltlen;
      ++i;
      ++v18;
    }
    for ( j = 0; j < v30; *(v18 - 1) = pass[v22] )
    {
      v22 = j % passlen;
      ++j;
      ++v18;
    }
    while ( 1 )
    {
LABEL_18:
      EVP_DigestInit_ex((engine_st *)md_type, &ctx, md_type, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      v14 = (int)src;
      EVP_DigestFinal_ex((int)src, (int)md_type, &ctx, (unsigned __int8 *)src, 0);
      if ( iter > 1 )
      {
        v31 = iter - 1;
        do
        {
          EVP_DigestInit_ex((engine_st *)md_type, &ctx, md_type, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestFinal_ex((int)src, (int)md_type, &ctx, (unsigned __int8 *)src, 0);
          --v31;
        }
        while ( v31 );
      }
      v23 = n;
      if ( n >= v34 )
        v23 = v34;
      memcpy((int)out, src, v23);
      if ( v34 >= n )
      {
        v13 = str;
        v38 = 1;
        goto end_3;
      }
      n -= v34;
      out += v34;
      for ( k = 0; k < v10; s[k - 1] = src->m128i_u8[v25] )
      {
        v25 = k % v34;
        ++k;
      }
      if ( !BN_bin2bn(s, v10, ret) || !BN_add_word(v34, ret, 1u) )
        break;
      v32 = 0;
      if ( v35 > 0 )
      {
        v26 = to;
        while ( BN_bin2bn(v26, v10, v16) && BN_add(v16, v16, ret) )
        {
          BN_bn2bin(v16, s);
          v27 = BN_num_bits(v16) + 7;
          v14 = v27 / 8;
          if ( v27 / 8 <= v10 )
          {
            if ( v27 / 8 >= v10 )
            {
              BN_bn2bin(v16, v26);
            }
            else
            {
              memset((int)v26, 0, v10 - v14);
              BN_bn2bin(v16, &to[v32 - v14 + v10]);
            }
          }
          else
          {
            BN_bn2bin(v16, s);
            v14 = (int)(s + 1);
            memcpy((int)v26, (const __m128i *)(s + 1), v10);
          }
          v26 += v10;
          v32 += v10;
          if ( v32 >= v35 )
            goto LABEL_18;
        }
        break;
      }
    }
    v13 = str;
  }
  ERR_put_error((int)v13, 0x23u, 111, 65, ".\\crypto\\pkcs12\\p12_key.c", 199);
end_3:
  CRYPTO_free(src);
  CRYPTO_free(s);
  CRYPTO_free(v13);
  CRYPTO_free(to);
  BN_free(v16);
  BN_free(ret);
  EVP_MD_CTX_cleanup(v14, (int)v13, &ctx);
  return v38;
}
