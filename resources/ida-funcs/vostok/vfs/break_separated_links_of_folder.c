void __cdecl vostok::vfs::break_separated_links_of_folder(
        vostok::vfs::base_node<1> *overlapper,
        unsigned int separator_mount_id)
{
  vostok::vfs::base_folder_node<1> *v2; // eax
  vostok::vfs::base_node<1> *i; // esi
  vostok::vfs::base_node<1> *pointer; // eax

  v2 = (vostok::vfs::base_folder_node<1> *)overlapper;
  if ( overlapper )
    v2 = vostok::vfs::cast_folder<1>(overlapper);
  for ( i = v2->m_first_child.pointer; i; i = i->m_next.pointer )
  {
    pointer = i->m_next_overlapped.pointer;
    if ( pointer && vostok::vfs::mount_id_of_node<1>(pointer) < separator_mount_id )
      i->m_next_overlapped.pointer = 0;
    if ( (i->m_flags & 1) != 0 )
      vostok::vfs::break_separated_links_of_folder(i, separator_mount_id);
  }
}
