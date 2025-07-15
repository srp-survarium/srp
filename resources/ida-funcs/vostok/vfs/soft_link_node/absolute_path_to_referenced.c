void __userpurge vostok::vfs::soft_link_node<1>::absolute_path_to_referenced(
        vostok::vfs::soft_link_node<1> *this@<ecx>,
        char **a2@<eax>,
        vostok::fs_new::virtual_path_string *out_path)
{
  vostok::vfs::base_node<1> *v4; // ecx
  char *in_relative_path; // [esp+4h] [ebp-4h] BYREF

  if ( a2 )
    v4 = (vostok::vfs::base_node<1> *)(a2 + 2);
  else
    v4 = 0;
  vostok::vfs::base_node<1>::get_full_path(v4, out_path);
  in_relative_path = *a2;
  vostok::fs_new::append_relative_path<vostok::fs_new::virtual_path_string,char const *>(
    out_path,
    (const char ***)&in_relative_path);
}
