void __thiscall vostok::network_core::http_client::handle_write_request(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  stlp_std::allocator<char> v3; // [esp+Fh] [ebp-21h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > handler; // [esp+10h] [ebp-20h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > delim; // [esp+18h] [ebp-18h] BYREF

  if ( err->m_val )
  {
    vostok::network_core::http_client::on_error(
      err,
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      this);
  }
  else
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &delim,
      "\r\n",
      &v3);
    handler.l_.a1_.t_ = this;
    handler.f_.f_ = vostok::network_core::http_client::handle_read_status_line;
    boost::asio::async_read_until<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>(
      &handler,
      &this->m_socket,
      &this->m_response_buff,
      &delim);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&delim);
  }
}
