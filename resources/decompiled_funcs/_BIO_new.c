bio_st *__cdecl BIO_new(bio_method_st *method)
{
  bio_st *v1; // esi

  v1 = (bio_st *)CRYPTO_malloc(64, ".\\crypto\\bio\\bio_lib.c", 70);
  if ( v1 )
  {
    if ( !BIO_set(v1, method) )
    {
      CRYPTO_free(v1);
      return 0;
    }
    return v1;
  }
  else
  {
    ERR_put_error(0x20u, 108, 65, ".\\crypto\\bio\\bio_lib.c", 73);
    return 0;
  }
}
