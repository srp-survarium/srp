int __cdecl pkey_ec_ctrl_str(evp_pkey_ctx_st *ctx, const char *type, const char *value)
{
  int v3; // eax

  if ( strcmp(type, "ec_paramgen_curve") )
    return -2;
  v3 = OBJ_sn2nid(value);
  if ( v3 )
    return EVP_PKEY_CTX_ctrl(ctx, 408, 2, 4097, v3, 0);
  v3 = OBJ_ln2nid(value);
  if ( v3 )
    return EVP_PKEY_CTX_ctrl(ctx, 408, 2, 4097, v3, 0);
  ERR_put_error(0x10u, 198, 141, ".\\crypto\\ec\\ec_pmeth.c", 259);
  return 0;
}
