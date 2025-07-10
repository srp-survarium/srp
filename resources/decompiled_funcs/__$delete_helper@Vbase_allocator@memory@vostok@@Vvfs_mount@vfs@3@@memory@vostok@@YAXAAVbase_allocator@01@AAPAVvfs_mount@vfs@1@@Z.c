void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
        vostok::memory::base_allocator *allocator,
        vostok::vfs::vfs_mount **pointer)
{
  vostok::vfs::vfs_mount *v2; // [esp+14h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::vfs::vfs_mount::~vfs_mount(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
