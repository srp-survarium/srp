int __cdecl pkey_rsa_ctrl_str(evp_pkey_ctx_st *ctx, const char *type, bignum_st *value)
{
  const char *v3; // edi
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi

  v3 = (const char *)value;
  if ( !value )
  {
    ERR_put_error(4u, 144, 147, ".\\crypto\\rsa\\rsa_pmeth.c", 464);
    return 0;
  }
  if ( !strcmp(type, "rsa_padding_mode") )
  {
    if ( !strcmp((const char *)value, "pkcs1") )
    {
      v5 = 1;
      return EVP_PKEY_CTX_ctrl(ctx, 6, -1, 4097, v5, 0);
    }
    if ( !strcmp((const char *)value, "sslv23") )
    {
      v5 = 2;
      return EVP_PKEY_CTX_ctrl(ctx, 6, -1, 4097, v5, 0);
    }
    if ( !strcmp((const char *)value, "none") )
    {
      v5 = 3;
      return EVP_PKEY_CTX_ctrl(ctx, 6, -1, 4097, v5, 0);
    }
    if ( !strcmp((const char *)value, "oeap") )
    {
      v5 = 4;
      return EVP_PKEY_CTX_ctrl(ctx, 6, -1, 4097, v5, 0);
    }
    if ( !strcmp((const char *)value, "x931") )
    {
      v5 = 5;
      return EVP_PKEY_CTX_ctrl(ctx, 6, -1, 4097, v5, 0);
    }
    if ( !strcmp((const char *)value, "pss") )
    {
      v5 = 6;
      return EVP_PKEY_CTX_ctrl(ctx, 6, -1, 4097, v5, 0);
    }
    ERR_put_error(4u, 144, 118, ".\\crypto\\rsa\\rsa_pmeth.c", 485);
    return -2;
  }
  if ( !strcmp(type, "rsa_pss_saltlen") )
  {
    v6 = atoi((const char *)value);
    return EVP_PKEY_CTX_ctrl(ctx, 6, 24, 4098, v6, 0);
  }
  else if ( !strcmp(type, "rsa_keygen_bits") )
  {
    v7 = atoi((const char *)value);
    return EVP_PKEY_CTX_ctrl(ctx, 6, 4, 4099, v7, 0);
  }
  else
  {
    if ( strcmp(type, "rsa_keygen_pubexp") )
      return -2;
    value = 0;
    result = BN_asc2bn(&value, v3);
    if ( result )
    {
      v8 = EVP_PKEY_CTX_ctrl(ctx, 6, 4, 4100, 0, value);
      if ( v8 <= 0 )
        BN_free(value);
      return v8;
    }
  }
  return result;
}
