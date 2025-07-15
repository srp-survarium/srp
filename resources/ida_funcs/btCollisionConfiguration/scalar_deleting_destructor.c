btCollisionConfiguration *__thiscall btCollisionConfiguration::`scalar deleting destructor'(
        btCollisionConfiguration *this,
        char a2)
{
  this->__vftable = (btCollisionConfiguration_vtbl *)&btCollisionConfiguration::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
