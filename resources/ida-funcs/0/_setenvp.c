int __cdecl _setenvp()
{
  unsigned __int8 *v0; // esi
  int v1; // edi
  int v3; // eax
  char **v4; // edi
  unsigned __int8 *i; // esi
  int v6; // eax
  unsigned int v7; // ebx
  char *v8; // eax

  if ( !__mbctype_initialized )
    __initmbctable();
  v0 = (unsigned __int8 *)_aenvptr;
  v1 = 0;
  if ( !_aenvptr )
    return -1;
  while ( *v0 )
  {
    if ( *v0 != 61 )
      ++v1;
    strlen(v0);
    v0 += v3 + 1;
  }
  v4 = (char **)_calloc_crt(v1 + 1, 4u);
  _environ = v4;
  if ( !v4 )
    return -1;
  for ( i = (unsigned __int8 *)_aenvptr; ; i += v7 )
  {
    if ( !*i )
    {
      free(_aenvptr);
      _aenvptr = 0;
      *v4 = 0;
      __env_initialized = 1;
      return 0;
    }
    strlen(i);
    v7 = v6 + 1;
    if ( *i != 61 )
      break;
LABEL_16:
    ;
  }
  v8 = (char *)_calloc_crt(v6 + 1, 1u);
  *v4 = v8;
  if ( v8 )
  {
    if ( strcpy_s(v8, v7, (const char *)i) )
      _invoke_watson(v7, (unsigned int)v4, (unsigned int)i);
    ++v4;
    goto LABEL_16;
  }
  free(_environ);
  _environ = 0;
  return -1;
}
