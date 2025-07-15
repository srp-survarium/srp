void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::ExecuteEvent(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::VM *pVM; // edi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *v5; // ecx
  unsigned int v6; // edx
  Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *v7; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent> result; // [esp+8h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent> efe; // [esp+Ch] [ebp-4h] BYREF

  pObject = this->pTraits.pObject;
  this->CurrentCount = this->pCoreTimer.pObject->CurrentCount;
  pVM = pObject->pVM;
  Scaleform::GFx::AS3::Instances::fl_utils::Timer::CreateTimerEventObject(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&efe,
    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[41].GetAdvanceStats);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&efe.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, efe.pObject, 0);
  if ( this->CurrentCount >= this->RepeatCount )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::Timer::CreateTimerEventObject(
      this,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
      (const Scaleform::GFx::ASString *)&pVM[1].__vftable[42]);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, result.pObject, 0);
    if ( result.pObject )
    {
      if ( ((int)result.pObject & 1) == 0 )
      {
        RefCount = result.pObject->RefCount;
        v5 = result.pObject;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          result.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
      }
    }
  }
  if ( efe.pObject && ((int)efe.pObject & 1) == 0 )
  {
    v6 = efe.pObject->RefCount;
    v7 = efe.pObject;
    if ( (v6 & 0x3FFFFF) != 0 )
    {
      efe.pObject->RefCount = v6 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
    }
  }
}
