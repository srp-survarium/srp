void __thiscall vostok::logging::log_file::flush(vostok::logging::log_file *this, char *in_file_name)
{
  const char *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  unsigned __int64 size; // [esp+140h] [ebp-1130h]
  vostok::fs_new::open_file_cache path[15]; // [esp+148h] [ebp-1128h] BYREF
  bool v11; // [esp+1267h] [ebp-9h]
  vostok::fs_new::file_type_pointer v12; // [esp+1268h] [ebp-8h] BYREF

  if ( this->m_file )
  {
    vostok::fs_new::device_file_system_proxy_base::flush(&this->m_device.m_device, this->m_file);
    if ( in_file_name )
    {
      v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_file_name);
      if ( vostok::strings::compare_insensitive(v2, in_file_name) )
      {
        v11 = vostok::fs_new::device_file_system_proxy_base::seek(
                &this->m_device.m_device,
                this->m_file,
                0,
                seek_file_begin);
        survarium::weapon_user_dead_state::finalize(v3);
        if ( *v4 )
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v4);
        vostok::fs_new::native_path_string::convert(in_file_name, &path[0].name);
        vostok::fs_new::create_folder_r(&this->m_device, &path[0].name, 0);
        survarium::weapon_user_dead_state::finalize(v5);
        v12.device = &this->m_device;
        vostok::fs_new::open_cached_file(
          &this->m_device,
          &v12.file,
          path,
          create_always,
          write,
          assert_on_fail_false,
          notify_watcher_false,
          use_buffering_true);
        if ( v12.file )
        {
          while ( 1 )
          {
            size = vostok::fs_new::device_file_system_proxy_base::read(
                     &this->m_device.m_device,
                     this->m_file,
                     &path[0].mode,
                     0x1000u);
            if ( size != 4096 )
              break;
            vostok::fs_new::device_file_system_no_watcher_proxy::write(
              &this->m_device.m_device,
              v12.file,
              &path[0].mode,
              0x1000u);
          }
          vostok::fs_new::device_file_system_no_watcher_proxy::write(
            &this->m_device.m_device,
            v12.file,
            &path[0].mode,
            size);
          vostok::fs_new::file_type_pointer::close(&v12);
          survarium::weapon_user_dead_state::finalize(v7);
        }
        else
        {
          vostok::fs_new::file_type_pointer::close(&v12);
          survarium::weapon_user_dead_state::finalize(v6);
        }
      }
    }
  }
}
