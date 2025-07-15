vostok::fs_new::physical_path_initializer *__thiscall vostok::fs_new::physical_path_info::children_begin(
        vostok::fs_new::physical_path_info *this,
        vostok::fs_new::physical_path_initializer *result)
{
  const char *v3; // eax
  char v5; // [esp+32h] [ebp-146h] BYREF
  char s; // [esp+33h] [ebp-145h] BYREF
  unsigned int saved_full_path_size; // [esp+34h] [ebp-144h]
  vostok::fs_new::physical_path_initializer initializer; // [esp+38h] [ebp-140h] BYREF

  if ( this->data.type == type_file )
  {
    vostok::fs_new::physical_path_info::children_end(this, result);
  }
  else
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(&initializer);
    initializer.device = this->device;
    initializer.parent = this;
    initializer.search_handle = -1;
    vostok::fs_new::physical_path_info::initialize_full_path_if_needed(this);
    saved_full_path_size = vostok::fs_new::path_string_impl::length(&this->data.path);
    s = 92;
    vostok::fs_new::path_string_impl::operator+=<char>(&this->data.path, &s);
    v5 = 42;
    vostok::fs_new::path_string_impl::operator+=<char>(&this->data.path, &v5);
    v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->data.path);
    this->device->find_first(this->device, (unsigned __int64 *)&initializer, &initializer.data, v3);
    vostok::fs_new::path_string_impl::set_length(&this->data.path, saved_full_path_size);
    result->search_handle = initializer.search_handle;
    result->parent = initializer.parent;
    vostok::fs_new::physical_path_info_data::physical_path_info_data(&result->data, &initializer.data);
    result->device = initializer.device;
  }
  return result;
}
