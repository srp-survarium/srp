void __thiscall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String ptargetChar,
        const __m128i *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  int v5; // ebx
  Scaleform::GFx::DisplayObject *pData; // esi
  unsigned int v8; // eax
  int v9; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v10; // edi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  int v12; // eax
  int v13; // esi
  void *v14; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v15; // esi
  int v16; // eax
  Scaleform::String v17; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  v17.pData = 0;
  pData = (Scaleform::GFx::DisplayObject *)ptargetChar.pData;
  if ( ptargetChar.pData )
  {
    if ( ((ptargetChar.pData[5].Size & 0x4000000) != 0 ? ptargetChar.HeapTypeBits : 0) != 0
      && (v8 = (ptargetChar.pData[5].Size & 0x4000000) != 0 ? ptargetChar.HeapTypeBits : 0,
          v9 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(v8 + 4 * *(unsigned __int8 *)(v8 + 65) + 24) + 120))(v8 + 4 * *(unsigned __int8 *)(v8 + 65) + 24),
          v9 != -1) )
    {
      v15 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v15 )
      {
        Scaleform::String::String(&v17, purl);
        v5 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v15, v9, &v17, method, 0, 0);
        v13 = v16;
      }
      else
      {
        v13 = 0;
      }
      if ( (v5 & 2) != 0 )
        Scaleform::String::~String(&v17);
    }
    else
    {
      v10 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v10 )
      {
        Scaleform::String::String(&ptargetChar, purl);
        pObject = pData->pNameHandle.pObject;
        v5 = 1;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pData);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v10, pObject, &ptargetChar, method, 0, 0);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      if ( (v5 & 1) != 0 )
      {
        v14 = (void *)(ptargetChar.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((ptargetChar.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
      }
    }
    if ( v13 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v13 + 36), pmovieClipLoader);
      Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(this, v5, v13, (Scaleform::GFx::LoadQueueEntry *)v13);
    }
  }
}


void __thiscall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String ptarget,
        const __m128i *purl,
        Scaleform::String env,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  Scaleform::String::DataDesc *pData; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  int v9; // ebx
  Scaleform::String::DataDesc *StringNode; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::DisplayObject *v12; // ebp
  Scaleform::GFx::ASStringNode *v13; // eax
  int v15; // ecx
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v16; // esi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  int v18; // eax
  int v19; // ebp
  Scaleform::GFx::Sprite *LevelMovie; // eax
  unsigned int v21; // eax
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v22; // ebp
  int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // [esp+10h] [ebp-4h] BYREF

  v24 = 0;
  pData = env.pData;
  pStringManager = this->BuiltinsMgr.pStringManager;
  if ( env.pData )
  {
    v9 = 1;
    StringNode = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                  pStringManager,
                                                  (__m128i *)ptarget.pData);
    ++StringNode[1].Size;
    env.pData = StringNode;
    Target = Scaleform::GFx::AS2::Environment::FindTarget(
               (Scaleform::GFx::AS2::Environment *)pData,
               (const Scaleform::GFx::ASString *)&env,
               0);
  }
  else
  {
    v9 = 2;
    v24 = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, (__m128i *)ptarget.pData);
    ++v24->RefCount;
    Target = this->FindTarget(this, &v24);
    StringNode = env.pData;
  }
  v12 = Target;
  if ( (v9 & 2) != 0 )
  {
    v13 = v24;
    --v24->RefCount;
    v9 &= ~2u;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  if ( (v9 & 1) != 0 )
  {
    v9 &= ~1u;
    if ( StringNode[1].Size-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)StringNode);
  }
  if ( v12 )
  {
    if ( ((v12->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? (unsigned int)v12 : 0) == 0
      || (v15 = *((v12->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
                ? &v12->AvmObjOffset
                : (unsigned __int8 *)65),
          v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)(((v12->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? (unsigned int)v12 : 0) + 4 * v15 + 0x18)
                                                                                                 + 120))(
                                                               ((v12->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
                                                              ? (unsigned int)v12
                                                              : 0)
                                                             + 4 * v15
                                                             + 24),
          v16 == (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)-1) )
    {
      v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v16 )
      {
        Scaleform::String::String(&ptarget, purl);
        pObject = v12->pNameHandle.pObject;
        v9 |= 4u;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v12);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v16, pObject, &ptarget, method, 0, 0);
        v19 = v18;
      }
      else
      {
        v19 = 0;
      }
      if ( (v9 & 4) == 0 )
        goto LABEL_29;
      v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(ptarget.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((ptarget.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
        goto LABEL_29;
LABEL_28:
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
LABEL_29:
      if ( v19 )
      {
        Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v19 + 36), pmovieClipLoader);
        Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(
          this,
          v9,
          (int)v16,
          (Scaleform::GFx::LoadQueueEntry *)v19);
      }
      return;
    }
LABEL_23:
    v22 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
    if ( v22 )
    {
      Scaleform::String::String(&env, purl);
      v9 |= 8u;
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v22, (int)v16, &env, method, 0, 0);
      v19 = v23;
    }
    else
    {
      v19 = 0;
    }
    if ( (v9 & 8) == 0 )
      goto LABEL_29;
    v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(env.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((env.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
      goto LABEL_29;
    goto LABEL_28;
  }
  env.pData = (Scaleform::String::DataDesc *)uri;
  LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0);
  LOBYTE(v24) = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(LevelMovie) > 6;
  v21 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(
          (const char *)v24,
          v9,
          (const char *)ptarget.pData,
          (const char **)&env,
          (bool)v24);
  v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v21;
  if ( !LOBYTE(env.pData->Size) && v21 != -1 )
    goto LABEL_23;
}
