void __thiscall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String ptargetChar,
        const __m128i *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v4; // bl
  Scaleform::GFx::DisplayObject *pData; // esi
  unsigned int v7; // eax
  int v8; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v9; // edi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::LoadQueueEntry *v11; // eax
  Scaleform::GFx::LoadQueueEntry *v12; // esi
  void *v13; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v14; // esi
  Scaleform::GFx::LoadQueueEntry *v15; // eax
  Scaleform::RefCountVImpl *v16; // eax
  Scaleform::String v17; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v17.pData = 0;
  pData = (Scaleform::GFx::DisplayObject *)ptargetChar.pData;
  if ( ptargetChar.pData )
  {
    if ( ((ptargetChar.pData[5].Size & 0x4000000) != 0 ? ptargetChar.HeapTypeBits : 0) != 0
      && (v7 = (ptargetChar.pData[5].Size & 0x4000000) != 0 ? ptargetChar.HeapTypeBits : 0,
          v8 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(v7 + 4 * *(unsigned __int8 *)(v7 + 65) + 24) + 120))(v7 + 4 * *(unsigned __int8 *)(v7 + 65) + 24),
          v8 != -1) )
    {
      v14 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v14 )
      {
        Scaleform::String::String(&v17, purl);
        v4 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v14, v8, &v17, method, 1, 0);
        v12 = v15;
      }
      else
      {
        v12 = 0;
      }
      if ( (v4 & 2) != 0 )
        Scaleform::String::~String(&v17);
    }
    else
    {
      v9 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v9 )
      {
        Scaleform::String::String(&ptargetChar, purl);
        pObject = pData->pNameHandle.pObject;
        v4 = 1;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pData);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v9, pObject, &ptargetChar, method, 1, 0);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( (v4 & 1) != 0 )
      {
        v13 = (void *)(ptargetChar.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((ptargetChar.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
      }
    }
    if ( v12 )
    {
      v16 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(
                                          &this->pMovieImpl->Scaleform::GFx::StateBag,
                                          21);
      if ( v16 )
      {
        Scaleform::RefCountImpl::Release(v16);
        Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, v12);
      }
      else
      {
        Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v12);
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::LoadVarsObject *ploadVars,
        const __m128i *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v5; // bl
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v6; // esi
  int v7; // eax
  int v8; // esi
  void *v9; // ebx
  Scaleform::RefCountVImpl *v10; // eax
  Scaleform::String url; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  url.pData = 0;
  v6 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
  if ( v6 )
  {
    Scaleform::String::String(&url, purl);
    v5 = 1;
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v6, &url, method, 1, 0);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  if ( (v5 & 1) != 0 )
  {
    v9 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  if ( v8 )
  {
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v8 + 52), ploadVars);
    v10 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v10 )
    {
      Scaleform::RefCountImpl::Release(v10);
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, (Scaleform::GFx::LoadQueueEntry *)v8);
    }
    else
    {
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v8);
    }
  }
}


void __thiscall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String ptarget,
        const __m128i *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v4; // bl
  Scaleform::String::DataDesc *pData; // ebp
  Scaleform::GFx::InteractiveObject *v7; // edi
  Scaleform::GFx::ASStringNode *v8; // eax
  int v9; // ecx
  unsigned int v10; // ebp
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v11; // ebp
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::LoadQueueEntry *v13; // eax
  Scaleform::GFx::LoadQueueEntry *v14; // ebp
  void *v15; // edi
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v17; // edi
  Scaleform::GFx::LoadQueueEntry *v18; // eax
  void *v19; // edi
  Scaleform::RefCountVImpl *v20; // eax
  Scaleform::String url; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  url.pData = 0;
  pData = ptarget.pData;
  ptarget.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                   this->BuiltinsMgr.pStringManager,
                                                   (__m128i *)ptarget.pData);
  ++ptarget.pData[1].Size;
  v7 = this->FindTarget(this, &ptarget);
  v8 = (Scaleform::GFx::ASStringNode *)ptarget.pData;
  --ptarget.pData[1].Size;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( !v7 )
  {
    ptarget.pData = (Scaleform::String::DataDesc *)uri;
    LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0);
    LOBYTE(url.pData) = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(LevelMovie) > 6;
    v10 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(
            (const char *)url.pData,
            0,
            (const char *)pData,
            (const char **)&ptarget,
            (bool)url.pData);
    if ( LOBYTE(ptarget.pData->Size) || v10 == -1 )
      return;
    goto LABEL_16;
  }
  if ( ((v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? (unsigned int)v7 : 0) != 0 )
  {
    v9 = *((v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
         ? &v7->AvmObjOffset
         : (unsigned __int8 *)65);
    v10 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(((v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
                                                            & 0x400) != 0
                                                           ? (unsigned int)v7
                                                           : 0)
                                                          + 4 * v9
                                                          + 0x18)
                                              + 120))(
            ((v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
           ? (unsigned int)v7
           : 0)
          + 4 * v9
          + 24);
    if ( v10 != -1 )
    {
LABEL_16:
      v17 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v17 )
      {
        Scaleform::String::String(&ptarget, purl);
        v4 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v17, v10, &ptarget, method, 1, 0);
        v14 = v18;
      }
      else
      {
        v14 = 0;
      }
      if ( (v4 & 2) != 0 )
      {
        v19 = (void *)(ptarget.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((ptarget.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
      }
      goto LABEL_22;
    }
  }
  v11 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
  if ( v11 )
  {
    Scaleform::String::String(&url, purl);
    pObject = v7->pNameHandle.pObject;
    v4 = 1;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v7);
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v11, pObject, &url, method, 1, 0);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  if ( (v4 & 1) != 0 )
  {
    v15 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  }
LABEL_22:
  if ( v14 )
  {
    v20 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v20 )
    {
      Scaleform::RefCountImpl::Release(v20);
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, v14);
    }
    else
    {
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v14);
    }
  }
}
