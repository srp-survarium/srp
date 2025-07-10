void __usercall vostok::threading::set_thread_name(char *log_string@<eax>)
{
  TlsSetValue(s_thread_logging_name_tls_key, log_string);
  vostok::debug::is_debugger_present();
}
