int __cdecl pkey_rsa_sign(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int *siglen,
        unsigned __int8 *tbs,
        unsigned int tbslen)
{
  evp_pkey_ctx_st *v5; // ebp
  RSA_PKEY_CTX *data; // esi
  rsa_st *rsa; // edi
  int v8; // eax
  unsigned int v9; // ebx
  int result; // eax
  int pad_mode; // eax
  int v12; // eax
  unsigned __int8 v13; // al
  unsigned __int8 *v14; // edx
  unsigned int v15; // eax
  unsigned __int8 *v16; // [esp-14h] [ebp-24h]
  int v17; // [esp-14h] [ebp-24h]
  unsigned int v18; // [esp-10h] [ebp-20h]
  const unsigned __int8 *tbuf; // [esp-10h] [ebp-20h]
  unsigned __int8 *v20; // [esp-Ch] [ebp-1Ch]
  unsigned __int8 *v21; // [esp-Ch] [ebp-1Ch]

  v5 = ctx;
  data = (RSA_PKEY_CTX *)ctx->data;
  rsa = ctx->pkey->pkey.rsa;
  if ( data->md )
  {
    v8 = EVP_MD_size(data->md);
    v9 = tbslen;
    if ( tbslen != v8 )
    {
      ERR_put_error(4u, 142, 143, ".\\crypto\\rsa\\rsa_pmeth.c", 163);
      return -1;
    }
    pad_mode = data->pad_mode;
    if ( pad_mode == 5 )
    {
      if ( !setup_tbuf(data, v5) )
        return -1;
      memcpy(data->tbuf, tbs, v9);
      v12 = EVP_CIPHER_CTX_cipher((const ssl_st *)data->md);
      v13 = RSA_X931_hash_id(v12);
      v14 = sig;
      data->tbuf[v9] = v13;
      result = RSA_private_encrypt(v9 + 1, data->tbuf, v14, rsa);
    }
    else if ( pad_mode == 1 )
    {
      v20 = sig;
      v18 = tbslen;
      v16 = tbs;
      v15 = EVP_CIPHER_CTX_cipher((const ssl_st *)data->md);
      result = RSA_sign(v15, v16, v18, v20, (unsigned int *)&ctx, rsa);
      if ( result <= 0 )
        return result;
      result = (int)ctx;
    }
    else
    {
      if ( pad_mode != 6
        || !setup_tbuf(data, v5)
        || !RSA_padding_add_PKCS1_PSS(rsa, data->tbuf, tbs, data->md, data->saltlen) )
      {
        return -1;
      }
      v21 = sig;
      tbuf = data->tbuf;
      v17 = RSA_size(rsa);
      result = RSA_private_encrypt(v17, tbuf, v21, rsa);
    }
  }
  else
  {
    result = RSA_private_encrypt(tbslen, tbs, sig, rsa);
  }
  if ( result >= 0 )
  {
    *siglen = result;
    return 1;
  }
  return result;
}
