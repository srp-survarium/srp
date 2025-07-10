void __cdecl sk_pop_free(stack_st *st, void (__cdecl *func)(void *))
{
  int i; // esi
  char **data; // eax
  bool v4; // zf
  void **v5; // eax

  if ( st )
  {
    for ( i = 0; i < st->num; ++i )
    {
      data = st->data;
      v4 = data[i] == 0;
      v5 = (void **)&data[i];
      if ( !v4 )
        func(*v5);
    }
    if ( st->data )
      CRYPTO_free(st->data);
    CRYPTO_free(st);
  }
}
