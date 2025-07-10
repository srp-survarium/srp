vostok::vfs::base_node<1> *__thiscall vostok::vfs::base_folder_node<1>::find_child(
        vostok::vfs::base_folder_node<1> *this,
        const char *name,
        vostok::vfs::base_node<1> **out_prev_node)
{
  vostok::vfs::base_node<1> *it_prev; // [esp+Ch] [ebp-8h]
  vostok::vfs::base_node<1> *it_node; // [esp+10h] [ebp-4h]

  it_node = this->m_first_child.pointer;
  it_prev = 0;
  while ( 1 )
  {
    if ( !it_node )
      return 0;
    if ( vostok::strings::equal(it_node->m_name, name) )
      break;
    it_prev = it_node;
    it_node = it_node->m_next.pointer;
  }
  if ( out_prev_node )
    *out_prev_node = it_prev;
  return it_node;
}
