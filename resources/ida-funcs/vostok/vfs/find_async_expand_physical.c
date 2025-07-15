void __cdecl vostok::vfs::find_async_expand_physical(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> *node_parent,
        vostok::sound::sound_debug_stats *async_data,
        vostok::vfs::recursive_bool recursive,
        unsigned int increment)
{
  BOOL v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > v6; // [esp-10h] [ebp-7E4h]
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+4h] [ebp-7D0h]
  boost::function1<void,vostok::vfs::mount_result> v8; // [esp+1Ch] [ebp-7B8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1> > > f; // [esp+3Ch] [ebp-798h]
  boost::function1<void,vostok::vfs::mount_result> v10; // [esp+64h] [ebp-770h] BYREF
  vostok::fs_new::device_file_system_interface *v11; // [esp+88h] [ebp-74Ch]
  vostok::fs_new::watcher_enabled_bool watcher_enabled; // [esp+8Ch] [ebp-748h]
  vostok::fs_new::device_file_system_interface *v13; // [esp+90h] [ebp-744h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > v14; // [esp+98h] [ebp-73Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+A4h] [ebp-730h] BYREF
  char v16; // [esp+AEh] [ebp-726h]
  char v17; // [esp+AFh] [ebp-725h]
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+B0h] [ebp-724h]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+B4h] [ebp-720h] BYREF
  vostok::fs_new::synchronous_device_interface sync_device; // [esp+1D0h] [ebp-604h] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+1DCh] [ebp-5F8h] BYREF
  vostok::fs_new::device_file_system_no_watcher_proxy device_proxy; // [esp+2F8h] [ebp-4DCh]
  vostok::vfs::query_mount_arguments args; // [esp+2FCh] [ebp-4D8h] BYREF

  v5 = (node->m_flags & 1) == 1;
  if ( (node->m_flags & 1) == 1 )
    v17 = 0;
  else
    v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
  if ( (node->m_flags & 8) == 8 )
    pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
  else
    pointer = node->m_mount_root.pointer;
  mount_root = pointer;
  vostok::fs_new::virtual_path_string::virtual_path_string(&virtual_path);
  vostok::vfs::base_node<1>::get_full_path(node, (vostok::fs_new::native_path_string *)&virtual_path);
  vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(&physical_path, node);
  watcher_enabled = pointer->watcher_enabled;
  v13 = pointer->device.pointer;
  device_proxy.m_device_file_system = v13;
  v11 = v13;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v13);
  sync_device.m_synchronize_query = 0;
  sync_device.m_device.m_device_file_system = v13;
  sync_device.m_out_of_memory = 0;
  vostok::vfs::query_mount_arguments::query_mount_arguments(&args);
  args.allocator = pointer->allocator.pointer;
  if ( &args != (vostok::vfs::query_mount_arguments *)&virtual_path )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)&virtual_path, (vostok::fixed_string<32> *)&args);
  vostok::fs_new::path_string_impl::verify_self(&args.virtual_path);
  args.asynchronous_device = mount_root->async_device.pointer;
  args.synchronous_device = mount_root->device.pointer != 0 ? &sync_device : 0;
  if ( (node->m_flags & 1) == 1 )
  {
    args.type = mount_type_physical_path;
    if ( &args.physical_path != &physical_path )
      vostok::buffer_string::operator=(
        (vostok::fixed_string<32> *)&physical_path,
        (vostok::fixed_string<32> *)&args.physical_path);
    vostok::fs_new::path_string_impl::verify_self(&args.physical_path);
    f = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::vfs::async_callbacks_data::on_lazy_mounted, async_data);
    boost::function1<void,vostok::vfs::mount_result>::function1<void,vostok::vfs::mount_result>(&v10, f, 0);
    boost::function1<unsigned int,char const *>::swap(
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v10,
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&args.callback);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v10);
  }
  else
  {
    args.type = mount_type_archive;
    if ( &args.fat_physical_path != &physical_path )
      vostok::buffer_string::operator=(
        (vostok::fixed_string<32> *)&physical_path,
        (vostok::fixed_string<32> *)&args.fat_physical_path);
    vostok::fs_new::path_string_impl::verify_self(&args.fat_physical_path);
    v6 = *boost::bind<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int,vostok::vfs::async_callbacks_data *,boost::arg<1>,unsigned int>(
            &v14,
            vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted,
            (vostok::vfs::async_callbacks_data *)async_data,
            1_24,
            increment);
    boost::function1<void,vostok::vfs::mount_result>::function1<void,vostok::vfs::mount_result>(&v8, v6, 0);
    boost::function1<unsigned int,char const *>::swap(
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v8,
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&args.callback);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v8);
  }
  args.recursive = recursive;
  args.submount_node = node;
  args.submount_type = (node->m_flags & 1) == 1 ? submount_type_lazy : submount_type_automatic_archive;
  args.parent_of_submount_node = node_parent;
  args.root_write_lock = (vostok::vfs::base_node<1> *)async_data[2].m_statistic[0];
  args.unlock_after_mount = 0;
  vostok::vfs::virtual_file_system::query_mount((vostok::vfs::virtual_file_system *)async_data[2].m_ui_world, &args);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&args.callback);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
}
