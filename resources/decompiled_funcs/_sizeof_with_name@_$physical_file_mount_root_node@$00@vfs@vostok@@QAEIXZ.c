unsigned int __thiscall vostok::vfs::physical_file_mount_root_node<1>::sizeof_with_name(
        vostok::vfs::physical_file_mount_root_node<1> *this)
{
  unsigned int v1; // esi
  unsigned int v2; // esi

  v1 = vostok::strings::length(this->virtual_path.pointer);
  v2 = v1 + vostok::strings::length(this->physical_path.pointer) + 169;
  return v2 + vostok::strings::length(this->file.base.m_name) + 2;
}
