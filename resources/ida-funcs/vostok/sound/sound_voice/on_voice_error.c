void __thiscall vostok::sound::sound_voice::on_voice_error(
        vostok::sound::sound_voice *this,
        void *buffer_context,
        HRESULT error)
{
  bool has_passed_filters; // al
  vostok::sound::sound_voice *v4; // [esp-4h] [ebp-34h]
  char v5; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v5 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                               (const char *)2),
        this = v4,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &log_callback);
    v5 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_voice_callbacks.cpp",
      0x39u,
      "void __thiscall vostok::sound::sound_voice::on_voice_error(void *,long)",
      (char *)&initiator_raw.filter_stack.m_last,
      error,
      "OnVoiceError: %d, %x",
      error,
      buffer_context);
  }
  if ( (v5 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&log_callback);
}
