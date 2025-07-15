bool __thiscall vostok::fs_new::windows_hdd_file_system::erase(
        vostok::fs_new::windows_hdd_file_system *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *absolute_physical_path)
{
  const char *v2; // eax
  const char *v3; // eax
  bool result; // al

  v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(absolute_physical_path);
  result = 1;
  if ( _unlink(v2) )
  {
    v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(absolute_physical_path);
    if ( _rmdir(v3) )
      return 0;
  }
  return result;
}
