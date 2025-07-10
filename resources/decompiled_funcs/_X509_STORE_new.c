x509_store_st *__cdecl X509_STORE_new()
{
  _DWORD *v0; // esi
  X509_VERIFY_PARAM_st *v1; // eax

  v0 = CRYPTO_malloc(72, ".\\crypto\\x509\\x509_lu.c", 182);
  if ( !v0 )
    return 0;
  v0[1] = sk_new((int (__cdecl *)(const void *, const void *))x509_object_cmp);
  *v0 = 1;
  v0[2] = sk_new_null();
  v0[4] = 0;
  v0[5] = 0;
  v1 = X509_VERIFY_PARAM_new();
  v0[3] = v1;
  if ( !v1 )
    return 0;
  v0[6] = 0;
  v0[7] = 0;
  v0[8] = 0;
  v0[9] = 0;
  v0[10] = 0;
  v0[11] = 0;
  v0[12] = 0;
  v0[13] = 0;
  v0[14] = 0;
  if ( !CRYPTO_new_ex_data(0) )
  {
    sk_free((stack_st *)v0[1]);
    CRYPTO_free(v0);
    return 0;
  }
  v0[17] = 1;
  return (x509_store_st *)v0;
}
