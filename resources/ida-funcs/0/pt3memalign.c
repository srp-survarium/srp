malloc_chunk **__usercall pt3memalign@<eax>(unsigned int alignment@<eax>, unsigned int bytes)
{
  volatile int *Value; // eax
  malloc_arena *v4; // esi
  char *v5; // eax
  char *v6; // edx
  int v7; // eax
  int v8; // ecx
  volatile __int32 *p_mutex; // ecx
  malloc_arena *v10; // [esp+8h] [ebp-4h]

  if ( __memalign_hook )
    return (malloc_chunk **)__memalign_hook(alignment, bytes, 0);
  if ( alignment <= 8 )
    return pt3malloc(bytes);
  Value = (volatile int *)TlsGetValue(arena_key);
  v4 = (malloc_arena *)Value;
  v10 = (malloc_arena *)Value;
  if ( !Value || sltrywait(Value) )
  {
    v4 = arena_get2(v4, bytes + 36);
    v10 = v4;
  }
  if ( !v4 )
    return 0;
  if ( v4 != &main_arena )
    bytes += 4;
  v5 = internal_memalign(0x10u, bytes, (malloc_state *)&v4->buf_[8]);
  v6 = v5;
  if ( v5 && v4 != &main_arena )
  {
    v7 = *((_DWORD *)v5 - 1);
    if ( (v7 & 1) != 0 || (*(v6 - 8) & 1) == 0 )
      v8 = 0;
    else
      v8 = 4;
    *(_DWORD *)&v6[(v7 & 0xFFFFFFF8) - v8 - 8] = v4;
    *((_DWORD *)v6 - 1) |= 4u;
  }
  p_mutex = &v10->mutex;
  _mm_pause();
  _InterlockedExchange(p_mutex, 0);
  return (malloc_chunk **)v6;
}
