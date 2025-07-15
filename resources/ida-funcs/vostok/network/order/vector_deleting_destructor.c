vostok::network::order *__thiscall vostok::network::order::`vector deleting destructor'(
        vostok::network::order *this,
        char a2)
{
  this->__vftable = (vostok::network::order_vtbl *)&vostok::network::order::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
