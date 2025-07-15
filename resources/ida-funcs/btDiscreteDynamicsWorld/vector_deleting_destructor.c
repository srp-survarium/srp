btDiscreteDynamicsWorld *__thiscall btDiscreteDynamicsWorld::`vector deleting destructor'(
        btDiscreteDynamicsWorld *this,
        char a2)
{
  btDiscreteDynamicsWorld::~btDiscreteDynamicsWorld(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
