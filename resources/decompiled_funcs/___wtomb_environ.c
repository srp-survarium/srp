int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const wchar_t *v1; // eax
  unsigned int v2; // eax
  char *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  char *envp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  envp = 0;
  v1 = *_wenviron;
  if ( !*_wenviron )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(0, 0, v1, -1, 0, 0, 0, 0);
    size = v2;
    if ( !v2 )
      break;
    v3 = (char *)_calloc_crt(v2, 1u);
    envp = v3;
    if ( !v3 )
      break;
    if ( !WideCharToMultiByte(0, 0, *v0, -1, v3, size, 0, 0) )
    {
      free(envp);
      return -1;
    }
    if ( __crtsetenv(&envp, 0) < 0 )
    {
      if ( envp )
      {
        free(envp);
        envp = 0;
      }
    }
    v1 = *++v0;
    if ( !*v0 )
      return 0;
  }
  return -1;
}
