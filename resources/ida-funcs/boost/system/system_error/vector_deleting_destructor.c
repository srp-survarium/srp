boost::system::system_error *__thiscall boost::system::system_error::`vector deleting destructor'(
        boost::system::system_error *this,
        char a2)
{
  boost::system::system_error::~system_error(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
