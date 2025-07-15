vostok::input::platform::mouse *__thiscall vostok::input::platform::mouse::`vector deleting destructor'(
        vostok::input::platform::mouse *this,
        char a2)
{
  vostok::input::platform::mouse::~mouse(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
