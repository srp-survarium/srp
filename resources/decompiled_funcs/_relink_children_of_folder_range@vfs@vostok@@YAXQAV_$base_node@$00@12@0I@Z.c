void __cdecl vostok::vfs::relink_children_of_folder_range(
        vostok::vfs::base_node<1> *const it_overlapper,
        vostok::vfs::base_node<1> *const last_overlapper,
        unsigned int separator_mount_id)
{
  if ( it_overlapper != last_overlapper )
    vostok::vfs::relink_children_of_folder_range(
      it_overlapper->m_next_overlapped.pointer,
      last_overlapper,
      separator_mount_id);
  vostok::vfs::relink_children_of_folder(it_overlapper, separator_mount_id);
}
