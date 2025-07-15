int __cdecl buffer_free(bio_st *a)
{
  void **ptr; // edi
  void *v3; // edi

  if ( !a )
    return 0;
  ptr = (void **)a->ptr;
  if ( ptr[2] )
    CRYPTO_free(ptr[2]);
  v3 = ptr[5];
  if ( v3 )
    CRYPTO_free(v3);
  CRYPTO_free(a->ptr);
  a->ptr = 0;
  a->init = 0;
  a->flags = 0;
  return 1;
}
