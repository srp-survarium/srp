void __thiscall vostok::vfs::mounter::merge_root_node(
        vostok::vfs::mounter *this,
        unsigned int path_hash,
        vostok::vfs::base_node<1> *new_root_node,
        vostok::vfs::base_node<1> **root_node_lock)
{
  unsigned int v4; // eax
  bool added_ontop; // [esp+7h] [ebp-1h] BYREF

  added_ontop = 0;
  vostok::vfs::mounter::merge_root_node_with_tree(this, new_root_node, *root_node_lock, &added_ontop);
  if ( added_ontop )
    vostok::vfs::lock_node(new_root_node, lock_type_write, lock_operation_lock);
  v4 = vostok::vfs::mount_id_of_node<1>(new_root_node);
  vostok::vfs::vfs_hashset::insert(&this->m_file_system->hashset, path_hash, new_root_node, v4);
  if ( added_ontop )
  {
    if ( *root_node_lock )
      vostok::vfs::unlock_node(*root_node_lock, lock_type_write);
    *root_node_lock = new_root_node;
  }
}
