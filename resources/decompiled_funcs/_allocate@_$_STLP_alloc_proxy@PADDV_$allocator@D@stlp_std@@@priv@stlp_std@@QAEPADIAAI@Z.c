// attributes: thunk
char *__thiscall stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  return stlp_std::allocator<char>::_M_allocate(this, __n, __allocated_n);
}
