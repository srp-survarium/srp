int __cdecl pkey_dsa_ctrl_str(evp_pkey_ctx_st *ctx, const char *type, const char *value)
{
  int v3; // eax
  int v5; // eax
  const env_md_st *digestbyname; // eax

  if ( !strcmp(type, "dsa_paramgen_bits") )
  {
    v3 = atoi(value);
    return EVP_PKEY_CTX_ctrl(ctx, 116, 2, 4097, v3, 0);
  }
  else if ( !strcmp(type, "dsa_paramgen_q_bits") )
  {
    v5 = atoi(value);
    return EVP_PKEY_CTX_ctrl(ctx, 116, 2, 4098, v5, 0);
  }
  else if ( !strcmp(type, "dsa_paramgen_md") )
  {
    digestbyname = EVP_get_digestbyname(value);
    return EVP_PKEY_CTX_ctrl(ctx, 116, 2, 4099, 0, (void *)digestbyname);
  }
  else
  {
    return -2;
  }
}
