void __cdecl boost::asio::detail::throw_error(const boost::system::error_code *err)
{
  if ( (err->m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(err);
}
