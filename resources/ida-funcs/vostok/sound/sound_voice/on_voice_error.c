void __thiscall vostok::sound::sound_voice::on_voice_error(
        vostok::sound::sound_voice *this,
        void *buffer_context,
        HRESULT error)
{
  char v3; // [esp+1Ch] [ebp-24h]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v4; // [esp+20h] [ebp-20h] BYREF

  v3 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
  {
    v4.vtable = 0;
    boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      &v4,
      vostok::core::g_log_callback);
    v3 = 1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v4,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_voice_callbacks.cpp",
      0x5Cu,
      "void __thiscall vostok::sound::sound_voice::on_voice_error(void *,long)",
      "sound:",
      error,
      "OnVoiceError: %d, %x",
      error,
      buffer_context);
  }
  if ( (v3 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v4);
}
