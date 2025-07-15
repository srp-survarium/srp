void __thiscall survarium::game::on_config_loaded(
        survarium::game *this,
        vostok::resources::queries_result *data,
        unsigned int create_renderer,
        int command_types_to_execute)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *m_result; // ecx
  bool has_passed_filters; // al
  survarium::game *v7; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp-Ch] [ebp-3Ch] BYREF
  unsigned int v9; // [esp-8h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-34h]
  int v11; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+10h] [ebp-20h] BYREF

  v11 = 0;
  m_result = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)data->m_result;
  if ( m_result == (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)1 )
  {
    v10 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)command_types_to_execute;
    v9 = create_renderer;
    v8.m_object = (vostok::resources::managed_resource *)1;
    vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[0], &v8);
    survarium::game::load_cc_script(
      v7,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)this,
      v8,
      v9,
      (int)v10);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          m_result = v10,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_result,
        &v12);
      v11 = 1;
      vostok::logging::append(
        &v12,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game.cpp",
        0x2F5u,
        "void __thiscall survarium::game::on_config_loaded(class vostok::resources::queries_result &,bool,unsigned int)",
        "game",
        error,
        "config file loading FAILED");
    }
    if ( (v11 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_result,
        (int *)&v12);
  }
}
