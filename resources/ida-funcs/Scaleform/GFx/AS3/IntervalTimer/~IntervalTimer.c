void __thiscall Scaleform::GFx::AS3::IntervalTimer::~IntervalTimer(Scaleform::GFx::AS3::IntervalTimer *this)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(this->Params.Data.Data, this->Params.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Params.Data.Data);
  pObject = this->TimerObj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TimerObj.pObject = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (this->Function.Flags & 0x1F) <= 9 )
    goto LABEL_12;
  if ( (this->Function.Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(&this->Function);
LABEL_12:
    this->__vftable = (Scaleform::GFx::AS3::IntervalTimer_vtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
    Scaleform::RefCountImplCore::~RefCountImplCore(this);
    return;
  }
  pWeakProxy = this->Function.Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  this->Function.Flags &= 0xFFFFFDE0;
  this->Function.Bonus.pWeakProxy = 0;
  this->Function.value.VS._1.VInt = 0;
  this->Function.value.VS._2.VObj = 0;
  this->__vftable = (Scaleform::GFx::AS3::IntervalTimer_vtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
