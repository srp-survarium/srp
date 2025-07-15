void __userpurge vostok::core::configs::binary_config::binary_config(
        vostok::core::configs::binary_config *this@<esi>,
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::resources::unmanaged_resource *a3@<ecx>,
        unsigned __int8 *buffer,
        unsigned int buffer_size)
{
  vostok::configs::binary_config_value *v5; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(a3, this, fs_iterator_class);
  this->m_root = 0;
  this->__vftable = (vostok::core::configs::binary_config_vtbl *)&vostok::core::configs::binary_config::`vftable';
  this->m_allocator = allocator;
  v5 = (vostok::configs::binary_config_value *)allocator->call_malloc(
                                                 allocator,
                                                 buffer_size,
                                                 "binary_config",
                                                 "vostok::core::configs::binary_config::load",
                                                 ".\\configs_binary_config.cpp",
                                                 34);
  this->m_root = v5;
  memcpy((unsigned __int8 *)v5, buffer, buffer_size);
  vostok::configs::binary_config_value::fix_up(this->m_root, (unsigned int)this->m_root);
}
