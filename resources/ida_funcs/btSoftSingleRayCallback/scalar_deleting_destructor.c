btSoftSingleRayCallback *__thiscall btSoftSingleRayCallback::`scalar deleting destructor'(
        btSoftSingleRayCallback *this,
        char a2)
{
  this->__vftable = (btSoftSingleRayCallback_vtbl *)&btBroadphaseAabbCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
