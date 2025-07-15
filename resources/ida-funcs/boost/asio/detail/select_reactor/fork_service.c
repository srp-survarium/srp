void __thiscall boost::asio::detail::select_reactor::fork_service(
        boost::asio::detail::select_reactor *this,
        boost::asio::io_service::fork_event fork_ev)
{
  boost::asio::detail::socket_select_interrupter *p_interrupter; // esi
  boost::asio::detail::socket_select_interrupter *v3; // ecx

  if ( fork_ev == fork_child )
  {
    p_interrupter = &this->interrupter_;
    boost::asio::detail::socket_select_interrupter::close_descriptors(
      (boost::asio::detail::socket_select_interrupter *)this,
      &this->interrupter_.read_descriptor_);
    p_interrupter->write_descriptor_ = -1;
    p_interrupter->read_descriptor_ = -1;
    boost::asio::detail::socket_select_interrupter::open_descriptors(v3, &p_interrupter->read_descriptor_);
  }
}
