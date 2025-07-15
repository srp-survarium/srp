vostok::resources::cook_base *__thiscall vostok::resources::resources_manager::unregister_cook(
        vostok::buffer_vector<vostok::resources::cook_base *> *this)
{
  int v1; // esi
  int v2; // ebx
  bool has_passed_filters; // al
  int v5; // [esp-8h] [ebp-40h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v6; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-28h] BYREF
  vostok::resources::cook_base *value; // [esp+30h] [ebp-8h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  v9 = 0;
  if ( s_cooks_registry.m_begin == s_cooks_registry.m_end )
  {
    value = 0;
    v1 = 518;
    do
    {
      vostok::buffer_vector<vostok::resources::cook_base *>::push_back(this, &value);
      --v1;
    }
    while ( v1 );
  }
  v2 = *((_DWORD *)s_cooks_registry.m_begin + 12);
  if ( v2 && *(_DWORD *)(v2 + 4) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802D94,
                                 (const char *)3),
          this = v6,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &log_callback);
      v5 = *(_DWORD *)(v2 + 4);
      v9 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_manager_cook.cpp",
        0x6Eu,
        "class vostok::resources::cook_base *__cdecl vostok::resources::resources_manager::unregister_cook(enum vostok::r"
        "esources::class_id_enum)",
        (char *)&stru_802D94,
        warning,
        "There are [%d] leaked resource(s). (classid = [%d])",
        v5,
        12);
    }
    if ( (v9 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&log_callback);
  }
  *((_DWORD *)s_cooks_registry.m_begin + 12) = 0;
  return (vostok::resources::cook_base *)v2;
}
