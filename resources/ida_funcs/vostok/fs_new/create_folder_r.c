bool __cdecl vostok::fs_new::create_folder_r(
        const vostok::fs_new::synchronous_device_interface *device,
        vostok::fs_new::native_path_string *path,
        bool create_last)
{
  survarium::game_camera *v4; // ecx
  vostok::render::skeleton_model_instance *v5; // eax
  int v6; // eax
  vostok::render::skeleton_model_instance *v7; // eax
  survarium::game_camera *v8; // ecx
  bool v9; // bl
  unsigned int v12; // [esp+128h] [ebp-3BCh]
  char s[2]; // [esp+136h] [ebp-3AEh] BYREF
  char *begin_src; // [esp+138h] [ebp-3ACh]
  char *end_src; // [esp+13Ch] [ebp-3A8h]
  char v16; // [esp+142h] [ebp-3A2h]
  char c; // [esp+143h] [ebp-3A1h]
  vostok::fs_new::native_path_string part; // [esp+144h] [ebp-3A0h] BYREF
  vostok::fs_new::path_part_iterator next_it; // [esp+260h] [ebp-284h] BYREF
  bool result; // [esp+27Bh] [ebp-269h]
  vostok::fs_new::native_path_string absolute_path; // [esp+27Ch] [ebp-268h] BYREF
  unsigned int colon_pos; // [esp+394h] [ebp-150h]
  unsigned int drive_part_length; // [esp+398h] [ebp-14Ch]
  vostok::fs_new::native_path_string cur_path; // [esp+39Ch] [ebp-148h] BYREF
  vostok::fs_new::path_part_iterator end_it; // [esp+4B4h] [ebp-30h] BYREF
  vostok::fs_new::path_part_iterator it; // [esp+4CCh] [ebp-18h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&absolute_path);
  if ( !vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
          (vostok::fixed_string<32> *)&absolute_path,
          path,
          assert_on_fail_true) )
    return 0;
  c = 58;
  colon_pos = vostok::buffer_string::find(&absolute_path.m_string, 0x3Au);
  v16 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  drive_part_length = colon_pos + 2;
  vostok::fs_new::native_path_string::native_path_string(&cur_path);
  v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&absolute_path);
  end_src = (char *)v5 + drive_part_length;
  begin_src = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&absolute_path);
  vostok::fs_new::path_string_impl::clear(&cur_path.m_string);
  vostok::buffer_string::append(&cur_path.m_string, begin_src, end_src);
  vostok::fs_new::path_string_impl::verify_self(&cur_path);
  v6 = vostok::fs_new::path_string_impl::length(&absolute_path);
  v12 = v6 - drive_part_length;
  v7 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&absolute_path);
  it.m_include_empty_string_in_iteration = include_empty_string_in_iteration_false;
  it.m_separator = 92;
  it.m_path_str = (char *)v7 + drive_part_length;
  it.m_path_end = (char *)v7 + drive_part_length + v12;
  it.m_cur_str = (char *)v7 + drive_part_length;
  it.m_cur_end = (char *)v7 + drive_part_length;
  vostok::fs_new::path_part_iterator::operator++(&it);
  vostok::fs_new::path_part_iterator::end(&end_it);
  s[1] = 0;
  survarium::weapon_user_dead_state::finalize(v8);
  result = 1;
  while ( it.m_include_empty_string_in_iteration != end_it.m_include_empty_string_in_iteration
       || it.m_cur_str != end_it.m_cur_str )
  {
    vostok::fs_new::native_path_string::native_path_string(&part);
    vostok::fs_new::path_part_iterator::append_to_string<vostok::fs_new::virtual_path_string>(
      &it,
      (vostok::fs_new::virtual_path_string *)&part);
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(&cur_path, &part.m_string);
    next_it = it;
    vostok::fs_new::path_part_iterator::operator++(&next_it);
    if ( !create_last
      && next_it.m_include_empty_string_in_iteration == end_it.m_include_empty_string_in_iteration
      && next_it.m_cur_str == end_it.m_cur_str )
    {
      return result;
    }
    v9 = result;
    result = vostok::fs_new::device_file_system_proxy_base::create_folder(&device->m_device, &cur_path) & v9;
    s[0] = 92;
    vostok::fs_new::path_string_impl::operator+=<char>(&cur_path, s);
    it = next_it;
  }
  return result;
}


bool __cdecl vostok::fs_new::create_folder_r(
        const vostok::fs_new::synchronous_device_interface *device,
        const char *path,
        bool create_last)
{
  vostok::fs_new::native_path_string *v3; // eax
  vostok::fs_new::path_string_impl v5; // [esp+140h] [ebp-114h] BYREF

  v3 = vostok::fs_new::native_path_string::convert(path, &v5);
  return vostok::fs_new::create_folder_r(device, v3, create_last);
}
