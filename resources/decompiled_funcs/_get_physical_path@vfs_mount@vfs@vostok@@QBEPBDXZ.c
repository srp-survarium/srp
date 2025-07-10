const char *__thiscall vostok::vfs::vfs_mount::get_physical_path(vostok::vfs::vfs_mount *this)
{
  return this->m_mount_root->physical_path.pointer;
}
