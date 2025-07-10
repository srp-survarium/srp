btCollisionDispatcher *__thiscall btCollisionDispatcher::`scalar deleting destructor'(
        btCollisionDispatcher *this,
        char a2)
{
  btCollisionDispatcher::~btCollisionDispatcher(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
