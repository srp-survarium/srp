void __cdecl vostok::vfs::erase_from_mount_history(
        vostok::vfs::vfs_mount *item,
        vostok::vfs::virtual_file_system *file_system)
{
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::erase(
    &file_system->mount_history,
    item);
}
