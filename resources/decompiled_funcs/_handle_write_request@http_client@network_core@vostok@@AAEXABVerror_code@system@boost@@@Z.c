void __thiscall vostok::network_core::http_client::handle_write_request(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  survarium::game_options *v2; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *v3; // eax
  char v5; // [esp+13h] [ebp-21h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > delim; // [esp+14h] [ebp-20h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+2Ch] [ebp-8h] BYREF

  if ( err->m_val )
  {
    vostok::network_core::http_client::on_error(this, err);
  }
  else
  {
    v2 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v5);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &delim,
      "\r\n",
      (const stlp_std::allocator<char> *)v2);
    v3 = boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
           (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::http_client::handle_read_status_line,
           (vostok::sound::sound_debug_stats *)this);
    boost::asio::async_read_until<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>(
      &this->m_socket,
      &this->m_response_buff,
      &delim,
      (const boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > *)v3);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&delim);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v5);
  }
}
