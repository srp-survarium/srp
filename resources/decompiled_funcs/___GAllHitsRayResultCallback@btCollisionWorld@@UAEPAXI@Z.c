btCollisionWorld::AllHitsRayResultCallback *__thiscall btCollisionWorld::AllHitsRayResultCallback::`scalar deleting destructor'(
        btCollisionWorld::AllHitsRayResultCallback *this,
        char a2)
{
  btCollisionWorld::AllHitsRayResultCallback::~AllHitsRayResultCallback(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
