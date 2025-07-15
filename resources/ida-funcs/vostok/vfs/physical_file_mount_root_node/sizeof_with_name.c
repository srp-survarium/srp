unsigned int __thiscall vostok::vfs::physical_file_mount_root_node<1>::sizeof_with_name(
        vostok::vfs::physical_file_mount_root_node<1> *this)
{
  return strlen(this->physical_path.pointer) + strlen(this->file.base.m_name) + strlen(this->virtual_path.pointer) + 171;
}
