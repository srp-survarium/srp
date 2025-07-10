FARPROC __cdecl win32_bind_var(dso_st *dso, const char *symname)
{
  FARPROC result; // eax
  int v3; // eax
  char *v4; // eax

  if ( dso && symname )
  {
    if ( sk_num(&dso->meth_data->stack) >= 1 )
    {
      v3 = sk_num(&dso->meth_data->stack);
      v4 = sk_value(&dso->meth_data->stack, v3 - 1);
      if ( v4 )
      {
        result = GetProcAddress(*(HMODULE *)v4, symname);
        if ( !result )
        {
          ERR_put_error(0x25u, 119, 106, ".\\crypto\\dso\\dso_win32.c", 265);
          ERR_add_error_data(3, "symname(", symname, ")");
          return 0;
        }
      }
      else
      {
        ERR_put_error(0x25u, 119, 104, ".\\crypto\\dso\\dso_win32.c", 259);
        return 0;
      }
    }
    else
    {
      ERR_put_error(0x25u, 119, 105, ".\\crypto\\dso\\dso_win32.c", 253);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x25u, 119, 67, ".\\crypto\\dso\\dso_win32.c", 248);
    return 0;
  }
  return result;
}
