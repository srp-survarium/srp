vostok::mutable_buffer *__usercall vostok::resources::query_result::pin_compressed_file@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>,
        vostok::mutable_buffer *a3@<esi>)
{
  vostok::vfs::base_node<1> *m_node; // eax
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int m_size; // edx
  vostok::const_buffer inline_data; // [esp+8h] [ebp-Ch] BYREF

  m_node = a2[39].m_node;
  if ( m_node
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v5 = *(_DWORD *)&m_node->m_name[41];
    v6 = *(_DWORD *)&m_node->m_name[161];
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 44), 1u);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      a3,
      (unsigned __int8 *)(v6 + 52),
      v5);
    return a3;
  }
  else
  {
    vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&inline_data);
    vostok::vfs::vfs_iterator::get_inline_data(a2 + 10, &inline_data);
    m_size = inline_data.m_size;
    a3->m_data = (char *)inline_data.m_data;
    a3->m_size = m_size;
    return a3;
  }
}
