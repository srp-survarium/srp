vostok::journaling::keyboard *__thiscall vostok::journaling::keyboard::`vector deleting destructor'(
        vostok::journaling::keyboard *this,
        char a2)
{
  this->__vftable = (vostok::journaling::keyboard_vtbl *)&vostok::journaling::keyboard::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
