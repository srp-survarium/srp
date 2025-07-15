void __userpurge Scaleform::GFx::AS3::Instances::fl_utils::Timer::start(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this@<ecx>,
        int a2@<edi>,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM_vtbl *v4; // edx
  Scaleform::GFx::AS3::IntervalTimer *pObject; // ecx
  Scaleform::GFx::MovieImpl *v6; // ebx
  Scaleform::GFx::AS3::IntervalTimer *v7; // eax
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::IntervalTimer *v9; // ecx
  Scaleform::GFx::AS3::IntervalTimer *v10; // eax
  Scaleform::GFx::AS3::IntervalTimer *v11; // edi
  Scaleform::RefCountVImpl *v12; // ecx

  v4 = this->pTraits.pObject->pVM[1].__vftable;
  pObject = this->pCoreTimer.pObject;
  v6 = (Scaleform::GFx::MovieImpl *)v4[1].~Scaleform::GFx::AS3::VM;
  if ( pObject )
  {
    if ( pObject->IsActive(pObject) )
      return;
    v7 = this->pCoreTimer.pObject;
    this->CurrentCount = v7->CurrentCount;
    if ( v7 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
    this->pCoreTimer.pObject = 0;
  }
  MHeap = this->pTraits.pObject->pVM->MHeap;
  v9 = (Scaleform::GFx::AS3::IntervalTimer *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))MHeap->Alloc)(
                                               MHeap,
                                               72,
                                               0,
                                               a2);
  if ( v9 )
  {
    Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(
      v9,
      this,
      (__int64)this->Delay,
      this->CurrentCount,
      this->RepeatCount);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  v12 = (Scaleform::RefCountVImpl *)this->pCoreTimer.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pCoreTimer.pObject = v11;
  Scaleform::GFx::MovieImpl::AddIntervalTimer(v6, v11);
  this->pCoreTimer.pObject->Start(this->pCoreTimer.pObject, v6);
}
