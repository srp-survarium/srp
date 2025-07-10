btCollisionWorld *__thiscall btCollisionWorld::`scalar deleting destructor'(btCollisionWorld *this, char a2)
{
  btCollisionWorld::~btCollisionWorld(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
