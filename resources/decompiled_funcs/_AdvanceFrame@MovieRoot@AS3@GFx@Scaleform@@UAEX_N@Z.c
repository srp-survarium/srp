void __thiscall Scaleform::GFx::AS3::MovieRoot::AdvanceFrame(Scaleform::GFx::AS3::MovieRoot *this, bool nextFrame)
{
  Scaleform::GFx::MovieDefImpl *v3; // edi
  Scaleform::GFx::DisplayObjContainer *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v5; // ebp
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // ebx
  unsigned int v10; // ebp
  bool v11; // al
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *pObject; // ecx
  Scaleform::GFx::Resource *v14; // edx
  unsigned int CollectionScheduledFlags; // [esp-4h] [ebp-Ch]
  bool loadingFinished; // [esp+7h] [ebp-1h]

  if ( (this->MainLoaderInfoEventsState & 2) != 0 )
    goto LABEL_24;
  v3 = this->pMovieImpl->pMainMovie->GetResourceMovieDef(this->pMovieImpl->pMainMovie);
  v4 = this->GetRootMovie(this, 0);
  v5 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v4;
  if ( v4
    && (v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&v4->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + v4->AvmObjOffset)
                                        + 20))((int)v4 + 4 * v4->AvmObjOffset)) != 0 )
  {
    v7 = v6 - 36;
  }
  else
  {
    v7 = 0;
  }
  if ( *(_DWORD *)(v7 + 8) )
    v8 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 8);
  else
    v8 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 4);
  v9 = v8;
  if ( ((unsigned __int8)v8 & 1) != 0 )
    v9 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v8 - 1);
  if ( v9 )
  {
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    if ( Scaleform::GFx::XML::ElementNode::HasAttributes(v9) )
    {
      if ( (this->MainLoaderInfoEventsState & 1) == 0 )
      {
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(v9->pLoaderInfo.pObject, v5);
        this->MainLoaderInfoEventsState |= 1u;
      }
      v10 = v3->GetFrameCount(v3);
      v11 = v3->GetLoadingFrame(v3) >= v10;
      loadingFinished = v11;
      if ( !nextFrame && !v11 )
        goto LABEL_20;
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(
        v9->pLoaderInfo.pObject,
        v3->pBindData.pObject->BytesLoaded,
        v3->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength);
      if ( !loadingFinished )
        goto LABEL_20;
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v9->pLoaderInfo.pObject);
    }
  }
  this->MainLoaderInfoEventsState |= 2u;
LABEL_20:
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) == 0 )
    {
      RefCount = v9->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
LABEL_24:
  if ( this->StageInvalidated )
  {
    Scaleform::GFx::AS3::EventChains::QueueEvents(
      &this->mEventChains,
      (Scaleform::GFx::EventId::IdCode)&vostok::memory::s_CRT_arena[5574219]);
    this->DoActions(this);
    this->StageInvalidated = 0;
  }
  if ( nextFrame )
  {
    pObject = this->MemContext.pObject->ASGC.pObject;
    if ( pObject )
    {
      v14 = (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject;
      if ( pObject->CollectionScheduledFlags )
      {
        CollectionScheduledFlags = pObject->CollectionScheduledFlags;
        pObject->CollectionScheduledFlags = 0;
        Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(pObject, v14, CollectionScheduledFlags);
      }
      Scaleform::GFx::AS3::ASRefCountCollector::AdvanceFrame(
        this->MemContext.pObject->ASGC.pObject,
        &this->NumAdvancesSinceCollection,
        &this->LastCollectionFrame,
        (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject);
    }
  }
}
