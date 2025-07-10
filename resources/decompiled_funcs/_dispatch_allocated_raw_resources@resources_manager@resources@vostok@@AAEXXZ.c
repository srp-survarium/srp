void __usercall vostok::resources::resources_manager::dispatch_allocated_raw_resources(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<edi>)
{
  vostok::vfs::vfs_iterator *v2; // ebx
  vostok::vfs::vfs_iterator *v3; // esi
  vostok::vfs::vfs_hashset *m_hashset; // ebx
  vostok::resources::query_result *v5; // ecx
  vostok::resources::device_manager *capable_device_manager; // eax
  vostok::vfs::vfs_iterator v7; // [esp+8h] [ebp-10h] BYREF

  if ( *(int *)((char *)&dword_203A4 + a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)dword_20388 + a2));
    v2 = *(vostok::vfs::vfs_iterator **)((char *)&dword_203A4 + a2);
    *(int *)((char *)&dword_203A4 + a2) = 0;
    *(int *)((char *)&dword_203A8 + a2) = 0;
    *(int *)((char *)dword_20380 + a2) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)dword_20388 + a2));
    v3 = v2;
    if ( v2 )
    {
      do
      {
        m_hashset = v3[38].m_hashset;
        vostok::vfs::vfs_iterator::vfs_iterator(&v7, v3 + 10);
        capable_device_manager = vostok::resources::query_result::find_capable_device_manager(v5, v3);
        capable_device_manager->push_query_impl(capable_device_manager, (vostok::resources::query_result *)v3);
        SetEvent(*(HANDLE *)((char *)&dword_203D0 + a2));
        v3 = (vostok::vfs::vfs_iterator *)m_hashset;
      }
      while ( m_hashset );
    }
  }
}
