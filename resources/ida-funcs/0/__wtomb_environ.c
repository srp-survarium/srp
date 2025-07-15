int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const wchar_t *v1; // eax
  unsigned int v2; // eax
  unsigned __int8 *v3; // eax
  int cbMultiByte; // [esp+Ch] [ebp-8h]
  char *poption; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  poption = 0;
  v1 = *_wenviron;
  if ( !*_wenviron )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(0, 0, v1, -1, 0, 0, 0, 0);
    cbMultiByte = v2;
    if ( !v2 )
      break;
    v3 = _calloc_crt(v2, 1u);
    poption = (char *)v3;
    if ( !v3 )
      break;
    if ( !WideCharToMultiByte(0, 0, *v0, -1, (LPSTR)v3, cbMultiByte, 0, 0) )
    {
      free(poption);
      return -1;
    }
    if ( __crtsetenv((int)v0, 0, &poption, 0) < 0 )
    {
      if ( poption )
      {
        free(poption);
        poption = 0;
      }
    }
    v1 = *++v0;
    if ( !*v0 )
      return 0;
  }
  return -1;
}
