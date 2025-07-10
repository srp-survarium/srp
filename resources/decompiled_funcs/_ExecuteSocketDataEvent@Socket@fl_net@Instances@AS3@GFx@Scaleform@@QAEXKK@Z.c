void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteSocketDataEvent(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int bytesLoaded,
        unsigned int totalBytes)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> efe; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASString evtName; // [esp+8h] [ebp-4h] BYREF

  evtName.pNode = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].__vftable[43].GetAdvanceStats;
  ++evtName.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(this, &evtName, 0) )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(this, &efe, &evtName);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&efe.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    efe.pObject->BytesLoaded = bytesLoaded;
    efe.pObject->BytesTotal = totalBytes;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, efe.pObject, 0);
    if ( efe.pObject )
    {
      if ( ((int)efe.pObject & 1) == 0 )
      {
        RefCount = efe.pObject->RefCount;
        pObject = efe.pObject;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
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
