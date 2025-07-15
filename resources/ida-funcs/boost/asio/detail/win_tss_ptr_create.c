unsigned int __cdecl boost::asio::detail::win_tss_ptr_create()
{
  boost::system::error_code ec; // [esp+15Ch] [ebp-10h] BYREF
  unsigned int last_error; // [esp+164h] [ebp-8h]
  unsigned int tss_key; // [esp+168h] [ebp-4h]

  tss_key = TlsAlloc();
  if ( tss_key == -1 )
  {
    last_error = GetLastError();
    ec.m_val = last_error;
    ec.m_cat = boost::system::system_category();
    if ( (last_error != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "tss");
  }
  return tss_key;
}
