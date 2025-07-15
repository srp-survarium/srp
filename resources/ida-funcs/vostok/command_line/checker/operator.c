void __usercall vostok::command_line::checker::operator()(
        vostok::command_line::key *const key_name@<edi>,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *a2@<ecx>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-20h] BYREF

  if ( !key_name || LOBYTE(key_name->m_string_value.m_begin) != 46 )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      a2,
      &log_callback);
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\command_line.cpp",
      0x14Du,
      "void __thiscall vostok::command_line::checker::operator ()(class vostok::command_line::key *const ,const char *,const char *)",
      "core:",
      info,
      "\nkey with name '%s' is not registered, use -help to see list of available commands",
      (const char *)key_name);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v2,
      (int *)&log_callback);
    vostok::debug::terminate(
      "Command line argument '%s' has not been registered\n\nUse -help to see list of available commands",
      (const char *)key_name);
  }
}
