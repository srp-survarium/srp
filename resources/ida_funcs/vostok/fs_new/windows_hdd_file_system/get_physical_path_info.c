vostok::fs_new::physical_path_info *__thiscall vostok::fs_new::windows_hdd_file_system::get_physical_path_info(
        vostok::fs_new::windows_hdd_file_system *this,
        vostok::fs_new::physical_path_info *result,
        vostok::fs_new::native_path_string *native_physical_path)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  const char *v6; // eax
  char *s; // [esp+20h] [ebp-298h] BYREF
  char v10; // [esp+27h] [ebp-291h]
  _stat32i64 local_stat; // [esp+28h] [ebp-290h] BYREF
  bool convert_result; // [esp+5Fh] [ebp-259h]
  vostok::fs_new::physical_path_initializer initializer; // [esp+60h] [ebp-258h] BYREF
  vostok::fs_new::native_path_string absolute_physical_path; // [esp+1A0h] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&absolute_physical_path);
  convert_result = vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
                     (vostok::fixed_string<32> *)&absolute_physical_path,
                     native_physical_path,
                     assert_on_fail_true);
  v10 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize(v4);
  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&absolute_physical_path);
  if ( _stat32i64(v6, &local_stat) == -1 )
  {
    vostok::fs_new::physical_path_info::physical_path_info(result);
  }
  else
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(&initializer);
    initializer.device = this;
    s = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&absolute_physical_path);
    vostok::fs_new::path_string_impl::operator=<char const *>(&initializer.data.path, &s);
    initializer.data.path_type = path_type_contains_full_path;
    initializer.parent = 0;
    initializer.data.type = ((local_stat.st_mode & 0x4000) != 0) + 1;
    initializer.data.file_size = local_stat.st_size;
    initializer.data.last_time_of_write = local_stat.st_mtime;
    vostok::fs_new::physical_path_info::physical_path_info(result, &initializer);
  }
  return result;
}
