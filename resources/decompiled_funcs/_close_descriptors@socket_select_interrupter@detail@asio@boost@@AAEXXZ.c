void __thiscall boost::asio::detail::socket_select_interrupter::close_descriptors(
        boost::asio::detail::socket_select_interrupter *this)
{
  unsigned __int8 state; // [esp+177h] [ebp-9h] BYREF
  boost::system::error_code ec; // [esp+178h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  state = 2;
  if ( this->read_descriptor_ != -1 )
    boost::asio::detail::socket_ops::close(this->read_descriptor_, &state, 1, &ec);
  if ( this->write_descriptor_ != -1 )
    boost::asio::detail::socket_ops::close(this->write_descriptor_, &state, 1, &ec);
}
