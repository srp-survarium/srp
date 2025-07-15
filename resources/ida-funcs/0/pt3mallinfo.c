mallinfo *__usercall pt3mallinfo@<eax>(int a1@<esi>, mallinfo *result, ...)
{
  mallinfo *v2; // eax
  malloc_arena *i; // edi
  mallinfo v5; // [esp+8h] [ebp-28h] BYREF

  *(_DWORD *)(a1 + 28) = 0;
  if ( __malloc_initialized < 0 )
    ptmalloc_init();
  v2 = vostok_mspace_mallinfo((malloc_state *)&main_arena.buf_[8], &v5);
  for ( i = main_arena.next; ; i = i->next )
  {
    *(_DWORD *)(a1 + 28) += v2->uordblks;
    if ( i == &main_arena )
      break;
    v2 = vostok_mspace_mallinfo((malloc_state *)&i->buf_[8], &v5);
  }
  return (mallinfo *)a1;
}
