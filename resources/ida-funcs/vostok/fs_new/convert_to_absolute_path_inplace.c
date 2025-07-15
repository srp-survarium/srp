char __usercall vostok::fs_new::convert_to_absolute_path_inplace@<al>(
        vostok::fs_new::native_path_string *in_out_path@<eax>,
        char *a2@<esi>)
{
  vostok::fs_new::native_path_string v4; // [esp+8h] [ebp-120h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&v4);
  if ( !vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
          in_out_path,
          a2,
          &v4,
          assert_on_fail_true) )
    return 0;
  if ( in_out_path != &v4 )
    vostok::buffer_string::operator=(&v4.m_string, &in_out_path->m_string);
  return 1;
}
