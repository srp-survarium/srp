btCollisionObject *__thiscall btCollisionObject::`scalar deleting destructor'(btCollisionObject *this, char a2)
{
  this->__vftable = (btCollisionObject_vtbl *)&btCollisionObject::`vftable';
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
