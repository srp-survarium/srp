int __usercall win32_load@<eax>(int a1@<ebx>, dso_st *dso)
{
  char *v2; // esi
  char *v3; // eax
  char *v4; // edi
  HMODULE LibraryA; // ebx
  char *v7; // eax

  v2 = 0;
  v3 = DSO_convert_filename(a1, dso, 0);
  v4 = v3;
  if ( !v3 )
  {
    ERR_put_error(a1, 0x25u, 120, 111, ".\\crypto\\dso\\dso_win32.c", 174);
    return 0;
  }
  LibraryA = LoadLibraryA(v3);
  if ( LibraryA )
  {
    v7 = (char *)CRYPTO_malloc(4, ".\\crypto\\dso\\dso_win32.c", 184);
    v2 = v7;
    if ( v7 )
    {
      *(_DWORD *)v7 = LibraryA;
      if ( sk_push(&dso->meth_data->stack, v7) )
      {
        dso->loaded_filename = v4;
        return 1;
      }
      ERR_put_error((int)LibraryA, 0x25u, 120, 105, ".\\crypto\\dso\\dso_win32.c", 193);
    }
    else
    {
      ERR_put_error((int)LibraryA, 0x25u, 120, 65, ".\\crypto\\dso\\dso_win32.c", 187);
    }
  }
  else
  {
    ERR_put_error(0, 0x25u, 120, 103, ".\\crypto\\dso\\dso_win32.c", 180);
    ERR_add_error_data(3, "filename(", v4, ")");
  }
  CRYPTO_free(v4);
  if ( v2 )
    CRYPTO_free(v2);
  if ( LibraryA )
    FreeLibrary(LibraryA);
  return 0;
}
