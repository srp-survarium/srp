boost::asio::ssl::detail::verify_callback_base *__thiscall boost::asio::ssl::detail::verify_callback_base::`scalar deleting destructor'(
        boost::asio::ssl::detail::verify_callback_base *this,
        char a2)
{
  this->__vftable = (boost::asio::ssl::detail::verify_callback_base_vtbl *)&boost::asio::ssl::detail::verify_callback_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
