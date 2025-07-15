vostok::const_buffer *__usercall vostok::resources::query_result::pin_raw_buffer@<eax>(
        vostok::resources::query_result *this@<ecx>,
        const char **a2@<edi>)
{
  vostok::resources::managed_resource *m_object; // eax
  const char *size; // ecx
  vostok::memory::managed_node *m_node; // eax
  const char **p_m_data; // eax
  const char *v6; // ecx
  const char *m_size; // eax
  vostok::const_buffer v9; // [esp+8h] [ebp-8h] BYREF

  m_object = this->m_raw_managed_resource.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    size = (const char *)m_object->m_memory_usage_self.size;
    m_node = m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    *a2 = (const char *)&m_node[1];
    a2[1] = size;
  }
  else
  {
    p_m_data = &this->m_creation_data_from_user.m_data;
    if ( this->m_creation_data_from_user.m_data
      || this->m_creation_data_from_user.m_size
      || (p_m_data = (const char **)&this->m_raw_unmanaged_buffer.m_data, this->m_raw_unmanaged_buffer.m_data) )
    {
      v6 = *p_m_data;
      m_size = p_m_data[1];
      *a2 = v6;
    }
    else
    {
      v9.m_data = 0;
      v9.m_size = 0;
      vostok::vfs::vfs_iterator::get_inline_data(&this->m_fat_it, &v9);
      *a2 = v9.m_data;
      m_size = (const char *)v9.m_size;
    }
    a2[1] = m_size;
  }
  return (vostok::const_buffer *)a2;
}
