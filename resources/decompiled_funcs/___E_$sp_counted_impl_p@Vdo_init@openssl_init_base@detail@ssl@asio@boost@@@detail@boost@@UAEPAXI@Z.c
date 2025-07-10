boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > > *__thiscall boost::detail::sp_counted_impl_p<boost::asio::ssl::detail::openssl_init_base::do_init>::`vector deleting destructor'(
        boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > > *this,
        char a2)
{
  this->__vftable = (boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > >_vtbl *)&boost::detail::sp_counted_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
