void __thiscall vostok::network_core::http_client::handle_read_content(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *v5; // [esp+24h] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > v6; // [esp+2Ch] [ebp-44h]
  boost::system::error_code ec; // [esp+34h] [ebp-3Ch] BYREF
  boost::asio::detail::read_streambuf_op<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> >,stlp_std::allocator<char>,boost::asio::detail::transfer_at_least_t,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > > v8; // [esp+3Ch] [ebp-34h] BYREF
  int v9; // [esp+54h] [ebp-1Ch]
  boost::asio::error::detail::misc_category *v10; // [esp+58h] [ebp-18h]
  int v11; // [esp+5Ch] [ebp-14h]
  boost::asio::error::detail::misc_category *misc_category; // [esp+60h] [ebp-10h]
  int v13; // [esp+64h] [ebp-Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+68h] [ebp-8h] BYREF

  if ( err->m_val )
  {
    v11 = 2;
    misc_category = boost::asio::error::get_misc_category();
    if ( err->m_cat == misc_category && err->m_val == v11 )
    {
      v9 = 2;
      v10 = boost::asio::error::get_misc_category();
      if ( err->m_cat == v10 && err->m_val == v9 )
      {
        vostok::network_core::http_client::add_result_content(this);
        vostok::network_core::http_client::close_connection(this);
      }
    }
    else
    {
      vostok::network_core::http_client::on_error(this, err);
    }
  }
  else if ( vostok::network_core::http_client::add_result_content(this) )
  {
    v13 = 1;
    v5 = boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
           (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::http_client::handle_read_content,
           (vostok::sound::sound_debug_stats *)this);
    ec.m_val = 0;
    ec.m_cat = boost::system::system_category();
    v6 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > *)v5;
    v8.completion_condition_.minimum_ = 1;
    v8.stream_ = &this->m_socket;
    v8.streambuf_ = &this->m_response_buff;
    v8.total_transferred_ = 0;
    v8.handler_ = v6;
    boost::asio::detail::read_streambuf_op<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::asio::detail::transfer_at_least_t,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>::operator()(
      &v8,
      &ec,
      0,
      1);
  }
  else
  {
    vostok::network_core::http_client::close_connection(this);
  }
}
