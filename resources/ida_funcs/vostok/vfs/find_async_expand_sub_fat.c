void __cdecl vostok::vfs::find_async_expand_sub_fat(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> *node_parent,
        vostok::vfs::async_callbacks_data *async_data,
        unsigned int increment)
{
  survarium::game_camera *v4; // ecx
  boost::function<void __cdecl(vostok::vfs::mount_result)> v5; // [esp-24h] [ebp-790h] BYREF
  vostok::vfs::lock_operation_enum v6; // [esp-4h] [ebp-770h]
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+0h] [ebp-76Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > v8; // [esp+Ch] [ebp-760h]
  boost::function1<void,vostok::vfs::mount_result> *v9; // [esp+18h] [ebp-754h]
  survarium::game_camera *v10; // [esp+1Ch] [ebp-750h]
  vostok::fs_new::watcher_enabled_bool watcher_enabled; // [esp+20h] [ebp-74Ch]
  survarium::game_camera *v12; // [esp+24h] [ebp-748h]
  vostok::vfs::mount_root_node_base<1> *v13; // [esp+30h] [ebp-73Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > result; // [esp+34h] [ebp-738h] BYREF
  char v15; // [esp+47h] [ebp-725h]
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+48h] [ebp-724h]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+4Ch] [ebp-720h] BYREF
  vostok::fs_new::synchronous_device_interface sync_device; // [esp+168h] [ebp-604h] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+174h] [ebp-5F8h] BYREF
  vostok::fs_new::device_file_system_no_watcher_proxy device_proxy; // [esp+290h] [ebp-4DCh]
  vostok::vfs::query_mount_arguments args; // [esp+294h] [ebp-4D8h] BYREF

  v15 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  if ( (node->m_flags & 8) == 8 )
  {
    pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
  }
  else
  {
    pointer = v13;
    pointer = node->m_mount_root.pointer;
  }
  mount_root = pointer;
  vostok::fs_new::virtual_path_string::virtual_path_string(&virtual_path);
  vostok::vfs::base_node<1>::get_full_path(node, (vostok::fs_new::native_path_string *)&virtual_path);
  vostok::fs_new::path_string_impl::path_string_impl(
    &physical_path,
    92,
    (const vostok::platform_pointer_selector<char,1>::helper *)&pointer->physical_path);
  watcher_enabled = pointer->watcher_enabled;
  v12 = (survarium::game_camera *)pointer->device.pointer;
  device_proxy.m_device_file_system = (vostok::fs_new::device_file_system_interface *)v12;
  v10 = v12;
  survarium::weapon_user_dead_state::finalize(v12);
  sync_device.m_synchronize_query = 0;
  sync_device.m_device.m_device_file_system = (vostok::fs_new::device_file_system_interface *)v12;
  sync_device.m_out_of_memory = 0;
  v6 = lock_operation_lock;
  v8 = *boost::bind<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int,vostok::vfs::async_callbacks_data *,boost::arg<1>,unsigned int>(
          &result,
          vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted,
          async_data,
          1_28,
          increment);
  v9 = &v5;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v8.l_.a1_.t_,
    &v5);
  boost::function1<void,vostok::vfs::mount_result>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int>>>>(
    v9,
    v8);
  vostok::vfs::query_mount_arguments::mount_archive(
    &args,
    mount_root->allocator.pointer,
    (vostok::vfs::query_mount_arguments *)&virtual_path,
    &physical_path,
    &physical_path,
    (vostok::fixed_string<16> *)&buf,
    mount_root->async_device.pointer,
    mount_root->device.pointer != 0 ? &sync_device : 0,
    v5,
    v6);
  args.submount_type = submount_type_subfat;
  args.submount_node = node;
  args.parent_of_submount_node = node_parent;
  args.root_write_lock = async_data->env.node;
  args.unlock_after_mount = 0;
  vostok::vfs::virtual_file_system::query_mount(async_data->env.file_system, &args);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&args.callback);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
}
