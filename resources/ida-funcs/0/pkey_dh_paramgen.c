dh_st *__cdecl pkey_dh_paramgen(evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  int *data; // edi
  bn_gencb_st *p_cb; // ebx
  dh_st *result; // eax
  char *v5; // esi
  int parameters; // edi
  bn_gencb_st cb; // [esp+Ch] [ebp-Ch] BYREF

  data = (int *)ctx->data;
  if ( ctx->pkey_gencb )
  {
    p_cb = &cb;
    evp_pkey_set_cb_translate(&cb, ctx);
  }
  else
  {
    p_cb = 0;
  }
  result = DH_new((int)p_cb);
  v5 = (char *)result;
  if ( result )
  {
    parameters = DH_generate_parameters_ex(result, *data, data[1], p_cb);
    if ( parameters )
    {
      EVP_PKEY_assign(pkey, (void *)0x1C, v5);
      return (dh_st *)parameters;
    }
    else
    {
      DH_free(0, (int)p_cb, (dh_st *)v5);
      return 0;
    }
  }
  return result;
}
