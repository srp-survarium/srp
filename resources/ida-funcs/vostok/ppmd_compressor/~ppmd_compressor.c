void __thiscall vostok::ppmd_compressor::~ppmd_compressor(vostok::ppmd_compressor *this)
{
  vostok::memory::base_allocator *m_allocator; // ebx
  ppmd_compressor_impl *m_impl; // eax
  _BYTE *v5; // ebp

  m_allocator = this->m_allocator;
  this->__vftable = (vostok::ppmd_compressor_vtbl *)&vostok::ppmd_compressor::`vftable';
  m_impl = this->m_impl;
  if ( m_impl )
  {
    v5 = __RTCastToVoid((void **)&m_impl->__vftable);
    ppmd_allocator::StopSubAllocator(&this->m_impl->m_allocator.m_allocator);
    m_allocator->call_free(m_allocator, v5, "vostok::ppmd_compressor::~ppmd_compressor", ".\\compressor_ppmd.cpp", 381u);
    this->m_impl = 0;
  }
  this->__vftable = (vostok::ppmd_compressor_vtbl *)&vostok::compressor::`vftable';
}
