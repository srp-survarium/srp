float *__thiscall stlp_std::priv::_STLP_alloc_proxy<float *,float,vostok::vectora_allocator<float>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<float *,float,vostok::vectora_allocator<float> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  int *v4; // [esp+0h] [ebp-18h]
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  char v7; // [esp+17h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  v5[0] = __n;
  v6 = 1;
  if ( __n )
    v4 = v5;
  else
    v4 = &v6;
  v5[1] = v4;
  return (float *)vostok::memory::base_allocator::realloc_impl(this->m_allocator, 0, 4 * *v4);
}
