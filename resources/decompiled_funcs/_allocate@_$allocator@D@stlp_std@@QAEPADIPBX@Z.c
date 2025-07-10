_STLP_atomic_freelist::item *__thiscall stlp_std::allocator<char>::allocate(
        stlp_std::allocator<char> *this,
        unsigned int __n,
        const void *__formal)
{
  if ( !__n )
    return 0;
  if ( __n <= 0x80 )
    return stlp_std::__node_alloc::_M_allocate(&__n);
  return (_STLP_atomic_freelist::item *)operator new(__n);
}
