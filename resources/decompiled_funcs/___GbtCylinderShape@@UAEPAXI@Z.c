btCapsuleShape *__thiscall btCylinderShape::`scalar deleting destructor'(btCapsuleShape *this, char a2)
{
  this->__vftable = (btCapsuleShape_vtbl *)&btCollisionShape::`vftable';
  if ( (a2 & 1) != 0 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
