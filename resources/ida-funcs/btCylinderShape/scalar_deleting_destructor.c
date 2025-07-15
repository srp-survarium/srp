btCylinderShape *__thiscall btCylinderShape::`scalar deleting destructor'(btCylinderShape *this, char a2)
{
  this->__vftable = (btCylinderShape_vtbl *)&btCollisionShape::`vftable';
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
