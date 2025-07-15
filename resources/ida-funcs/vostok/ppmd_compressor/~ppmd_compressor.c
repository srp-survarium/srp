void __thiscall vostok::ppmd_compressor::~ppmd_compressor(vostok::ppmd_compressor *this)
{
  vostok::memory::base_allocator *m_allocator; // [esp-4h] [ebp-Ch]

  m_allocator = this->m_allocator;
  this->__vftable = (vostok::ppmd_compressor_vtbl *)&vostok::ppmd_compressor::`vftable';
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,ppmd_compressor_impl,vostok::memory::detail::call_destructor_predicate>(
    &this->m_impl,
    m_allocator);
  this->__vftable = (vostok::ppmd_compressor_vtbl *)&vostok::compressor::`vftable';
}
