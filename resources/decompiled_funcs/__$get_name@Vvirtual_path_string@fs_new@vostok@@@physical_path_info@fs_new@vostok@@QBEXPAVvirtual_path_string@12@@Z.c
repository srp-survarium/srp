void __thiscall vostok::fs_new::physical_path_info::get_name<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::physical_path_info *this,
        vostok::fs_new::virtual_path_string *out_name)
{
  char *v2; // [esp+8h] [ebp-8h] BYREF
  char *s; // [esp+Ch] [ebp-4h] BYREF

  if ( this->data.path_type == path_type_contains_name )
  {
    s = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->data.path);
    vostok::fs_new::virtual_path_string::operator=<char const *>(out_name, (const char **)&s);
  }
  else
  {
    v2 = (char *)vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->data.path);
    vostok::fs_new::virtual_path_string::operator=<char const *>(out_name, (const char **)&v2);
  }
}
