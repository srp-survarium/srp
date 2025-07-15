const char *__thiscall vostok::vfs::vfs_mount::get_virtual_path(vostok::vfs::vfs_mount *this)
{
  return this->m_mount_root->virtual_path.pointer;
}
