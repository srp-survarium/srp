int __usercall pkey_dh_ctrl_str@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, const char *type, char *value)
{
  unsigned int v4; // eax
  unsigned int v6; // eax

  if ( !strcmp(type, "dh_paramgen_prime_len") )
  {
    v4 = atoi(a1, value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 28, 2, 4097, v4, 0);
  }
  else if ( !strcmp(type, "dh_paramgen_generator") )
  {
    v6 = atoi(a1, value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 28, 2, 4098, v6, 0);
  }
  else
  {
    return -2;
  }
}
