void __usercall vostok::fs_new::physical_path_iterator::operator++(
        vostok::fs_new::physical_path_iterator *this@<ecx>,
        unsigned int a2@<ebx>)
{
  _BYTE *v2; // eax
  bool do_debug_break; // [esp+17h] [ebp-149h] BYREF
  unsigned __int64 saved_handle; // [esp+18h] [ebp-148h]
  vostok::fs_new::physical_path_initializer initializer; // [esp+20h] [ebp-140h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2 || debug_macro_helper_ignore_always_2 || this->device )
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(&initializer);
    saved_handle = this->search_handle;
    if ( !this->device->find_next(this->device, &this->search_handle, &this->data) )
    {
      ((void (__thiscall *)(vostok::fs_new::device_file_system_interface *, _DWORD, _DWORD))this->device->find_close)(
        this->device,
        saved_handle,
        HIDWORD(saved_handle));
      LODWORD(this->search_handle) = -1;
      HIDWORD(this->search_handle) = -1;
    }
  }
  else
  {
    if ( occurances_left_2 == -1 )
      occurances_left_2 = vostok::ui::ui_dialog::input_priority((survarium::game_world *)debug_macro_helper_ignore_always_2);
    if ( occurances_left_2-- )
    {
      if ( !debug_macro_helper_ignore_always_2 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          a2,
          &do_debug_break,
          process_error_false,
          &debug_macro_helper_ignore_always_2,
          assert_untyped,
          "assertion_failed",
          "device",
          ".\\physical_path_info_iterator.cpp",
          "vostok::fs_new::physical_path_iterator::operator ++",
          0x58u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}
