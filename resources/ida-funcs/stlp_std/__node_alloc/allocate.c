_STLP_atomic_freelist::item *__cdecl stlp_std::__node_alloc::allocate(unsigned int *__n)
{
  if ( *__n <= 0x80 )
    return stlp_std::__node_alloc::_M_allocate(__n);
  else
    return (_STLP_atomic_freelist::item *)operator new(*__n);
}
