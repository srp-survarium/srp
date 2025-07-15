int __cdecl win32_unload(dso_st *dso)
{
  char *v2; // eax
  char *v3; // esi

  if ( dso )
  {
    if ( sk_num(&dso->meth_data->stack) >= 1 )
    {
      v2 = sk_pop(&dso->meth_data->stack);
      v3 = v2;
      if ( v2 )
      {
        if ( FreeLibrary(*(HMODULE *)v2) )
        {
          CRYPTO_free(v3);
          return 1;
        }
        else
        {
          ERR_put_error(0x25u, 121, 107, ".\\crypto\\dso\\dso_win32.c", 228);
          sk_push(&dso->meth_data->stack, v3);
          return 0;
        }
      }
      else
      {
        ERR_put_error(0x25u, 121, 104, ".\\crypto\\dso\\dso_win32.c", 223);
        return 0;
      }
    }
    else
    {
      return 1;
    }
  }
  else
  {
    ERR_put_error(0x25u, 121, 67, ".\\crypto\\dso\\dso_win32.c", 215);
    return 0;
  }
}
