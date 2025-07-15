void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        unsigned int bytesLoaded,
        unsigned int totalBytes)
{
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *pObject; // edx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *v6; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> efe; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASString evtName; // [esp+8h] [ebp-4h] BYREF

  evtName.pNode = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].__vftable[43].~Scaleform::GFx::AS3::VM;
  ++evtName.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(this, &evtName, 0) )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(
      this,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&efe,
      &evtName);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&efe.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    pObject = efe.pObject;
    this->BytesTotal = totalBytes;
    this->BytesLoaded = bytesLoaded;
    pObject->BytesLoaded = bytesLoaded;
    efe.pObject->BytesTotal = totalBytes;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, efe.pObject, 0);
    if ( efe.pObject )
    {
      if ( ((int)efe.pObject & 1) == 0 )
      {
        RefCount = efe.pObject->RefCount;
        v6 = efe.pObject;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          efe.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
    }
  }
  pNode = evtName.pNode;
  --evtName.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
