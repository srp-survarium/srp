int __usercall DSO_free@<eax>(int a1@<ebx>, dso_st *dso)
{
  int (__cdecl *dso_unload)(dso_st *); // eax
  int (__cdecl *finish)(dso_st *); // eax

  if ( !dso )
  {
    ERR_put_error(a1, 0x25u, 111, 67, ".\\crypto\\dso\\dso_lib.c", 137);
    return 0;
  }
  if ( CRYPTO_add_lock(&dso->references, -1, 28, ".\\crypto\\dso\\dso_lib.c", 141) <= 0 )
  {
    dso_unload = dso->meth->dso_unload;
    if ( dso_unload && !dso_unload(dso) )
    {
      ERR_put_error(a1, 0x25u, 111, 107, ".\\crypto\\dso\\dso_lib.c", 156);
      return 0;
    }
    finish = dso->meth->finish;
    if ( finish && !finish(dso) )
    {
      ERR_put_error(a1, 0x25u, 111, 102, ".\\crypto\\dso\\dso_lib.c", 162);
      return 0;
    }
    sk_free(&dso->meth_data->stack);
    if ( dso->filename )
      CRYPTO_free(dso->filename);
    if ( dso->loaded_filename )
      CRYPTO_free(dso->loaded_filename);
    CRYPTO_free(dso);
  }
  return 1;
}
