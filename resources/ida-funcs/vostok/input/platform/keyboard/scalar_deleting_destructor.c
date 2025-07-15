vostok::input::platform::keyboard *__thiscall vostok::input::platform::keyboard::`scalar deleting destructor'(
        vostok::input::platform::keyboard *this,
        char a2)
{
  vostok::input::platform::keyboard::~keyboard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
