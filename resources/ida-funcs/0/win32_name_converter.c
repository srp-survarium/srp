char *__cdecl win32_name_converter(dso_st *dso, char *filename)
{
  unsigned int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  char *v8; // esi

  v2 = strlen(filename);
  strstr((unsigned __int8 *)filename, "/");
  if ( v3 || (strstr((unsigned __int8 *)filename, "\\"), v4) || (strstr((unsigned __int8 *)filename, ":"), v5) )
  {
    v6 = 0;
    v7 = (char *)CRYPTO_malloc(v2 + 1, ".\\crypto\\dso\\dso_win32.c", 644);
  }
  else
  {
    v6 = 1;
    v7 = (char *)CRYPTO_malloc(v2 + 5, ".\\crypto\\dso\\dso_win32.c", 641);
  }
  v8 = v7;
  if ( v7 )
  {
    if ( v6 )
      sprintf((int)filename, (int)v7, v7, "%s.dll", filename);
    else
      sprintf((int)filename, (int)v7, v7, (char *)&stru_7F9BE8.allocator, filename);
    return v8;
  }
  else
  {
    ERR_put_error(v6, 0x25u, 125, 109, ".\\crypto\\dso\\dso_win32.c", 648);
    return 0;
  }
}
