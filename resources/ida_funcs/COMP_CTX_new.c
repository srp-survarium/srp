comp_ctx_st *__cdecl COMP_CTX_new(comp_method_st *meth)
{
  comp_ctx_st *v1; // esi
  comp_ctx_st *result; // eax
  int (__cdecl *init)(comp_ctx_st *); // eax

  v1 = (comp_ctx_st *)CRYPTO_malloc(28, ".\\crypto\\comp\\comp_lib.c", 11);
  result = 0;
  if ( v1 )
  {
    v1->compress_in = 0;
    v1->compress_out = 0;
    v1->expand_in = 0;
    v1->expand_out = 0;
    v1->ex_data.sk = 0;
    v1->ex_data.dummy = 0;
    v1->meth = meth;
    init = meth->init;
    if ( init )
    {
      if ( !init(v1) )
      {
        CRYPTO_free(v1);
        return 0;
      }
    }
    return v1;
  }
  return result;
}
