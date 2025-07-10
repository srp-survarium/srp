dsa_st *__cdecl pkey_dsa_paramgen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  void *data; // esi
  bn_gencb_st *p_cb; // ebx
  dsa_st *result; // eax
  char *v5; // edi
  int v6; // esi
  bn_gencb_st cb; // [esp+Ch] [ebp-Ch] BYREF

  data = ctx->data;
  if ( ctx->pkey_gencb )
  {
    p_cb = &cb;
    evp_pkey_set_cb_translate(&cb, ctx);
  }
  else
  {
    p_cb = 0;
  }
  result = DSA_new();
  v5 = (char *)result;
  if ( result )
  {
    v6 = dsa_builtin_paramgen(
           result,
           *(_DWORD *)data,
           *((_DWORD *)data + 1),
           *((const env_md_st **)data + 2),
           0,
           0,
           0,
           0,
           p_cb);
    if ( v6 )
    {
      EVP_PKEY_assign(pkey, 116, v5);
      return (dsa_st *)v6;
    }
    else
    {
      DSA_free((unsigned int)v5, (dsa_st *)v5);
      return 0;
    }
  }
  return result;
}
