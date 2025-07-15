unsigned int __usercall pkey_rsa_verify@<eax>(
        int a1@<ebx>,
        evp_pkey_ctx_st *ctx,
        const unsigned __int8 *sig,
        int siglen,
        unsigned __int8 *tbs,
        unsigned int tbslen)
{
  evp_pkey_st *pkey; // eax
  RSA_PKEY_CTX *data; // esi
  const ssl_st *md; // edx
  rsa_st *rsa; // edi
  int pad_mode; // eax
  void *v11; // eax
  unsigned int result; // eax
  int v13; // eax
  unsigned __int8 *v14; // eax
  unsigned __int8 *tbuf; // esi
  unsigned __int8 *v16; // ecx
  const unsigned __int8 *v17; // [esp-14h] [ebp-1Ch]
  unsigned int v18; // [esp-10h] [ebp-18h]
  const unsigned __int8 *v19; // [esp-Ch] [ebp-14h]
  int v20; // [esp-8h] [ebp-10h]

  pkey = ctx->pkey;
  data = (RSA_PKEY_CTX *)ctx->data;
  md = (const ssl_st *)data->md;
  rsa = pkey->pkey.rsa;
  if ( !md )
  {
    if ( data->tbuf
      || (v13 = EVP_PKEY_size(pkey),
          v14 = (unsigned __int8 *)CRYPTO_malloc(v13, ".\\crypto\\rsa\\rsa_pmeth.c", 132),
          (data->tbuf = v14) != 0) )
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
    v20 = siglen;
    v19 = sig;
    v18 = tbslen;
    v17 = tbs;
    v11 = (void *)EVP_CIPHER_CTX_cipher(md);
    return RSA_verify(a1, v11, v17, v18, v19, v20, rsa);
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
  if ( pkey_rsa_verifyrecover(a1, ctx, 0, &ctx, sig, siglen) <= 0 )
    return 0;
  result = (unsigned int)ctx;
LABEL_17:
  if ( result != tbslen )
    return 0;
  tbuf = data->tbuf;
  v16 = tbs;
  if ( result >= 4 )
  {
    while ( *(_DWORD *)v16 == *(_DWORD *)tbuf )
    {
      result -= 4;
      tbuf += 4;
      v16 += 4;
      if ( result < 4 )
        return !result || *tbuf == *v16 && (result <= 1 || tbuf[1] == v16[1] && (result <= 2 || tbuf[2] == v16[2]));
    }
    return 0;
  }
  return !result || *tbuf == *v16 && (result <= 1 || tbuf[1] == v16[1] && (result <= 2 || tbuf[2] == v16[2]));
}
