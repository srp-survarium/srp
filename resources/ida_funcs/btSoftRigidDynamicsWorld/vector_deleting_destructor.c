btSoftRigidDynamicsWorld *__thiscall btSoftRigidDynamicsWorld::`vector deleting destructor'(
        btSoftRigidDynamicsWorld *this,
        char a2)
{
  btSoftRigidDynamicsWorld::~btSoftRigidDynamicsWorld(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
