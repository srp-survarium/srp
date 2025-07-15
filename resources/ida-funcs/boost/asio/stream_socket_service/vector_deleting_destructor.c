boost::asio::stream_socket_service<boost::asio::ip::tcp> *__thiscall boost::asio::stream_socket_service<boost::asio::ip::tcp>::`vector deleting destructor'(
        boost::asio::stream_socket_service<boost::asio::ip::tcp> *this,
        char a2)
{
  DeleteCriticalSection(&this->service_impl_.mutex_.crit_section_);
  this->__vftable = (boost::asio::stream_socket_service<boost::asio::ip::tcp>_vtbl *)&boost::asio::io_service::service::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
