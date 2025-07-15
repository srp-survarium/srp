void __cdecl vostok::vfs::helper_callback(
        const vostok::vfs::vfs_locked_iterator *iterator,
        vostok::vfs::result_enum result,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::vfs::result_enum *out_result,
        bool *callback_ready)
{
  vostok::vfs::vfs_locked_iterator *v5; // ecx

  vostok::vfs::vfs_locked_iterator::grab(out_iterator, iterator, v5);
  *out_result = result;
  *callback_ready = 1;
}
