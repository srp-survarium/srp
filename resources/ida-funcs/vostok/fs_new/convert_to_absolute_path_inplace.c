char __cdecl vostok::fs_new::convert_to_absolute_path_inplace(
        vostok::fs_new::native_path_string *in_out_path,
        assert_on_fail_bool assert_on_fail)
{
  vostok::fs_new::native_path_string absolute_path; // [esp+1Ch] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&absolute_path);
  if ( !vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
          (vostok::fixed_string<32> *)&absolute_path,
          in_out_path,
          assert_on_fail) )
    return 0;
  if ( in_out_path != &absolute_path )
    vostok::buffer_string::operator=(
      (vostok::fixed_string<32> *)&absolute_path,
      (vostok::fixed_string<32> *)in_out_path);
  vostok::fs_new::path_string_impl::verify_self(in_out_path);
  return 1;
}
