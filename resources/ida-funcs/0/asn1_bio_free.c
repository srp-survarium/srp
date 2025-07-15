int __cdecl asn1_bio_free(bio_st *b)
{
  void **ptr; // esi

  ptr = (void **)b->ptr;
  if ( !ptr )
    return 0;
  if ( ptr[1] )
    CRYPTO_free(ptr[1]);
  CRYPTO_free(ptr);
  b->init = 0;
  b->ptr = 0;
  b->flags = 0;
  return 1;
}
