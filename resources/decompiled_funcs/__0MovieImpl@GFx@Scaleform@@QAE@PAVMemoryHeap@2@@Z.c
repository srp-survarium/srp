void __thiscall Scaleform::GFx::MovieImpl::MovieImpl(Scaleform::GFx::MovieImpl *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // eax
  Scaleform::ArrayDefaultPolicy *p_Policy; // ecx
  Scaleform::GFx::MouseState *mMouseState; // edi
  int i; // ebp
  Scaleform::GFx::KeyboardState *KeyboardStates; // edi
  int j; // ebp
  Scaleform::GFx::MovieImpl::DragState *CurrentDragStates; // ecx
  int v10; // edx
  float *p_y; // eax
  Scaleform::GFx::FocusGroupDescr *FocusGroups; // ebp
  Scaleform::ArrayDefaultPolicy *v13; // edi
  Scaleform::MemoryHeap *v14; // eax
  bool v15; // sf
  unsigned int *p_Size; // ecx
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // edi
  Scaleform::Render::TreeRoot::NodeData *v18; // eax
  Scaleform::Render::ContextImpl::EntryData *v19; // ebp
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeRoot *pObject; // ecx
  Scaleform::Render::TreeRoot *v22; // ebp
  bool v23; // zf
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::Render::TreeNode::NodeData *v25; // eax
  Scaleform::Render::TreeNode::NodeData *v26; // ebp
  Scaleform::Render::ContextImpl::Entry *v27; // eax
  Scaleform::Render::TreeContainer *v28; // ecx
  Scaleform::Render::TreeContainer *v29; // ebp
  Scaleform::Render::TreeRoot *v30; // ebp
  unsigned int Size; // eax
  Scaleform::MemoryHeap *v32; // ecx
  Scaleform::Lock *v33; // eax
  Scaleform::GFx::StateBagImpl *v34; // edi
  Scaleform::RefCountVImpl *v35; // ecx
  Scaleform::GFx::StateBagImpl *v36; // ecx
  unsigned __int8 v37; // al
  unsigned __int8 *p_KeyboardIndex; // ecx
  Scaleform::MemoryHeap *v39; // ecx
  Scaleform::GFx::FontManagerStates *v40; // eax
  Scaleform::GFx::StateBagImpl *v41; // ecx
  Scaleform::GFx::StateBag *v42; // ecx
  Scaleform::GFx::FontManagerStates *v43; // edi
  Scaleform::GFx::FontManagerStates *v44; // ecx
  unsigned __int64 v45; // rax
  Scaleform::Render::TreeContainer *v46; // [esp+8h] [ebp-18h]
  Scaleform::Render::ContextImpl::RTHandle v47; // [esp+1Ch] [ebp-4h] BYREF
  int pheapa; // [esp+24h] [ebp+4h]
  float pheapb; // [esp+24h] [ebp+4h]

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
  v10 = 5;
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
    --v10;
    *(p_y - 10) = 0.0;
    *(p_y - 7) = 0.0;
    *(p_y - 8) = 0.0;
    *(p_y - 6) = NAN;
  }
  while ( v10 >= 0 );
  this->StickyVariables.mHash.pTable = 0;
  this->TopmostLevelCharacters.Data.Data = 0;
  this->TopmostLevelCharacters.Data.Size = 0;
  this->TopmostLevelCharacters.Data.Policy.Capacity = 0;
  this->IntervalTimers.Data.Data = 0;
  this->IntervalTimers.Data.Size = 0;
  FocusGroups = this->FocusGroups;
  this->IntervalTimers.Data.Policy.Capacity = 0;
  this->FocusRectContainerNode.pObject = 0;
  pheapa = 15;
  v13 = &this->FocusGroups[0].TabableArray.Data.Policy;
  do
  {
    FocusGroups->FocusRectNode.pObject = 0;
    v14 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, FocusGroups);
    v13[-2].Capacity = 0;
    v13[-1].Capacity = 0;
    v13->Capacity = 0;
    v13[1].Capacity = (unsigned int)v14;
    v13[2].Capacity = 0;
    v13[3].Capacity = 0;
    v13[4].Capacity = 0;
    *(float *)&v13[5].Capacity = 0.0;
    *(float *)&v13[6].Capacity = 0.0;
    ++FocusGroups;
    *(float *)&v13[7].Capacity = 0.0;
    v13 += 16;
    v15 = --pheapa < 0;
    *(float *)&v13[-8].Capacity = 0.0;
    LOBYTE(v13[-7].Capacity) = 0;
    BYTE1(v13[-7].Capacity) = 0;
  }
  while ( !v15 );
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
  v18 = (Scaleform::Render::TreeRoot::NodeData *)p_RenderContext->pHeap->Alloc(p_RenderContext->pHeap, 208u, 0);
  v19 = v18;
  if ( v18 )
    Scaleform::Render::TreeRoot::NodeData::NodeData(v18);
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(&this->RenderContext, v19);
  pObject = this->pRenderRoot.pObject;
  v22 = (Scaleform::Render::TreeRoot *)EntryHelper;
  if ( pObject )
  {
    v23 = pObject->RefCount-- == 1;
    if ( v23 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pRenderRoot.pObject = v22;
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(&v47, v22);
  if ( v47.pData.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v47.pData.pObject);
  v24 = (Scaleform::RefCountVImpl *)this->hDisplayRoot.pData.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  this->hDisplayRoot = (Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot>)v47.pData.pObject;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v47);
  v25 = (Scaleform::Render::TreeNode::NodeData *)p_RenderContext->pHeap->Alloc(p_RenderContext->pHeap, 160u, 0);
  v26 = v25;
  if ( v25 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v25, ET_Container);
    v26->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v26[1].Type = 0;
    v26[1].__vftable = 0;
  }
  v27 = Scaleform::Render::ContextImpl::Context::createEntryHelper(
          &this->RenderContext,
          &v26->Scaleform::Render::ContextImpl::EntryData);
  v28 = this->pTopMostRoot.pObject;
  v29 = (Scaleform::Render::TreeContainer *)v27;
  if ( v28 )
  {
    v23 = v28->RefCount-- == 1;
    if ( v23 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v28);
  }
  this->pTopMostRoot.pObject = v29;
  v30 = this->pRenderRoot.pObject;
  v46 = this->pTopMostRoot.pObject;
  Size = Scaleform::Render::TreeContainer::GetSize(v30);
  Scaleform::Render::TreeContainer::Insert(v30, Size, v46);
  Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
  this->pMainMovie = 0;
  this->Flags |= 0x40180u;
  this->TimeRemainder = 0.0;
  v32 = this->pHeap;
  this->FrameTime = 0.083333336;
  this->pPlayListOptHead = 0;
  this->pPlayListHead = 0;
  LODWORD(this->TimeElapsed) = 0;
  HIDWORD(this->TimeElapsed) = 0;
  this->ForceFrameCatchUp = 0;
  this->pLoadQueueHead = 0;
  this->pLoadQueueMTHead = 0;
  v33 = (Scaleform::Lock *)v32->Alloc(v32, 48u, 0);
  v34 = (Scaleform::GFx::StateBagImpl *)v33;
  if ( v33 )
  {
    v33->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::RefCountImplCore::`vftable';
    v33->cs.LockCount = 1;
    v33->cs.RecursionCount = (int)&Scaleform::GFx::StateBag::`vftable';
    v33->cs.OwningThread = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
    v33->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>'};
    v33->cs.RecursionCount = (int)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::StateBag'};
    v33->cs.OwningThread = &Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>'};
    v33->cs.LockSemaphore = 0;
    v33->cs.SpinCount = 0;
    Scaleform::Lock::Lock(v33 + 1, 0);
    v35 = (Scaleform::RefCountVImpl *)v34->pDelegate.pObject;
    if ( v35 )
      Scaleform::RefCountImpl::Release(v35);
    v34->pDelegate.pObject = 0;
  }
  else
  {
    v34 = 0;
  }
  v36 = this->pStateBag.pObject;
  if ( v36 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v36);
  this->pStateBag.pObject = v34;
  v37 = 0;
  p_KeyboardIndex = &this->KeyboardStates[0].KeyboardIndex;
  do
  {
    *p_KeyboardIndex = v37++;
    p_KeyboardIndex += 1660;
  }
  while ( v37 < 6u );
  v39 = this->pHeap;
  this->pRetValHolder = 0;
  v40 = (Scaleform::GFx::FontManagerStates *)v39->Alloc(v39, 32u, 0);
  if ( v40 )
  {
    v41 = this->pStateBag.pObject;
    if ( v41 )
      v42 = &v41->Scaleform::GFx::StateBag;
    else
      v42 = 0;
    v40->RefCount = 1;
    v40->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
    v40->Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,327>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::FontManagerStates_vtbl *)&Scaleform::GFx::FontManagerStates::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>'};
    v40->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::FontManagerStates::`vftable'{for `Scaleform::GFx::StateBag'};
    v40->pFontLib.pObject = 0;
    v40->pFontMap.pObject = 0;
    v40->pFontProvider.pObject = 0;
    v40->pTranslator.pObject = 0;
    v40->pDelegate = v42;
    v43 = v40;
  }
  else
  {
    v43 = 0;
  }
  v44 = this->pFontManagerStates.pObject;
  if ( v44 )
    Scaleform::RefCountNTSImpl::Release(v44);
  this->pFontManagerStates.pObject = v43;
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
  v45 = Scaleform::Timer::GetTicks() / 0x3E8;
  LODWORD(this->StartTickMs) = v45;
  LODWORD(this->PauseTickMs) = 0;
  HIDWORD(this->PauseTickMs) = 0;
  HIDWORD(this->StartTickMs) = HIDWORD(v45);
  this->SafeRect.x1 = 0.0;
  this->SafeRect.y1 = 0.0;
  pheapb = 0.0 + 0.0;
  this->SafeRect.x2 = pheapb;
  this->SafeRect.y2 = pheapb;
  this->pAudio = 0;
  this->pSoundRenderer = 0;
  this->pObjectInterface = 0;
  this->LastLoadQueueEntryCnt = 0;
  this->pUnloadListHead = 0;
  this->MultitouchMode = MTI_None;
  this->PreviouslyCaptured = 0;
  this->FocusRectChanged = 1;
}
