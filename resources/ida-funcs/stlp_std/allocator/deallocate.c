void __thiscall stlp_std::allocator<char>::deallocate(stlp_std::allocator<char> *this, char *__p, unsigned int __n)
{
  if ( __p )
  {
    if ( __n <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(__p, __n);
    else
      operator delete(__p);
  }
}
