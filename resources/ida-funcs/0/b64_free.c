int __cdecl b64_free(bio_st *a)
{
  if ( !a )
    return 0;
  CRYPTO_free(a->ptr);
  a->ptr = 0;
  a->init = 0;
  a->flags = 0;
  return 1;
}
