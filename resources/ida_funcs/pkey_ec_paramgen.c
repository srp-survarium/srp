ec_key_st *__cdecl pkey_ec_paramgen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  const ec_group_st **data; // edi
  ec_key_st *result; // eax
  char *v4; // esi
  BOOL v5; // edi

  data = (const ec_group_st **)ctx->data;
  if ( *data )
  {
    result = EC_KEY_new();
    v4 = (char *)result;
    if ( result )
    {
      v5 = EC_KEY_set_group(result, *data);
      if ( v5 )
      {
        EVP_PKEY_assign(pkey, 408, v4);
        return (ec_key_st *)v5;
      }
      else
      {
        EC_KEY_free((ec_key_st *)v4);
        return 0;
      }
    }
  }
  else
  {
    ERR_put_error(0x10u, 219, 139, ".\\crypto\\ec\\ec_pmeth.c", 274);
    return 0;
  }
  return result;
}
