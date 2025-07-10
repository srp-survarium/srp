bool __thiscall vostok::fs_new::device_file_system_no_watcher_proxy::open(
        vostok::fs_new::device_file_system_no_watcher_proxy *this,
        void ***out_file,
        vostok::fs_new::native_path_string *physical_path,
        const vostok::fs_new::open_file_params *params)
{
  vostok::fs_new::device_file_system_interface *m_device_file_system; // [esp+10h] [ebp-130h]
  vostok::fs_new::synchronous_device_interface device; // [esp+14h] [ebp-12Ch] BYREF
  void *handle; // [esp+20h] [ebp-120h] BYREF
  bool open_result; // [esp+27h] [ebp-119h]
  vostok::fs_new::native_path_string absolute_native_path; // [esp+28h] [ebp-118h] BYREF

  if ( params->mode == create_always )
  {
    m_device_file_system = this->m_device_file_system;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    device.m_synchronize_query = 0;
    device.m_device.m_device_file_system = m_device_file_system;
    device.m_out_of_memory = 0;
    vostok::fs_new::create_folder_r(&device, physical_path, 0);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
  }
  vostok::fs_new::native_path_string::native_path_string(&absolute_native_path);
  if ( !vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
          (vostok::fixed_string<32> *)&absolute_native_path,
          physical_path,
          params->assert_on_fail) )
    return 0;
  handle = 0;
  open_result = this->m_device_file_system->open(this->m_device_file_system, &handle, &absolute_native_path, params);
  *out_file = (void **)handle;
  return open_result;
}
