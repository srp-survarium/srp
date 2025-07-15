vostok::journaling::gamepad *__thiscall vostok::journaling::gamepad::`scalar deleting destructor'(
        vostok::journaling::gamepad *this,
        char a2)
{
  this->__vftable = (vostok::journaling::gamepad_vtbl *)&vostok::journaling::gamepad::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
