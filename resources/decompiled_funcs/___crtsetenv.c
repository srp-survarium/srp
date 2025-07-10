int __usercall __crtsetenv@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char **poption, int primary)
{
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // edi
  char **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  char **v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  char **v14; // esi
  char **v15; // eax
  char **v16; // ecx
  int v17; // eax
  char *v18; // edi
  int v19; // eax
  const char *v20; // eax
  const char *equal; // [esp+4h] [ebp-14h]
  char **env; // [esp+8h] [ebp-10h]
  int retval; // [esp+Ch] [ebp-Ch]
  BOOL remove; // [esp+10h] [ebp-8h]
  char *option; // [esp+14h] [ebp-4h]

  retval = 0;
  if ( !poption )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
  v5 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( !*poption )
    goto LABEL_12;
  v6 = _mbschr(v5, 0x3Du);
  v7 = v6;
  equal = (const char *)v6;
  if ( !v6 || v5 == v6 )
    goto LABEL_12;
  remove = v6[1] == 0;
  v8 = _environ;
  if ( _environ == __initenv )
  {
    v8 = copy_environ((const char **)_environ);
    _environ = v8;
  }
  if ( !v8 )
  {
    if ( primary && _wenviron )
    {
      if ( __wtomb_environ() )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      v9 = (char **)_malloc_crt(4u);
      _environ = v9;
      if ( !v9 )
        return -1;
      *v9 = 0;
      if ( !_wenviron )
      {
        v10 = (unsigned __int16 **)_malloc_crt(4u);
        _wenviron = v10;
        if ( !v10 )
          return -1;
        *v10 = 0;
      }
    }
  }
  v11 = _environ;
  env = _environ;
  if ( !_environ )
    return -1;
  v12 = findenv(v7 - (const unsigned __int8 *)option, option);
  v13 = v12;
  if ( v12 < 0 || !*v11 )
  {
    if ( !remove )
    {
      if ( v12 < 0 )
        v13 = -v12;
      if ( (int)(v13 + 2) <= (int)v13 )
        return -1;
      if ( v13 + 2 >= 0x3FFFFFFF )
        return -1;
      v15 = (char **)_recalloc_crt(_environ, 4u, v13 + 2);
      if ( !v15 )
        return -1;
      v16 = &v15[v13];
      *v16 = option;
      v16[1] = 0;
      *poption = 0;
      goto LABEL_36;
    }
    free(option);
    *poption = 0;
    return 0;
  }
  v14 = &v11[v12];
  free(*v14);
  if ( !remove )
  {
    *v14 = option;
    *poption = 0;
    goto LABEL_37;
  }
  while ( *v14 )
  {
    *v14 = v14[1];
    v14 = &env[++v13];
  }
  if ( v13 >= 0x3FFFFFFF )
    goto LABEL_37;
  v15 = (char **)_recalloc_crt(_environ, v13, 4u);
  if ( !v15 )
    goto LABEL_37;
LABEL_36:
  _environ = v15;
LABEL_37:
  if ( primary )
  {
    strlen((unsigned __int8 *)option);
    v18 = (char *)_calloc_crt(v17 + 2, 1u);
    if ( v18 )
    {
      strlen((unsigned __int8 *)option);
      if ( strcpy_s(v18, v19 + 2, option) )
        _invoke_watson(0, (unsigned int)v18, (unsigned int)option);
      v20 = &equal[v18 - option];
      *v20 = 0;
      if ( !SetEnvironmentVariableA(v18, !remove ? v20 + 1 : 0) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(v18);
    }
  }
  if ( remove )
  {
    free(option);
    *poption = 0;
  }
  return retval;
}
