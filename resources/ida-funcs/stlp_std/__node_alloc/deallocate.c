void __cdecl stlp_std::__node_alloc::deallocate(_STLP_atomic_freelist::item *__p, unsigned int __n)
{
  if ( __n <= 0x80 )
    stlp_std::__node_alloc::_M_deallocate(__p, __n);
  else
    operator delete(__p);
}
