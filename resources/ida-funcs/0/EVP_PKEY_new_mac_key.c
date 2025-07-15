evp_pkey_st *__usercall EVP_PKEY_new_mac_key@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int type,
        engine_st *e,
        unsigned __int8 *key,
        int keylen)
{
  evp_pkey_st *result; // eax
  evp_pkey_ctx_st *v7; // esi
  evp_pkey_st *ppkey; // [esp+4h] [ebp-4h] BYREF

  ppkey = 0;
  result = (evp_pkey_st *)EVP_PKEY_CTX_new_id(a2, type, e);
  v7 = (evp_pkey_ctx_st *)result;
  if ( result )
  {
    if ( EVP_PKEY_keygen_init(a1, (evp_pkey_ctx_st *)result) > 0 && EVP_PKEY_CTX_ctrl(a1, v7, -1, 4, 6, keylen, key) > 0 )
      EVP_PKEY_keygen(a1, v7, &ppkey);
    EVP_PKEY_CTX_free(a2, v7);
    return ppkey;
  }
  return result;
}
