boost::asio::detail::select_reactor *__thiscall boost::asio::detail::select_reactor::`vector deleting destructor'(
        boost::asio::detail::select_reactor *this,
        char a2)
{
  boost::asio::detail::select_reactor::~select_reactor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
