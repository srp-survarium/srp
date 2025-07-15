void __thiscall vostok::vfs::query_notification_operation::query_hot_unmount(
        vostok::vfs::query_notification_operation *this)
{
  vostok::vfs::base_node<1> *v1; // eax
  survarium::game_camera *v2; // ecx
  vostok::vfs::mount_result v3[2]; // [esp-8h] [ebp-820h] BYREF
  vostok::vfs::query_notification_operation *thisa; // [esp+8h] [ebp-810h]
  vostok::vfs::unmounter v5; // [esp+14h] [ebp-804h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v6; // [esp+13Ch] [ebp-6DCh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // [esp+140h] [ebp-6D8h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v8; // [esp+144h] [ebp-6D4h] BYREF
  bool m_out_of_memory; // [esp+14Bh] [ebp-6CDh]
  vostok::platform_pointer_selector<vostok::memory::base_allocator,1>::helper *p_allocator; // [esp+14Ch] [ebp-6CCh]
  vostok::platform_pointer_selector<vostok::fs_new::device_file_system_interface,1>::helper *p_device; // [esp+150h] [ebp-6C8h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v12; // [esp+26Ch] [ebp-5ACh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v13; // [esp+270h] [ebp-5A8h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+274h] [ebp-5A4h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v15; // [esp+314h] [ebp-504h] BYREF
  int v16; // [esp+318h] [ebp-500h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v17; // [esp+324h] [ebp-4F4h] BYREF
  int v18; // [esp+328h] [ebp-4F0h]
  vostok::fs_new::synchronous_device_interface sync_device; // [esp+334h] [ebp-4E4h] BYREF
  vostok::vfs::query_mount_arguments args; // [esp+340h] [ebp-4D8h] BYREF

  thisa = this;
  if ( vostok::vfs::query_notification_operation::try_convert_to_virtual_path(this, this->m_physical_path) )
  {
    if ( vostok::vfs::query_notification_operation::find_node_on_virtual_path(thisa) )
    {
      p_device = &thisa->m_mount_root->device;
      p_allocator = &thisa->m_mount_root->allocator;
      vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        &sync_device,
        thisa->m_mount_root->async_device.pointer,
        p_allocator->pointer,
        p_device->pointer,
        thisa->m_mount_root->watcher_enabled);
      m_out_of_memory = sync_device.m_out_of_memory;
      if ( sync_device.m_out_of_memory )
      {
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v8,
          0);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v15,
          &v8);
        v16 = 3;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v8);
        v6 = &v15;
        v7 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v3;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v3[0].mount,
          &v15);
        v7[1].m_object = v6[1].m_object;
        boost::function1<void,vostok::vfs::mount_result>::operator()(
          &thisa->m_callback->boost::function1<void,vostok::vfs::mount_result>,
          v3[0]);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v15);
        vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
      }
      else if ( vostok::vfs::query_notification_operation::try_write_lock(thisa) )
      {
        vostok::vfs::query_mount_arguments::query_mount_arguments(&args);
        v3[0].result = (vostok::vfs::result_enum)thisa->m_physical_path;
        v3[0].mount.m_object = (vostok::vfs::vfs_mount *)5;
        v1 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(thisa->m_mount_root);
        vostok::vfs::query_notification_operation::fill_mount_arguments(
          thisa,
          &args,
          &sync_device,
          v1,
          submount_type_hot_unmount,
          (const vostok::fs_new::native_path_string *)v3[0].result);
        vostok::vfs::unmounter::unmounter(&v5, &args, thisa->m_file_system);
        survarium::weapon_user_dead_state::finalize(v2);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&args.callback);
        vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
      }
      else
      {
        vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
      }
    }
    else
    {
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &other,
        0);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v17,
        &other);
      v18 = 1;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
      v12 = &v17;
      v13 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v3;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v3[0].mount,
        &v17);
      v13[1].m_object = v12[1].m_object;
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        &thisa->m_callback->boost::function1<void,vostok::vfs::mount_result>,
        v3[0]);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v17);
    }
  }
}
