void __thiscall vostok::network_core::udp_match_client::handle_receive(
        vostok::network_core::udp_match_client *this,
        const boost::system::error_code *error_code,
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *bytes_transferred)
{
  survarium::game_camera *v3; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **unacknowledged_packets_count; // [esp+8h] [ebp-D8h]
  char v8; // [esp+4Ch] [ebp-94h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > v9; // [esp+50h] [ebp-90h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+78h] [ebp-68h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+98h] [ebp-48h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v12; // [esp+BCh] [ebp-24h] BYREF
  char v13; // [esp+D7h] [ebp-9h]
  vostok::network_core::packet_reader reader; // [esp+D8h] [ebp-8h] BYREF

  v8 = 0;
  vostok::network_core::udp_match_client::check_consistency(this);
  v13 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this;
  this->m_is_receiving = 0;
  if ( (error_code->m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v4);
      v8 = 3;
      error_code->m_cat->message(error_code->m_cat, &v12, error_code->m_val);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[40],
        0x61u,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[452],
        "network_core:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[412],
        v12._M_start_of_storage._M_data);
    }
    if ( (v8 & 2) != 0 )
    {
      v8 &= ~2u;
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v12);
    }
    if ( (v8 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v4,
        (int *)&log_callback);
    vostok::network_core::udp_match_client::on_error(this, unable_to_read_from_socket, *error_code);
  }
  else if ( bytes_transferred )
  {
    if ( boost::asio::ip::detail::operator==(&this->m_server_endpoint.impl_, &this->m_remote_endpoint.impl_) )
    {
      if ( this->m_network_flow_emulator )
      {
        unacknowledged_packets_count = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                         v5,
                                         (int)&this->m_connection.m_unacknowledged_packets);
        vostok::network_core::udp_network_flow_emulator::on_packet_received(
          this->m_network_flow_emulator,
          this->m_receive_buffer.elems,
          bytes_transferred,
          &this->m_remote_endpoint,
          this->m_time_in_ms,
          (unsigned int)unacknowledged_packets_count);
      }
      else
      {
        v9._M_impl._M_start = (const void **)&this->m_receive_buffer;
        v9._M_impl._M_finish = (const void **)&bytes_transferred->_M_impl._M_start;
        reader.m_packet = (const vostok::network_core::base_packet *)&v9;
        reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                      &v9,
                                                      (int)&v9);
        vostok::network_core::udp_match_client::process_incoming_packet(this, &reader, &this->m_remote_endpoint);
      }
      vostok::network_core::udp_match_client::check_consistency(this);
      if ( this->m_connection.m_state != disconnected )
        vostok::network_core::udp_match_client::start_receiving(this);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5);
        v8 = 8;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v9._M_impl._M_end_of_storage,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          &stru_984D24.m_working_macro_list.m_buffer[1].m_store[40],
          0x6Du,
          &stru_984D24.m_working_macro_list.m_buffer[0].m_store[452],
          "network_core:",
          error,
          &stru_984D24.m_working_macro_list.m_buffer[1].m_store[96]);
      }
      if ( (v8 & 8) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
          (int *)&v9._M_impl._M_end_of_storage);
      vostok::network_core::udp_match_client::on_error(this, unable_to_read_from_socket, *error_code);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v4);
      v8 = 4;
      vostok::logging::append(
        &v10,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[40],
        0x67u,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[452],
        "network_core:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[64]);
    }
    if ( (v8 & 4) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v4,
        (int *)&v10);
    vostok::network_core::udp_match_client::on_error(this, unable_to_read_from_socket, *error_code);
  }
}
