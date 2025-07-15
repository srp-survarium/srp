int __usercall pkey_dsa_ctrl_str@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, const char *type, char *value)
{
  unsigned int v4; // eax
  unsigned int v6; // eax
  const env_md_st *digestbyname; // eax

  if ( !strcmp(type, "dsa_paramgen_bits") )
  {
    v4 = atoi(a1, value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 116, 2, 4097, v4, 0);
  }
  else if ( !strcmp(type, "dsa_paramgen_q_bits") )
  {
    v6 = atoi(a1, value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 116, 2, 4098, v6, 0);
  }
  else if ( !strcmp(type, "dsa_paramgen_md") )
  {
    digestbyname = EVP_get_digestbyname(value);
    return EVP_PKEY_CTX_ctrl(a1, ctx, 116, 2, 4099, 0, (void *)digestbyname);
  }
  else
  {
    return -2;
  }
}
