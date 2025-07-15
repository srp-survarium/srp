vostok::vfs::vfs_iterator *__usercall vostok::resources::query_result::get_fat_it_zero_if_physical_path_it@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // ecx
  vostok::vfs::base_node<1> *m_link_target; // edx
  vostok::vfs::vfs_iterator::type_enum m_type; // ecx

  if ( (this->m_flags & 0x800) != 0 )
  {
    a2->m_hashset = 0;
    a2->m_node = 0;
    a2->m_link_target = 0;
    a2->m_type = type_number;
  }
  else
  {
    p_m_fat_it = &this->m_fat_it;
    a2->m_hashset = p_m_fat_it->m_hashset;
    a2->m_node = p_m_fat_it->m_node;
    m_link_target = p_m_fat_it->m_link_target;
    m_type = p_m_fat_it->m_type;
    a2->m_link_target = m_link_target;
    a2->m_type = m_type;
  }
  return a2;
}
