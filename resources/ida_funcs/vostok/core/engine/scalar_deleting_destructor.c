vostok::core::engine *__thiscall vostok::core::engine::`scalar deleting destructor'(
        vostok::core::engine *this,
        char a2)
{
  this->__vftable = (vostok::core::engine_vtbl *)&vostok::core::engine::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
