vostok::vfs::base_node<1> *__thiscall vostok::vfs::query_notification_operation::find_node_on_virtual_path(
        vostok::vfs::query_notification_operation *this)
{
  const char *v1; // eax
  vostok::vfs::base_node<1> *node_on_virtual_path; // [esp+Ch] [ebp-44h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+10h] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_iterator it_end; // [esp+30h] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+40h] [ebp-10h] BYREF

  v1 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_virtual_path);
  vostok::vfs::vfs_hashset::equal_range(&this->m_file_system->hashset, &begin_end, v1, lock_type_read);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  node_on_virtual_path = vostok::vfs::query_notification_operation::find_node_on_virtual_path(this, &it, &it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  return node_on_virtual_path;
}
