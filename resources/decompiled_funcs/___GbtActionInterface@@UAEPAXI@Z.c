btActionInterface *__thiscall btActionInterface::`scalar deleting destructor'(btActionInterface *this, char a2)
{
  this->__vftable = (btActionInterface_vtbl *)&btActionInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
