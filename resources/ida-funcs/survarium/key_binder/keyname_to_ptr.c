survarium::keyboard_key_descr *__thiscall survarium::key_binder::keyname_to_ptr(
        survarium::key_binder *this,
        char *_name)
{
  int v2; // edi
  survarium::keyboard_key_descr *v3; // eax
  int v4; // eax
  bool has_passed_filters; // al
  survarium::key_binder *v7; // [esp-4h] [ebp-38h]
  survarium::key_binder *v8; // [esp-4h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+8h] [ebp-2Ch] BYREF
  int v10; // [esp+2Ch] [ebp-8h]

  v10 = 0;
  v2 = 0;
  if ( survarium::keyboards[0].key_name )
  {
    v3 = survarium::keyboards;
    while ( 1 )
    {
      v4 = _stricmp(_name, (char *)v3->key_name);
      this = v7;
      if ( !v4 )
        return &survarium::keyboards[v2];
      v3 = &survarium::keyboards[++v2];
      if ( !v3->key_name )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)4),
          this = v8,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v9);
      v10 = 1;
      vostok::logging::append(
        &v9,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\key_binder.cpp",
        0x164u,
        "struct survarium::keyboard_key_descr *__thiscall survarium::key_binder::keyname_to_ptr(const char *)",
        "game",
        info,
        "! cant find corresponding [keyboard_key_descr*] for keyname %s",
        _name);
    }
    if ( (v10 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v9);
    return 0;
  }
}
