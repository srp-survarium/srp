vostok::render::skeleton_model_instance *__cdecl vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path)
{
  unsigned int last_slash_pos; // [esp+4h] [ebp-4h]

  last_slash_pos = vostok::fs_new::path_string_impl::rfind((vostok::fs_new::path_string_impl *)path, 92);
  if ( last_slash_pos == -1 )
    return vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  else
    return (vostok::render::skeleton_model_instance *)((char *)&vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path)->__vftable
                                                     + last_slash_pos
                                                     + 1);
}


vostok::render::skeleton_model_instance *__cdecl vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path)
{
  unsigned int last_slash_pos; // [esp+4h] [ebp-4h]

  last_slash_pos = vostok::fs_new::path_string_impl::rfind((vostok::fs_new::path_string_impl *)path, 47);
  if ( last_slash_pos == -1 )
    return vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  else
    return (vostok::render::skeleton_model_instance *)((char *)&vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path)->__vftable
                                                     + last_slash_pos
                                                     + 1);
}
