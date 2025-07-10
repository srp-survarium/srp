void __thiscall Scaleform::GFx::AS3::MovieRoot::UnloadMovie(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *ploader,
        bool stop,
        bool gc)
{
  char v5; // bl
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *ContentLoaderInfo; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  Scaleform::GFx::InteractiveObject *v8; // ecx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *p_pDispObj; // eax
  Scaleform::GFx::DisplayObject *v10; // esi
  Scaleform::GFx::InteractiveObject *ConstStringNode; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v14; // eax
  Scaleform::GFx::InteractiveObject *v15; // ecx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *p_obj; // eax
  Scaleform::GFx::DisplayObject *v17; // esi
  void (__thiscall *v18)(struct Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor *); // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // ecx
  Scaleform::GFx::LoadQueueEntryMT *i; // eax
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // ecx
  Scaleform::GFx::LoadQueueEntry *k; // eax
  Scaleform::GFx::DisplayObject *v23; // ebx
  Scaleform::GFx::DisplayObjContainer *v24; // ecx
  Scaleform::GFx::DisplayObject *ChildAt; // eax
  Scaleform::GFx::Resource *v26; // eax
  Scaleform::GFx::MovieDefImpl *v27; // esi
  char v28; // al
  Scaleform::GFx::AS3::MovieRoot *v29; // ebx
  Scaleform::GFx::MovieDefImpl *v30; // ebp
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> > *v31; // esi
  unsigned int v32; // edi
  Scaleform::GFx::DisplayObject *v33; // ecx
  Scaleform::GFx::AS3::Stage *v34; // eax
  int v35; // eax
  int v36; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v37; // ecx
  Scaleform::GFx::Sprite *v38; // ecx
  Scaleform::GFx::AS3::MemoryContextImpl *v39; // eax
  Scaleform::RefCountNTSImpl **p_pObject; // esi
  unsigned int v41; // ebp
  int v42; // eax
  int v43; // edi
  int v44; // ecx
  Scaleform::GFx::InteractiveObject **v45; // eax
  Scaleform::GFx::InteractiveObject *v46; // ebx
  int AvmObjOffset; // edx
  int v48; // eax
  int v49; // eax
  Scaleform::RefCountNTSImpl **v50; // edi
  int v51; // ebp
  int v52; // eax
  int v53; // eax
  int v54; // eax
  Scaleform::GFx::DisplayObject_vtbl **v55; // esi
  Scaleform::GFx::DisplayObject_vtbl *v56; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v57; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::DisplayObjContainer *v59; // esi
  Scaleform::GFx::AS3::MovieRoot *v60; // esi
  Scaleform::Render::Text::Allocator *v61; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v62; // ecx
  unsigned int v63; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::DisplayObject> contentDisplayObj; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::MovieRoot *v65; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> loaderInfo; // [esp+14h] [ebp-14h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> obj; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor vis; // [esp+1Ch] [ebp-Ch] BYREF
  Scaleform::GFx::DisplayObjContainer *doc; // [esp+24h] [ebp-4h]
  Scaleform::GFx::Resource *ploadera; // [esp+2Ch] [ebp+4h]
  unsigned int j; // [esp+30h] [ebp+8h]

  v5 = 0;
  v65 = this;
  doc = 0;
  ContentLoaderInfo = Scaleform::GFx::AS3::Instances::fl_display::Loader::GetContentLoaderInfo(ploader);
  loaderInfo.pObject = ContentLoaderInfo;
  if ( ContentLoaderInfo )
    ContentLoaderInfo->RefCount = (ContentLoaderInfo->RefCount + 1) & 0x8FBFFFFF;
  contentDisplayObj.pObject = 0;
  if ( ContentLoaderInfo )
  {
    pObject = ContentLoaderInfo->Content.pObject;
    if ( pObject )
    {
      v8 = obj.pObject;
      p_pDispObj = (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&pObject->pDispObj;
    }
    else
    {
      v8 = 0;
      v5 = 1;
      obj.pObject = 0;
      p_pDispObj = &obj;
    }
    v10 = p_pDispObj->pObject;
    if ( (v5 & 1) != 0 )
    {
      v5 &= ~1u;
      if ( v8 )
        Scaleform::RefCountNTSImpl::Release(v8);
    }
    if ( v10 )
    {
      ++v10->RefCount;
      contentDisplayObj.pObject = v10;
    }
    ConstStringNode = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                             this->BuiltinsMgr.pStringManager,
                                                             "unload",
                                                             6u,
                                                             0);
    v12 = loaderInfo.pObject;
    obj.pObject = ConstStringNode;
    ++ConstStringNode->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      v12,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&vis,
      (const Scaleform::GFx::ASString *)&obj,
      0,
      0);
    v13 = (Scaleform::GFx::ASStringNode *)obj.pObject;
    --obj.pObject->__vftable;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v14 = loaderInfo.pObject->Content.pObject;
    if ( v14 )
    {
      v15 = obj.pObject;
      p_obj = (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&v14->pDispObj;
    }
    else
    {
      v5 |= 2u;
      v15 = 0;
      obj.pObject = 0;
      p_obj = &obj;
    }
    v17 = p_obj->pObject;
    if ( (v5 & 2) != 0 && v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      loaderInfo.pObject,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)vis.__vftable,
      v17);
    if ( vis.__vftable )
    {
      if ( ((int)vis.__vftable & 1) == 0 )
      {
        v18 = vis.__vftable[2].~Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor;
        if ( ((unsigned int)&byte_3FFFFF & (unsigned int)v18) != 0 )
        {
          v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)vis.__vftable;
          vis.__vftable[2].~Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor = (void (__thiscall *)(struct Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor *))((char *)v18 - 1);
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
        }
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl_display::Loader::ResetContent(ploader);
  for ( i = this->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
  {
    pQueueEntry = i->pQueueEntry;
    if ( (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].__vftable == ploader )
      pQueueEntry->Canceled = 1;
  }
  for ( k = this->pMovieImpl->pLoadQueueHead; k; k = k->pNext )
  {
    if ( (Scaleform::GFx::AS3::Instances::fl_display::Loader *)k[1].__vftable == ploader )
      k->Canceled = 1;
  }
  v23 = contentDisplayObj.pObject;
  v24 = (Scaleform::GFx::DisplayObjContainer *)ploader->pDispObj.pObject;
  doc = v24;
  if ( contentDisplayObj.pObject
    || v24
    && v24->mDisplayList.DisplayObjectArray.Data.Size > (unsigned int)contentDisplayObj.pObject
    && (ChildAt = (Scaleform::GFx::DisplayObject *)Scaleform::GFx::DisplayObjContainer::GetChildAt(
                                                     v24,
                                                     (unsigned int)contentDisplayObj.pObject),
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::DisplayObject>::operator=(&contentDisplayObj, ChildAt),
        (v23 = contentDisplayObj.pObject) != 0) )
  {
    v23->OnEventUnload(v23);
    v23->ForceShutdown(v23);
    v26 = v23->GetResourceMovieDef(v23);
    ploadera = v26;
    if ( v26 )
    {
      v27 = (Scaleform::GFx::MovieDefImpl *)v26;
      Scaleform::RefCountImpl::AddRef(v26);
      v28 = Scaleform::GFx::AS3::MovieRoot::RemoveLoadedMovieDef(this, v27);
      if ( stop )
      {
        if ( v28 )
        {
          v29 = this;
          Scaleform::Hash<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>,Scaleform::AllocatorLH<int,2>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>>::Begin(
            &this->mEventChains.Chains,
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::Iterator *)&vis);
          v30 = v27;
          while ( vis.__vftable
               && vis.~Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor
               && (int)vis.pDefImpl <= *((_DWORD *)vis.~Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor
                                       + 1) )
          {
            v31 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> > *)*((_DWORD *)vis.~Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor + 4 * ((int)&vis.pDefImpl->__vftable + 1));
            if ( v31 )
            {
              v32 = 0;
              while ( v32 < v31->Data.Size )
              {
                v33 = v31->Data.Data[v32].pObject;
                if ( v33 && v33->GetResourceMovieDef(v33) == v30 )
                  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
                    v31,
                    v32);
                else
                  ++v32;
              }
            }
            Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::ConstIterator::operator++((Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::ConstIterator *)&vis);
          }
          v34 = v29->pStage.pObject;
          if ( v34
            && (v35 = (*(int (__thiscall **)(int))(*((_DWORD *)&v34->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                   + v34->AvmObjOffset)
                                                 + 20))((int)v34 + 4 * v34->AvmObjOffset)) != 0 )
          {
            v36 = v35 - 36;
          }
          else
          {
            v36 = 0;
          }
          v37 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v36 + 8);
          if ( !v37 )
            v37 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v36 + 4);
          if ( ((unsigned __int8)v37 & 1) != 0 )
            v37 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v37 - 1);
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(v37, v30);
          Scaleform::GFx::MovieImpl::ShutdownTimersForMovieDef(v29->pMovieImpl, v30);
          Scaleform::GFx::MovieImpl::UnregisterFonts(v29->pMovieImpl, v30);
          v38 = (v29->pStage.pObject->pRoot.pObject->Flags & 0x400) != 0
              ? (Scaleform::GFx::Sprite *)v29->pStage.pObject->pRoot.pObject
              : 0;
          if ( v38 )
            Scaleform::GFx::Sprite::ReleaseAllSounds(v38, v30);
          v39 = v29->MemContext.pObject;
          if ( v39->TextAllocator.pObject )
          {
            vis.__vftable = (Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor_vtbl *)&`Scaleform::GFx::AS3::MovieRoot::UnloadMovie'::`46'::TextFormatVisitor::`vftable';
            vis.pDefImpl = v30;
            Scaleform::Render::Text::Allocator::VisitTextFormatCache(v39->TextAllocator.pObject, &vis);
          }
          p_pObject = &v29->mMouseState[0].LastMouseOverObj.pObject;
          vis.__vftable = (Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor_vtbl *)6;
          do
          {
            v41 = 0;
            j = 0;
            if ( *(p_pObject - 2) )
            {
              do
              {
                v42 = (int)*(p_pObject - 3);
                v43 = v41;
                v44 = *(_DWORD *)(v42 + 4 * v41);
                v45 = (Scaleform::GFx::InteractiveObject **)(4 * v41 + v42);
                if ( v44 )
                  ++*(_DWORD *)(v44 + 4);
                v46 = *v45;
                obj.pObject = v46;
                if ( !v46 )
                  goto LABEL_89;
                AvmObjOffset = v46->AvmObjOffset;
                if ( *((_DWORD *)&v46->pWeakProxy + AvmObjOffset) )
                  v48 = *((_DWORD *)&v46->pWeakProxy + AvmObjOffset);
                else
                  v48 = *(&v46->RefCount + AvmObjOffset);
                if ( (v48 & 1) != 0 )
                  --v48;
                if ( v48
                  && (v49 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v48 + 20) + 28))(*(_DWORD *)(v48 + 20))) != 0
                  && *(Scaleform::GFx::Resource **)(*(_DWORD *)(v49 + 60) + 184) == ploadera )
                {
                  if ( *(p_pObject - 2) == (Scaleform::RefCountNTSImpl *)1 )
                  {
                    v50 = (Scaleform::RefCountNTSImpl **)*(p_pObject - 3);
                    v51 = 1;
                    do
                    {
                      if ( *v50 )
                        Scaleform::RefCountNTSImpl::Release(*v50);
                      --v50;
                      --v51;
                    }
                    while ( v51 );
                    if ( ((unsigned int)*(p_pObject - 1) & 0xFFFFFFFE) != 0 )
                    {
                      if ( *(p_pObject - 3) )
                      {
                        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(p_pObject - 3));
                        *(p_pObject - 3) = 0;
                      }
                      *(p_pObject - 1) = 0;
                    }
                    v41 = j;
                    *(p_pObject - 2) = 0;
                    v46 = obj.pObject;
                  }
                  else
                  {
                    if ( (&(*(p_pObject - 3))->__vftable)[v43] )
                      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)(&(*(p_pObject - 3))->__vftable)[v43]);
                    memmove(
                      (unsigned __int8 *)*(p_pObject - 3) + v43 * 4,
                      (unsigned __int8 *)&(*(p_pObject - 3))->RefCount + v43 * 4,
                      4 * ((_DWORD)*(p_pObject - 2) - v41) - 4);
                    *(p_pObject - 2) = (Scaleform::RefCountNTSImpl *)((char *)*(p_pObject - 2) - 1);
                  }
                }
                else
                {
LABEL_89:
                  j = ++v41;
                }
                if ( v46 )
                  Scaleform::RefCountNTSImpl::Release(v46);
              }
              while ( v41 < (unsigned int)*(p_pObject - 2) );
            }
            if ( *p_pObject )
            {
              v52 = (int)*p_pObject + 4 * BYTE1((*p_pObject)[8].__vftable);
              if ( *(_DWORD *)(v52 + 8) )
                v53 = *(_DWORD *)(v52 + 8);
              else
                v53 = *(_DWORD *)(v52 + 4);
              if ( (v53 & 1) != 0 )
                --v53;
              if ( v53 )
              {
                v54 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v53 + 20) + 28))(*(_DWORD *)(v53 + 20));
                if ( v54 )
                {
                  if ( *(Scaleform::GFx::Resource **)(*(_DWORD *)(v54 + 60) + 184) == ploadera )
                  {
                    if ( *p_pObject )
                      Scaleform::RefCountNTSImpl::Release(*p_pObject);
                    *p_pObject = 0;
                  }
                }
              }
            }
            p_pObject += 52;
            --vis.__vftable;
          }
          while ( vis.__vftable );
          v23 = contentDisplayObj.pObject;
        }
      }
    }
    v55 = &v23->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + v23->AvmObjOffset;
    v56 = v55[2];
    if ( !v56 )
      v56 = v55[1];
    if ( ((unsigned __int8)v56 & 1) != 0 )
      v56 = (Scaleform::GFx::DisplayObject_vtbl *)((char *)v56 - 1);
    v55[2] = v56;
    v57 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v55[1];
    if ( v57 )
    {
      if ( ((unsigned __int8)v57 & 1) != 0 )
      {
        v55[1] = (Scaleform::GFx::DisplayObject_vtbl *)((char *)&v57[-1].RefCount + 3);
      }
      else
      {
        RefCount = v57->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v57->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v57);
        }
      }
      v55[1] = 0;
    }
    v59 = doc;
    if ( doc )
    {
      Scaleform::GFx::DisplayList::Clear(&doc->mDisplayList, doc);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v59);
    }
    if ( ploadera )
      Scaleform::GFx::Resource::Release(ploadera);
  }
  v60 = v65;
  if ( gc )
    v65->pAVM.pObject->GC.GC->CollectionScheduledFlags = 10;
  v61 = v60->MemContext.pObject->TextAllocator.pObject;
  if ( v61 )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(v61, 0);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(v60->MemContext.pObject->TextAllocator.pObject, 0);
  }
  if ( v23 && ((unsigned __int8)v23 & 1) == 0 )
    Scaleform::RefCountNTSImpl::Release(v23);
  v62 = loaderInfo.pObject;
  if ( loaderInfo.pObject )
  {
    if ( ((int)loaderInfo.pObject & 1) == 0 )
    {
      v63 = loaderInfo.pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v63) != 0 )
      {
        loaderInfo.pObject->RefCount = v63 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v62);
      }
    }
  }
}
