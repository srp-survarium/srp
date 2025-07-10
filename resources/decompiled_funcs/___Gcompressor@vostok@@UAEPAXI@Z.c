vostok::compressor *__thiscall vostok::compressor::`scalar deleting destructor'(vostok::compressor *this, char a2)
{
  this->__vftable = (vostok::compressor_vtbl *)&vostok::compressor::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
