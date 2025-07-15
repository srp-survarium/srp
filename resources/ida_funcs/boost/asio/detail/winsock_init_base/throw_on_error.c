void __cdecl boost::asio::detail::winsock_init_base::throw_on_error(boost::asio::detail::winsock_init_base::data *d)
{
  boost::system::error_code ec; // [esp+15Ch] [ebp-Ch] BYREF
  int result; // [esp+164h] [ebp-4h]

  result = InterlockedExchangeAdd(&d->result_, 0);
  if ( result )
  {
    ec.m_val = result;
    ec.m_cat = boost::system::system_category();
    if ( (result != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "winsock");
  }
}
