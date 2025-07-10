bool __thiscall vostok::vfs::query_notification_operation::mounts_filter(
        vostok::vfs::query_notification_operation *this,
        const char *descriptor,
        const char *physical_path,
        const char *virtual_path)
{
  const char *v4; // eax
  const char *v6; // eax

  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_physical_path);
  if ( !vostok::fs_new::path_starts_with(v4, physical_path) )
    return 0;
  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_virtual_path);
  return vostok::fs_new::path_starts_with(v6, virtual_path);
}
