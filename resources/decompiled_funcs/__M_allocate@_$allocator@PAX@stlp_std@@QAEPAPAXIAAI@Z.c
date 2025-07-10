void **__thiscall stlp_std::allocator<void *>::_M_allocate(
        stlp_std::allocator<void *> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  void **result; // eax
  unsigned int __buf_size; // [esp+8h] [ebp-4h] BYREF

  if ( __n > 0x3FFFFFFF )
  {
    puts("out of memory\n");
    exit(1);
  }
  if ( !__n )
    return 0;
  __buf_size = 4 * __n;
  result = (void **)stlp_std::__node_alloc::allocate(&__buf_size);
  *__allocated_n = __buf_size >> 2;
  return result;
}
