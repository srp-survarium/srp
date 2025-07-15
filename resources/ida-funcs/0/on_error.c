void __usercall on_error(
        char *const message@<eax>,
        char *a2@<edi>,
        vostok::process_error_enum process_error,
        bool *do_debug_break_parameter)
{
  if ( s_debug_engine )
  {
    s_debug_engine->on_runtime_error(s_debug_engine);
    if ( s_debug_engine )
    {
      if ( s_debug_engine->terminate_on_error(s_debug_engine) && !vostok::debug::is_debugger_present() )
        vostok::debug::terminate((char *)uri);
    }
  }
  if ( process_error == process_error_true )
    vostok::debug::platform::on_error(a2, do_debug_break_parameter, message, 0x2000u, 0);
  else
    vostok::debug::platform::on_error_message_box(do_debug_break_parameter, message, a2, 0x2000u);
}
