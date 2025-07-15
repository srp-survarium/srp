btDispatcher *__thiscall btDispatcher::`scalar deleting destructor'(btDispatcher *this, char a2)
{
  this->__vftable = (btDispatcher_vtbl *)&btDispatcher::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
