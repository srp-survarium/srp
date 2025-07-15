int __usercall pkey_ec_ctrl_str@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, const char *type, char *value)
{
  void *v4; // eax

  if ( strcmp(type, "ec_paramgen_curve") )
    return -2;
  v4 = OBJ_sn2nid(value);
  if ( v4 )
    return EVP_PKEY_CTX_ctrl(a1, ctx, 408, 2, 4097, (int)v4, 0);
  v4 = OBJ_ln2nid(value);
  if ( v4 )
    return EVP_PKEY_CTX_ctrl(a1, ctx, 408, 2, 4097, (int)v4, 0);
  ERR_put_error(a1, 0x10u, 198, 141, ".\\crypto\\ec\\ec_pmeth.c", 259);
  return 0;
}
