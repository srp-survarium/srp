_DWORD *__usercall pt3memalign@<eax>(unsigned int alignment@<eax>, char *bytes)
{
  unsigned int v2; // ebx
  malloc_arena *Value; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  int v7; // eax
  int v8; // ecx
  volatile __int32 *p_mutex; // ecx
  malloc_arena *ar_ptr; // [esp+8h] [ebp-8h]

  v2 = (unsigned int)bytes;
  if ( __memalign_hook )
    return __memalign_hook(alignment, (unsigned int)bytes, 0);
  if ( alignment <= 8 )
    return pt3malloc(bytes);
  Value = (malloc_arena *)TlsGetValue(arena_key);
  ar_ptr = Value;
  if ( !Value || (_mm_pause(), _InterlockedExchange(&Value->mutex, 1)) )
  {
    Value = arena_get2(Value, (const void *)0x10, (unsigned int)(bytes + 36));
    ar_ptr = Value;
  }
  if ( !Value )
    return 0;
  if ( Value != &main_arena )
    v2 = (unsigned int)(bytes + 4);
  v5 = internal_memalign((malloc_state *)&Value->buf_[8], 0x10u, v2);
  v6 = v5;
  if ( v5 && Value != &main_arena )
  {
    v7 = *(v5 - 1);
    if ( (v7 & 1) != 0 || (*(_BYTE *)(v6 - 2) & 1) == 0 )
      v8 = 0;
    else
      v8 = 4;
    *(_DWORD *)((char *)v6 + (v7 & 0xFFFFFFF8) - v8 - 8) = Value;
    *(v6 - 1) |= 4u;
  }
  p_mutex = &ar_ptr->mutex;
  _mm_pause();
  _InterlockedExchange(p_mutex, 0);
  return v6;
}
