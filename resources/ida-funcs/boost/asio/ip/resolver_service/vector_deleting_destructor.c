boost::asio::ip::resolver_service<boost::asio::ip::tcp> *__thiscall boost::asio::ip::resolver_service<boost::asio::ip::tcp>::`vector deleting destructor'(
        boost::asio::ip::resolver_service<boost::asio::ip::tcp> *this,
        char a2)
{
  boost::asio::detail::resolver_service_base::~resolver_service_base(
    (boost::asio::detail::resolver_service_base *)this,
    (unsigned int)&this->service_impl_);
  this->__vftable = (boost::asio::ip::resolver_service<boost::asio::ip::tcp>_vtbl *)&boost::asio::io_service::service::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
