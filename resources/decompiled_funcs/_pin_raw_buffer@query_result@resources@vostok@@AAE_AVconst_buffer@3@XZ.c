vostok::mutable_buffer *__usercall vostok::resources::query_result::pin_raw_buffer@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        vostok::mutable_buffer *a3@<esi>)
{
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int m_size; // ecx
  vostok::const_buffer inline_data; // [esp+8h] [ebp-Ch] BYREF

  v4 = *(_DWORD *)(a2 + 632);
  if ( v4
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v5 = *(_DWORD *)(v4 + 92);
    v6 = *(_DWORD *)(v4 + 212);
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 44), 1u);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      a3,
      (unsigned __int8 *)(v6 + 52),
      v5);
    return a3;
  }
  else if ( *(_DWORD *)(a2 + 208) || *(_DWORD *)(a2 + 212) )
  {
    a3->m_data = *(char **)(a2 + 208);
    a3->m_size = *(_DWORD *)(a2 + 212);
    return a3;
  }
  else
  {
    if ( vostok::mutable_buffer::operator bool((vostok::mutable_buffer *)(a2 + 636)) )
    {
      vostok::const_buffer::const_buffer((vostok::const_buffer *)a3, (const vostok::mutable_buffer *)(a2 + 636));
    }
    else
    {
      vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&inline_data);
      vostok::vfs::vfs_iterator::get_inline_data((vostok::vfs::vfs_iterator *)(a2 + 160), &inline_data);
      m_size = inline_data.m_size;
      a3->m_data = (char *)inline_data.m_data;
      a3->m_size = m_size;
    }
    return a3;
  }
}
