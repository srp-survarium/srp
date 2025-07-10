void __cdecl X509_OBJECT_up_ref_count(x509_object_st *a)
{
  if ( a->type == 1 )
  {
    CRYPTO_add_lock((int *)a->data.ptr + 4, 1, 3, ".\\crypto\\x509\\x509_lu.c", 405);
  }
  else if ( a->type == 2 )
  {
    CRYPTO_add_lock((int *)a->data.ptr + 3, 1, 6, ".\\crypto\\x509\\x509_lu.c", 408);
  }
}
