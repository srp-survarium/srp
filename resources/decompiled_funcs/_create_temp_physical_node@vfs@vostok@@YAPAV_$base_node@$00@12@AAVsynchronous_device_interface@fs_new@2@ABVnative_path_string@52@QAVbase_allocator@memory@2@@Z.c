vostok::vfs::base_node<1> *__cdecl vostok::vfs::create_temp_physical_node(
        vostok::fs_new::synchronous_device_interface *device,
        vostok::fs_new::native_path_string *physical_path,
        vostok::memory::base_allocator *const allocator)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  unsigned int v5; // eax
  boost::function<void __cdecl(vostok::vfs::mount_result)> v6; // [esp-2Ch] [ebp-6A0h] BYREF
  vostok::vfs::recursive_bool v7; // [esp-Ch] [ebp-680h]
  vostok::vfs::virtual_file_system *v8; // [esp-8h] [ebp-67Ch]
  vostok::fs_new::watcher_enabled_bool p_args; // [esp-4h] [ebp-678h]
  boost::function<void __cdecl(vostok::vfs::mount_result)> *v10; // [esp+6Ch] [ebp-608h]
  vostok::vfs::base_node<1> *v11; // [esp+70h] [ebp-604h]
  vostok::fs_new::path_string_impl v12; // [esp+74h] [ebp-600h] BYREF
  const char *file_name; // [esp+18Ch] [ebp-4E8h]
  vostok::vfs::physical_file_mount_root_node<1> *out_node; // [esp+190h] [ebp-4E4h]
  unsigned __int64 file_size; // [esp+194h] [ebp-4E0h] BYREF
  vostok::vfs::query_mount_arguments args; // [esp+19Ch] [ebp-4D8h] BYREF

  if ( physical_path->m_string.m_begin == physical_path->m_string.m_end )
    return 0;
  file_size = 0;
  if ( !vostok::fs_new::calculate_file_size(device, &file_size, physical_path, assert_on_fail_true) )
    return 0;
  vostok::fs_new::path_string_impl::path_string_impl(&v12, 47, (const char (*)[1])&buf);
  p_args = watcher_enabled_true;
  v8 = 0;
  v7 = recursive_false;
  v10 = &v6;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &v6);
  vostok::vfs::query_mount_arguments::mount_physical_path(
    &args,
    allocator,
    (const vostok::fs_new::virtual_path_string *)&v12,
    physical_path,
    (const char *)&buf,
    0,
    device,
    v6,
    v7,
    (vostok::vfs::lock_operation_enum)v8,
    p_args);
  file_name = (const char *)vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)physical_path);
  p_args = (vostok::fs_new::watcher_enabled_bool)&args;
  v8 = 0;
  v5 = vostok::strings::length(file_name);
  out_node = vostok::vfs::mount_root_node_functions::create<vostok::vfs::physical_file_mount_root_node,1>(
               file_name,
               v5,
               v8,
               (vostok::vfs::query_mount_arguments *)p_args);
  v11 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_file_mount_root_node,1>(out_node);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&args.callback);
  return v11;
}
