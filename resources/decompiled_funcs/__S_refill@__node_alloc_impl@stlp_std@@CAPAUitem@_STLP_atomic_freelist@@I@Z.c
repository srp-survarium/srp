_STLP_atomic_freelist::item *__cdecl stlp_std::__node_alloc_impl::_S_refill(unsigned int __n)
{
  char *v1; // ebp
  bool v2; // zf
  _STLP_atomic_freelist::item *v3; // esi
  int __nobjs; // [esp+8h] [ebp-4h] BYREF

  __nobjs = 20;
  v1 = stlp_std::__node_alloc_impl::_S_chunk_alloc(__n, (unsigned int *)&__nobjs);
  if ( __nobjs > 1 )
  {
    v2 = __nobjs-- == 1;
    v3 = (_STLP_atomic_freelist::item *)v1;
    if ( !v2 )
    {
      do
      {
        v3 = (_STLP_atomic_freelist::item *)((char *)v3 + __n);
        _STLP_atomic_freelist::push(&stlp_std::__node_alloc_impl::_S_free_list[(__n - 1) >> 3], v3);
        --__nobjs;
      }
      while ( __nobjs );
    }
  }
  return (_STLP_atomic_freelist::item *)v1;
}
