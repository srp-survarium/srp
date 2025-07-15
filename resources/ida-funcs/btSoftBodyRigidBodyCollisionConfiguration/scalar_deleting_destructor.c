btSoftBodyRigidBodyCollisionConfiguration *__thiscall btSoftBodyRigidBodyCollisionConfiguration::`scalar deleting destructor'(
        btSoftBodyRigidBodyCollisionConfiguration *this,
        char a2)
{
  btSoftBodyRigidBodyCollisionConfiguration::~btSoftBodyRigidBodyCollisionConfiguration(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
