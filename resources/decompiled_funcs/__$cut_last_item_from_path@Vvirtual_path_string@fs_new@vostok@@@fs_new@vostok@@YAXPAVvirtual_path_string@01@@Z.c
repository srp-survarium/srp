void __cdecl vostok::fs_new::cut_last_item_from_path<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *in_out_result)
{
  unsigned int last_slash_pos; // [esp+8h] [ebp-4h]

  last_slash_pos = vostok::fs_new::path_string_impl::rfind(in_out_result, 47);
  if ( last_slash_pos == -1 )
    vostok::fs_new::path_string_impl::set_length(in_out_result, 0);
  else
    vostok::fs_new::path_string_impl::set_length(in_out_result, last_slash_pos);
}
