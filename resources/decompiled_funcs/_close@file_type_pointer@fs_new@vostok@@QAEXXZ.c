void __thiscall vostok::fs_new::file_type_pointer::close(vostok::fs_new::file_type_pointer *this)
{
  _BYTE *v1; // eax

  if ( this->file && !vostok::fs_new::g_use_open_file_cache )
  {
    survarium::weapon_user_dead_state::finalize(0);
    if ( *v1 )
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v1);
    vostok::fs_new::device_file_system_no_watcher_proxy::close(&this->device->m_device, this->file);
  }
  this->file = 0;
}
