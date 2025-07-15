void __cdecl vostok::vfs::exchange_nodes_impl(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *virtual_path,
        unsigned int virtual_path_hash,
        vostok::vfs::exchange_nodes_action action,
        vostok::vfs::virtual_file_system *file_system,
        vostok::vfs::base_node<1> *what_node,
        vostok::vfs::base_node<1> *with_node,
        vostok::vfs::base_node<1> *overlapper,
        vostok::vfs::base_node<1> *root_write_lock,
        vostok::memory::base_allocator *allocator)
{
  unsigned int v9; // eax
  const char *v10; // eax
  unsigned int v11; // [esp-4h] [ebp-1Ch]
  vostok::vfs::base_node<1> *overlapped; // [esp+10h] [ebp-8h]
  vostok::vfs::base_folder_node<1> *parent_folder; // [esp+14h] [ebp-4h]

  parent_folder = what_node->m_parent.pointer;
  vostok::vfs::base_folder_node<1>::unlink_child(parent_folder, what_node, 1);
  vostok::vfs::base_folder_node<1>::prepend_child(parent_folder, with_node);
  overlapped = what_node->m_next_overlapped.pointer;
  with_node->m_next_overlapped.pointer = overlapped;
  if ( overlapper )
    overlapper->m_next_overlapped.pointer = with_node;
  v9 = vostok::vfs::mount_id_of_node<1>(with_node);
  if ( action == exchange_nodes_insert )
  {
    vostok::vfs::vfs_hashset::insert(&file_system->hashset, virtual_path_hash, with_node, v9);
    vostok::vfs::free_node(file_system, what_node, &root_write_lock, virtual_path_hash, allocator);
  }
  else
  {
    vostok::vfs::vfs_hashset::replace(&file_system->hashset, virtual_path_hash, with_node, what_node, v9);
  }
  if ( overlapper && (overlapper->m_flags & 1) == 1 && overlapped && (overlapped->m_flags & 1) == 1 )
  {
    v11 = vostok::vfs::mount_id_of_node<1>(with_node);
    v10 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(virtual_path);
    vostok::vfs::separate_folders_by_file_node(&file_system->hashset, v10, virtual_path_hash, overlapper, v11);
  }
}
