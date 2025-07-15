void __userpurge vostok::core::configs::binary_config::load(
        vostok::core::configs::binary_config *this@<esi>,
        unsigned int buffer_size@<edi>,
        unsigned __int8 *buffer)
{
  vostok::configs::binary_config_value *v3; // eax

  v3 = (vostok::configs::binary_config_value *)((int (__thiscall *)(vostok::memory::base_allocator *))this->m_allocator->call_malloc)(this->m_allocator);
  this->m_root = v3;
  memcpy((unsigned __int8 *)v3, buffer, buffer_size);
  vostok::configs::binary_config_value::fix_up(this->m_root, (unsigned int)this->m_root);
}
