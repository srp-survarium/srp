boost::asio::detail::win_iocp_io_service *__thiscall boost::asio::detail::win_iocp_io_service::`vector deleting destructor'(
        boost::asio::detail::win_iocp_io_service *this,
        char a2)
{
  boost::asio::detail::win_iocp_io_service::~win_iocp_io_service(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
