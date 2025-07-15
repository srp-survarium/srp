survarium::game_action_descr *__thiscall survarium::key_binder::action_name_to_ptr(
        survarium::key_binder *this,
        char *_name)
{
  unsigned int v2; // esi
  int v3; // edi
  int v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  char v10; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  v10 = 0;
  v3 = 0;
  do
  {
    v4 = _stricmp(_name, (char *)actions_[v2].action_name);
    v5 = v8;
    if ( !v4 )
      return &actions_[v3];
    ++v2;
    ++v3;
  }
  while ( v2 < 54 );
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)4),
        v5 = v9,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v5,
      &v11);
    v10 = 1;
    vostok::logging::append(
      &v11,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\key_binder.cpp",
      0x137u,
      "struct survarium::game_action_descr *__thiscall survarium::key_binder::action_name_to_ptr(const char *)",
      "game",
      info,
      "! cant find corresponding [id] for action_name",
      _name);
  }
  if ( (v10 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
      (int *)&v11);
  return 0;
}
