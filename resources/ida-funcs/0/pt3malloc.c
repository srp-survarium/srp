_DWORD *__usercall pt3malloc@<eax>(char *bytes@<eax>)
{
  char *v1; // edi
  malloc_arena *Value; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // ecx
  volatile __int32 *p_mutex; // ecx
  malloc_arena *ar_ptr; // [esp+4h] [ebp-8h]

  v1 = bytes;
  if ( __malloc_hook )
    return __malloc_hook((unsigned int)bytes, 0);
  Value = (malloc_arena *)TlsGetValue(arena_key);
  ar_ptr = Value;
  if ( !Value || (_mm_pause(), _InterlockedExchange(&Value->mutex, 1)) )
  {
    Value = arena_get2(Value, v1, (unsigned int)(v1 + 4));
    ar_ptr = Value;
  }
  if ( !Value )
    return 0;
  if ( Value != &main_arena )
    v1 += 4;
  v4 = vostok_mspace_malloc(&Value->buf_[8], (unsigned int)v1);
  v5 = v4;
  if ( v4 && Value != &main_arena )
  {
    v6 = *(v4 - 1);
    if ( (v6 & 1) != 0 || (*(_BYTE *)(v5 - 2) & 1) == 0 )
      v7 = 0;
    else
      v7 = 4;
    *(_DWORD *)((char *)v5 + (v6 & 0xFFFFFFF8) - v7 - 8) = Value;
    *(v5 - 1) |= 4u;
  }
  p_mutex = &ar_ptr->mutex;
  _mm_pause();
  _InterlockedExchange(p_mutex, 0);
  return v5;
}
