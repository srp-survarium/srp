int __usercall __crtsetenv@<eax>(int a1@<edi>, float *a2@<esi>, char **poption, const int primary)
{
  char *v5; // esi
  int v6; // eax
  int v7; // edi
  char **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  char **v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // esi
  char **v15; // eax
  unsigned __int8 **v16; // ecx
  int v17; // eax
  unsigned __int8 *v18; // edi
  int v19; // eax
  char *v20; // eax
  survarium::empty_hands *v21; // [esp-Ch] [ebp-24h]
  survarium::empty_hands *v22; // [esp-Ch] [ebp-24h]
  vostok::collision::ray_triangle_result *v25; // [esp+0h] [ebp-18h]
  const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *v26; // [esp+4h] [ebp-14h]
  char **v27; // [esp+8h] [ebp-10h]
  int v28; // [esp+Ch] [ebp-Ch]
  BOOL v29; // [esp+10h] [ebp-8h]
  unsigned __int8 *buf; // [esp+14h] [ebp-4h]

  v28 = 0;
  if ( !poption )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, (int)a2);
    return -1;
  }
  v5 = *poption;
  buf = (unsigned __int8 *)*poption;
  if ( !*poption )
    goto LABEL_12;
  _mbschr(a1, (int)v5, v5, 0x3Du);
  v7 = v6;
  v26 = (const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *)v6;
  if ( !v6 || v5 == (char *)v6 )
    goto LABEL_12;
  v29 = *(_BYTE *)(v6 + 1) == 0;
  v8 = _environ;
  if ( _environ == __initenv )
  {
    v8 = copy_environ(_environ);
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
      if ( v29 )
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
  v27 = _environ;
  if ( !_environ )
    return -1;
  v12 = findenv((const char *)(v7 - (_DWORD)buf), (char *)buf);
  v13 = v12;
  if ( v12 < 0 || !*v11 )
  {
    if ( !v29 )
    {
      if ( v12 < 0 )
        v13 = -v12;
      if ( v13 + 2 <= v13 )
        return -1;
      if ( (unsigned int)(v13 + 2) >= 0x3FFFFFFF )
        return -1;
      _recalloc_crt(
        v21,
        (int)v11,
        (const vostok::collision::object *)_environ,
        (const vostok::math::float3 *)4,
        (const vostok::math::float3 *)(v13 + 2),
        *(float *)&a1,
        a2,
        v25,
        v26);
      if ( !v15 )
        return -1;
      v16 = (unsigned __int8 **)&v15[v13];
      *v16 = buf;
      v16[1] = 0;
      *poption = 0;
      goto LABEL_36;
    }
    free(buf);
    *poption = 0;
    return 0;
  }
  v14 = (int)&v11[v12];
  free(*(void **)v14);
  if ( !v29 )
  {
    *(_DWORD *)v14 = buf;
    *poption = 0;
    goto LABEL_37;
  }
  while ( *(_DWORD *)v14 )
  {
    *(_DWORD *)v14 = *(_DWORD *)(v14 + 4);
    v14 = (int)&v27[++v13];
  }
  if ( (unsigned int)v13 >= 0x3FFFFFFF )
    goto LABEL_37;
  _recalloc_crt(
    v22,
    v14,
    (const vostok::collision::object *)_environ,
    (const vostok::math::float3 *)v13,
    (const vostok::math::float3 *)4,
    *(float *)&a1,
    a2,
    v25,
    v26);
  if ( !v15 )
    goto LABEL_37;
LABEL_36:
  _environ = v15;
LABEL_37:
  if ( primary )
  {
    strlen(buf);
    v18 = _calloc_crt(v17 + 2, 1u);
    if ( v18 )
    {
      strlen(buf);
      if ( strcpy_s((int)v18, (char *)v18, v19 + 2, (const char *)buf) )
        _invoke_watson(0, (int)v18, (int)buf);
      v20 = (char *)v26 + v18 - buf;
      *v20 = 0;
      if ( !SetEnvironmentVariableA((LPCSTR)v18, !v29 ? v20 + 1 : 0) )
      {
        v28 = -1;
        *_errno() = 42;
      }
      free(v18);
    }
  }
  if ( v29 )
  {
    free(buf);
    *poption = 0;
  }
  return v28;
}
