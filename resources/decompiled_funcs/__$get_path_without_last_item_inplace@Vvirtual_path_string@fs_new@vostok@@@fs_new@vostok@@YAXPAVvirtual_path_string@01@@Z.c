void __cdecl vostok::fs_new::get_path_without_last_item_inplace<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *in_out_path)
{
  unsigned __int8 *v1; // eax
  const char *v2; // eax
  char *begin_src; // [esp+14h] [ebp-124h]
  vostok::fs_new::virtual_path_string new_path; // [esp+18h] [ebp-120h] BYREF
  const char *last_slash_pos; // [esp+134h] [ebp-4h]

  v1 = (unsigned __int8 *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)in_out_path);
  strrchr(v1, 0x2Fu);
  last_slash_pos = v2;
  if ( v2 )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&new_path);
    begin_src = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)in_out_path);
    vostok::fs_new::path_string_impl::clear(&new_path.m_string);
    vostok::buffer_string::append(&new_path.m_string, begin_src, last_slash_pos);
    vostok::fs_new::path_string_impl::verify_self(&new_path);
    if ( in_out_path != &new_path )
      vostok::buffer_string::operator=((vostok::fixed_string<32> *)&new_path, (vostok::fixed_string<32> *)in_out_path);
    vostok::fs_new::path_string_impl::verify_self(in_out_path);
  }
  else
  {
    vostok::fs_new::path_string_impl::clear(&in_out_path->m_string);
  }
}
