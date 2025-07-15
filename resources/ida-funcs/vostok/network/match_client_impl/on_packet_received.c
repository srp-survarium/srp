void __thiscall vostok::network::match_client_impl::on_packet_received(
        vostok::network::match_client_impl *this,
        unsigned __int8 message_type,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reader)
{
  vostok::network::match_client_impl *v3; // edi
  boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum> *v4; // ecx
  bool has_passed_filters; // al
  int v6; // ecx
  vostok::network::match_client_impl *v7; // [esp-4h] [ebp-3Ch]
  char v8; // [esp+10h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+18h] [ebp-20h] BYREF

  v3 = this;
  v8 = 0;
  if ( message_type == 80 )
  {
    *(_DWORD *)((char *)&loc_6EF80 + (_DWORD)this) = 2;
    boost::function<void __cdecl (void)>::operator=(
      (boost::function<void __cdecl(void)> *)((char *)&loc_6EF60 + (_DWORD)this),
      (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&loc_55F88 + (_DWORD)this));
    if ( *(_DWORD *)&v3->m_packets_storage.elems[0][(_DWORD)&loc_6EF3F + 1] )
      boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum>::operator()(
        v4,
        &v3->m_packets_storage.elems[0][(_DWORD)&loc_6EF3F + 1],
        successfully_connected,
        successfully_handshaked,
        host_cannot_be_resolved,
        (vostok::lobby::server::messages_enum)48);
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)v4,
      (char *)&loc_6EF60 + (_DWORD)v3,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)0x50,
      reader);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack,
                                 (const char *)2),
          this = v7,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v9);
      v8 = 1;
      vostok::logging::append(
        &v9,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\match_client_impl.cpp",
        0x3Bu,
        "void __thiscall vostok::network::match_client_impl::on_packet_received(unsigned char,class vostok::network_core:"
        ":buffer_reader &)",
        &initiator_raw.filter_stack.gap0,
        error,
        "connection forbidden [%d]",
        message_type);
    }
    if ( (v8 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v9);
    v6 = -(*(_DWORD *)&v3->m_packets_storage.elems[0][(_DWORD)&loc_6EF3F + 1] != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v6) != 0 )
      boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login::server::messages_enum>::operator()(
        (boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby::server::messages_enum> *)v6,
        &v3->m_packets_storage.elems[0][(_DWORD)&loc_6EF3F + 1],
        successfully_connected,
        successfully_handshaked,
        host_cannot_be_resolved,
        query_client_status|0x10);
  }
}
