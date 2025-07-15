char __userpurge vostok::fs_new::device_file_system_no_watcher_proxy::open@<al>(
        vostok::fs_new::device_file_system_no_watcher_proxy *this@<esi>,
        const vostok::fs_new::native_path_string *physical_path@<eax>,
        void ***out_file,
        const vostok::fs_new::open_file_params *params)
{
  const vostok::fs_new::open_file_params *v4; // ebx
  vostok::fs_new::synchronous_device_interface *v6; // ecx
  char result; // al
  vostok::fs_new::device_file_system_interface *m_device_file_system; // ecx
  vostok::fs_new::native_path_string v9; // [esp+8h] [ebp-128h] BYREF
  vostok::fs_new::synchronous_device_interface device; // [esp+124h] [ebp-Ch] BYREF

  v4 = params;
  if ( params->mode == create_always )
  {
    device.m_device = (vostok::fs_new::device_file_system_no_watcher_proxy)this->m_device_file_system;
    device.m_synchronize_query = 0;
    device.m_out_of_memory = 0;
    vostok::fs_new::create_folder_r(&device, physical_path, 0);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v6, (int *)&device);
  }
  vostok::fs_new::native_path_string::native_path_string(&v9);
  result = vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
             physical_path,
             (char *)this,
             &v9,
             v4->assert_on_fail);
  if ( result )
  {
    m_device_file_system = this->m_device_file_system;
    params = 0;
    result = m_device_file_system->open(m_device_file_system, (void **const)&params, &v9, v4);
    *out_file = (void **)params;
  }
  return result;
}
