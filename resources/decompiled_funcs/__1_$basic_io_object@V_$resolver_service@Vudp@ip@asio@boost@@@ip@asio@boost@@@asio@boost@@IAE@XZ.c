void __thiscall boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *this)
{
  boost::shared_ptr<void>::reset(&this->implementation);
  if ( this->implementation.pn.pi_ )
    boost::detail::sp_counted_base::release(this->implementation.pn.pi_);
}
