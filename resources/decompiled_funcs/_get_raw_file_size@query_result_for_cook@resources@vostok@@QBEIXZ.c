vostok::vfs::base_node<1> *__usercall vostok::resources::query_result_for_cook::get_raw_file_size@<eax>(
        vostok::resources::query_result_for_cook *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>)
{
  vostok::vfs::base_node<1> *m_node; // edx
  _BYTE v4[12]; // [esp+0h] [ebp-Ch] BYREF

  if ( a2[10].m_node )
    return (vostok::vfs::base_node<1> *)vostok::vfs::vfs_iterator::get_file_size(a2 + 10);
  m_node = a2[13].m_node;
  *(_DWORD *)v4 = a2[13].m_hashset;
  *(_DWORD *)&v4[4] = m_node;
  return vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)v4);
}
