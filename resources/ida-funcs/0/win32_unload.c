int __usercall win32_unload@<eax>(int a1@<ebx>, dso_st *dso)
{
  char *v3; // eax
  char *v4; // esi

  if ( dso )
  {
    if ( sk_num(&dso->meth_data->stack) >= 1 )
    {
      v3 = sk_pop(&dso->meth_data->stack);
      v4 = v3;
      if ( v3 )
      {
        if ( FreeLibrary(*(HMODULE *)v3) )
        {
          CRYPTO_free(v4);
          return 1;
        }
        else
        {
          ERR_put_error(a1, 0x25u, 121, 107, ".\\crypto\\dso\\dso_win32.c", 228);
          sk_push(&dso->meth_data->stack, v4);
          return 0;
        }
      }
      else
      {
        ERR_put_error(a1, 0x25u, 121, 104, ".\\crypto\\dso\\dso_win32.c", 223);
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
    ERR_put_error(a1, 0x25u, 121, 67, ".\\crypto\\dso\\dso_win32.c", 215);
    return 0;
  }
}
