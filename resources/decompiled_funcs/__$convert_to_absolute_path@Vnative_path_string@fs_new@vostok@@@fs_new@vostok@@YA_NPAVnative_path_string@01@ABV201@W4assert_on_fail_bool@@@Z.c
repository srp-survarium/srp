char __cdecl vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
        vostok::fixed_string<32> *out_result,
        vostok::fs_new::native_path_string *relative_path,
        assert_on_fail_bool assert_on_fail)
{
  survarium::game_camera *v3; // ecx
  vostok::fixed_string<32> *v4; // eax
  survarium::game_camera *v6; // ecx
  vostok::fixed_string<32> *current_directory; // [esp+4h] [ebp-138h]
  vostok::fs_new::native_path_string v8; // [esp+24h] [ebp-118h] BYREF
  char v9; // [esp+13Bh] [ebp-1h]

  v9 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( vostok::fs_new::is_absolute_path<vostok::fs_new::native_path_string>(relative_path) )
  {
    vostok::fs_new::native_path_string::native_path_string(&v8, relative_path);
    if ( out_result != v4 )
      vostok::buffer_string::operator=(v4, out_result);
    vostok::fs_new::path_string_impl::verify_self((vostok::fs_new::path_string_impl *)out_result);
    return 1;
  }
  else
  {
    current_directory = (vostok::fixed_string<32> *)vostok::fs_new::get_current_directory();
    if ( out_result != current_directory )
      vostok::buffer_string::operator=(current_directory, out_result);
    vostok::fs_new::path_string_impl::verify_self((vostok::fs_new::path_string_impl *)out_result);
    if ( vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>(
           (vostok::fs_new::native_path_string *)out_result,
           relative_path) )
    {
      return 1;
    }
    else
    {
      if ( assert_on_fail )
        survarium::weapon_user_dead_state::finalize(v6);
      return 0;
    }
  }
}
