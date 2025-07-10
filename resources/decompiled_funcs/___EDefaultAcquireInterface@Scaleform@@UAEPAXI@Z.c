Scaleform::DefaultAcquireInterface *__thiscall Scaleform::DefaultAcquireInterface::`vector deleting destructor'(
        Scaleform::DefaultAcquireInterface *this,
        char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `vector destructor iterator'(
      (char *)this,
      4u,
      (int)this[-1].__vftable,
      (void (__thiscall *)(void *))Scaleform::DefaultAcquireInterface::~DefaultAcquireInterface);
    if ( (a2 & 1) != 0 )
      operator delete(&this[-1]);
    return this - 1;
  }
  else
  {
    this->__vftable = (Scaleform::DefaultAcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
    if ( (a2 & 1) != 0 )
      operator delete(this);
    return this;
  }
}
