void __thiscall Scaleform::GFx::MovieImpl::~MovieImpl(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::TreeContainer *pObject; // edi
  unsigned int Size; // eax
  unsigned int v4; // ebx
  Scaleform::GFx::FocusGroupDescr *FocusGroups; // edi
  Scaleform::Render::ContextImpl::Entry *v6; // ecx
  bool v7; // zf
  Scaleform::Render::TreeContainer *v8; // ecx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::Render::TreeRoot *v10; // ecx
  Scaleform::GFx::State *v11; // eax
  Scaleform::GFx::State *v12; // edi
  Scaleform::GFx::FontManagerStates *v13; // ecx
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  Scaleform::GFx::MovieImpl::ReturnValueHolder *pRetValHolder; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // edi
  unsigned int v18; // ebp
  Scaleform::GFx::LoadQueueEntryMT *v19; // edi
  unsigned int i; // ebx
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // ecx
  Scaleform::GFx::LoadQueueEntryMT *v22; // ecx
  unsigned int v23; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *p_TopmostLevelCharacters; // edi
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  unsigned int v26; // ebx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  Scaleform::RefCountVImpl *v28; // ecx
  Scaleform::Render::TreeContainer *v29; // ecx
  Scaleform::Render::TreeRoot *v30; // ecx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v31; // ecx
  Scaleform::GFx::InteractiveObject *v32; // ecx
  Scaleform::RefCountVImpl *v33; // ecx
  Scaleform::RefCountVImpl *v34; // ecx
  Scaleform::RefCountVImpl *v35; // ecx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *p_pMovieDef; // edi
  unsigned int v37; // ebx
  unsigned int v38; // eax
  Scaleform::GFx::MovieImpl::FontDesc *v39; // edi
  unsigned int v40; // ebx
  Scaleform::GFx::Resource *v41; // ecx
  unsigned int *p_FocusGroupsCnt; // ebx
  Scaleform::GFx::CharacterHandle *v43; // edi
  _DWORD *v44; // eax
  unsigned int v45; // eax
  Scaleform::RefCountNTSImpl **v46; // edi
  unsigned int v47; // ebp
  Scaleform::Render::ContextImpl::Entry *v48; // ecx
  Scaleform::Render::TreeContainer *v49; // ecx
  unsigned int v50; // eax
  Scaleform::RefCountVImpl **v51; // edi
  unsigned int v52; // ebx
  unsigned int v53; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v54; // edi
  unsigned int v55; // ebx
  Scaleform::GFx::MovieImpl::ReturnValueHolder **p_pRetValHolder; // edi
  int k; // ebx
  unsigned int *p_MouseCursorCount; // edi
  int m; // ebx
  Scaleform::GFx::FontManagerStates *v60; // ecx
  Scaleform::RefCountVImpl *v61; // ecx
  Scaleform::RefCountVImpl *v62; // ecx
  Scaleform::RefCountVImpl *v63; // ecx
  Scaleform::RefCountVImpl *v64; // ecx
  Scaleform::Render::TreeContainer *v65; // ecx
  Scaleform::Render::TreeRoot *v66; // ecx
  Scaleform::RefCountVImpl *v67; // ecx
  unsigned int v68; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *p_pSprite; // edi
  unsigned int v70; // ebx
  Scaleform::GFx::MovieDefImpl *v71; // ecx
  Scaleform::RefCountVImpl *v72; // ecx
  Scaleform::RefCountVImpl *v73; // ecx
  Scaleform::RefCountVImpl *v74; // [esp+3Ch] [ebp-4h]
  int j; // [esp+3Ch] [ebp-4h]

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
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->RemoveMovie(Instance, this);
  Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, 1);
  v10 = this->pRenderRoot.pObject;
  if ( v10 )
  {
    v7 = v10->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
  }
  this->pRenderRoot.pObject = 0;
  v11 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
  v12 = v11;
  v74 = (Scaleform::RefCountVImpl *)v11;
  if ( v11
    && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::State *, Scaleform::GFx::MovieImpl *))v11->__vftable[30].~Scaleform::GFx::State)(
         v11,
         this) )
  {
    v12->__vftable[32].~Scaleform::GFx::State(v12);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->pIMECandidateListStyle);
  v13 = this->pFontManagerStates.pObject;
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release(v13);
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
    Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy> *)&pRetValHolder->StringArray);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder);
  }
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  v18 = 0;
  if ( pLoadQueueMTHead )
  {
    do
    {
      ++v18;
      Scaleform::GFx::LoadQueueEntryMT::Cancel(pLoadQueueMTHead);
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
    }
    while ( pLoadQueueMTHead );
    if ( v18 )
    {
      do
      {
        v19 = this->pLoadQueueMTHead;
        for ( i = 0; v19; v19 = v19->pNext )
        {
          if ( v19->LoadFinished(v19) )
            ++i;
        }
      }
      while ( v18 > i );
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
    v22 = this->pLoadQueueMTHead;
    this->pLoadQueueMTHead = v22->pNext;
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntryMT *, int))v22->~Scaleform::GFx::LoadQueueEntryMT)(v22, 1);
  }
  v23 = this->TopmostLevelCharacters.Data.Size;
  p_TopmostLevelCharacters = &this->TopmostLevelCharacters;
  if ( v23 )
  {
    p_pObject = &p_TopmostLevelCharacters->Data.Data[v23 - 1].pObject;
    v26 = this->TopmostLevelCharacters.Data.Size;
    do
    {
      if ( *p_pObject )
        Scaleform::RefCountNTSImpl::Release(*p_pObject);
      --p_pObject;
      --v26;
    }
    while ( v26 );
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
  v28 = (Scaleform::RefCountVImpl *)this->pASMovieRoot.pObject;
  if ( v28 )
    Scaleform::RefCountImpl::Release(v28);
  this->pASMovieRoot.pObject = 0;
  v29 = this->pTopMostRoot.pObject;
  if ( v29 )
  {
    v7 = v29->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v29);
  }
  this->pTopMostRoot.pObject = 0;
  v30 = this->pRenderRoot.pObject;
  if ( v30 )
  {
    v7 = v30->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v30);
  }
  this->pRenderRoot.pObject = 0;
  v31 = this->hDisplayRoot.pData.pObject;
  if ( v31 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v31);
  this->hDisplayRoot.pData.pObject = 0;
  if ( v74 )
    Scaleform::RefCountImpl::Release(v74);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::IndirectTransPair>::DestructArray(
    this->IndirectTransformPairs.Data.Data,
    this->IndirectTransformPairs.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->IndirectTransformPairs.Data.Data);
  v32 = this->GestureTopMostChar.pObject;
  if ( v32 )
    Scaleform::RefCountNTSImpl::Release(v32);
  v33 = (Scaleform::RefCountVImpl *)this->MultitouchHAL.pObject;
  if ( v33 )
    Scaleform::RefCountImpl::Release(v33);
  v34 = (Scaleform::RefCountVImpl *)this->DIContext.pObject;
  if ( v34 )
    Scaleform::RefCountImpl::Release(v34);
  Scaleform::Render::ContextImpl::Context::~Context(&this->RenderContext);
  v35 = (Scaleform::RefCountVImpl *)this->pSavedASMovieRoot.pObject;
  if ( v35 )
    Scaleform::RefCountImpl::Release(v35);
  if ( this->MovieDefKillList.Data.Size )
  {
    p_pMovieDef = &this->MovieDefKillList.Data.Data[this->MovieDefKillList.Data.Size - 1].pMovieDef;
    v37 = this->MovieDefKillList.Data.Size;
    do
    {
      if ( p_pMovieDef->pObject )
        Scaleform::GFx::Resource::Release(p_pMovieDef->pObject);
      p_pMovieDef -= 4;
      --v37;
    }
    while ( v37 );
  }
  if ( this->MovieDefKillList.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MovieDefKillList.Data.Data);
  v38 = this->RegisteredFonts.Data.Size;
  v39 = &this->RegisteredFonts.Data.Data[v38 - 1];
  if ( v38 )
  {
    v40 = this->RegisteredFonts.Data.Size;
    do
    {
      v41 = v39->pFont.pObject;
      if ( v41 )
        Scaleform::GFx::Resource::Release(v41);
      if ( v39->pMovieDef.pObject )
        Scaleform::GFx::Resource::Release(v39->pMovieDef.pObject);
      --v39;
      --v40;
    }
    while ( v40 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RegisteredFonts.Data.Data);
  p_FocusGroupsCnt = &this->FocusGroupsCnt;
  for ( j = 15; j >= 0; --j )
  {
    v43 = (Scaleform::GFx::CharacterHandle *)*(p_FocusGroupsCnt - 10);
    p_FocusGroupsCnt -= 16;
    if ( v43 )
    {
      if ( --v43->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v43);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43);
      }
    }
    v44 = (_DWORD *)p_FocusGroupsCnt[5];
    if ( v44 )
    {
      v7 = (*v44)-- == 1;
      if ( v7 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v44);
    }
    v45 = p_FocusGroupsCnt[2];
    v46 = (Scaleform::RefCountNTSImpl **)(p_FocusGroupsCnt[1] + 4 * v45 - 4);
    if ( v45 )
    {
      v47 = p_FocusGroupsCnt[2];
      do
      {
        if ( *v46 )
          Scaleform::RefCountNTSImpl::Release(*v46);
        --v46;
        --v47;
      }
      while ( v47 );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)p_FocusGroupsCnt[1]);
    v48 = (Scaleform::Render::ContextImpl::Entry *)*p_FocusGroupsCnt;
    if ( *p_FocusGroupsCnt )
    {
      v7 = v48->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v48);
    }
  }
  v49 = this->FocusRectContainerNode.pObject;
  if ( v49 )
  {
    v7 = v49->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v49);
  }
  v50 = this->IntervalTimers.Data.Size;
  v51 = (Scaleform::RefCountVImpl **)&this->IntervalTimers.Data.Data[v50 - 1];
  if ( v50 )
  {
    v52 = this->IntervalTimers.Data.Size;
    do
    {
      if ( *v51 )
        Scaleform::RefCountImpl::Release(*v51);
      --v51;
      --v52;
    }
    while ( v52 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->IntervalTimers.Data.Data);
  v53 = this->TopmostLevelCharacters.Data.Size;
  v54 = &this->TopmostLevelCharacters.Data.Data[v53 - 1];
  if ( v53 )
  {
    v55 = this->TopmostLevelCharacters.Data.Size;
    do
    {
      if ( v54->pObject )
        Scaleform::RefCountNTSImpl::Release(v54->pObject);
      --v54;
      --v55;
    }
    while ( v55 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->TopmostLevelCharacters.Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StickyVariables);
  p_pRetValHolder = &this->pRetValHolder;
  for ( k = 5; k >= 0; --k )
  {
    p_pRetValHolder -= 415;
    Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)p_pRetValHolder);
  }
  p_MouseCursorCount = &this->MouseCursorCount;
  for ( m = 5; m >= 0; --m )
  {
    p_MouseCursorCount -= 14;
    Scaleform::GFx::MouseState::~MouseState((Scaleform::GFx::MouseState *)p_MouseCursorCount);
  }
  v60 = this->pFontManagerStates.pObject;
  if ( v60 )
    Scaleform::RefCountNTSImpl::Release(v60);
  v61 = (Scaleform::RefCountVImpl *)this->pExtIntfHandler.pObject;
  if ( v61 )
    Scaleform::RefCountImpl::Release(v61);
  v62 = (Scaleform::RefCountVImpl *)this->pFSCommandHandler.pObject;
  if ( v62 )
    Scaleform::RefCountImpl::Release(v62);
  v63 = (Scaleform::RefCountVImpl *)this->pUserEventHandler.pObject;
  if ( v63 )
    Scaleform::RefCountImpl::Release(v63);
  v64 = (Scaleform::RefCountVImpl *)this->pCachedLog.pObject;
  if ( v64 )
    Scaleform::RefCountImpl::Release(v64);
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::Clear(&this->VideoProviders);
  v65 = this->pTopMostRoot.pObject;
  if ( v65 )
  {
    v7 = v65->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v65);
  }
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&this->hDisplayRoot);
  v66 = this->pRenderRoot.pObject;
  if ( v66 )
  {
    v7 = v66->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v66);
  }
  v67 = (Scaleform::RefCountVImpl *)this->pStateBag.pObject;
  if ( v67 )
    Scaleform::RefCountImpl::Release(v67);
  v68 = this->MovieLevels.Data.Size;
  if ( v68 )
  {
    p_pSprite = &this->MovieLevels.Data.Data[v68 - 1].pSprite;
    v70 = this->MovieLevels.Data.Size;
    do
    {
      if ( p_pSprite->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pSprite->pObject);
      p_pSprite -= 2;
      --v70;
    }
    while ( v70 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MovieLevels.Data.Data);
  v71 = this->pMainMovieDef.pObject;
  if ( v71 )
    Scaleform::GFx::Resource::Release(v71);
  v72 = (Scaleform::RefCountVImpl *)this->AdvanceStats.pObject;
  if ( v72 )
    Scaleform::RefCountImpl::Release(v72);
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::MovieImpl_vtbl *)&Scaleform::GFx::Movie::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>'};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::Movie::`vftable'{for `Scaleform::GFx::StateBag'};
  v73 = (Scaleform::RefCountVImpl *)this->pASMovieRoot.pObject;
  if ( v73 )
    Scaleform::RefCountImpl::Release(v73);
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
