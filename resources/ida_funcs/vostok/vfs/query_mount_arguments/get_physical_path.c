vostok::fs_new::native_path_string *__thiscall vostok::vfs::query_mount_arguments::get_physical_path(
        vostok::vfs::query_mount_arguments *this,
        vostok::fs_new::native_path_string *result)
{
  char *v3; // eax
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  vostok::fs_new::path_string_impl v7; // [esp+28h] [ebp-238h] BYREF
  bool append_result; // [esp+13Fh] [ebp-121h]
  vostok::fs_new::native_path_string out_result; // [esp+140h] [ebp-120h] BYREF
  vostok::vfs::external_subfat_node<1> *external_subfat; // [esp+25Ch] [ebp-4h]

  if ( this->type == mount_type_physical_path )
  {
    vostok::fs_new::native_path_string::native_path_string(result, &this->physical_path);
    return result;
  }
  else if ( this->submount_node && (this->submount_node->m_flags & 0x1000) == 0x1000 )
  {
    vostok::fs_new::native_path_string::native_path_string(&out_result);
    v3 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->fat_physical_path);
    vostok::fs_new::get_path_without_last_item<vostok::fs_new::native_path_string>(&out_result, v3);
    external_subfat = vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(this->submount_node);
    vostok::fs_new::path_string_impl::path_string_impl(&v7, 92, &external_subfat->relative_path_to_external);
    append_result = vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>(
                      &out_result,
                      (vostok::fs_new::native_path_string *)&v7);
    survarium::weapon_user_dead_state::finalize(v4);
    if ( *v5 )
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)append_result);
    vostok::fs_new::native_path_string::native_path_string(result, &out_result);
    return result;
  }
  else
  {
    vostok::fs_new::native_path_string::native_path_string(result, &this->fat_physical_path);
    return result;
  }
}
