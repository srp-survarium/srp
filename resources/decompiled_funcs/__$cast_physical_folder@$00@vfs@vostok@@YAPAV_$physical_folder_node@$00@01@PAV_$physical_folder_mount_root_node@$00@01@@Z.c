vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::cast_physical_folder<1>(
        vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  return &node->folder;
}
