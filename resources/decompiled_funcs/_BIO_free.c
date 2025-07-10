int __usercall BIO_free@<eax>(unsigned int a1@<edi>, bio_st *a)
{
  int result; // eax
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // eax
  int (__cdecl *destroy)(bio_st *); // eax

  if ( !a )
    return 0;
  if ( CRYPTO_add_lock(&a->references, -1, 21, ".\\crypto\\bio\\bio_lib.c", 117) > 0 )
    return 1;
  callback = a->callback;
  if ( !callback || (result = callback(a, 1, 0, 0, 0, 1), result > 0) )
  {
    CRYPTO_free_ex_data(a1);
    if ( a->method )
    {
      destroy = a->method->destroy;
      if ( destroy )
      {
        destroy(a);
        CRYPTO_free(a);
      }
    }
    return 1;
  }
  return result;
}
