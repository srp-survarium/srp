int __cdecl pkey_dh_ctrl_str(evp_pkey_ctx_st *ctx, const char *type, const char *value)
{
  int v3; // eax
  int v5; // eax

  if ( !strcmp(type, "dh_paramgen_prime_len") )
  {
    v3 = atoi(value);
    return EVP_PKEY_CTX_ctrl(ctx, 28, 2, 4097, v3, 0);
  }
  else if ( !strcmp(type, "dh_paramgen_generator") )
  {
    v5 = atoi(value);
    return EVP_PKEY_CTX_ctrl(ctx, 28, 2, 4098, v5, 0);
  }
  else
  {
    return -2;
  }
}
