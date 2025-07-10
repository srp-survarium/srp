Scaleform::Mutex_AreadyLockedAcquireInterface *__thiscall Scaleform::Mutex_AreadyLockedAcquireInterface::`scalar deleting destructor'(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this,
        char a2)
{
  this->__vftable = (Scaleform::Mutex_AreadyLockedAcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
