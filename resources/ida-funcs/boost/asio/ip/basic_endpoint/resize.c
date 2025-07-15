void __thiscall boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>::resize(
        boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *this,
        unsigned int new_size)
{
  boost::system::error_code err; // [esp+168h] [ebp-8h] BYREF

  if ( new_size > 0x80 )
  {
    err.m_val = 10022;
    err.m_cat = boost::system::system_category();
    if ( boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>> )
      boost::asio::detail::do_throw_error(&err);
  }
}
