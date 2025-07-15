void __cdecl sk_free(stack_st *st)
{
  if ( st )
  {
    if ( st->data )
      CRYPTO_free(st->data);
    CRYPTO_free(st);
  }
}
