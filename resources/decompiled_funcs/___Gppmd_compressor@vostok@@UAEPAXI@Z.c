vostok::ppmd_compressor *__thiscall vostok::ppmd_compressor::`scalar deleting destructor'(
        vostok::ppmd_compressor *this,
        char a2)
{
  vostok::memory::base_allocator *m_allocator; // [esp-4h] [ebp-Ch]
  const vostok::memory::detail::call_destructor_predicate *v5; // [esp+0h] [ebp-8h]

  m_allocator = this->m_allocator;
  this->__vftable = (vostok::ppmd_compressor_vtbl *)&vostok::ppmd_compressor::`vftable';
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,ppmd_compressor_impl,vostok::memory::detail::call_destructor_predicate>(
    m_allocator,
    &this->m_impl,
    v5);
  this->__vftable = (vostok::ppmd_compressor_vtbl *)&vostok::compressor::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
