void __thiscall vostok::network_core::udp_match_client::enqueue(
        vostok::network_core::udp_match_client *this,
        vostok::network_core::udp_match_packet *packet)
{
  BOOL v2; // ecx
  char v4; // [esp+24h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-20h] BYREF

  v4 = 0;
  v2 = this->m_connection.m_state == connected;
  if ( v2 )
  {
    vostok::network_core::udp_match_connection::enqueue(&this->m_connection, packet);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v2);
      v4 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[40],
        0xACu,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[180],
        "network_core:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[116]);
    }
    if ( (v4 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
        (int *)&log_callback);
    vostok::network_core::delete_udp_match_packet(
      this->m_connection.m_packets_allocator,
      (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
  }
  vostok::network_core::udp_match_client::check_consistency(this);
}
