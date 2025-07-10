vostok::fs_new::physical_path_info *__usercall vostok::resources::get_physical_path_info@<eax>(
        const vostok::fs_new::native_path_string *path@<eax>,
        vostok::fs_new::physical_path_info *a2@<esi>)
{
  vostok::animation::mixing::animation_interval *v2; // eax
  vostok::fs_new::device_file_system_proxy_base *v3; // eax

  v2 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->((vostok::fs_new::synchronous_device_interface *)((char *)&loc_205EB + (unsigned int)vostok::resources::g_resources_manager.m_variable + 1));
  v3 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v2);
  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(v3, a2, path);
  return a2;
}
