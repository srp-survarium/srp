vostok::vfs::vfs_iterator *__userpurge vostok::vfs::vfs_iterator::children_begin@<eax>(
        vostok::vfs::vfs_iterator *this@<ecx>,
        vostok::vfs::vfs_hashset **a2@<esi>,
        vostok::vfs::vfs_iterator *result)
{
  vostok::vfs::base_node<1> *m_node; // eax
  vostok::vfs::base_node<1> *m_link_target; // ecx
  vostok::vfs::base_node<1> *first_child; // edi
  vostok::vfs::vfs_hashset *referenced_link_node; // eax
  vostok::vfs::vfs_hashset *v7; // ecx

  m_node = result->m_node;
  if ( m_node )
  {
    m_link_target = result->m_link_target;
    if ( m_link_target )
      m_node = result->m_link_target;
    first_child = vostok::vfs::base_node<1>::get_first_child(m_link_target, (int)m_node);
  }
  else
  {
    first_child = 0;
  }
  referenced_link_node = (vostok::vfs::vfs_hashset *)vostok::vfs::find_referenced_link_node(first_child);
  v7 = (vostok::vfs::vfs_hashset *)(~(2 * (unsigned __int8)result->m_type) & 2 | 1);
  *a2 = result->m_hashset;
  a2[1] = (vostok::vfs::vfs_hashset *)first_child;
  a2[2] = referenced_link_node;
  a2[3] = v7;
  if ( first_child )
    vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)first_child, (int)a2);
  return (vostok::vfs::vfs_iterator *)a2;
}
