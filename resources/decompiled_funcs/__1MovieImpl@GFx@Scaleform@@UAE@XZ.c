void __thiscall Scaleform::GFx::MovieImpl::~MovieImpl(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::TreeContainer *pObject; // edi
  unsigned int Size; // eax
  unsigned int v4; // ebx
  Scaleform::GFx::FocusGroupDescr *FocusGroups; // edi
  Scaleform::Render::ContextImpl::Entry *v6; // ecx
  bool v7; // zf
  Scaleform::Render::TreeContainer *v8; // ecx
  Scaleform::Render::TreeRoot *v9; // ecx
  Scaleform::GFx::State *v10; // edi
  Scaleform::GFx::FontManagerStates *v11; // ecx
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  Scaleform::GFx::MovieImpl::ReturnValueHolder *pRetValHolder; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // edi
  unsigned int v16; // ebp
  Scaleform::GFx::LoadQueueEntryMT *v17; // edi
  unsigned int i; // ebx
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // ecx
  Scaleform::GFx::LoadQueueEntryMT *v20; // ecx
  unsigned int v21; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *p_TopmostLevelCharacters; // edi
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  unsigned int v24; // ebx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  Scaleform::RefCountVImpl *v26; // ecx
  Scaleform::Render::TreeContainer *v27; // ecx
  Scaleform::Render::TreeRoot *v28; // ecx
  Scaleform::RefCountVImpl *v29; // ecx
  Scaleform::GFx::InteractiveObject *v30; // ecx
  Scaleform::RefCountVImpl *v31; // ecx
  Scaleform::RefCountVImpl *v32; // ecx
  Scaleform::RefCountVImpl *v33; // ecx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *p_pMovieDef; // edi
  unsigned int v35; // ebx
  unsigned int v36; // eax
  Scaleform::GFx::MovieImpl::FontDesc *v37; // edi
  unsigned int v38; // ebx
  Scaleform::GFx::Resource *v39; // ecx
  unsigned int *p_FocusGroupsCnt; // ebx
  Scaleform::GFx::CharacterHandle *v41; // edi
  _DWORD *v42; // eax
  unsigned int v43; // eax
  Scaleform::RefCountNTSImpl **v44; // edi
  unsigned int v45; // ebp
  Scaleform::Render::ContextImpl::Entry *v46; // ecx
  Scaleform::Render::TreeContainer *v47; // ecx
  unsigned int v48; // eax
  Scaleform::RefCountVImpl **v49; // edi
  unsigned int v50; // ebx
  unsigned int v51; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v52; // edi
  unsigned int v53; // ebx
  Scaleform::GFx::MovieImpl::ReturnValueHolder **p_pRetValHolder; // edi
  int j; // ebx
  unsigned int *p_MouseCursorCount; // edi
  int k; // ebx
  Scaleform::GFx::FontManagerStates *v58; // ecx
  Scaleform::RefCountVImpl *v59; // ecx
  Scaleform::RefCountVImpl *v60; // ecx
  Scaleform::RefCountVImpl *v61; // ecx
  Scaleform::Log *v62; // ecx
  Scaleform::Render::TreeContainer *v63; // ecx
  Scaleform::Render::TreeRoot *v64; // ecx
  Scaleform::GFx::StateBagImpl *v65; // ecx
  unsigned int v66; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *p_pSprite; // edi
  unsigned int v68; // ebx
  Scaleform::GFx::MovieDefImpl *v69; // ecx
  Scaleform::GFx::AMP::ViewStats *v70; // ecx
  Scaleform::RefCountVImpl *v71; // ecx
  Scaleform::RefCountVImpl *pIMEManager; // [esp+38h] [ebp-4h]
  Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> pIMEManagera; // [esp+38h] [ebp-4h]

  pObject = this->FocusRectContainerNode.pObject;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::MovieImpl_vtbl *)&Scaleform::GFx::MovieImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>'};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::MovieImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  if ( pObject )
  {
    Size = Scaleform::Render::TreeContainer::GetSize(pObject);
    Scaleform::Render::TreeContainer::Remove(pObject, 0, Size);
    v4 = 0;
    if ( this->FocusGroupsCnt )
    {
      FocusGroups = this->FocusGroups;
      do
      {
        v6 = FocusGroups->FocusRectNode.pObject;
        if ( FocusGroups->FocusRectNode.pObject )
        {
          v7 = v6->RefCount-- == 1;
          if ( v7 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
        }
        FocusGroups->FocusRectNode.pObject = 0;
        ++v4;
        ++FocusGroups;
      }
      while ( v4 < this->FocusGroupsCnt );
    }
    v8 = this->FocusRectContainerNode.pObject;
    if ( v8 )
    {
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
    }
    this->FocusRectContainerNode.pObject = 0;
  }
  Scaleform::GFx::MovieImpl::ClearDrawingContextList(this);
  Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, 1);
  v9 = this->pRenderRoot.pObject;
  if ( v9 )
  {
    v7 = v9->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
  }
  this->pRenderRoot.pObject = 0;
  v10 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
  pIMEManager = (Scaleform::RefCountVImpl *)v10;
  if ( v10
    && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::State *, Scaleform::GFx::MovieImpl *))v10->__vftable[30].~Scaleform::GFx::State)(
         v10,
         this) )
  {
    v10->__vftable[32].~Scaleform::GFx::State(v10);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->pIMECandidateListStyle);
  v11 = this->pFontManagerStates.pObject;
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release(v11);
  this->pFontManagerStates.pObject = 0;
  Scaleform::GFx::MovieImpl::ShutdownTimers(this);
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::Clear(&this->VideoProviders);
  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    pMainMovie->StopActiveSounds(pMainMovie);
  this->Flags |= 0x80000u;
  this->pASMovieRoot.pObject->ClearDisplayList(this->pASMovieRoot.pObject);
  Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(this);
  Scaleform::GFx::MovieImpl::ClearStickyVariables(this);
  pRetValHolder = this->pRetValHolder;
  if ( pRetValHolder )
  {
    if ( pRetValHolder->CharBuffer )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder->CharBuffer);
    pNode = pRetValHolder->StringArray.Data.DefaultValue.pNode;
    v7 = pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&pRetValHolder->StringArray.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder);
  }
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  v16 = 0;
  if ( pLoadQueueMTHead )
  {
    do
    {
      ++v16;
      Scaleform::GFx::LoadQueueEntryMT::Cancel(pLoadQueueMTHead);
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
    }
    while ( pLoadQueueMTHead );
    if ( v16 )
    {
      do
      {
        v17 = this->pLoadQueueMTHead;
        for ( i = 0; v17; v17 = v17->pNext )
        {
          if ( v17->LoadFinished(v17) )
            ++i;
        }
      }
      while ( v16 > i );
    }
  }
  while ( this->pLoadQueueHead )
  {
    pLoadQueueHead = this->pLoadQueueHead;
    this->pLoadQueueHead = pLoadQueueHead->pNext;
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))pLoadQueueHead->~Scaleform::GFx::LoadQueueEntry)(
      pLoadQueueHead,
      1);
  }
  while ( this->pLoadQueueMTHead )
  {
    v20 = this->pLoadQueueMTHead;
    this->pLoadQueueMTHead = v20->pNext;
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntryMT *, int))v20->~Scaleform::GFx::LoadQueueEntryMT)(v20, 1);
  }
  v21 = this->TopmostLevelCharacters.Data.Size;
  p_TopmostLevelCharacters = &this->TopmostLevelCharacters;
  if ( v21 )
  {
    p_pObject = &p_TopmostLevelCharacters->Data.Data[v21 - 1].pObject;
    v24 = this->TopmostLevelCharacters.Data.Size;
    do
    {
      if ( *p_pObject )
        Scaleform::RefCountNTSImpl::Release(*p_pObject);
      --p_pObject;
      --v24;
    }
    while ( v24 );
    p_TopmostLevelCharacters = &this->TopmostLevelCharacters;
    if ( (this->TopmostLevelCharacters.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_TopmostLevelCharacters->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TopmostLevelCharacters->Data.Data);
        p_TopmostLevelCharacters->Data.Data = 0;
      }
      this->TopmostLevelCharacters.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->TopmostLevelCharacters.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->TopmostLevelCharacters,
      &this->TopmostLevelCharacters,
      0);
  }
  p_TopmostLevelCharacters->Data.Size = 0;
  pObjectInterface = this->pObjectInterface;
  if ( pObjectInterface )
    ((void (__thiscall *)(Scaleform::GFx::Value::ObjectInterface *, int))pObjectInterface->~Scaleform::GFx::Value::ObjectInterface)(
      pObjectInterface,
      1);
  this->pASMovieRoot.pObject->Shutdown(this->pASMovieRoot.pObject);
  v26 = (Scaleform::RefCountVImpl *)this->pASMovieRoot.pObject;
  if ( v26 )
    Scaleform::RefCountImpl::Release(v26);
  this->pASMovieRoot.pObject = 0;
  v27 = this->pTopMostRoot.pObject;
  if ( v27 )
  {
    v7 = v27->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v27);
  }
  this->pTopMostRoot.pObject = 0;
  v28 = this->pRenderRoot.pObject;
  if ( v28 )
  {
    v7 = v28->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v28);
  }
  this->pRenderRoot.pObject = 0;
  v29 = (Scaleform::RefCountVImpl *)this->hDisplayRoot.pData.pObject;
  if ( v29 )
    Scaleform::RefCountImpl::Release(v29);
  this->hDisplayRoot.pData.pObject = 0;
  if ( pIMEManager )
    Scaleform::RefCountImpl::Release(pIMEManager);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::IndirectTransPair>::DestructArray(
    this->IndirectTransformPairs.Data.Data,
    this->IndirectTransformPairs.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->IndirectTransformPairs.Data.Data);
  v30 = this->GestureTopMostChar.pObject;
  if ( v30 )
    Scaleform::RefCountNTSImpl::Release(v30);
  v31 = (Scaleform::RefCountVImpl *)this->MultitouchHAL.pObject;
  if ( v31 )
    Scaleform::RefCountImpl::Release(v31);
  v32 = (Scaleform::RefCountVImpl *)this->DIContext.pObject;
  if ( v32 )
    Scaleform::RefCountImpl::Release(v32);
  Scaleform::Render::ContextImpl::Context::~Context(&this->RenderContext);
  v33 = (Scaleform::RefCountVImpl *)this->pSavedASMovieRoot.pObject;
  if ( v33 )
    Scaleform::RefCountImpl::Release(v33);
  if ( this->MovieDefKillList.Data.Size )
  {
    p_pMovieDef = &this->MovieDefKillList.Data.Data[this->MovieDefKillList.Data.Size - 1].pMovieDef;
    v35 = this->MovieDefKillList.Data.Size;
    do
    {
      if ( p_pMovieDef->pObject )
        Scaleform::GFx::Resource::Release(p_pMovieDef->pObject);
      p_pMovieDef -= 4;
      --v35;
    }
    while ( v35 );
  }
  if ( this->MovieDefKillList.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MovieDefKillList.Data.Data);
  v36 = this->RegisteredFonts.Data.Size;
  v37 = &this->RegisteredFonts.Data.Data[v36 - 1];
  if ( v36 )
  {
    v38 = this->RegisteredFonts.Data.Size;
    do
    {
      v39 = v37->pFont.pObject;
      if ( v39 )
        Scaleform::GFx::Resource::Release(v39);
      if ( v37->pMovieDef.pObject )
        Scaleform::GFx::Resource::Release(v37->pMovieDef.pObject);
      --v37;
      --v38;
    }
    while ( v38 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RegisteredFonts.Data.Data);
  p_FocusGroupsCnt = &this->FocusGroupsCnt;
  for ( pIMEManagera.pObject = (Scaleform::GFx::IMEManagerBase *)15; (int)pIMEManagera.pObject >= 0; --pIMEManagera.pObject )
  {
    v41 = (Scaleform::GFx::CharacterHandle *)*(p_FocusGroupsCnt - 10);
    p_FocusGroupsCnt -= 16;
    if ( v41 )
    {
      if ( --v41->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v41);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v41);
      }
    }
    v42 = (_DWORD *)p_FocusGroupsCnt[5];
    if ( v42 )
    {
      v7 = (*v42)-- == 1;
      if ( v7 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v42);
    }
    v43 = p_FocusGroupsCnt[2];
    v44 = (Scaleform::RefCountNTSImpl **)(p_FocusGroupsCnt[1] + 4 * v43 - 4);
    if ( v43 )
    {
      v45 = p_FocusGroupsCnt[2];
      do
      {
        if ( *v44 )
          Scaleform::RefCountNTSImpl::Release(*v44);
        --v44;
        --v45;
      }
      while ( v45 );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)p_FocusGroupsCnt[1]);
    v46 = (Scaleform::Render::ContextImpl::Entry *)*p_FocusGroupsCnt;
    if ( *p_FocusGroupsCnt )
    {
      v7 = v46->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v46);
    }
  }
  v47 = this->FocusRectContainerNode.pObject;
  if ( v47 )
  {
    v7 = v47->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v47);
  }
  v48 = this->IntervalTimers.Data.Size;
  v49 = (Scaleform::RefCountVImpl **)&this->IntervalTimers.Data.Data[v48 - 1];
  if ( v48 )
  {
    v50 = this->IntervalTimers.Data.Size;
    do
    {
      if ( *v49 )
        Scaleform::RefCountImpl::Release(*v49);
      --v49;
      --v50;
    }
    while ( v50 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->IntervalTimers.Data.Data);
  v51 = this->TopmostLevelCharacters.Data.Size;
  v52 = &this->TopmostLevelCharacters.Data.Data[v51 - 1];
  if ( v51 )
  {
    v53 = this->TopmostLevelCharacters.Data.Size;
    do
    {
      if ( v52->pObject )
        Scaleform::RefCountNTSImpl::Release(v52->pObject);
      --v52;
      --v53;
    }
    while ( v53 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->TopmostLevelCharacters.Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StickyVariables);
  p_pRetValHolder = &this->pRetValHolder;
  for ( j = 5; j >= 0; --j )
  {
    p_pRetValHolder -= 415;
    Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)p_pRetValHolder);
  }
  p_MouseCursorCount = &this->MouseCursorCount;
  for ( k = 5; k >= 0; --k )
  {
    p_MouseCursorCount -= 14;
    Scaleform::GFx::MouseState::~MouseState((Scaleform::GFx::MouseState *)p_MouseCursorCount);
  }
  v58 = this->pFontManagerStates.pObject;
  if ( v58 )
    Scaleform::RefCountNTSImpl::Release(v58);
  v59 = (Scaleform::RefCountVImpl *)this->pExtIntfHandler.pObject;
  if ( v59 )
    Scaleform::RefCountImpl::Release(v59);
  v60 = (Scaleform::RefCountVImpl *)this->pFSCommandHandler.pObject;
  if ( v60 )
    Scaleform::RefCountImpl::Release(v60);
  v61 = (Scaleform::RefCountVImpl *)this->pUserEventHandler.pObject;
  if ( v61 )
    Scaleform::RefCountImpl::Release(v61);
  v62 = this->pCachedLog.pObject;
  if ( v62 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v62);
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::Clear(&this->VideoProviders);
  v63 = this->pTopMostRoot.pObject;
  if ( v63 )
  {
    v7 = v63->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v63);
  }
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&this->hDisplayRoot);
  v64 = this->pRenderRoot.pObject;
  if ( v64 )
  {
    v7 = v64->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v64);
  }
  v65 = this->pStateBag.pObject;
  if ( v65 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v65);
  v66 = this->MovieLevels.Data.Size;
  if ( v66 )
  {
    p_pSprite = &this->MovieLevels.Data.Data[v66 - 1].pSprite;
    v68 = this->MovieLevels.Data.Size;
    do
    {
      if ( p_pSprite->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pSprite->pObject);
      p_pSprite -= 2;
      --v68;
    }
    while ( v68 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MovieLevels.Data.Data);
  v69 = this->pMainMovieDef.pObject;
  if ( v69 )
    Scaleform::GFx::Resource::Release(v69);
  v70 = this->AdvanceStats.pObject;
  if ( v70 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v70);
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::MovieImpl_vtbl *)&Scaleform::GFx::Movie::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>'};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::Movie::`vftable'{for `Scaleform::GFx::StateBag'};
  v71 = (Scaleform::RefCountVImpl *)this->pASMovieRoot.pObject;
  if ( v71 )
    Scaleform::RefCountImpl::Release(v71);
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
