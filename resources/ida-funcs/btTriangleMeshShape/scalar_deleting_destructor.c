btCollisionShape *__thiscall btTriangleMeshShape::`scalar deleting destructor'(btCollisionShape *this, char a2)
{
  this->__vftable = (btCollisionShape_vtbl *)&btCollisionShape::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
