int __cdecl RSA_verify_ASN1_OCTET_STRING(
        int dtype,
        const unsigned __int8 *m,
        unsigned int m_len,
        unsigned __int8 *sigbuf,
        int siglen,
        rsa_st *rsa)
{
  unsigned __int8 *v7; // edi
  int v8; // eax
  asn1_string_st *v9; // ebp
  unsigned int v10; // eax
  unsigned __int8 *data; // ecx
  int v13; // [esp+8h] [ebp-8h]
  unsigned __int8 *in; // [esp+Ch] [ebp-4h] BYREF

  v13 = 0;
  if ( siglen != RSA_size(rsa) )
  {
    ERR_put_error(4u, 120, 119, ".\\crypto\\rsa\\rsa_saos.c", 116);
    return 0;
  }
  v7 = (unsigned __int8 *)CRYPTO_malloc(siglen, ".\\crypto\\rsa\\rsa_saos.c", 120);
  if ( !v7 )
  {
    ERR_put_error(4u, 120, 65, ".\\crypto\\rsa\\rsa_saos.c", 123);
    return 0;
  }
  v8 = RSA_public_decrypt(siglen, sigbuf, v7, rsa);
  if ( v8 > 0 )
  {
    in = v7;
    v9 = d2i_ASN1_OCTET_STRING(0, (const unsigned __int8 **)&in, v8);
    if ( v9 )
    {
      v10 = m_len;
      if ( v9->length == m_len )
      {
        data = v9->data;
        if ( m_len < 4 )
        {
LABEL_11:
          if ( !v10 || *data == *m && (v10 <= 1 || data[1] == m[1] && (v10 <= 2 || data[2] == m[2])) )
          {
            v13 = 1;
err_61:
            ASN1_STRING_free(v9);
            goto LABEL_20;
          }
        }
        else
        {
          while ( *(_DWORD *)m == *(_DWORD *)data )
          {
            v10 -= 4;
            data += 4;
            m += 4;
            if ( v10 < 4 )
              goto LABEL_11;
          }
        }
      }
      ERR_put_error(4u, 120, 104, ".\\crypto\\rsa\\rsa_saos.c", 137);
      goto err_61;
    }
  }
LABEL_20:
  OPENSSL_cleanse(v7, siglen);
  CRYPTO_free(v7);
  return v13;
}
