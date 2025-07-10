int __cdecl win32_load(dso_st *dso)
{
  char *v1; // esi
  char *v2; // eax
  char *v3; // edi
  HMODULE LibraryA; // ebx
  char *v6; // eax

  v1 = 0;
  v2 = DSO_convert_filename(dso, 0);
  v3 = v2;
  if ( !v2 )
  {
    ERR_put_error(0x25u, 120, 111, ".\\crypto\\dso\\dso_win32.c", 174);
    return 0;
  }
  LibraryA = LoadLibraryA(v2);
  if ( LibraryA )
  {
    v6 = (char *)CRYPTO_malloc(4, ".\\crypto\\dso\\dso_win32.c", 184);
    v1 = v6;
    if ( v6 )
    {
      *(_DWORD *)v6 = LibraryA;
      if ( sk_push(&dso->meth_data->stack, v6) )
      {
        dso->loaded_filename = v3;
        return 1;
      }
      ERR_put_error(0x25u, 120, 105, ".\\crypto\\dso\\dso_win32.c", 193);
    }
    else
    {
      ERR_put_error(0x25u, 120, 65, ".\\crypto\\dso\\dso_win32.c", 187);
    }
  }
  else
  {
    ERR_put_error(0x25u, 120, 103, ".\\crypto\\dso\\dso_win32.c", 180);
    ERR_add_error_data(3, "filename(", v3, ")");
  }
  CRYPTO_free(v3);
  if ( v1 )
    CRYPTO_free(v1);
  if ( LibraryA )
    FreeLibrary(LibraryA);
  return 0;
}
