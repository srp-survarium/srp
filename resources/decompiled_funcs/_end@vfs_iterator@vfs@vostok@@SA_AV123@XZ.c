vostok::vfs::vfs_iterator *__cdecl vostok::vfs::vfs_iterator::end(vostok::vfs::vfs_iterator *result)
{
  vostok::vfs::vfs_iterator::vfs_iterator(result, 0, 0, 0, type_not_scanned);
  return result;
}
