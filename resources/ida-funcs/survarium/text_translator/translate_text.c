void __userpurge survarium::text_translator::translate_text(
        survarium::text_translator *this@<ecx>,
        int a2@<eax>,
        char *text_id,
        char *translated_text)
{
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  unsigned int v9; // eax
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-3Ch]
  char *_Src; // [esp+10h] [ebp-28h]
  char v13; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+18h] [ebp-20h] BYREF

  v13 = 0;
  v5 = vostok::configs::binary_config_value::operator[](
         *(vostok::configs::binary_config_value **)(*(_DWORD *)a2 + 264),
         "strings");
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)v5, (unsigned int)text_id) )
  {
    v8 = vostok::configs::binary_config_value::operator[](
           *(vostok::configs::binary_config_value **)(*(_DWORD *)a2 + 264),
           "strings");
    _Src = (char *)vostok::configs::binary_config_value::operator[](v8, text_id)->data.pointer;
  }
  else
  {
    _Src = text_id;
  }
  v9 = strlen(_Src);
  if ( v9 >= 0x200 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          v7 = v11,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v7,
        &v14);
      v13 = 1;
      vostok::logging::append(
        &v14,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\text_translator.cpp",
        0x43u,
        "void __thiscall survarium::text_translator::translate_text(const char *,char [])",
        "game",
        error,
        "TEXT_TRANSLATOR: Too long localization string [%s]",
        text_id);
    }
    if ( (v13 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v14);
    v9 = 511;
  }
  strncpy_s(translated_text, 0x200u, _Src, v9);
}
