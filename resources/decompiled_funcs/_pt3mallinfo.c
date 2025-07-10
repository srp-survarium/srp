mallinfo *__usercall pt3mallinfo@<eax>(int a1@<edi>, mallinfo *result, ...)
{
  bool v2; // sf
  malloc_arena *v3; // esi
  mallinfo *v4; // eax
  malloc_state *v6; // [esp+0h] [ebp-5Ch]

  v2 = __malloc_initialized < 0;
  *(_DWORD *)(a1 + 28) = 0;
  if ( v2 )
    ptmalloc_init();
  v3 = &main_arena;
  do
  {
    v4 = internal_mallinfo((mallinfo *)&v3->buf_[8], v6);
    v3 = v3->next;
    *(_DWORD *)(a1 + 28) += v4->uordblks;
  }
  while ( v3 != &main_arena );
  return (mallinfo *)a1;
}
