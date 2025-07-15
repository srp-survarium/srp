void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        unsigned int bytesLoaded,
        unsigned int totalBytes)
{
  unsigned int v4; // ebx
  unsigned int v5; // edi
  int v6; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString evtName; // [esp+4h] [ebp-4h] BYREF

  evtName.pNode = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].__vftable[43].~Scaleform::GFx::AS3::VM;
  ++evtName.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(this, &evtName, 0) )
  {
    v4 = totalBytes;
    v5 = bytesLoaded;
    this->bytesLoaded = bytesLoaded;
    this->bytesTotal = v4;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(
      this,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *)&bytesLoaded,
      &evtName);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)(bytesLoaded + 40),
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    *(_DWORD *)(bytesLoaded + 52) = v5;
    *(_DWORD *)(bytesLoaded + 56) = v4;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
      this,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)bytesLoaded,
      0);
    if ( bytesLoaded )
    {
      if ( (bytesLoaded & 1) == 0 )
      {
        v6 = *(_DWORD *)(bytesLoaded + 16);
        v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)bytesLoaded;
        if ( (v6 & 0x3FFFFF) != 0 )
        {
          *(_DWORD *)(bytesLoaded + 16) = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
  }
  pNode = evtName.pNode;
  --evtName.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
