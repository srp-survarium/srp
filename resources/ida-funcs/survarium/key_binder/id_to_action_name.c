const char *__thiscall survarium::key_binder::id_to_action_name(
        survarium::key_binder *this,
        survarium::game_action_id _id)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  unsigned int i; // eax
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-34h]
  char v7; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v8; // [esp+10h] [ebp-20h] BYREF

  v7 = 0;
  v2 = 0;
  for ( i = 0; i < 54; ++i )
  {
    if ( _id == actions_[i].id )
      return actions_[(_DWORD)v2].action_name;
    v2 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v2 + 1);
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)4),
        v2 = v6,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v2,
      &v8);
    v7 = 1;
    vostok::logging::append(
      &v8,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\key_binder.cpp",
      0x122u,
      "const char *__thiscall survarium::key_binder::id_to_action_name(enum survarium::game_action_id) const",
      "game",
      info,
      "can't find corresponding [action_name] for id");
  }
  if ( (v7 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&v8);
  return 0;
}
