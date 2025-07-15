void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::DispatchEventIOError(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> eventObj; // [esp+4h] [ebp-4h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(this, &eventObj, "soundIOError");
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&eventObj.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, eventObj.pObject, 0);
  if ( eventObj.pObject && ((int)eventObj.pObject & 1) == 0 )
  {
    RefCount = eventObj.pObject->RefCount;
    pObject = eventObj.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      eventObj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
