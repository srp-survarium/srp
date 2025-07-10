void __thiscall boost::asio::detail::scoped_ptr<boost::asio::io_service>::~scoped_ptr<boost::asio::io_service>(
        boost::asio::detail::scoped_ptr<boost::asio::io_service> *this)
{
  boost::asio::io_service *p; // [esp+28h] [ebp-4h]

  p = this->p_;
  if ( this->p_ )
  {
    boost::asio::io_service::~io_service(p);
    operator delete(p);
  }
}
