char __thiscall vostok::vfs::vfs_hashset::find_and_lock_branch(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_branch,
        const char *path,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  unsigned int hash; // [esp+8h] [ebp-8h]
  unsigned int path_length; // [esp+Ch] [ebp-4h]

  path_length = vostok::strings::length(path);
  hash = vostok::fs_new::path_crc32(path, path_length, 0);
  return vostok::vfs::vfs_hashset::find_and_lock_branch(this, out_locked_branch, path, hash, lock_type, lock_operation);
}
