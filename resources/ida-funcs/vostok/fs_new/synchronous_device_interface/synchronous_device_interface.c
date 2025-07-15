void __userpurge vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        vostok::fs_new::synchronous_device_interface *this@<ecx>,
        int a2@<esi>,
        vostok::fs_new::asynchronous_device_query_vtbl *adi,
        vostok::memory::base_allocator *allocator)
{
  vostok::threading::event *v4; // ecx

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_BYTE *)(a2 + 8) = 0;
  vostok::fs_new::asynchronous_device_interface::get_synchronous_access(
    (vostok::fs_new::asynchronous_device_interface *)this,
    adi,
    (vostok::memory::base_allocator *)a2,
    allocator);
  if ( *(_DWORD *)a2 )
    vostok::threading::event::wait(v4, (HANDLE *)(*(_DWORD *)a2 + 40), 0xFFFFFFFF);
}
