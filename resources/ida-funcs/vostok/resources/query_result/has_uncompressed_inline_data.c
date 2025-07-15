BOOL __usercall vostok::resources::query_result::has_uncompressed_inline_data@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>)
{
  vostok::vfs::vfs_iterator *v2; // ecx
  vostok::vfs::base_node<1> *m_link_target; // eax

  if ( !a2[10].m_node )
    return 0;
  v2 = a2 + 10;
  m_link_target = a2[10].m_link_target;
  if ( !m_link_target )
    m_link_target = v2->m_node;
  return (m_link_target->m_flags & 0x40) != 0 && !vostok::vfs::vfs_iterator::is_compressed(v2);
}
