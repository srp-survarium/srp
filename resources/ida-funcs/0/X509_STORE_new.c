x509_store_st *__usercall X509_STORE_new@<eax>(int a1@<ebx>)
{
  _DWORD *v1; // esi
  X509_VERIFY_PARAM_st *v2; // eax

  v1 = CRYPTO_malloc(72, ".\\crypto\\x509\\x509_lu.c", 182);
  if ( !v1 )
    return 0;
  v1[1] = sk_new((int (__cdecl *)(const void *, const void *))x509_object_cmp);
  *v1 = 1;
  v1[2] = sk_new_null();
  v1[4] = 0;
  v1[5] = 0;
  v2 = X509_VERIFY_PARAM_new();
  v1[3] = v2;
  if ( !v2 )
    return 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  if ( !CRYPTO_new_ex_data(0, a1) )
  {
    sk_free((stack_st *)v1[1]);
    CRYPTO_free(v1);
    return 0;
  }
  v1[17] = 1;
  return (x509_store_st *)v1;
}
