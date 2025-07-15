vostok::vfs::vfs_iterator *__userpurge vostok::vfs::vfs_iterator::operator++@<eax>(
        vostok::vfs::vfs_iterator *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<esi>,
        vostok::vfs::vfs_iterator *result)
{
  vostok::vfs::base_node<1> *m_node; // eax
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_node<1> *v5; // edi

  if ( a2->m_node )
  {
    do
    {
      m_node = a2->m_node;
      if ( (m_node->m_flags & 0x800) != 0x800 )
        break;
      pointer = m_node->m_next.pointer;
      a2->m_node = pointer;
    }
    while ( pointer );
  }
  v5 = a2->m_node->m_next.pointer;
  a2->m_node = v5;
  if ( v5 )
    a2->m_link_target = vostok::vfs::find_referenced_link_node(v5);
  else
    a2->m_link_target = 0;
  *result = *a2;
  return result;
}
