void __userpurge vostok::network::login_client_impl::close_connection(
        vostok::network::login_client_impl *this@<ecx>,
        int a2@<edi>,
        bool stop_ping_timer)
{
  boost::asio::ssl::detail::stream_core *v3; // ecx
  const boost::system::error_category *v4; // eax
  bool v5; // zf
  boost::system::error_code ec; // [esp+8h] [ebp-10h] BYREF
  boost::system::error_code what; // [esp+10h] [ebp-8h] BYREF

  if ( stop_ping_timer )
    boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::cancel(
      (boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *)this,
      a2 + 312);
  boost::asio::ssl::detail::stream_core::~stream_core((boost::asio::ssl::detail::stream_core *)this, a2 + 96, a2);
  if ( a2 != -88 )
    boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>(
      (boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > &> *)(a2 + 88),
      (boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *)a2,
      v3,
      (boost::asio::ssl::context *)(a2 + 68));
  ec.m_val = 0;
  v4 = boost::system::system_category();
  v5 = *(_DWORD *)(a2 + 4) == -1;
  ec.m_cat = v4;
  if ( !v5 )
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::shutdown(
      (boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *)a2,
      &ec,
      &what.m_val);
  boost::asio::detail::win_iocp_socket_service_base::close(
    (boost::asio::detail::win_iocp_socket_service_base *)(*(_DWORD *)a2 + 20),
    (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)(a2 + 4),
    &what,
    &ec);
  *(_DWORD *)(a2 + 360) = 0;
}
