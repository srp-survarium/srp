void __usercall on_error(
        unsigned int a1@<ebx>,
        vostok::process_error_enum process_error,
        bool *do_debug_break_parameter,
        char *const message,
        survarium::game_camera *message_size,
        bool *ignore_always_parameter)
{
  vostok::debug::engine *v6; // eax
  vostok::debug::engine *v7; // [esp+4h] [ebp-4h]

  if ( vostok::debug::debug_engine() )
  {
    v7 = vostok::debug::debug_engine();
    v7->flush_log_file(v7, 0);
  }
  if ( vostok::debug::debug_engine() )
  {
    v6 = vostok::debug::debug_engine();
    if ( ((unsigned __int8 (__thiscall *)(vostok::debug::engine *, vostok::debug::engine *))v6->terminate_on_error)(
           v6,
           v6) )
    {
      if ( !vostok::debug::is_debugger_present() )
        vostok::debug::terminate((char *)&buf);
    }
  }
  if ( process_error == process_error_true )
    vostok::debug::platform::on_error(
      message_size,
      a1,
      do_debug_break_parameter,
      message,
      message_size,
      ignore_always_parameter,
      0,
      error_type_assert);
  else
    vostok::debug::platform::on_error_message_box(
      do_debug_break_parameter,
      message,
      (unsigned int)message_size,
      ignore_always_parameter,
      0,
      0);
}
