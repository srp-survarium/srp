malloc_chunk **__cdecl pt3malloc(unsigned int bytes)
{
  unsigned int v1; // ebx
  volatile int *Value; // eax
  malloc_arena *v4; // esi
  malloc_chunk **v5; // eax
  malloc_chunk **v6; // edx
  int v7; // eax
  int v8; // ecx
  volatile __int32 *p_mutex; // ecx
  malloc_arena *v10; // [esp+8h] [ebp-4h]

  v1 = bytes;
  if ( __malloc_hook )
    return (malloc_chunk **)__malloc_hook(bytes, 0);
  Value = (volatile int *)TlsGetValue(arena_key);
  v4 = (malloc_arena *)Value;
  v10 = (malloc_arena *)Value;
  if ( !Value || sltrywait(Value) )
  {
    v4 = arena_get2(v4, bytes + 4);
    v10 = v4;
  }
  if ( !v4 )
    return 0;
  if ( v4 != &main_arena )
    v1 = bytes + 4;
  v5 = vostok_mspace_malloc((malloc_state *)&v4->buf_[8], v1);
  v6 = v5;
  if ( v5 && v4 != &main_arena )
  {
    v7 = (int)*(v5 - 1);
    if ( (v7 & 1) != 0 || (*(_BYTE *)(v6 - 2) & 1) == 0 )
      v8 = 0;
    else
      v8 = 4;
    *(malloc_chunk **)((char *)v6 + (v7 & 0xFFFFFFF8) - v8 - 8) = (malloc_chunk *)v4;
    *(v6 - 1) = (malloc_chunk *)((unsigned int)*(v6 - 1) | 4);
  }
  p_mutex = &v10->mutex;
  _mm_pause();
  _InterlockedExchange(p_mutex, 0);
  return v6;
}
