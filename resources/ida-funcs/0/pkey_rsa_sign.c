int __usercall pkey_rsa_sign@<eax>(
        int a1@<ebx>,
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int *siglen,
        const __m128i *tbs,
        unsigned int tbslen)
{
  evp_pkey_ctx_st *v6; // ebp
  void *data; // esi
  rsa_st *rsa; // edi
  int v9; // eax
  unsigned int v10; // ebx
  int result; // eax
  int v12; // eax
  int v13; // eax
  char v14; // al
  unsigned __int8 *v15; // edx
  unsigned int v16; // eax
  const unsigned __int8 *v17; // [esp-14h] [ebp-24h]
  int v18; // [esp-14h] [ebp-24h]
  unsigned int v19; // [esp-10h] [ebp-20h]
  const unsigned __int8 *v20; // [esp-10h] [ebp-20h]
  unsigned __int8 *v21; // [esp-Ch] [ebp-1Ch]
  unsigned __int8 *v22; // [esp-Ch] [ebp-1Ch]

  v6 = ctx;
  data = ctx->data;
  rsa = ctx->pkey->pkey.rsa;
  if ( *((_DWORD *)data + 5) )
  {
    v9 = EVP_MD_size(a1, *((const env_md_st **)data + 5));
    v10 = tbslen;
    if ( tbslen != v9 )
    {
      ERR_put_error(tbslen, 4u, 142, 143, ".\\crypto\\rsa\\rsa_pmeth.c", 163);
      return -1;
    }
    v12 = *((_DWORD *)data + 4);
    if ( v12 == 5 )
    {
      if ( !setup_tbuf((RSA_PKEY_CTX *)data, v6) )
        return -1;
      memcpy(*((_DWORD *)data + 7), tbs, v10);
      v13 = EVP_CIPHER_CTX_cipher(*((const ssl_st **)data + 5));
      v14 = RSA_X931_hash_id(v13);
      v15 = sig;
      *(_BYTE *)(v10 + *((_DWORD *)data + 7)) = v14;
      result = RSA_private_encrypt(v10 + 1, *((const unsigned __int8 **)data + 7), v15, rsa);
    }
    else if ( v12 == 1 )
    {
      v21 = sig;
      v19 = tbslen;
      v17 = (const unsigned __int8 *)tbs;
      v16 = EVP_CIPHER_CTX_cipher(*((const ssl_st **)data + 5));
      result = RSA_sign(v16, v17, v19, v21, (unsigned int *)&ctx, rsa);
      if ( result <= 0 )
        return result;
      result = (int)ctx;
    }
    else
    {
      if ( v12 != 6
        || !setup_tbuf((RSA_PKEY_CTX *)data, v6)
        || !RSA_padding_add_PKCS1_PSS(
              rsa,
              *((unsigned __int8 **)data + 7),
              (const unsigned __int8 *)tbs,
              *((const env_md_st **)data + 5),
              *((_DWORD *)data + 6)) )
      {
        return -1;
      }
      v22 = sig;
      v20 = (const unsigned __int8 *)*((_DWORD *)data + 7);
      v18 = RSA_size(rsa);
      result = RSA_private_encrypt(v18, v20, v22, rsa);
    }
  }
  else
  {
    result = RSA_private_encrypt(tbslen, (const unsigned __int8 *)tbs, sig, rsa);
  }
  if ( result >= 0 )
  {
    *siglen = result;
    return 1;
  }
  return result;
}
