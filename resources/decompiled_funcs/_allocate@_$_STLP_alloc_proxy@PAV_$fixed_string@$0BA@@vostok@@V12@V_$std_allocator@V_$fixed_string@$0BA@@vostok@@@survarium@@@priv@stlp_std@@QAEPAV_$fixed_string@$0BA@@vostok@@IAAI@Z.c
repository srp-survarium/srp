vostok::fixed_string<16> *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<16> *,vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<16> *,vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (vostok::fixed_string<16> *)vostok::memory::doug_lea_allocator::realloc_impl(
                                       (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                       0,
                                       28 * *v3);
}
