btCollisionWorld::RayResultCallback *__thiscall btCollisionWorld::RayResultCallback::`scalar deleting destructor'(
        btCollisionWorld::RayResultCallback *this,
        char a2)
{
  this->__vftable = (btCollisionWorld::RayResultCallback_vtbl *)&btCollisionWorld::RayResultCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
