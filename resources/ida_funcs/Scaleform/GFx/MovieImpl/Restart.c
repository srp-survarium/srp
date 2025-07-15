void __userpurge Scaleform::GFx::MovieImpl::Restart(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        bool advance0)
{
  Scaleform::GFx::MovieDefImpl *v5; // eax
  int i; // edi
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // edi
  Scaleform::RefCountVImpl *v8; // ebp
  Scaleform::GFx::LoadQueueEntryMT *v9; // edi
  unsigned int j; // ebp
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // ecx
  Scaleform::GFx::LoadQueueEntryMT *v12; // ecx
  Scaleform::GFx::Resource *v13; // edi
  Scaleform::GFx::InteractiveObject *pMainMovie; // eax
  Scaleform::GFx::InteractiveObject *v15; // ecx
  Scaleform::GFx::MovieImpl::ReturnValueHolder *pRetValHolder; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::MouseState *mMouseState; // edi
  int v20; // ebp
  unsigned int k; // edi
  Scaleform::GFx::UserEventHandler *pObject; // ecx
  Scaleform::GFx::UserEventHandler *v23; // ecx
  Scaleform::GFx::KeyboardState *KeyboardStates; // edi
  int v25; // ebp
  int v26; // [esp+48h] [ebp-3Ch]
  int v27; // [esp+4Ch] [ebp-38h]
  Scaleform::RefCountVImpl *pIMEManager; // [esp+5Ch] [ebp-28h]
  Scaleform::GFx::Resource *v29; // [esp+60h] [ebp-24h]
  Scaleform::GFx::Resource *v30; // [esp+64h] [ebp-20h] BYREF
  char v31; // [esp+68h] [ebp-1Ch]
  int v32; // [esp+6Ch] [ebp-18h]
  unsigned int v33; // [esp+70h] [ebp-14h]
  int v34; // [esp+74h] [ebp-10h] BYREF
  char v35; // [esp+78h] [ebp-Ch]
  int v36; // [esp+7Ch] [ebp-8h]
  unsigned int v37; // [esp+80h] [ebp-4h]

  if ( this->pMainMovie )
  {
    this->Flags2 |= 4u;
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
    v5 = this->pMainMovie->GetResourceMovieDef(this->pMainMovie);
    v29 = v5;
    if ( v5 )
      Scaleform::RefCountImpl::AddRef(v5);
    v27 = a3;
    for ( i = this->MovieLevels.Data.Size - 1; i >= 0; --i )
      Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this, i);
    v26 = a2;
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->MovieLevels.Data,
      &this->MovieLevels,
      0);
    pLoadQueueMTHead = this->pLoadQueueMTHead;
    v8 = 0;
    if ( pLoadQueueMTHead )
    {
      do
      {
        v8 = (Scaleform::RefCountVImpl *)((char *)v8 + 1);
        Scaleform::GFx::LoadQueueEntryMT::Cancel(pLoadQueueMTHead);
        pLoadQueueMTHead = pLoadQueueMTHead->pNext;
      }
      while ( pLoadQueueMTHead );
      pIMEManager = v8;
      if ( v8 )
      {
        do
        {
          v9 = this->pLoadQueueMTHead;
          for ( j = 0; v9; v9 = v9->pNext )
          {
            if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::LoadQueueEntryMT *, int, int))v9->LoadFinished)(
                   v9,
                   v26,
                   v27) )
            {
              ++j;
            }
          }
        }
        while ( (unsigned int)pIMEManager > j );
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
      v12 = this->pLoadQueueMTHead;
      this->pLoadQueueMTHead = v12->pNext;
      ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntryMT *, int))v12->~Scaleform::GFx::LoadQueueEntryMT)(v12, 1);
    }
    this->pLoadQueueHead = 0;
    this->pLoadQueueMTHead = 0;
    this->Flags |= 0x80000u;
    this->pPlayListOptHead = 0;
    this->pPlayListHead = 0;
    v13 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::GFx::StateBag *, int, int, int))this->GetStateAddRef)(
                                        &this->Scaleform::GFx::StateBag,
                                        24,
                                        v26,
                                        v27);
    v30 = v13;
    if ( v13
      && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::MovieImpl *))v13->__vftable[7].GetResourceTypeCode)(
           v13,
           this) )
    {
      HIBYTE(v29) = 1;
      v13->__vftable[7].GetKey(v13, 0);
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->pIMECandidateListStyle);
    this->pIMECandidateListStyle = 0;
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::Clear(&this->VideoProviders);
    pMainMovie = this->pMainMovie;
    if ( pMainMovie )
    {
      v15 = (pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
          ? pMainMovie
          : 0;
      v15->StopActiveSounds(v15);
    }
    this->pASMovieRoot.pObject->Shutdown(this->pASMovieRoot.pObject);
    Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(this);
    pRetValHolder = this->pRetValHolder;
    if ( pRetValHolder )
    {
      if ( pRetValHolder->CharBuffer )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder->CharBuffer);
      pNode = pRetValHolder->StringArray.Data.DefaultValue.pNode;
      if ( pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&pRetValHolder->StringArray.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder);
    }
    this->pRetValHolder = 0;
    Scaleform::GFx::MovieImpl::ResetFocusStates(this);
    this->Flags &= (unsigned int)&byte_3FFFFF;
    mMouseState = this->mMouseState;
    v20 = 6;
    do
    {
      Scaleform::GFx::MouseState::ResetState(mMouseState++);
      --v20;
    }
    while ( v20 );
    this->pASMovieRoot.pObject->ForceCollect(this->pASMovieRoot.pObject, 2u);
    this->Flags2 &= ~4u;
    this->pASMovieRoot.pObject->Init(this->pASMovieRoot.pObject, (Scaleform::GFx::MovieDefImpl *)v30);
    if ( this->pMainMovie )
    {
      if ( this->pUserEventHandler.pObject )
      {
        for ( k = 0; k < this->MouseCursorCount; ++k )
        {
          pObject = this->pUserEventHandler.pObject;
          v31 = 0;
          v30 = (Scaleform::GFx::Resource *)21;
          v32 = 0;
          v33 = k;
          pObject->HandleEvent(pObject, this, (const Scaleform::GFx::Event *)&v30);
          v23 = this->pUserEventHandler.pObject;
          v35 = 0;
          v34 = 23;
          v36 = 0;
          v37 = k;
          v23->HandleEvent(v23, this, (const Scaleform::GFx::Event *)&v34);
        }
      }
      this->FocusRectChanged = 1;
      KeyboardStates = this->KeyboardStates;
      v25 = 6;
      do
      {
        Scaleform::GFx::KeyboardState::ResetState(KeyboardStates++);
        --v25;
      }
      while ( v25 );
      if ( advance0 )
        ((void (__thiscall *)(Scaleform::GFx::MovieImpl *, _DWORD, _DWORD, int))this->Advance)(this, 0.0, 0, 1);
      this->pASMovieRoot.pObject->ForceCollect(this->pASMovieRoot.pObject, 2u);
      if ( pIMEManager )
        Scaleform::RefCountImpl::Release(pIMEManager);
      if ( v29 )
        Scaleform::GFx::Resource::Release(v29);
    }
    else
    {
      if ( pIMEManager )
        Scaleform::RefCountImpl::Release(pIMEManager);
      if ( v30 )
        Scaleform::GFx::Resource::Release(v30);
    }
  }
}
