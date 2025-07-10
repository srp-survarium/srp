void __thiscall Scaleform::GFx::MovieImpl::ShutdownTimers(Scaleform::GFx::MovieImpl *this)
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::ASIntervalTimerIntf *pObject; // ecx
  unsigned int v5; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327,Scaleform::ArrayDefaultPolicy> *p_IntervalTimers; // esi
  Scaleform::RefCountVImpl **v7; // edi
  unsigned int v8; // ebx

  Size = this->IntervalTimers.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    pObject = this->IntervalTimers.Data.Data[i].pObject;
    pObject->Clear(pObject);
  }
  v5 = this->IntervalTimers.Data.Size;
  p_IntervalTimers = &this->IntervalTimers;
  if ( !v5 )
  {
    if ( !this->IntervalTimers.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->IntervalTimers,
        &this->IntervalTimers,
        0);
    goto LABEL_14;
  }
  v7 = (Scaleform::RefCountVImpl **)&p_IntervalTimers->Data.Data[v5 - 1];
  v8 = v5;
  do
  {
    if ( *v7 )
      Scaleform::RefCountImpl::Release(*v7);
    --v7;
    --v8;
  }
  while ( v8 );
  if ( (p_IntervalTimers->Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_14:
    p_IntervalTimers->Data.Size = 0;
    return;
  }
  if ( p_IntervalTimers->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_IntervalTimers->Data.Data);
    p_IntervalTimers->Data.Data = 0;
  }
  p_IntervalTimers->Data.Policy.Capacity = 0;
  p_IntervalTimers->Data.Size = 0;
}
