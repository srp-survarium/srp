void __cdecl vostok::vfs::add_to_mount_history(
        vostok::vfs::vfs_mount *new_item,
        vostok::vfs::virtual_file_system *file_system)
{
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::push_back(
    &file_system->mount_history,
    new_item,
    0);
}
