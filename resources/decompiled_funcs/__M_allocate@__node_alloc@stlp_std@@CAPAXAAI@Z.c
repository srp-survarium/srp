_STLP_atomic_freelist::item *__cdecl stlp_std::__node_alloc::_M_allocate(unsigned int *__n)
{
  unsigned int v1; // eax
  _STLP_atomic_freelist::item *result; // eax

  v1 = (*__n + 7) & 0xFFFFFFF8;
  *__n = v1;
  result = (_STLP_atomic_freelist::item *)_STLP_atomic_freelist::pop(&stlp_std::__node_alloc_impl::_S_free_list[(v1 - 1) >> 3]);
  if ( !result )
    return stlp_std::__node_alloc_impl::_S_refill(*__n);
  return result;
}
