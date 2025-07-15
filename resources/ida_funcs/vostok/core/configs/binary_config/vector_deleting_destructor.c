vostok::core::configs::binary_config *__thiscall vostok::core::configs::binary_config::`vector deleting destructor'(
        vostok::core::configs::binary_config *this,
        char a2)
{
  vostok::memory::base_allocator *m_allocator; // ecx

  m_allocator = this->m_allocator;
  this->__vftable = (vostok::core::configs::binary_config_vtbl *)&vostok::core::configs::binary_config::`vftable';
  if ( this->m_root )
  {
    m_allocator->call_free(m_allocator, this->m_root);
    this->m_root = 0;
  }
  this->__vftable = (vostok::core::configs::binary_config_vtbl *)&vostok::configs::binary_config::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
