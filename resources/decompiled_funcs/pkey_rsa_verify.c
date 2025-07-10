unsigned int __cdecl pkey_rsa_verify(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int siglen,
        const unsigned __int8 *tbs,
        unsigned int tbslen)
{
  evp_pkey_st *pkey; // eax
  RSA_PKEY_CTX *data; // esi
  const ssl_st *md; // edx
  rsa_st *rsa; // edi
  int pad_mode; // eax
  unsigned int v10; // eax
  unsigned int result; // eax
  int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *tbuf; // esi
  const unsigned __int8 *v15; // ecx
  const unsigned __int8 *v16; // [esp-14h] [ebp-1Ch]
  unsigned int v17; // [esp-10h] [ebp-18h]
  unsigned __int8 *v18; // [esp-Ch] [ebp-14h]
  unsigned int v19; // [esp-8h] [ebp-10h]

  pkey = ctx->pkey;
  data = (RSA_PKEY_CTX *)ctx->data;
  md = (const ssl_st *)data->md;
  rsa = pkey->pkey.rsa;
  if ( !md )
  {
    if ( data->tbuf
      || (v12 = EVP_PKEY_size(pkey),
          v13 = (unsigned __int8 *)CRYPTO_malloc(v12, ".\\crypto\\rsa\\rsa_pmeth.c", 132),
          (data->tbuf = v13) != 0) )
    {
      result = RSA_public_decrypt(siglen, sig, data->tbuf, rsa);
      if ( !result )
        return result;
      goto LABEL_17;
    }
    return -1;
  }
  pad_mode = data->pad_mode;
  if ( pad_mode == 1 )
  {
    v19 = siglen;
    v18 = sig;
    v17 = tbslen;
    v16 = tbs;
    v10 = EVP_CIPHER_CTX_cipher(md);
    return RSA_verify(v10, v16, v17, v18, v19, rsa);
  }
  if ( pad_mode != 5 )
  {
    if ( pad_mode == 6 && setup_tbuf(data, ctx) )
    {
      if ( RSA_public_decrypt(siglen, sig, data->tbuf, rsa) <= 0 )
        return 0;
      return RSA_verify_PKCS1_PSS(rsa, tbs, data->md, data->tbuf, data->saltlen) > 0;
    }
    return -1;
  }
  if ( pkey_rsa_verifyrecover(ctx, 0, (unsigned int *)&ctx, sig, siglen) <= 0 )
    return 0;
  result = (unsigned int)ctx;
LABEL_17:
  if ( result != tbslen )
    return 0;
  tbuf = data->tbuf;
  v15 = tbs;
  if ( result >= 4 )
  {
    while ( *(_DWORD *)v15 == *(_DWORD *)tbuf )
    {
      result -= 4;
      tbuf += 4;
      v15 += 4;
      if ( result < 4 )
        return !result || *tbuf == *v15 && (result <= 1 || tbuf[1] == v15[1] && (result <= 2 || tbuf[2] == v15[2]));
    }
    return 0;
  }
  return !result || *tbuf == *v15 && (result <= 1 || tbuf[1] == v15[1] && (result <= 2 || tbuf[2] == v15[2]));
}
