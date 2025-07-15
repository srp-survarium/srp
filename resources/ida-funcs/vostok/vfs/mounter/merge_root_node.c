void __userpurge vostok::vfs::mounter::merge_root_node(
        vostok::vfs::base_node<1> *new_root_node@<edi>,
        vostok::vfs::base_node<1> **root_node_lock@<esi>,
        vostok::vfs::mounter *this,
        __int16 path_hash)
{
  vostok::vfs::mounter *v4; // ebx
  vostok::vfs::base_node<1> *v5; // eax
  vostok::vfs::should_overlap_predicate v6; // eax
  vostok::vfs::vfs_hashset *v7; // ecx
  vostok::vfs::mounter *v8; // [esp-8h] [ebp-10h]

  v4 = this;
  v5 = *root_node_lock;
  v8 = this;
  HIBYTE(this) = 0;
  vostok::vfs::mounter::merge_root_node_with_tree(new_root_node, v5, v8, (bool *)&this + 3);
  if ( HIBYTE(this) )
    vostok::vfs::lock_node(new_root_node, lock_type_write, lock_operation_lock);
  v6.mount_id = vostok::vfs::mount_id_of_node<1>(new_root_node);
  vostok::vfs::vfs_hashset::insert(v7, (int)&v4->m_file_system->hashset, path_hash, new_root_node, v6);
  if ( HIBYTE(this) )
  {
    if ( *root_node_lock )
      vostok::vfs::unlock_node(*root_node_lock, lock_type_write);
    *root_node_lock = new_root_node;
  }
}
