btSingleRayCallback *__thiscall btSoftSingleRayCallback::`scalar deleting destructor'(
        btSingleRayCallback *this,
        char a2)
{
  this->__vftable = (btSingleRayCallback_vtbl *)&btBroadphaseAabbCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
