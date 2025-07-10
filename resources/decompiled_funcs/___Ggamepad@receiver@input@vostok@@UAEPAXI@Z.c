vostok::input::receiver::gamepad *__thiscall vostok::input::receiver::gamepad::`scalar deleting destructor'(
        vostok::input::receiver::gamepad *this,
        char a2)
{
  this->__vftable = (vostok::input::receiver::gamepad_vtbl *)&vostok::input::receiver::gamepad::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
