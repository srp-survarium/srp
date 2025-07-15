void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evt,
        Scaleform::GFx::DisplayObject *dispObject)
{
  char v4; // al
  unsigned int RefCount; // eax
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> captureArray; // [esp+Ch] [ebp-90h] BYREF

  *((_BYTE *)evt + 48) |= 0x20u;
  if ( dispObject )
  {
    if ( this )
      this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    ++dispObject->RefCount;
    Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(
      &captureArray,
      this->pTraits.pObject->pVM->MHeap);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(this, dispObject, &captureArray);
    if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ExecuteCapturePhase(this, evt, &captureArray) )
    {
      evt->Phase = 2;
      if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, evt, 0) )
      {
        v4 = *((_BYTE *)evt + 48);
        if ( (v4 & 0x18) == 0 && (v4 & 1) != 0 )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ExecuteBubblePhase(this, evt, &captureArray);
      }
      else
      {
        dispObject->Flags |= 0x20u;
      }
    }
    Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::~ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(&captureArray);
    Scaleform::RefCountNTSImpl::Release(dispObject);
    if ( ((unsigned __int8)this & 1) == 0 )
    {
      RefCount = this->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        this->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, evt, 0);
  }
}
