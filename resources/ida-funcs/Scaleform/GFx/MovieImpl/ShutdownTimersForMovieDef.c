void __thiscall Scaleform::GFx::MovieImpl::ShutdownTimersForMovieDef(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *defimpl)
{
  unsigned int Size; // esi
  unsigned int v4; // ebp
  Scaleform::GFx::ASIntervalTimerIntf *pObject; // ecx
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *Data; // esi
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v8; // esi
  unsigned int i; // [esp+Ch] [ebp-4h]

  Size = this->IntervalTimers.Data.Size;
  v4 = 0;
  for ( i = Size; v4 < Size; ++v4 )
  {
    pObject = this->IntervalTimers.Data.Data[v4].pObject;
    if ( pObject->ClearFor(pObject, this, defimpl) )
    {
      Data = this->IntervalTimers.Data.Data;
      v7 = (Scaleform::RefCountVImpl *)Data[v4].pObject;
      v8 = &Data[v4];
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      v8->pObject = 0;
      Size = i;
    }
  }
}
