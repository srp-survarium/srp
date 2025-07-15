_STLP_atomic_freelist::item *__cdecl stlp_std::__node_alloc_impl::_S_refill(unsigned int __n)
{
  _STLP_atomic_freelist::item *v1; // ebp
  bool v2; // zf
  _STLP_atomic_freelist::item *v3; // esi
  int v5; // [esp+8h] [ebp-4h] BYREF

  v5 = 20;
  v1 = stlp_std::__node_alloc_impl::_S_chunk_alloc(__n, &v5);
  if ( v5 > 1 )
  {
    v2 = v5-- == 1;
    v3 = v1;
    if ( !v2 )
    {
      do
      {
        v3 = (_STLP_atomic_freelist::item *)((char *)v3 + __n);
        _STLP_atomic_freelist::push(&stlp_std::__node_alloc_impl::_S_free_list[(__n - 1) >> 3], v3);
        --v5;
      }
      while ( v5 );
    }
  }
  return v1;
}
