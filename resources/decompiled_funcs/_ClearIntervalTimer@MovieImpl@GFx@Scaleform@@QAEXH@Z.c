void __thiscall Scaleform::GFx::MovieImpl::ClearIntervalTimer(Scaleform::GFx::MovieImpl *this, int timerId)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::ASIntervalTimerIntf *pObject; // ecx
  Scaleform::GFx::ASIntervalTimerIntf *v6; // ecx

  Size = this->IntervalTimers.Data.Size;
  v4 = 0;
  if ( Size )
  {
    while ( 1 )
    {
      pObject = this->IntervalTimers.Data.Data[v4].pObject;
      if ( pObject )
      {
        if ( pObject->GetId(pObject) == timerId )
          break;
      }
      if ( ++v4 >= Size )
        return;
    }
    v6 = this->IntervalTimers.Data.Data[v4].pObject;
    v6->Clear(v6);
  }
}
