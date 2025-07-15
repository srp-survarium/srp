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
  if ( v3
    || (strstr((unsigned __int8 *)filename, "\\"), v4)
    || (strstr((unsigned __int8 *)filename, (unsigned __int8 *)&stru_95963C.m_max_end), v5) )
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
      sprintf(v7, "%s.dll", filename);
    else
      sprintf(v7, "%s", filename);
    return v8;
  }
  else
  {
    ERR_put_error(0x25u, 125, 109, ".\\crypto\\dso\\dso_win32.c", 648);
    return 0;
  }
}
