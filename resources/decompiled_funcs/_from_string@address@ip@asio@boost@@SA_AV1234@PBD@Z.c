boost::asio::ip::address *__cdecl boost::asio::ip::address::from_string(boost::asio::ip::address *result, char *str)
{
  boost::asio::ip::address addr; // [esp+1F0h] [ebp-24h] BYREF
  boost::system::error_code ec; // [esp+20Ch] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::ip::address::from_string(&addr, str, &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec);
  *result = addr;
  return result;
}
