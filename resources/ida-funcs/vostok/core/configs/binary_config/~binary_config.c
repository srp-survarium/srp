void __thiscall vostok::core::configs::binary_config::~binary_config(vostok::core::configs::binary_config *this)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::configs::binary_config_value *m_root; // eax

  m_allocator = this->m_allocator;
  this->__vftable = (vostok::core::configs::binary_config_vtbl *)&vostok::core::configs::binary_config::`vftable';
  m_root = this->m_root;
  if ( m_root )
  {
    m_allocator->call_free(
      m_allocator,
      (void *)m_root,
      "vostok::core::configs::binary_config::~binary_config",
      ".\\configs_binary_config.cpp",
      27u);
    this->m_root = 0;
  }
  this->__vftable = (vostok::core::configs::binary_config_vtbl *)&vostok::configs::binary_config::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
