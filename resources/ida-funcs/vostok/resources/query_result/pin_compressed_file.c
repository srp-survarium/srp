vostok::const_buffer *__usercall vostok::resources::query_result::pin_compressed_file@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::const_buffer *a2@<edi>)
{
  vostok::resources::managed_resource *m_object; // eax
  unsigned int size; // ecx
  vostok::memory::managed_node *m_node; // eax
  vostok::const_buffer v6; // [esp+8h] [ebp-8h] BYREF

  m_object = this->m_compressed_resource.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    size = m_object->m_memory_usage_self.size;
    m_node = m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    a2->m_data = (const char *)&m_node[1];
    a2->m_size = size;
  }
  else
  {
    v6 = 0;
    vostok::vfs::vfs_iterator::get_inline_data(&this->m_fat_it, &v6);
    *a2 = v6;
  }
  return a2;
}
