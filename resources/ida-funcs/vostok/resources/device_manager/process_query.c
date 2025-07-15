char __thiscall vostok::resources::device_manager::process_query(
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query,
        vostok::fs_new::synchronous_device_interface *device)
{
  char result; // al
  vostok::resources::device_manager *v4; // ecx
  const vostok::fs_new::synchronous_device_interface *v5; // [esp+0h] [ebp-10h]
  void **out_file; // [esp+Ch] [ebp-4h] BYREF

  out_file = 0;
  result = vostok::resources::device_manager::open_file(this, device, &out_file, query);
  if ( result )
  {
    if ( (query->m_flags & 2) != 0 )
      vostok::resources::device_manager::process_read_query(
        query,
        (vostok::resources::device_manager *)out_file,
        device,
        v5);
    else
      vostok::resources::device_manager::process_write_query(
        v4,
        (vostok::resources::device_manager *)out_file,
        query,
        device);
    device->m_device.m_device_file_system->close(device->m_device.m_device_file_system, out_file);
    return 1;
  }
  return result;
}
