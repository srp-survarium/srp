void (__cdecl *__usercall win32_bind_func@<eax>(int a1@<ebx>, dso_st *dso, const char *symname))()
{
  void (__cdecl *result)(); // eax
  int v4; // eax
  char *v5; // eax

  if ( dso && symname )
  {
    if ( sk_num(&dso->meth_data->stack) >= 1 )
    {
      v4 = sk_num(&dso->meth_data->stack);
      v5 = sk_value(&dso->meth_data->stack, v4 - 1);
      if ( v5 )
      {
        result = (void (__cdecl *)())GetProcAddress(*(HMODULE *)v5, symname);
        if ( !result )
        {
          ERR_put_error(a1, 0x25u, 118, 106, ".\\crypto\\dso\\dso_win32.c", 296);
          ERR_add_error_data(3, "symname(", symname, ")");
          return 0;
        }
      }
      else
      {
        ERR_put_error(a1, 0x25u, 118, 104, ".\\crypto\\dso\\dso_win32.c", 290);
        return 0;
      }
    }
    else
    {
      ERR_put_error(a1, 0x25u, 118, 105, ".\\crypto\\dso\\dso_win32.c", 284);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x25u, 118, 67, ".\\crypto\\dso\\dso_win32.c", 279);
    return 0;
  }
  return result;
}
