void __cdecl stlp_std::__node_alloc::_M_deallocate(_STLP_atomic_freelist::item *__p, unsigned int __n)
{
  _STLP_atomic_freelist::push(&stlp_std::__node_alloc_impl::_S_free_list[(__n - 1) >> 3], __p);
}
