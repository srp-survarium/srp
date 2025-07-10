void __userpurge vostok::core::configs::binary_config::binary_config(
        vostok::core::configs::binary_config *this@<esi>,
        vostok::memory::base_allocator *allocator@<edi>,
        unsigned __int8 *buffer,
        unsigned int buffer_size)
{
  vostok::configs::binary_config_value *v4; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::core::configs::binary_config_vtbl *)&vostok::core::configs::binary_config::`vftable';
  this->m_allocator = allocator;
  this->m_root = 0;
  v4 = (vostok::configs::binary_config_value *)allocator->call_malloc(allocator, buffer_size);
  this->m_root = v4;
  memcpy((unsigned __int8 *)v4, buffer, buffer_size);
  vostok::configs::binary_config_value::fix_up(this->m_root, (unsigned int)this->m_root);
}
