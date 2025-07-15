void __thiscall boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this)
{
  boost::asio::detail::win_iocp_socket_service_base::destroy(&this->service->service_impl_, &this->implementation);
  if ( this->implementation.cancel_token_.pn.pi_ )
    boost::detail::sp_counted_base::release(this->implementation.cancel_token_.pn.pi_);
}


void __thiscall boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
        boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *this)
{
  boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > *service; // [esp+1Ch] [ebp-20h]
  boost::system::error_code ec; // [esp+34h] [ebp-8h] BYREF

  service = this->service;
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::cancel(
    &service->service_impl_,
    &this->implementation,
    &ec);
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(&this->implementation.timer_data.op_queue_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->implementation);
}


void __thiscall boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *this)
{
  boost::shared_ptr<void>::reset(&this->implementation);
  if ( this->implementation.pn.pi_ )
    boost::detail::sp_counted_base::release(this->implementation.pn.pi_);
}
