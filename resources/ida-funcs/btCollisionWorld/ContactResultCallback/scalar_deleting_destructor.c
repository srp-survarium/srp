btCollisionWorld::ContactResultCallback *__thiscall btCollisionWorld::ContactResultCallback::`scalar deleting destructor'(
        btCollisionWorld::ContactResultCallback *this,
        char a2)
{
  this->__vftable = (btCollisionWorld::ContactResultCallback_vtbl *)&btCollisionWorld::ContactResultCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
