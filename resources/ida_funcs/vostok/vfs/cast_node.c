vostok::vfs::base_node<1> *__cdecl vostok::vfs::cast_node<1>(vostok::vfs::physical_file_mount_root_node<1> *node)
{
  return &node->file.base;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::cast_node<1>(vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  return &node->folder.folder.base;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::cast_node<1>(vostok::vfs::hard_link_node<1> *node)
{
  return &node->base;
}
