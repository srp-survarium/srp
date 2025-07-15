malloc_chunk **__usercall pt3realloc@<eax>(char *oldmem@<edi>, unsigned int bytes)
{
  int v3; // eax
  malloc_arena *v4; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // edx
  int v7; // eax
  int v8; // ecx

  if ( __realloc_hook )
    return (malloc_chunk **)__realloc_hook(oldmem, bytes, 0);
  if ( !oldmem )
    return pt3malloc(bytes);
  v3 = *((_DWORD *)oldmem - 1);
  if ( (v3 & 1) != 0 || (*(oldmem - 8) & 1) == 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      v4 = *(malloc_arena **)&oldmem[(v3 & 0xFFFFFFF8) - 8];
      goto LABEL_12;
    }
LABEL_11:
    v4 = &main_arena;
    goto LABEL_12;
  }
  if ( (v3 & 4) == 0 )
    goto LABEL_11;
  v4 = *(malloc_arena **)&oldmem[(v3 & 0xFFFFFFF8) - 12];
LABEL_12:
  slwait(&v4->mutex);
  TlsSetValue(arena_key, v4);
  if ( v4 != &main_arena )
    bytes += 4;
  v5 = vostok_mspace_realloc((malloc_state *)&v4->buf_[8], (unsigned __int8 *)oldmem, bytes);
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
  _mm_pause();
  _InterlockedExchange(&v4->mutex, 0);
  return (malloc_chunk **)v6;
}
