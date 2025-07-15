int (__cdecl *__cdecl onexit_nolock(int (__cdecl *func)()))()
{
  PVOID *v1; // edi
  PVOID *v2; // eax
  PVOID *v3; // esi
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // eax
  unsigned int v7; // eax
  char *v8; // eax
  PVOID *ptr; // [esp+Ch] [ebp-4h]

  v1 = (PVOID *)_decode_pointer(__onexitbegin);
  ptr = v1;
  v2 = (PVOID *)_decode_pointer(__onexitend);
  v3 = v2;
  if ( v2 >= v1 )
  {
    v4 = (char *)v2 - (char *)v1;
    if ( (unsigned int)((char *)v2 - (char *)v1) < 0xFFFFFFFC )
    {
      v5 = _msize(v1);
      if ( v5 >= v4 + 4 )
      {
LABEL_11:
        *v3 = _encode_pointer(func);
        __onexitend = (void (__cdecl **)())_encode_pointer(v3 + 1);
        return func;
      }
      v6 = 2048;
      if ( v5 < 0x800 )
        v6 = v5;
      v7 = v5 + v6;
      if ( v7 >= v5 && (v8 = (char *)_realloc_crt(ptr, v7)) != 0
        || v5 + 16 >= v5 && (v8 = (char *)_realloc_crt(ptr, v5 + 16)) != 0 )
      {
        v3 = (PVOID *)&v8[4 * (v4 >> 2)];
        __onexitbegin = (void (__cdecl **)())_encode_pointer(v8);
        goto LABEL_11;
      }
    }
  }
  return 0;
}
