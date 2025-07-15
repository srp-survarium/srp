void __thiscall Scaleform::RefCountImpl::Release(Scaleform::RefCountVImpl *this)
{
  if ( InterlockedExchangeAdd(&this->RefCount, -1) == 1 )
  {
    if ( this )
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, int))this->~Scaleform::RefCountVImpl)(this, 1);
  }
}
