void __thiscall boost::asio::detail::win_iocp_io_service::stop(boost::asio::detail::win_iocp_io_service *this)
{
  boost::system::error_code ec; // [esp+160h] [ebp-Ch] BYREF
  unsigned int last_error; // [esp+168h] [ebp-4h]

  if ( !InterlockedExchange(&this->stopped_, 1) && !PostQueuedCompletionStatus(this->iocp_.handle, 0, 0, 0) )
  {
    last_error = GetLastError();
    ec.m_val = last_error;
    ec.m_cat = boost::system::system_category();
    if ( (last_error != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "pqcs");
  }
}
