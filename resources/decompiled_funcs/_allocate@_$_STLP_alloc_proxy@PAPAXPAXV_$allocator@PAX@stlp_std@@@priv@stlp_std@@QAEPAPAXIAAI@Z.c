void **__thiscall stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  void *v3; // eax
  unsigned int v6; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  if ( __n > 0x3FFFFFFF )
  {
    puts("out of memory\n");
    exit(1);
  }
  if ( !__n )
    return 0;
  v6 = 4 * __n;
  v3 = stlp_std::__node_alloc::allocate(&v6);
  *__allocated_n = v6 >> 2;
  return (void **)v3;
}
