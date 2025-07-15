unsigned int __thiscall vostok::memory::pthreads3_allocator::allocated_size(vostok::memory::pthreads3_allocator *this)
{
  unsigned int result; // eax
  mallinfo *v2; // [esp+0h] [ebp-58h]
  _BYTE v3[40]; // [esp+30h] [ebp-28h] BYREF

  result = g_ptmalloc3_arena.total_size - g_ptmalloc3_arena.free_size;
  if ( g_ptmalloc3_arena.total_size != g_ptmalloc3_arena.free_size )
    return pt3mallinfo((int)v3, v2)->uordblks - 528;
  return result;
}
