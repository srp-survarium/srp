int __cdecl PKCS12_key_gen_uni(
        unsigned __int8 *pass,
        int passlen,
        unsigned __int8 *salt,
        int saltlen,
        unsigned __int8 *id,
        int iter,
        int n,
        unsigned __int8 *out,
        const env_md_st *md_type)
{
  int v9; // esi
  int v10; // edi
  void *v12; // ebx
  signed int v13; // edi
  int v14; // eax
  bignum_st *v15; // ebp
  bignum_st *v16; // eax
  unsigned __int8 *v17; // ecx
  signed int i; // ebx
  int v19; // edx
  int j; // edi
  int v21; // edx
  unsigned int v22; // eax
  int k; // ecx
  int v24; // edx
  unsigned __int8 *v25; // ebx
  int v26; // kr00_4
  unsigned __int8 *s; // [esp+Ch] [ebp-3Ch]
  unsigned __int8 *to; // [esp+10h] [ebp-38h]
  int v29; // [esp+14h] [ebp-34h]
  int v30; // [esp+14h] [ebp-34h]
  int v31; // [esp+14h] [ebp-34h]
  bignum_st *ret; // [esp+18h] [ebp-30h]
  signed int v33; // [esp+1Ch] [ebp-2Ch]
  signed int count; // [esp+20h] [ebp-28h]
  void *data; // [esp+24h] [ebp-24h]
  unsigned __int8 *src; // [esp+28h] [ebp-20h]
  int v37; // [esp+2Ch] [ebp-1Ch]
  env_md_ctx_st ctx; // [esp+30h] [ebp-18h] BYREF

  v37 = 0;
  EVP_MD_CTX_init(&ctx);
  v9 = EVP_MD_block_size(md_type);
  v10 = EVP_MD_size(md_type);
  v33 = v10;
  if ( v10 < 0 )
    return 0;
  v12 = CRYPTO_malloc(v9, ".\\crypto\\pkcs12\\p12_key.c", 138);
  data = v12;
  src = (unsigned __int8 *)CRYPTO_malloc(v10, ".\\crypto\\pkcs12\\p12_key.c", 139);
  s = (unsigned __int8 *)CRYPTO_malloc(v9 + 1, ".\\crypto\\pkcs12\\p12_key.c", 140);
  v13 = v9 * ((v9 + saltlen - 1) / v9);
  if ( passlen )
  {
    v14 = v9 * ((v9 + passlen - 1) / v9);
    v29 = v14;
  }
  else
  {
    v29 = 0;
    v14 = 0;
  }
  count = v13 + v14;
  to = (unsigned __int8 *)CRYPTO_malloc(v13 + v14, ".\\crypto\\pkcs12\\p12_key.c", 145);
  v15 = BN_new();
  v16 = BN_new();
  ret = v16;
  if ( v12 && src && s && to && v15 && v16 )
  {
    if ( v9 > 0 )
      memset((int)v12, id, v9);
    v17 = to;
    for ( i = 0; i < v13; *(v17 - 1) = salt[v19] )
    {
      v19 = i % saltlen;
      ++i;
      ++v17;
    }
    for ( j = 0; j < v29; *(v17 - 1) = pass[v21] )
    {
      v21 = j % passlen;
      ++j;
      ++v17;
    }
    while ( 1 )
    {
LABEL_18:
      EVP_DigestInit_ex(&ctx, md_type, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      v13 = (signed int)src;
      EVP_DigestFinal_ex((unsigned int)src, &ctx, src, 0);
      if ( iter > 1 )
      {
        v30 = iter - 1;
        do
        {
          EVP_DigestInit_ex(&ctx, md_type, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestFinal_ex((unsigned int)src, &ctx, src, 0);
          --v30;
        }
        while ( v30 );
      }
      v22 = n;
      if ( n >= v33 )
        v22 = v33;
      memcpy(out, src, v22);
      if ( v33 >= n )
      {
        v12 = data;
        v37 = 1;
        goto end_3;
      }
      n -= v33;
      out += v33;
      for ( k = 0; k < v9; s[k - 1] = src[v24] )
      {
        v24 = k % v33;
        ++k;
      }
      if ( !BN_bin2bn(s, v9, ret) || !BN_add_word(ret, 1u) )
        break;
      v31 = 0;
      if ( count > 0 )
      {
        v25 = to;
        while ( BN_bin2bn(v25, v9, v15) && BN_add(v15, v15, ret) )
        {
          BN_bn2bin(v15, s);
          v26 = BN_num_bits(v15) + 7;
          v13 = v26 / 8;
          if ( v26 / 8 <= v9 )
          {
            if ( v26 / 8 >= v9 )
            {
              BN_bn2bin(v15, v25);
            }
            else
            {
              memset((int)v25, 0, v9 - v13);
              BN_bn2bin(v15, &to[v31 - v13 + v9]);
            }
          }
          else
          {
            BN_bn2bin(v15, s);
            v13 = (signed int)(s + 1);
            memcpy(v25, s + 1, v9);
          }
          v25 += v9;
          v31 += v9;
          if ( v31 >= count )
            goto LABEL_18;
        }
        break;
      }
    }
    v12 = data;
  }
  ERR_put_error(0x23u, 111, 65, ".\\crypto\\pkcs12\\p12_key.c", 199);
end_3:
  CRYPTO_free(src);
  CRYPTO_free(s);
  CRYPTO_free(v12);
  CRYPTO_free(to);
  BN_free(v15);
  BN_free(ret);
  EVP_MD_CTX_cleanup(v13, &ctx);
  return v37;
}
