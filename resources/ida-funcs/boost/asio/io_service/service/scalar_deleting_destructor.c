boost::asio::io_service::service *__thiscall boost::asio::io_service::service::`scalar deleting destructor'(
        boost::asio::io_service::service *this,
        char a2)
{
  this->__vftable = (boost::asio::io_service::service_vtbl *)&boost::asio::io_service::service::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
