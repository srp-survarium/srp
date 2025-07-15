const char *__thiscall vostok::vfs::vfs_mount::get_descriptor(vostok::vfs::vfs_mount *this)
{
  return this->m_mount_root->descriptor.pointer;
}
