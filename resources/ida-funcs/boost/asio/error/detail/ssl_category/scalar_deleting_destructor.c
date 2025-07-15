boost::asio::error::detail::misc_category *__thiscall boost::asio::error::detail::ssl_category::`scalar deleting destructor'(
        boost::asio::error::detail::misc_category *this,
        char a2)
{
  this->__vftable = (boost::asio::error::detail::misc_category_vtbl *)&boost::system::error_category::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
