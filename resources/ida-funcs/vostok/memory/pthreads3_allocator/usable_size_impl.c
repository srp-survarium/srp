unsigned int __thiscall vostok::memory::pthreads3_allocator::usable_size_impl(
        vostok::memory::pthreads3_allocator *this,
        _DWORD *pointer)
{
  int v2; // eax
  int v3; // ecx

  if ( !pointer )
    return 0;
  v2 = *(pointer - 1);
  if ( (v2 & 2) == 0 )
    return 0;
  if ( (v2 & 1) != 0 || (v3 = 8, (*(_BYTE *)(pointer - 2) & 1) == 0) )
    v3 = 4;
  return (v2 & 0xFFFFFFF8) - v3;
}
