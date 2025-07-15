bool __usercall vostok::vfs::need_physical_folder_mount@<al>(
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::traverse_enum traverse_type)
{
  bool v3; // bl
  vostok::vfs::physical_folder_node<1> *v4; // eax
  int v6; // ecx

  v3 = traverse_type && (find_flags & 1) != 0;
  v4 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
  if ( !v4 )
    return 0;
  v6 = (v3 ? 2 : 0) | 1;
  return (v6 & v4->m_folder_flags.m_flags) != v6;
}
