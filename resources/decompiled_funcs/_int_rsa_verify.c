int __cdecl int_rsa_verify(
        unsigned int dtype,
        const unsigned __int8 *m,
        unsigned int m_len,
        unsigned __int8 *rm,
        unsigned int *prm_len,
        unsigned __int8 *sigbuf,
        int siglen,
        rsa_st *rsa)
{
  int v9; // eax
  void *v10; // edi
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // esi
  unsigned int v13; // ecx
  const unsigned __int8 *v14; // eax
  X509_sig_st *v15; // eax
  X509_sig_st *v16; // edi
  int v17; // eax
  _iobuf *v18; // eax
  const char *v19; // eax
  const env_md_st *digestbyname; // eax
  asn1_string_st *digest; // ecx
  unsigned __int8 *data; // ecx
  const unsigned __int8 *v23; // esi
  unsigned int v24; // eax
  int v25; // [esp-10h] [ebp-20h]
  int v26; // [esp+4h] [ebp-Ch]
  void *v27; // [esp+8h] [ebp-8h]
  unsigned __int8 *in; // [esp+Ch] [ebp-4h] BYREF

  v26 = 0;
  if ( siglen != RSA_size(rsa) )
  {
    ERR_put_error(4u, 145, 119, ".\\crypto\\rsa\\rsa_sign.c", 158);
    return 0;
  }
  if ( dtype != 114 || !rm )
  {
    v10 = CRYPTO_malloc(siglen, ".\\crypto\\rsa\\rsa_sign.c", 172);
    v27 = v10;
    if ( !v10 )
    {
      ERR_put_error(4u, 145, 65, ".\\crypto\\rsa\\rsa_sign.c", 175);
      return 0;
    }
    if ( dtype == 114 && m_len != 36 )
    {
      ERR_put_error(4u, 145, 131, ".\\crypto\\rsa\\rsa_sign.c", 179);
LABEL_54:
      OPENSSL_cleanse(v10, siglen);
      CRYPTO_free(v10);
      return v26;
    }
    v11 = (unsigned __int8 *)RSA_public_decrypt(siglen, sigbuf, (unsigned __int8 *)v10, rsa);
    v12 = v11;
    if ( (int)v11 <= 0 )
      goto LABEL_54;
    if ( dtype == 114 )
    {
      if ( v11 == (unsigned __int8 *)36 )
      {
        v13 = 36;
        v14 = m;
        while ( *(_DWORD *)&v14[(_BYTE *)v10 - m] == *(_DWORD *)v14 )
        {
          v13 -= 4;
          v14 += 4;
          if ( v13 < 4 )
          {
            v26 = 1;
            goto LABEL_54;
          }
        }
      }
      ERR_put_error(4u, 145, 104, ".\\crypto\\rsa\\rsa_sign.c", 189);
      goto LABEL_54;
    }
    in = (unsigned __int8 *)v10;
    v15 = d2i_X509_SIG(0, &in, v11);
    v16 = v15;
    if ( !v15 )
    {
LABEL_53:
      v10 = v27;
      goto LABEL_54;
    }
    if ( in != (unsigned __int8 *)v27 + (_DWORD)v12 )
    {
      v25 = 200;
LABEL_51:
      ERR_put_error(4u, 145, 104, ".\\crypto\\rsa\\rsa_sign.c", v25);
      goto err_60;
    }
    if ( v15->algor->parameter && ASN1_TYPE_get(v15->algor->parameter) != 5 )
    {
      v25 = 209;
      goto LABEL_51;
    }
    v17 = OBJ_obj2nid(v16->algor->algorithm);
    if ( v17 != dtype )
    {
      if ( dtype == 4 )
      {
        if ( v17 != 8 )
        {
LABEL_30:
          ERR_put_error(4u, 145, 100, ".\\crypto\\rsa\\rsa_sign.c", 236);
err_60:
          X509_SIG_free(v16);
          goto LABEL_53;
        }
      }
      else if ( dtype != 3 || v17 != 7 )
      {
        goto LABEL_30;
      }
      v18 = __iob_func();
      fprintf(v18 + 2, "signature has problems, re-make with post SSLeay045\n");
    }
    if ( rm )
    {
      v19 = OBJ_nid2sn(dtype);
      digestbyname = EVP_get_digestbyname(v19);
      if ( digestbyname && EVP_MD_size(digestbyname) != v16->digest->length )
      {
        ERR_put_error(4u, 145, 143, ".\\crypto\\rsa\\rsa_sign.c", 246);
        goto err_60;
      }
      memcpy(rm, v16->digest->data, v16->digest->length);
      *prm_len = v16->digest->length;
LABEL_39:
      v26 = 1;
      goto err_60;
    }
    digest = v16->digest;
    if ( digest->length == m_len )
    {
      data = digest->data;
      v23 = m;
      v24 = m_len;
      if ( m_len < 4 )
      {
LABEL_44:
        if ( !v24 || *data == *v23 && (v24 <= 1 || data[1] == v23[1] && (v24 <= 2 || data[2] == v23[2])) )
          goto LABEL_39;
      }
      else
      {
        while ( *(_DWORD *)v23 == *(_DWORD *)data )
        {
          v24 -= 4;
          data += 4;
          v23 += 4;
          if ( v24 < 4 )
            goto LABEL_44;
        }
      }
    }
    v25 = 258;
    goto LABEL_51;
  }
  v9 = RSA_public_decrypt(siglen, sigbuf, rm, rsa);
  if ( v9 <= 0 )
    return 0;
  *prm_len = v9;
  return 1;
}
