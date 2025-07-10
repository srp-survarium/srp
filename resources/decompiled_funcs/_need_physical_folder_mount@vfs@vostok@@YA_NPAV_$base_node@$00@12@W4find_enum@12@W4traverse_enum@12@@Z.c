bool __cdecl vostok::vfs::need_physical_folder_mount(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::traverse_enum traverse_type)
{
  bool v4; // [esp+3h] [ebp-21h]
  _DWORD v5[6]; // [esp+4h] [ebp-20h] BYREF
  bool need_recursive; // [esp+1Fh] [ebp-5h]
  vostok::vfs::physical_folder_node<1> *physical_folder; // [esp+20h] [ebp-4h]

  v4 = traverse_type && (find_flags & 1) != 0;
  need_recursive = v4;
  physical_folder = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
  if ( !physical_folder )
    return 0;
  v5[4] = v5;
  v5[0] = (need_recursive ? 2 : 0) | 1;
  v5[1] = v5[0];
  v5[2] = &physical_folder->m_folder_flags;
  v5[3] = v5[0];
  return (v5[0] & physical_folder->m_folder_flags.m_flags) != v5[0];
}
