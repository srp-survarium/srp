vostok::engine::console *__thiscall vostok::engine::console::`vector deleting destructor'(
        vostok::engine::console *this,
        char a2)
{
  this->__vftable = (vostok::engine::console_vtbl *)&vostok::engine::console::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
