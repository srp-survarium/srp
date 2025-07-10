vostok::network::response *__thiscall vostok::network::response::`scalar deleting destructor'(
        vostok::network::response *this,
        char a2)
{
  this->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
