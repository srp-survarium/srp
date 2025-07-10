int __cdecl RSA_sign(
        unsigned int type,
        unsigned __int8 *m,
        unsigned int m_len,
        unsigned __int8 *sigret,
        unsigned int *siglen,
        rsa_st *rsa)
{
  rsa_st *v6; // edi
  const unsigned __int8 *v7; // ebx
  rsa_st *v8; // ebp
  int (__cdecl *rsa_sign)(int, const unsigned __int8 *, unsigned int, unsigned __int8 *, unsigned int *, const rsa_st *); // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // [esp+10h] [ebp-2Ch]
  X509_sig_st a; // [esp+14h] [ebp-28h] BYREF
  _DWORD v17[2]; // [esp+1Ch] [ebp-20h] BYREF
  asn1_object_st *v18; // [esp+24h] [ebp-18h] BYREF
  _DWORD v19[4]; // [esp+2Ch] [ebp-10h] BYREF

  v6 = rsa;
  v7 = 0;
  v8 = 0;
  if ( (rsa->flags & 0x40) != 0 )
  {
    rsa_sign = rsa->meth->rsa_sign;
    if ( rsa_sign )
      return rsa_sign(type, m, m_len, sigret, siglen, rsa);
  }
  if ( type == 114 )
  {
    v11 = 36;
    if ( m_len != 36 )
    {
      ERR_put_error(4u, 117, 131, ".\\crypto\\rsa\\rsa_sign.c", 88);
      return 0;
    }
    v7 = m;
  }
  else
  {
    a.algor = (X509_algor_st *)&v18;
    v18 = OBJ_nid2obj(type);
    if ( !v18 )
    {
      ERR_put_error(4u, 117, 117, ".\\crypto\\rsa\\rsa_sign.c", 98);
      return 0;
    }
    if ( !v18->length )
    {
      ERR_put_error(4u, 117, 116, ".\\crypto\\rsa\\rsa_sign.c", 103);
      return 0;
    }
    v17[0] = 5;
    v17[1] = 0;
    a.algor->parameter = (asn1_type_st *)v17;
    a.digest = (asn1_string_st *)v19;
    v19[2] = m;
    v19[0] = m_len;
    v11 = i2d_X509_SIG(&a, 0);
  }
  v12 = RSA_size(v6);
  v15 = v12;
  if ( v11 > v12 - 11 )
  {
    ERR_put_error(4u, 117, 112, ".\\crypto\\rsa\\rsa_sign.c", 119);
    return 0;
  }
  if ( type != 114 )
  {
    v8 = (rsa_st *)CRYPTO_malloc(v12 + 1, ".\\crypto\\rsa\\rsa_sign.c", 123);
    if ( !v8 )
    {
      ERR_put_error(4u, 117, 65, ".\\crypto\\rsa\\rsa_sign.c", 126);
      return 0;
    }
    rsa = v8;
    i2d_X509_SIG(&a, (unsigned __int8 **)&rsa);
    v7 = (const unsigned __int8 *)v8;
  }
  v13 = RSA_private_encrypt(v11, v7, sigret, v6);
  if ( v13 > 0 )
  {
    v14 = 1;
    *siglen = v13;
  }
  else
  {
    v14 = 0;
  }
  if ( type != 114 )
  {
    OPENSSL_cleanse(v8, v15 + 1);
    CRYPTO_free(v8);
  }
  return v14;
}
