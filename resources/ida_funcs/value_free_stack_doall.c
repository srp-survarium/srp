void __cdecl value_free_stack_doall(CONF_VALUE *a)
{
  stack_st *value; // ebx
  int i; // edi
  void **v3; // esi

  if ( !a->name )
  {
    value = (stack_st *)a->value;
    for ( i = sk_num(value) - 1; i >= 0; --i )
    {
      v3 = (void **)sk_value(value, i);
      CRYPTO_free(v3[2]);
      CRYPTO_free(v3[1]);
      CRYPTO_free(v3);
    }
    if ( value )
      sk_free(value);
    CRYPTO_free(a->section);
    CRYPTO_free(a);
  }
}
