void __thiscall vostok::network_core::async_connector::on_connected(
        vostok::network_core::async_connector *this,
        boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *error_code,
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> iterator)
{
  int v4; // ecx
  bool has_passed_filters; // al
  int v6; // ecx
  bool v7; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  char v10; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+10h] [ebp-20h] BYREF

  v4 = -(error_code->vtable != 0);
  v10 = 0;
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
  {
    this->m_connection_state = host_name_is_unresolved;
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"network_core",
                                 (const char *)4),
          v4 = (int)v8,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4,
        &v11);
      v10 = 1;
      vostok::logging::append(
        &v11,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\async_connector.cpp",
        0x1Cu,
        "void __thiscall vostok::network_core::async_connector::on_connected(const class boost::system::error_code &,clas"
        "s boost::asio::ip::basic_resolver_iterator<class boost::asio::ip::tcp>)",
        "network_core",
        info,
        "async_connector::on_connected error occured, reset state to unresolved");
    }
    if ( (v10 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v11);
    v6 = -(this->m_on_error.vtable != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v6) != 0 )
      boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
        error_code,
        &this->m_on_error.vtable,
        (vostok::resources::query_result *)3,
        (const vostok::resources::memory_usage_type *)error_code->vtable,
        (vostok::resources::class_id_enum)(&error_code->vtable)[1]);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v7 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"network_core", (const char *)4),
          v4 = (int)v9,
          v7) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4,
        &v11);
      v10 = 2;
      vostok::logging::append(
        &v11,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\async_connector.cpp",
        0x22u,
        "void __thiscall vostok::network_core::async_connector::on_connected(const class boost::system::error_code &,clas"
        "s boost::asio::ip::basic_resolver_iterator<class boost::asio::ip::tcp>)",
        "network_core",
        info,
        "connection_has_been_established!");
    }
    if ( (v10 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v11);
    v6 = -(this->m_on_connected.vtable != 0);
    this->m_connection_state = connection_has_been_established;
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v6) != 0 )
      boost::function0<void>::operator()((boost::function0<bool> *)v6, &this->m_on_connected.vtable);
  }
  boost::detail::shared_count::~shared_count(
    (boost::detail::shared_count *)v6,
    (volatile signed __int32 **)&iterator.values_.pn);
}
