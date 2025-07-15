void __thiscall vostok::network_core::http_client::handle_read_content(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  vostok::network_core::http_client *v3; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::network_core::http_client *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > handler; // [esp+10h] [ebp-Ch] BYREF

  if ( !err->m_val )
  {
    if ( vostok::network_core::http_client::add_result_content(this, (int)this) )
    {
      handler.l_.a1_.t_ = this;
      handler.f_.f_ = vostok::network_core::http_client::handle_read_content;
      boost::asio::async_read<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::asio::detail::transfer_at_least_t,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>(
        &handler,
        &this->m_socket,
        &this->m_response_buff,
        (boost::asio::detail::transfer_at_least_t)1);
      return;
    }
    goto LABEL_9;
  }
  handler.l_.a1_.t_ = (vostok::network_core::http_client *)boost::asio::error::get_misc_category();
  handler.f_.f_ = (void (__thiscall *)(vostok::network_core::http_client *, const boost::system::error_code *))2;
  if ( boost::system::operator!=(err, (const boost::system::error_code *)&handler) )
  {
    vostok::network_core::http_client::on_error(err, v4, this);
    return;
  }
  if ( err->m_cat == boost::asio::error::get_misc_category() && err->m_val == 2 )
  {
    vostok::network_core::http_client::add_result_content(v5, (int)this);
LABEL_9:
    vostok::network_core::http_client::close_connection(v3, (int)this);
  }
}
