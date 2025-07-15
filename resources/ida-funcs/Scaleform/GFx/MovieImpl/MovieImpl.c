void __userpurge Scaleform::GFx::MovieImpl::MovieImpl(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebp>,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // eax
  Scaleform::ArrayDefaultPolicy *p_Policy; // ecx
  Scaleform::GFx::MouseState *mMouseState; // edi
  int i; // ebp
  Scaleform::GFx::KeyboardState *KeyboardStates; // edi
  int j; // ebp
  Scaleform::GFx::MovieImpl::DragState *CurrentDragStates; // ecx
  int v11; // edx
  float *p_y; // eax
  Scaleform::GFx::FocusGroupDescr *FocusGroups; // ebp
  Scaleform::ArrayDefaultPolicy *v14; // edi
  Scaleform::MemoryHeap *v15; // eax
  bool v16; // sf
  unsigned int *p_Size; // ecx
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // edi
  Scaleform::Render::TreeRoot::NodeData *v19; // eax
  Scaleform::Render::ContextImpl::EntryData *v20; // ebp
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeRoot *pObject; // ecx
  Scaleform::Render::TreeRoot *v23; // ebp
  bool v24; // zf
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v25; // ecx
  Scaleform::Render::TreeNode::NodeData *v26; // eax
  Scaleform::Render::TreeNode::NodeData *v27; // ebp
  Scaleform::Render::ContextImpl::Entry *v28; // eax
  Scaleform::Render::TreeContainer *v29; // ecx
  Scaleform::Render::TreeContainer *v30; // ebp
  Scaleform::Render::TreeRoot *v31; // ebp
  unsigned int Size; // eax
  Scaleform::MemoryHeap *v33; // ecx
  Scaleform::Lock *v34; // eax
  Scaleform::GFx::StateBagImpl *v35; // edi
  Scaleform::RefCountVImpl *v36; // ecx
  Scaleform::RefCountVImpl *v37; // ecx
  unsigned __int8 v38; // al
  unsigned __int8 *p_KeyboardIndex; // ecx
  Scaleform::MemoryHeap *v40; // ecx
  Scaleform::GFx::FontManagerStates *v41; // eax
  Scaleform::GFx::StateBagImpl *v42; // ecx
  Scaleform::GFx::StateBag *v43; // ecx
  Scaleform::GFx::FontManagerStates *v44; // edi
  Scaleform::GFx::FontManagerStates *v45; // ecx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v47; // eax
  Scaleform::GFx::AMP::ViewStats *v48; // eax
  Scaleform::GFx::AMP::ViewStats *v49; // eax
  Scaleform::GFx::AMP::ViewStats *v50; // edi
  Scaleform::RefCountVImpl *v51; // ecx
  Scaleform::AmpServer *v52; // eax
  Scaleform::GFx::AMP::ViewStats *v53; // eax
  Scaleform::GFx::AMP::ViewStats *v54; // eax
  Scaleform::GFx::AMP::ViewStats *v55; // edi
  Scaleform::RefCountVImpl *v56; // ecx
  Scaleform::Render::TreeContainer *v58; // [esp+10h] [ebp-18h]
  Scaleform::Render::ContextImpl::RTHandle v59; // [esp+24h] [ebp-4h] BYREF
  int v60; // [esp+2Ch] [ebp+4h]
  float v61; // [esp+2Ch] [ebp+4h]

  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::MovieImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  this->pASMovieRoot.pObject = 0;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::MovieImpl_vtbl *)&Scaleform::GFx::MovieImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>'};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::MovieImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  this->AdvanceStats.pObject = 0;
  this->pHeap = pheap;
  this->pMainMovieDef.pObject = 0;
  p_RootMovieDefNodes = &this->RootMovieDefNodes;
  this->MovieLevels.Data.Data = 0;
  this->MovieLevels.Data.Size = 0;
  this->MovieLevels.Data.Policy.Capacity = 0;
  if ( this == (Scaleform::GFx::MovieImpl *)-56 )
    p_Policy = 0;
  else
    p_Policy = &this->MovieLevels.Data.Policy;
  p_RootMovieDefNodes->Root.pPrev = (Scaleform::GFx::MovieDefRootNode *)p_Policy;
  p_RootMovieDefNodes->Root.pNext = (Scaleform::GFx::MovieDefRootNode *)p_Policy;
  this->pStateBag.pObject = 0;
  this->pRenderRoot.pObject = 0;
  this->hDisplayRoot.pData.pObject = 0;
  this->pTopMostRoot.pObject = 0;
  this->mViewport.AspectRatio = 1.0;
  this->mViewport.Scale = 1.0;
  this->mViewport.BufferWidth = 0;
  this->mViewport.BufferHeight = 0;
  this->mViewport.Top = 0;
  this->mViewport.Left = 0;
  this->mViewport.Height = 1;
  this->mViewport.Width = 1;
  this->mViewport.ScissorHeight = 0;
  this->mViewport.ScissorWidth = 0;
  this->mViewport.ScissorTop = 0;
  this->mViewport.ScissorLeft = 0;
  this->mViewport.Flags = 0;
  this->PixelScale = 1.0;
  this->VisibleFrameRect.x1 = 0.0;
  this->VisibleFrameRect.y1 = 0.0;
  this->VisibleFrameRect.x2 = 0.0;
  this->VisibleFrameRect.y2 = 0.0;
  this->SafeRect.x1 = 0.0;
  this->SafeRect.y1 = 0.0;
  this->SafeRect.x2 = 0.0;
  this->SafeRect.y2 = 0.0;
  this->ViewportMatrix.M[0][1] = 0.0;
  this->ViewportMatrix.M[0][2] = 0.0;
  this->ViewportMatrix.M[0][3] = 0.0;
  this->ViewportMatrix.M[1][0] = 0.0;
  this->ViewportMatrix.M[1][2] = 0.0;
  this->ViewportMatrix.M[1][3] = 0.0;
  this->ViewportMatrix.M[0][0] = 1.0;
  this->ViewportMatrix.M[1][1] = 1.0;
  Scaleform::Render::ScreenToWorld::ScreenToWorld(&this->ScreenToWorld);
  this->VideoProviders.pTable = 0;
  this->pCachedLog.pObject = 0;
  this->pUserEventHandler.pObject = 0;
  this->pFSCommandHandler.pObject = 0;
  this->pExtIntfHandler.pObject = 0;
  this->pFontManagerStates.pObject = 0;
  this->pXMLObjectManager = 0;
  Scaleform::GFx::InputEventsQueue::InputEventsQueue(&this->InputEventsQueue);
  this->BackgroundColor.Channels.Red = 0;
  this->BackgroundColor.Channels.Green = 0;
  this->BackgroundColor.Channels.Blue = 0;
  this->BackgroundColor.Channels.Alpha = -1;
  mMouseState = this->mMouseState;
  for ( i = 5; i >= 0; --i )
    Scaleform::GFx::MouseState::MouseState(mMouseState++);
  this->MouseCursorCount = 1;
  this->ControllerCount = 1;
  this->UserData = 0;
  KeyboardStates = this->KeyboardStates;
  for ( j = 5; j >= 0; --j )
    Scaleform::GFx::KeyboardState::KeyboardState(KeyboardStates++);
  CurrentDragStates = this->CurrentDragStates;
  v11 = 5;
  p_y = &this->CurrentDragStates[0].BoundRB.y;
  do
  {
    CurrentDragStates->pCharacter = 0;
    *((_BYTE *)p_y - 16) = 0;
    *((_BYTE *)p_y - 15) = 0;
    *(p_y - 2) = 0.0;
    *(p_y - 3) = 0.0;
    ++CurrentDragStates;
    *p_y = 0.0;
    p_y += 9;
    --v11;
    *(p_y - 10) = 0.0;
    *(p_y - 7) = 0.0;
    *(p_y - 8) = 0.0;
    *(p_y - 6) = NAN;
  }
  while ( v11 >= 0 );
  this->StickyVariables.mHash.pTable = 0;
  this->TopmostLevelCharacters.Data.Data = 0;
  this->TopmostLevelCharacters.Data.Size = 0;
  this->TopmostLevelCharacters.Data.Policy.Capacity = 0;
  this->IntervalTimers.Data.Data = 0;
  this->IntervalTimers.Data.Size = 0;
  FocusGroups = this->FocusGroups;
  this->IntervalTimers.Data.Policy.Capacity = 0;
  this->FocusRectContainerNode.pObject = 0;
  v60 = 15;
  v14 = &this->FocusGroups[0].TabableArray.Data.Policy;
  do
  {
    FocusGroups->FocusRectNode.pObject = 0;
    v15 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, FocusGroups);
    v14[-2].Capacity = 0;
    v14[-1].Capacity = 0;
    v14->Capacity = 0;
    v14[1].Capacity = (unsigned int)v15;
    v14[2].Capacity = 0;
    v14[3].Capacity = 0;
    v14[4].Capacity = 0;
    *(float *)&v14[5].Capacity = 0.0;
    *(float *)&v14[6].Capacity = 0.0;
    ++FocusGroups;
    *(float *)&v14[7].Capacity = 0.0;
    v14 += 16;
    v16 = --v60 < 0;
    *(float *)&v14[-8].Capacity = 0.0;
    LOBYTE(v14[-7].Capacity) = 0;
    BYTE1(v14[-7].Capacity) = 0;
  }
  while ( !v16 );
  this->Flags = 0;
  this->Flags2 = 0;
  this->RegisteredFonts.Data.Data = 0;
  this->RegisteredFonts.Data.Size = 0;
  this->RegisteredFonts.Data.Policy.Capacity = 0;
  if ( this == (Scaleform::GFx::MovieImpl *)-16272 )
    p_Size = 0;
  else
    p_Size = &this->RegisteredFonts.Data.Size;
  this->DrawingContextList.Root.pPrev = (Scaleform::GFx::DrawingContext *)p_Size;
  this->DrawingContextList.Root.pNext = (Scaleform::GFx::DrawingContext *)p_Size;
  this->MovieDefKillList.Data.Data = 0;
  this->MovieDefKillList.Data.Size = 0;
  this->MovieDefKillList.Data.Policy.Capacity = 0;
  this->pSavedASMovieRoot.pObject = 0;
  p_RenderContext = &this->RenderContext;
  Scaleform::Render::ContextImpl::Context::Context(
    &this->RenderContext,
    (int)&this->RenderContext,
    Scaleform::Memory::pGlobalHeap);
  this->DIContext.pObject = 0;
  this->pRTCommandQueue = 0;
  this->MultitouchHAL.pObject = 0;
  this->GestureTopMostChar.pObject = 0;
  this->IndirectTransformPairs.Data.Data = 0;
  this->IndirectTransformPairs.Data.Size = 0;
  this->IndirectTransformPairs.Data.Policy.Capacity = 0;
  v19 = (Scaleform::Render::TreeRoot::NodeData *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))p_RenderContext->pHeap->Alloc)(
                                                   p_RenderContext->pHeap,
                                                   208,
                                                   0,
                                                   a2);
  v20 = v19;
  if ( v19 )
    Scaleform::Render::TreeRoot::NodeData::NodeData(v19);
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(&this->RenderContext, v20);
  pObject = this->pRenderRoot.pObject;
  v23 = (Scaleform::Render::TreeRoot *)EntryHelper;
  if ( pObject )
  {
    v24 = pObject->RefCount-- == 1;
    if ( v24 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pRenderRoot.pObject = v23;
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(&v59, v23);
  if ( v59.pData.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v59.pData.pObject);
  v25 = this->hDisplayRoot.pData.pObject;
  if ( v25 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v25);
  this->hDisplayRoot = (Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot>)v59.pData.pObject;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v59);
  v26 = (Scaleform::Render::TreeNode::NodeData *)p_RenderContext->pHeap->Alloc(p_RenderContext->pHeap, 160u, 0);
  v27 = v26;
  if ( v26 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v26, ET_Container);
    v27->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v27[1].Type = 0;
    v27[1].__vftable = 0;
  }
  v28 = Scaleform::Render::ContextImpl::Context::createEntryHelper(
          &this->RenderContext,
          &v27->Scaleform::Render::ContextImpl::EntryData);
  v29 = this->pTopMostRoot.pObject;
  v30 = (Scaleform::Render::TreeContainer *)v28;
  if ( v29 )
  {
    v24 = v29->RefCount-- == 1;
    if ( v24 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v29);
  }
  this->pTopMostRoot.pObject = v30;
  v31 = this->pRenderRoot.pObject;
  v58 = this->pTopMostRoot.pObject;
  Size = Scaleform::Render::TreeContainer::GetSize(v31);
  Scaleform::Render::TreeContainer::Insert(v31, Size, (Scaleform::Render::TreeNodeArray *)v58);
  Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
  this->pMainMovie = 0;
  this->Flags |= (unsigned int)&loc_4017F + 1;
  this->TimeRemainder = 0.0;
  v33 = this->pHeap;
  this->FrameTime = 0.083333336;
  this->pPlayListOptHead = 0;
  this->pPlayListHead = 0;
  LODWORD(this->TimeElapsed) = 0;
  HIDWORD(this->TimeElapsed) = 0;
  this->ForceFrameCatchUp = 0;
  this->pLoadQueueHead = 0;
  this->pLoadQueueMTHead = 0;
  v34 = (Scaleform::Lock *)v33->Alloc(v33, 48u, 0);
  v35 = (Scaleform::GFx::StateBagImpl *)v34;
  if ( v34 )
  {
    v34->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::RefCountImplCore::`vftable';
    v34->cs.LockCount = 1;
    v34->cs.RecursionCount = (int)&Scaleform::GFx::StateBag::`vftable';
    v34->cs.OwningThread = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
    v34->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>'};
    v34->cs.RecursionCount = (int)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::StateBag'};
    v34->cs.OwningThread = &Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>'};
    v34->cs.LockSemaphore = 0;
    v34->cs.SpinCount = 0;
    Scaleform::Lock::Lock(v34 + 1, 0);
    v36 = (Scaleform::RefCountVImpl *)v35->pDelegate.pObject;
    if ( v36 )
      Scaleform::RefCountImpl::Release(v36);
    v35->pDelegate.pObject = 0;
  }
  else
  {
    v35 = 0;
  }
  v37 = (Scaleform::RefCountVImpl *)this->pStateBag.pObject;
  if ( v37 )
    Scaleform::RefCountImpl::Release(v37);
  this->pStateBag.pObject = v35;
  v38 = 0;
  p_KeyboardIndex = &this->KeyboardStates[0].KeyboardIndex;
  do
  {
    *p_KeyboardIndex = v38++;
    p_KeyboardIndex += 1660;
  }
  while ( v38 < 6u );
  v40 = this->pHeap;
  this->pRetValHolder = 0;
  v41 = (Scaleform::GFx::FontManagerStates *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))v40->Alloc)(v40, 32);
  if ( v41 )
  {
    v42 = this->pStateBag.pObject;
    if ( v42 )
      v43 = &v42->Scaleform::GFx::StateBag;
    else
      v43 = 0;
    v41->RefCount = 1;
    v41->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
    v41->Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,327>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::FontManagerStates_vtbl *)&Scaleform::GFx::FontManagerStates::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>'};
    v41->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::FontManagerStates::`vftable'{for `Scaleform::GFx::StateBag'};
    v41->pFontLib.pObject = 0;
    v41->pFontMap.pObject = 0;
    v41->pFontProvider.pObject = 0;
    v41->pTranslator.pObject = 0;
    v41->pDelegate = v43;
    v44 = v41;
  }
  else
  {
    v44 = 0;
  }
  v45 = this->pFontManagerStates.pObject;
  if ( v45 )
    Scaleform::RefCountNTSImpl::Release(v45);
  this->pFontManagerStates.pObject = v44;
  this->ViewScaleX = 1.0;
  this->InstanceNameCount = 0;
  this->ViewScaleY = 1.0;
  this->ViewScaleMode = SM_ShowAll;
  this->ViewAlignment = Align_Center;
  this->ViewOffsetY = 0.0;
  this->FocusGroupsCnt = 1;
  this->ViewOffsetX = 0.0;
  *(_DWORD *)this->FocusGroupIndexes = 0;
  *(_DWORD *)&this->FocusGroupIndexes[4] = 0;
  *(_DWORD *)&this->FocusGroupIndexes[8] = 0;
  *(_DWORD *)&this->FocusGroupIndexes[12] = 0;
  this->LastIntervalTimerId = 0;
  this->pIMECandidateListStyle = 0;
  this->StartTickMs = Scaleform::Timer::GetTicks() / 0x3E8;
  LODWORD(this->PauseTickMs) = 0;
  HIDWORD(this->PauseTickMs) = 0;
  this->SafeRect.x1 = 0.0;
  this->SafeRect.y1 = 0.0;
  v61 = 0.0 + 0.0;
  this->SafeRect.x2 = v61;
  this->SafeRect.y2 = v61;
  this->pAudio = 0;
  this->pSoundRenderer = 0;
  this->pObjectInterface = 0;
  this->LastLoadQueueEntryCnt = 0;
  this->pUnloadListHead = 0;
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->IsEnabled(Instance) )
  {
    v47 = Scaleform::AmpServer::GetInstance();
    v59.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)2;
    v48 = (Scaleform::GFx::AMP::ViewStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              v47,
                                              288,
                                              &v59);
    if ( v48 )
    {
      Scaleform::GFx::AMP::ViewStats::ViewStats(v48);
      v50 = v49;
    }
    else
    {
      v50 = 0;
    }
    v51 = (Scaleform::RefCountVImpl *)this->AdvanceStats.pObject;
    if ( v51 )
      Scaleform::RefCountImpl::Release(v51);
    this->AdvanceStats.pObject = v50;
    v52 = Scaleform::AmpServer::GetInstance();
    v52->AddMovie(v52, this);
  }
  else
  {
    v53 = (Scaleform::GFx::AMP::ViewStats *)this->pHeap->Alloc(this->pHeap, 288, 0);
    if ( v53 )
    {
      Scaleform::GFx::AMP::ViewStats::ViewStats(v53);
      v55 = v54;
    }
    else
    {
      v55 = 0;
    }
    v56 = (Scaleform::RefCountVImpl *)this->AdvanceStats.pObject;
    if ( v56 )
      Scaleform::RefCountImpl::Release(v56);
    this->AdvanceStats.pObject = v55;
  }
  this->MultitouchMode = MTI_None;
  this->PreviouslyCaptured = 0;
  this->FocusRectChanged = 1;
}
