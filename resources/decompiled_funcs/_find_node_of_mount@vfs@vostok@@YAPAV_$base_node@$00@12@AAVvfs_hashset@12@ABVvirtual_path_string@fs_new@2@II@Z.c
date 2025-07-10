vostok::vfs::base_node<1> *__cdecl vostok::vfs::find_node_of_mount(
        vostok::vfs::vfs_hashset *hashset,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *virtual_path,
        unsigned int virtual_path_hash,
        unsigned int mount_id)
{
  const char *v4; // eax
  vostok::vfs::base_node<1> *node; // [esp+8h] [ebp-44h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+Ch] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+1Ch] [ebp-30h] BYREF
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+2Ch] [ebp-20h] BYREF

  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(virtual_path);
  vostok::vfs::vfs_hashset::equal_range(hashset, &begin_end, v4, virtual_path_hash, lock_type_read);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    node = it.node;
    if ( vostok::vfs::mount_id_of_node<1>(it.node) == mount_id )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return node;
    }
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  return 0;
}
