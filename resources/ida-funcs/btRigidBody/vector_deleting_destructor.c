btRigidBody *__thiscall btRigidBody::`vector deleting destructor'(btRigidBody *this, char a2)
{
  btRigidBody::~btRigidBody(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
