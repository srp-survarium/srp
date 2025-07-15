vostok::input::platform::gamepad *__thiscall vostok::input::platform::gamepad::`scalar deleting destructor'(
        vostok::input::platform::gamepad *this,
        char a2)
{
  this->__vftable = (vostok::input::platform::gamepad_vtbl *)&vostok::input::platform::gamepad::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
