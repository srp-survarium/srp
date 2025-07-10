btBroadphaseInterface *__thiscall btBroadphaseInterface::`scalar deleting destructor'(
        btBroadphaseInterface *this,
        char a2)
{
  this->__vftable = (btBroadphaseInterface_vtbl *)&btBroadphaseInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
