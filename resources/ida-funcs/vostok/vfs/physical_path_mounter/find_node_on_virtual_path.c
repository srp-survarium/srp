vostok::vfs::base_node<1> *__thiscall vostok::vfs::physical_path_mounter::find_node_on_virtual_path(
        vostok::vfs::physical_path_mounter *this,
        vostok::vfs::base_node<1> **out_overlapper)
{
  const char *v2; // eax
  vostok::vfs::base_node<1> *node; // [esp+10h] [ebp-44h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+14h] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_iterator it_end; // [esp+34h] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+44h] [ebp-10h] BYREF

  v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
  vostok::vfs::vfs_hashset::equal_range(&this->m_file_system->hashset, &begin_end, v2, lock_type_read);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  *out_overlapper = 0;
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    node = it.node;
    if ( vostok::vfs::mount_id_of_node<1>(it.node) == this->m_mount_id )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return node;
    }
    *out_overlapper = node;
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  return 0;
}
