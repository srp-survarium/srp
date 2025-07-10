char *__thiscall stlp_std::allocator<char>::_M_allocate(
        stlp_std::allocator<char> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  char *result; // eax

  if ( !__n )
    return 0;
  if ( __n <= 0x80 )
    result = (char *)stlp_std::__node_alloc::_M_allocate(&__n);
  else
    result = (char *)operator new(__n);
  *__allocated_n = __n;
  return result;
}
