vostok::journaling::mouse *__thiscall vostok::journaling::mouse::`vector deleting destructor'(
        vostok::journaling::mouse *this,
        char a2)
{
  this->__vftable = (vostok::journaling::mouse_vtbl *)&vostok::journaling::mouse::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
