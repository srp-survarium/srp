void __userpurge vostok::resources::resources_manager::push_to_device_manager(
        vostok::vfs::vfs_iterator *query@<esi>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::query_result *v2; // ecx
  vostok::resources::device_manager *capable_device_manager; // eax
  vostok::vfs::vfs_iterator fat_it; // [esp+0h] [ebp-10h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, query + 10);
  capable_device_manager = vostok::resources::query_result::find_capable_device_manager(v2, query);
  capable_device_manager->push_query_impl(capable_device_manager, (vostok::resources::query_result *)query);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
}
