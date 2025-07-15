void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteCloseEvent(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> efe; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASString evtName; // [esp+8h] [ebp-4h] BYREF

  evtName.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                    this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                    "close",
                    5u,
                    0);
  ++evtName.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(this, &evtName, 0) )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(this, &efe, &evtName, 0, 0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&efe.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, efe.pObject, 0);
    if ( efe.pObject )
    {
      if ( ((int)efe.pObject & 1) == 0 )
      {
        RefCount = efe.pObject->RefCount;
        pObject = efe.pObject;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          efe.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  pNode = evtName.pNode;
  --evtName.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
