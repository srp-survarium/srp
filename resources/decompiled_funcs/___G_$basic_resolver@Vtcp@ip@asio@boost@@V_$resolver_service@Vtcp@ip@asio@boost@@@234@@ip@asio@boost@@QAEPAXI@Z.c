boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *__thiscall boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::`scalar deleting destructor'(
        boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *this,
        char a2)
{
  boost::shared_ptr<void>::reset(&this->implementation);
  if ( this->implementation.pn.pi_ )
    boost::detail::sp_counted_base::release(this->implementation.pn.pi_);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
