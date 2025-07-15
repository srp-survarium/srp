void __thiscall stlp_std::allocator<char>::deallocate(
        stlp_std::allocator<char> *this,
        _STLP_atomic_freelist::item *__p,
        unsigned int __n)
{
  if ( __p )
    stlp_std::__node_alloc::deallocate(__p, __n);
}


void __thiscall stlp_std::allocator<void *>::deallocate(
        stlp_std::allocator<void *> *this,
        _STLP_atomic_freelist::item *__p,
        unsigned int __n)
{
  if ( __p )
    stlp_std::__node_alloc::deallocate(__p, 4 * __n);
}
