btDynamicsWorld *__thiscall btDynamicsWorld::`vector deleting destructor'(btDynamicsWorld *this, char a2)
{
  this->__vftable = (btDynamicsWorld_vtbl *)&btDynamicsWorld::`vftable';
  btCollisionWorld::~btCollisionWorld(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
