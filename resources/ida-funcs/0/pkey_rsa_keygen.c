rsa_st *__usercall pkey_rsa_keygen@<eax>(int a1@<edi>, int a2@<ebx>, evp_pkey_ctx_st *ctx, evp_pkey_st *pkey)
{
  void *data; // esi
  bignum_st *v5; // eax
  rsa_st *result; // eax
  rsa_st *v7; // ebx
  bn_gencb_st *p_cb; // edi
  int key; // esi
  bn_gencb_st cb; // [esp+8h] [ebp-Ch] BYREF

  data = ctx->data;
  if ( !*((_DWORD *)data + 1) )
  {
    v5 = BN_new(a2);
    *((_DWORD *)data + 1) = v5;
    if ( !v5 || !BN_set_word(a2, v5, 0x10001u) )
      return 0;
  }
  result = RSA_new(a2);
  v7 = result;
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
    key = RSA_generate_key_ex(v7, *(_DWORD *)data, *((bignum_st **)data + 1), p_cb);
    if ( key <= 0 )
      RSA_free(a1, (int)v7, v7);
    else
      EVP_PKEY_assign(pkey, (void *)6, (char *)v7);
    return (rsa_st *)key;
  }
  return result;
}
