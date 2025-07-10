vostok::logging::initiator_filter *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::logging::initiator_filter *,vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::logging::initiator_filter *,vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v8; // [esp+13h] [ebp-1h]

  v8 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (vostok::logging::initiator_filter *)vostok::memory::base_allocator::realloc_impl(
                                                this->m_allocator,
                                                0,
                                                60 * *v3);
}
