int __usercall int_rsa_verify@<eax>(
        int a1@<ebx>,
        void *dtype,
        const unsigned __int8 *m,
        unsigned int m_len,
        unsigned __int8 *rm,
        unsigned int *prm_len,
        const unsigned __int8 *sigbuf,
        int siglen,
        rsa_st *rsa)
{
  int v10; // eax
  void *v11; // edi
  const unsigned __int8 **v12; // eax
  const unsigned __int8 **v13; // esi
  unsigned int v14; // ecx
  const unsigned __int8 *v15; // eax
  X509_sig_st *v16; // eax
  X509_sig_st *v17; // edi
  void *v18; // eax
  _iobuf *v19; // eax
  char *v20; // eax
  const env_md_st *digestbyname; // eax
  asn1_string_st *digest; // ecx
  unsigned __int8 *data; // ecx
  const unsigned __int8 *v24; // esi
  unsigned int v25; // eax
  int v26; // [esp-10h] [ebp-20h]
  int v27; // [esp+4h] [ebp-Ch]
  void *v28; // [esp+8h] [ebp-8h]
  unsigned __int8 *v29; // [esp+Ch] [ebp-4h] BYREF

  v27 = 0;
  if ( siglen != RSA_size(rsa) )
  {
    ERR_put_error(a1, 4u, 145, 119, ".\\crypto\\rsa\\rsa_sign.c", 158);
    return 0;
  }
  if ( dtype != (void *)114 || !rm )
  {
    v11 = CRYPTO_malloc(siglen, ".\\crypto\\rsa\\rsa_sign.c", 172);
    v28 = v11;
    if ( !v11 )
    {
      ERR_put_error((int)dtype, 4u, 145, 65, ".\\crypto\\rsa\\rsa_sign.c", 175);
      return 0;
    }
    if ( dtype == (void *)114 && m_len != 36 )
    {
      ERR_put_error(114, 4u, 145, 131, ".\\crypto\\rsa\\rsa_sign.c", 179);
LABEL_54:
      OPENSSL_cleanse(v11, siglen);
      CRYPTO_free(v11);
      return v27;
    }
    v12 = (const unsigned __int8 **)RSA_public_decrypt(siglen, sigbuf, (unsigned __int8 *)v11, rsa);
    v13 = v12;
    if ( (int)v12 <= 0 )
      goto LABEL_54;
    if ( dtype == (void *)114 )
    {
      if ( v12 == (const unsigned __int8 **)36 )
      {
        v14 = 36;
        v15 = m;
        while ( *(_DWORD *)&v15[(_BYTE *)v11 - m] == *(_DWORD *)v15 )
        {
          v14 -= 4;
          v15 += 4;
          if ( v14 < 4 )
          {
            v27 = 1;
            goto LABEL_54;
          }
        }
      }
      ERR_put_error(114, 4u, 145, 104, ".\\crypto\\rsa\\rsa_sign.c", 189);
      goto LABEL_54;
    }
    v29 = (unsigned __int8 *)v11;
    v16 = d2i_X509_SIG(0, &v29, v12);
    v17 = v16;
    if ( !v16 )
    {
LABEL_53:
      v11 = v28;
      goto LABEL_54;
    }
    if ( v29 != (unsigned __int8 *)v28 + (_DWORD)v13 )
    {
      v26 = 200;
LABEL_51:
      ERR_put_error((int)dtype, 4u, 145, 104, ".\\crypto\\rsa\\rsa_sign.c", v26);
      goto err_62;
    }
    if ( v16->algor->parameter && ASN1_TYPE_get(v16->algor->parameter) != 5 )
    {
      v26 = 209;
      goto LABEL_51;
    }
    v18 = OBJ_obj2nid(v17->algor->algorithm);
    if ( v18 != dtype )
    {
      if ( dtype == (void *)4 )
      {
        if ( v18 != (void *)8 )
        {
LABEL_30:
          ERR_put_error((int)dtype, 4u, 145, 100, ".\\crypto\\rsa\\rsa_sign.c", 236);
err_62:
          X509_SIG_free(v17);
          goto LABEL_53;
        }
      }
      else if ( dtype != (void *)3 || v18 != (void *)7 )
      {
        goto LABEL_30;
      }
      v19 = __iob_func();
      fprintf((int)v17, v19 + 2, "signature has problems, re-make with post SSLeay045\n");
    }
    if ( rm )
    {
      v20 = (char *)OBJ_nid2sn((int)dtype, (unsigned int)dtype);
      digestbyname = EVP_get_digestbyname(v20);
      if ( digestbyname && EVP_MD_size((int)dtype, digestbyname) != v17->digest->length )
      {
        ERR_put_error((int)dtype, 4u, 145, 143, ".\\crypto\\rsa\\rsa_sign.c", 246);
        goto err_62;
      }
      memcpy((int)rm, (const __m128i *)v17->digest->data, v17->digest->length);
      *prm_len = v17->digest->length;
LABEL_39:
      v27 = 1;
      goto err_62;
    }
    digest = v17->digest;
    if ( digest->length == m_len )
    {
      data = digest->data;
      v24 = m;
      v25 = m_len;
      if ( m_len < 4 )
      {
LABEL_44:
        if ( !v25 || *data == *v24 && (v25 <= 1 || data[1] == v24[1] && (v25 <= 2 || data[2] == v24[2])) )
          goto LABEL_39;
      }
      else
      {
        while ( *(_DWORD *)v24 == *(_DWORD *)data )
        {
          v25 -= 4;
          data += 4;
          v24 += 4;
          if ( v25 < 4 )
            goto LABEL_44;
        }
      }
    }
    v26 = 258;
    goto LABEL_51;
  }
  v10 = RSA_public_decrypt(siglen, sigbuf, rm, rsa);
  if ( v10 <= 0 )
    return 0;
  *prm_len = v10;
  return 1;
}
