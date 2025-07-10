conf_st *__cdecl def_create(conf_method_st *meth)
{
  conf_st *result; // eax
  conf_st *v2; // esi

  result = (conf_st *)CRYPTO_malloc(16, ".\\crypto\\conf\\conf_def.c", 132);
  v2 = result;
  if ( result )
  {
    if ( meth->init(result) )
    {
      return v2;
    }
    else
    {
      CRYPTO_free(v2);
      return 0;
    }
  }
  return result;
}
