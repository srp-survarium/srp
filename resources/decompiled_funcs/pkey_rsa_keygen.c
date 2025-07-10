rsa_st *__usercall pkey_rsa_keygen@<eax>(unsigned int a1@<edi>, evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  void *data; // esi
  bignum_st *v4; // eax
  rsa_st *result; // eax
  rsa_st *v6; // ebx
  bn_gencb_st *p_cb; // edi
  int key; // esi
  bn_gencb_st cb; // [esp+8h] [ebp-Ch] BYREF

  data = ctx->data;
  if ( !*((_DWORD *)data + 1) )
  {
    v4 = BN_new();
    *((_DWORD *)data + 1) = v4;
    if ( !v4 || !BN_set_word(v4, 0x10001u) )
      return 0;
  }
  result = RSA_new();
  v6 = result;
  if ( result )
  {
    if ( ctx->pkey_gencb )
    {
      p_cb = &cb;
      evp_pkey_set_cb_translate(&cb, ctx);
    }
    else
    {
      p_cb = 0;
    }
    key = RSA_generate_key_ex(v6, *(_DWORD *)data, *((bignum_st **)data + 1), p_cb);
    if ( key <= 0 )
      RSA_free(a1, v6);
    else
      EVP_PKEY_assign(pkey, 6, (char *)v6);
    return (rsa_st *)key;
  }
  return result;
}
