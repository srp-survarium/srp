int *__thiscall Scaleform::RefCountNTSImplCore::`vector deleting destructor'(
        Scaleform::RefCountNTSImplCore *this,
        char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `vector destructor iterator'(
      (char *)this,
      8u,
      this[-1].RefCount,
      (void (__thiscall *)(void *))Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore);
    if ( (a2 & 1) != 0 )
      operator delete(&this[-1].RefCount);
    return &this[-1].RefCount;
  }
  else
  {
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
    if ( (a2 & 1) != 0 )
      operator delete(this);
    return (int *)this;
  }
}
