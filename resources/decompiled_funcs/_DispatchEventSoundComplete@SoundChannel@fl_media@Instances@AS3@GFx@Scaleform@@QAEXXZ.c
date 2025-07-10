void __thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::DispatchEventSoundComplete(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> eventObj; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASString eventType; // [esp+8h] [ebp-4h] BYREF

  eventType.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      "soundComplete",
                      0xDu,
                      0);
  ++eventType.pNode->RefCount;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(this, &eventObj, &eventType, 0, 0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&eventObj.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, eventObj.pObject, 0);
  if ( eventObj.pObject )
  {
    if ( ((int)eventObj.pObject & 1) != 0 )
    {
      --eventObj.pObject;
    }
    else
    {
      RefCount = eventObj.pObject->RefCount;
      pObject = eventObj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        eventObj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  pNode = eventType.pNode;
  --eventType.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
