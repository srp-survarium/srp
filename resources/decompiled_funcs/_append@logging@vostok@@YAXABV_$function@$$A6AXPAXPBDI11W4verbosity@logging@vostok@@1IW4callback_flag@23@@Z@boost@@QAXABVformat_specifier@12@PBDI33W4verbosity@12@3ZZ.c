void vostok::logging::append(
        const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *log_callback,
        void *const user_data,
        vostok::logging::format_specifier *format_specifier,
        const char *file,
        unsigned int line,
        const char *function_signature,
        const char *initiator,
        vostok::logging::verbosity verbosity,
        char *format,
        ...)
{
  survarium::game_camera *v9; // ecx
  vostok::logging::logger v10; // [esp+103Ch] [ebp-474h] BYREF
  char *args; // [esp+1284h] [ebp-22Ch]
  vostok::logging::log_format v12; // [esp+1288h] [ebp-228h] BYREF
  va_list va; // [esp+14DCh] [ebp+2Ch] BYREF

  va_start(va, format);
  vostok::logging::log_format::set(&v12, format_specifier);
  va_copy(args, va);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10);
  survarium::weapon_user_dead_state::finalize(v9);
  v10.m_log_callback = log_callback;
  v10.m_log_format_ptr = &v12;
  v10.m_user_data = user_data;
  v10.m_initiator = initiator;
  v10.m_file = file;
  v10.m_function_signature = function_signature;
  v10.m_line = line;
  v10.m_verbosity = verbosity;
  if ( &v12 )
    qmemcpy(&v10, v10.m_log_format_ptr, 0x228u);
  else
    vostok::logging::log_format::set(&v10.m_log_format, &vostok::logging::format_message);
  vostok::logging::logger::operator()(&v10, format, args);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v10);
}
