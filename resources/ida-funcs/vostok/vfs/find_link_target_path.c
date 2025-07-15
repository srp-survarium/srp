void __cdecl vostok::vfs::find_link_target_path<1>(vostok::fs_new::virtual_path_string *out_path)
{
  int v1; // ecx

  if ( (*(_WORD *)(v1 + 48) & 0x200) == 0x200 )
    vostok::vfs::base_node<1>::get_full_path(*(vostok::vfs::base_node<1> **)(v1 - 8), out_path);
  else
    vostok::vfs::soft_link_node<1>::absolute_path_to_referenced(
      (vostok::vfs::soft_link_node<1> *)v1,
      (char **)(v1 - 8),
      out_path);
}
