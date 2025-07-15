int __usercall pkey_rsa_ctrl_str@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, const char *type, char *value)
{
  char *v4; // edi
  int result; // eax
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // esi

  v4 = value;
  if ( !value )
  {
    ERR_put_error(a1, 4u, 144, 147, ".\\crypto\\rsa\\rsa_pmeth.c", 464);
    return 0;
  }
  if ( !strcmp(type, "rsa_padding_mode") )
  {
    if ( !strcmp(value, "pkcs1") )
    {
      v6 = 1;
      return EVP_PKEY_CTX_ctrl(a1, ctx, 6, -1, 4097, v6, 0);
    }
    if ( !strcmp(value, "sslv23") )
    {
      v6 = 2;
      return EVP_PKEY_CTX_ctrl(a1, ctx, 6, -1, 4097, v6, 0);
    }
    if ( !strcmp(value, "none") )
    {
      v6 = 3;
      return EVP_PKEY_CTX_ctrl(a1, ctx, 6, -1, 4097, v6, 0);
    }
    if ( !strcmp(value, "oeap") )
    {
      v6 = 4;
      return EVP_PKEY_CTX_ctrl(a1, ctx, 6, -1, 4097, v6, 0);
    }
    if ( !strcmp(value, "x931") )
    {
      v6 = 5;
      return EVP_PKEY_CTX_ctrl(a1, ctx, 6, -1, 4097, v6, 0);
    }
    if ( !strcmp(value, "pss") )
    {
      v6 = 6;
      return EVP_PKEY_CTX_ctrl(a1, ctx, 6, -1, 4097, v6, 0);
    }
    ERR_put_error(a1, 4u, 144, 118, ".\\crypto\\rsa\\rsa_pmeth.c", 485);
    return -2;
  }
  if ( !strcmp(type, "rsa_pss_saltlen") )
  {
    v7 = atoi(a1, value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 6, 24, 4098, v7, 0);
  }
  else if ( !strcmp(type, "rsa_keygen_bits") )
  {
    v8 = atoi(a1, value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 6, 4, 4099, v8, 0);
  }
  else
  {
    if ( strcmp(type, "rsa_keygen_pubexp") )
      return -2;
    value = 0;
    result = BN_asc2bn((bignum_st **)&value, v4);
    if ( result )
    {
      v9 = EVP_PKEY_CTX_ctrl(a1, ctx, 6, 4, 4100, 0, value);
      if ( v9 <= 0 )
        BN_free((bignum_st *)value);
      return v9;
    }
  }
  return result;
}
