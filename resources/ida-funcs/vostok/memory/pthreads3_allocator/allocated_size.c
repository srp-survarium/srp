int __thiscall vostok::memory::pthreads3_allocator::allocated_size(vostok::memory::pthreads3_allocator *this)
{
  int result; // eax
  mallinfo *v2; // [esp+0h] [ebp-58h]
  _DWORD v3[10]; // [esp+8h] [ebp-50h] BYREF
  _BYTE v4[40]; // [esp+30h] [ebp-28h] BYREF

  result = g_ptmalloc3_arena.total_size - g_ptmalloc3_arena.free_size;
  if ( g_ptmalloc3_arena.total_size != g_ptmalloc3_arena.free_size )
  {
    qmemcpy(v3, pt3mallinfo((int)v4, v2), sizeof(v3));
    return v3[7] - 528;
  }
  return result;
}
