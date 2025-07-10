X509_VERIFY_PARAM_st *__cdecl X509_VERIFY_PARAM_new()
{
  _DWORD *v0; // esi
  stack_st *v1; // eax

  v0 = CRYPTO_malloc(40, ".\\crypto\\x509\\x509_vpm.c", 91);
  *v0 = 0;
  v0[1] = 0;
  v0[2] = 0;
  v0[3] = 0;
  v0[4] = 0;
  v0[5] = 0;
  v0[6] = 0;
  v0[7] = 0;
  v0[8] = 0;
  v0[9] = 0;
  if ( v0 )
  {
    v1 = (stack_st *)v0[9];
    *v0 = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[4] = 0;
    v0[5] = 0;
    v0[8] = -1;
    if ( v1 )
    {
      sk_pop_free(v1, (void (__cdecl *)(void *))ASN1_OBJECT_free);
      v0[9] = 0;
    }
  }
  return (X509_VERIFY_PARAM_st *)v0;
}
