unsigned int __thiscall boost::asio::io_service::poll(boost::asio::io_service *this)
{
  boost::system::error_code ec; // [esp+2BCh] [ebp-Ch] BYREF
  unsigned int s; // [esp+2C4h] [ebp-4h]

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  s = boost::asio::detail::win_iocp_io_service::poll(this->impl_, &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec);
  return s;
}
