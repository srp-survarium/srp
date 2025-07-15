vostok::vfs::base_node<1> *__userpurge vostok::vfs::base_folder_node<1>::find_child@<eax>(
        vostok::vfs::base_folder_node<1> *this@<ecx>,
        vostok::vfs::base_node<1> **a2@<eax>,
        char *name,
        vostok::vfs::base_node<1> **out_prev_node)
{
  vostok::vfs::base_node<1> *pointer; // esi
  vostok::vfs::base_node<1> *v5; // edi

  pointer = *a2;
  v5 = 0;
  while ( 1 )
  {
    if ( !pointer )
      return 0;
    if ( !vostok::strings::compare(pointer->m_name, name) )
      break;
    v5 = pointer;
    pointer = pointer->m_next.pointer;
  }
  if ( out_prev_node )
    *out_prev_node = v5;
  return pointer;
}
