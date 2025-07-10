_DWORD *__usercall pt3realloc@<eax>(char *oldmem@<edi>, char *bytes)
{
  unsigned int v2; // ebp
  int v4; // eax
  malloc_arena *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  int v8; // eax
  int v9; // ecx

  v2 = (unsigned int)bytes;
  if ( __realloc_hook )
    return __realloc_hook(oldmem, (unsigned int)bytes, 0);
  if ( !oldmem )
    return pt3malloc(bytes);
  v4 = *((_DWORD *)oldmem - 1);
  if ( (v4 & 1) != 0 || (*(oldmem - 8) & 1) == 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      v5 = *(malloc_arena **)&oldmem[(v4 & 0xFFFFFFF8) - 8];
      goto LABEL_12;
    }
LABEL_11:
    v5 = &main_arena;
    goto LABEL_12;
  }
  if ( (v4 & 4) == 0 )
    goto LABEL_11;
  v5 = *(malloc_arena **)&oldmem[(v4 & 0xFFFFFFF8) - 12];
  do
LABEL_12:
    _mm_pause();
  while ( _InterlockedExchange(&v5->mutex, 1) );
  TlsSetValue(arena_key, v5);
  if ( v5 != &main_arena )
    v2 = (unsigned int)(bytes + 4);
  v6 = internal_realloc((malloc_state *)&v5->buf_[8], oldmem, v2);
  v7 = v6;
  if ( v6 && v5 != &main_arena )
  {
    v8 = *(v6 - 1);
    if ( (v8 & 1) != 0 || (*(_BYTE *)(v7 - 2) & 1) == 0 )
      v9 = 0;
    else
      v9 = 4;
    *(_DWORD *)((char *)v7 + (v8 & 0xFFFFFFF8) - v9 - 8) = v5;
    *(v7 - 1) |= 4u;
  }
  _mm_pause();
  _InterlockedExchange(&v5->mutex, 0);
  return v7;
}
