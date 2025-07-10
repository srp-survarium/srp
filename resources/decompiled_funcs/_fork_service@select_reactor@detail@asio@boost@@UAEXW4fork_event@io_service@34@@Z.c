void __thiscall boost::asio::detail::select_reactor::fork_service(
        boost::asio::detail::select_reactor *this,
        boost::asio::io_service::fork_event fork_ev)
{
  if ( fork_ev == fork_child )
  {
    boost::asio::detail::socket_select_interrupter::close_descriptors(&this->interrupter_);
    this->interrupter_.write_descriptor_ = -1;
    this->interrupter_.read_descriptor_ = -1;
    boost::asio::detail::socket_select_interrupter::open_descriptors(&this->interrupter_);
  }
}
