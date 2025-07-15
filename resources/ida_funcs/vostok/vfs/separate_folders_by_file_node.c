void __cdecl vostok::vfs::separate_folders_by_file_node(
        vostok::vfs::vfs_hashset *hashset,
        const char *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *last_overlapper,
        unsigned int separator_mount_id)
{
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+8h] [ebp-44h] BYREF
  vostok::vfs::base_node<1> *first_overlapper; // [esp+28h] [ebp-24h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+2Ch] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+3Ch] [ebp-10h] BYREF

  vostok::vfs::vfs_hashset::equal_range(hashset, &begin_end, path, hash, lock_type_write);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  first_overlapper = 0;
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    if ( (it.node->m_flags & 1) == 1 )
    {
      if ( !first_overlapper )
        first_overlapper = it.node;
    }
    else
    {
      first_overlapper = 0;
    }
    if ( it.node == last_overlapper )
      break;
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  vostok::vfs::relink_children_of_folder_range(first_overlapper, last_overlapper, separator_mount_id);
  vostok::vfs::break_separated_links_of_folder_range(first_overlapper, last_overlapper, separator_mount_id);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
}
