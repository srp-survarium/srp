evp_pkey_st *__cdecl EVP_PKEY_new_mac_key(int type, engine_st *e, unsigned __int8 *key, int keylen)
{
  evp_pkey_st *result; // eax
  evp_pkey_ctx_st *v5; // esi
  evp_pkey_st *ppkey; // [esp+4h] [ebp-4h] BYREF

  ppkey = 0;
  result = (evp_pkey_st *)EVP_PKEY_CTX_new_id(type, e);
  v5 = (evp_pkey_ctx_st *)result;
  if ( result )
  {
    if ( EVP_PKEY_keygen_init((evp_pkey_ctx_st *)result) > 0 && EVP_PKEY_CTX_ctrl(v5, -1, 4, 6, keylen, key) > 0 )
      EVP_PKEY_keygen(v5, &ppkey);
    EVP_PKEY_CTX_free(v5);
    return ppkey;
  }
  return result;
}
