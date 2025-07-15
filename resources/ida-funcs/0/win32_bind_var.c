FARPROC __usercall win32_bind_var@<eax>(int a1@<ebx>, dso_st *dso, const char *symname)
{
  FARPROC result; // eax
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
        result = GetProcAddress(*(HMODULE *)v5, symname);
        if ( !result )
        {
          ERR_put_error(a1, 0x25u, 119, 106, ".\\crypto\\dso\\dso_win32.c", 265);
          ERR_add_error_data(3, "symname(", symname, ")");
          return 0;
        }
      }
      else
      {
        ERR_put_error(a1, 0x25u, 119, 104, ".\\crypto\\dso\\dso_win32.c", 259);
        return 0;
      }
    }
    else
    {
      ERR_put_error(a1, 0x25u, 119, 105, ".\\crypto\\dso\\dso_win32.c", 253);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x25u, 119, 67, ".\\crypto\\dso\\dso_win32.c", 248);
    return 0;
  }
  return result;
}
