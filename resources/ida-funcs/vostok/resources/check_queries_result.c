bool __cdecl vostok::resources::check_queries_result(vostok::resources::queries_result *data)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v1; // ecx
  volatile int m_result; // eax
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool v5; // al
  const char *requested_path; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-5Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-5Ch]
  vostok::resources::class_id_enum m_class_id; // [esp-4h] [ebp-5Ch]
  int v11; // [esp+Ch] [ebp-4Ch]
  vostok::resources::query_result *m_queries; // [esp+10h] [ebp-48h]
  unsigned int v13; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v15; // [esp+38h] [ebp-20h] BYREF

  m_result = data->m_result;
  v11 = 0;
  if ( m_result != 1 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802D94,
                                 (const char *)2),
          v1 = v8,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v1,
        &log_callback);
      v11 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_queries_result.cpp",
        0x133u,
        "bool __cdecl vostok::resources::check_queries_result(class vostok::resources::queries_result &)",
        (char *)&stru_802D94,
        error,
        "!!! Resources creation failed for:");
    }
    if ( (v11 & 1) != 0 )
    {
      v11 &= ~1u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v1,
        (int *)&log_callback);
    }
    v13 = 0;
    if ( data->m_size )
    {
      m_queries = data->m_queries;
      do
      {
        if ( !vostok::resources::query_result_for_user::is_successful(
                (vostok::resources::query_result_for_user *)v1,
                (int)m_queries) )
        {
          if ( !vostok::core::g_log_filter_tree
            || (v5 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_802D94, (const char *)2),
                v4 = v9,
                v5) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v4,
              &v15);
            m_class_id = m_queries->m_class_id;
            v11 |= 2u;
            requested_path = vostok::resources::query_result_for_user::get_requested_path(m_queries);
            vostok::logging::append(
              &v15,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\resources_queries_result.cpp",
              0x137u,
              "bool __cdecl vostok::resources::check_queries_result(class vostok::resources::queries_result &)",
              (char *)&stru_802D94,
              error,
              "%s : %d",
              requested_path,
              m_class_id);
          }
          if ( (v11 & 2) != 0 )
          {
            v11 &= ~2u;
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
              (int *)&v15);
          }
        }
        v1 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)++v13;
        ++m_queries;
      }
      while ( v13 < data->m_size );
    }
    LOBYTE(m_result) = 0;
  }
  return m_result;
}
