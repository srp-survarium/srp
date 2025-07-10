Scaleform::RefCountImplCore *__thiscall Scaleform::RefCountImplCore::`vector deleting destructor'(
        Scaleform::RefCountImplCore *this,
        char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `vector destructor iterator'(
      (char *)this,
      8u,
      this[-1].RefCount,
      (void (__thiscall *)(void *))Scaleform::RefCountImplCore::~RefCountImplCore);
    if ( (a2 & 1) != 0 )
      operator delete((void *)&this[-1].RefCount);
    return (Scaleform::RefCountImplCore *)((char *)this - 4);
  }
  else
  {
    Scaleform::RefCountImplCore::~RefCountImplCore(this);
    if ( (a2 & 1) != 0 )
      operator delete(this);
    return this;
  }
}
