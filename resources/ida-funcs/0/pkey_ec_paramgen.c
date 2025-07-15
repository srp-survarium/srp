ec_key_st *__usercall pkey_ec_paramgen@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  const ec_group_st **data; // edi
  ec_key_st *result; // eax
  char *v5; // esi
  BOOL v6; // edi

  data = (const ec_group_st **)ctx->data;
  if ( *data )
  {
    result = EC_KEY_new(a1);
    v5 = (char *)result;
    if ( result )
    {
      v6 = EC_KEY_set_group(result, *data);
      if ( v6 )
      {
        EVP_PKEY_assign(pkey, (void *)0x198, v5);
        return (ec_key_st *)v6;
      }
      else
      {
        EC_KEY_free((ec_key_st *)v5);
        return 0;
      }
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 219, 139, ".\\crypto\\ec\\ec_pmeth.c", 274);
    return 0;
  }
  return result;
}
