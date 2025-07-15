int __cdecl RSA_sign_ASN1_OCTET_STRING(
        int type,
        unsigned __int8 *m,
        unsigned __int8 *m_len,
        unsigned __int8 *sigret,
        unsigned int *siglen,
        rsa_st *rsa)
{
  int v6; // eax
  rsa_st *v7; // ebx
  int v8; // edi
  int v9; // eax
  int v11; // ebp
  unsigned __int8 *v12; // esi
  int v13; // eax
  int v14; // edi
  asn1_string_st a; // [esp+Ch] [ebp-10h] BYREF

  a.type = 4;
  a.length = (int)m_len;
  a.data = m;
  v6 = i2d_ASN1_OCTET_STRING(&a, 0);
  v7 = rsa;
  v8 = v6;
  v9 = RSA_size(rsa);
  if ( v8 <= v9 - 11 )
  {
    v11 = v9 + 1;
    v12 = (unsigned __int8 *)CRYPTO_malloc(v9 + 1, ".\\crypto\\rsa\\rsa_saos.c", 85);
    if ( v12 )
    {
      m_len = v12;
      i2d_ASN1_OCTET_STRING(&a, &m_len);
      v13 = RSA_private_encrypt(v8, v12, sigret, v7);
      if ( v13 > 0 )
      {
        v14 = 1;
        *siglen = v13;
      }
      else
      {
        v14 = 0;
      }
      OPENSSL_cleanse(v12, v11);
      CRYPTO_free(v12);
      return v14;
    }
    else
    {
      ERR_put_error((int)v7, 4u, 118, 65, ".\\crypto\\rsa\\rsa_saos.c", 88);
      return 0;
    }
  }
  else
  {
    ERR_put_error((int)v7, 4u, 118, 112, ".\\crypto\\rsa\\rsa_saos.c", 82);
    return 0;
  }
}
