btCollisionWorld::ClosestRayResultCallback *__thiscall btCollisionWorld::RayResultCallback::`scalar deleting destructor'(
        btCollisionWorld::ClosestRayResultCallback *this,
        char a2)
{
  this->__vftable = (btCollisionWorld::ClosestRayResultCallback_vtbl *)&btCollisionWorld::RayResultCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
