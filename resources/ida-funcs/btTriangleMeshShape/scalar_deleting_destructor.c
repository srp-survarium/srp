btTriangleMeshShape *__thiscall btTriangleMeshShape::`scalar deleting destructor'(btTriangleMeshShape *this, char a2)
{
  this->__vftable = (btTriangleMeshShape_vtbl *)&btCollisionShape::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
