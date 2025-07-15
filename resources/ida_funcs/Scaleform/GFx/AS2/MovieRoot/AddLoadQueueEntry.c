void __thiscall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ptargetChar,
        char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  int v5; // ebx
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::GFx::InteractiveObject *v8; // eax
  int v9; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v10; // edi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  int v12; // eax
  int v13; // esi
  void *v14; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v15; // esi
  int v16; // eax
  Scaleform::String url; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  url.pData = 0;
  v6 = ptargetChar;
  if ( ptargetChar )
  {
    if ( ((ptargetChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
        ? (unsigned int)ptargetChar
        : 0) != 0
      && (v8 = (ptargetChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
             ? ptargetChar
             : 0,
          v9 = (*(int (__thiscall **)(int *))(*(&v8->Depth + v8->AvmObjOffset) + 120))(&v8->Depth + v8->AvmObjOffset),
          v9 != -1) )
    {
      v15 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v15 )
      {
        Scaleform::String::String(&url, purl);
        v5 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v15, v9, &url, method, 0, 0);
        v13 = v16;
      }
      else
      {
        v13 = 0;
      }
      if ( (v5 & 2) != 0 )
        Scaleform::String::~String(&url);
    }
    else
    {
      v10 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v10 )
      {
        Scaleform::String::String((Scaleform::String *)&ptargetChar, purl);
        pObject = v6->pNameHandle.pObject;
        v5 = 1;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v6);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          v10,
          pObject,
          (const Scaleform::String *)&ptargetChar,
          method,
          0,
          0);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      if ( (v5 & 1) != 0 )
      {
        v14 = (void *)((unsigned int)ptargetChar & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)ptargetChar & 0xFFFFFFFC) + 4), -1) == 1 )
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
        char *ptarget,
        char *purl,
        Scaleform::GFx::AS2::Environment *env,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  Scaleform::GFx::AS2::Environment *v6; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  unsigned int v9; // ebx
  Scaleform::GFx::AS2::Environment *StringNode; // esi
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
  v6 = env;
  pStringManager = this->BuiltinsMgr.pStringManager;
  if ( env )
  {
    v9 = 1;
    StringNode = (Scaleform::GFx::AS2::Environment *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                       pStringManager,
                                                       ptarget);
    ++StringNode->Stack.pPageEnd;
    env = StringNode;
    Target = Scaleform::GFx::AS2::Environment::FindTarget(v6, (const Scaleform::GFx::ASString *)&env, 0);
  }
  else
  {
    v9 = 2;
    v24 = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, ptarget);
    ++v24->RefCount;
    Target = this->FindTarget(this, &v24);
    StringNode = env;
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
    if ( StringNode->Stack.pPageEnd-- == (Scaleform::GFx::AS2::Value *)1 )
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
        Scaleform::String::String((Scaleform::String *)&ptarget, purl);
        pObject = v12->pNameHandle.pObject;
        v9 |= 4u;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v12);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          v16,
          pObject,
          (const Scaleform::String *)&ptarget,
          method,
          0,
          0);
        v19 = v18;
      }
      else
      {
        v19 = 0;
      }
      if ( (v9 & 4) == 0 )
        goto LABEL_29;
      v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)((unsigned int)ptarget & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)ptarget & 0xFFFFFFFC) + 4), -1) != 1 )
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
      Scaleform::String::String((Scaleform::String *)&env, purl);
      v9 |= 8u;
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
        v22,
        (int)v16,
        (const Scaleform::String *)&env,
        method,
        0,
        0);
      v19 = v23;
    }
    else
    {
      v19 = 0;
    }
    if ( (v9 & 8) == 0 )
      goto LABEL_29;
    v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)((unsigned int)env & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)env & 0xFFFFFFFC) + 4), -1) != 1 )
      goto LABEL_29;
    goto LABEL_28;
  }
  env = (Scaleform::GFx::AS2::Environment *)&buf;
  LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0);
  LOBYTE(v24) = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(LevelMovie) > 6;
  v21 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName((char *)v24, v9, ptarget, (char **)&env, (bool)v24);
  v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v21;
  if ( !LOBYTE(env->__vftable) && v21 != -1 )
    goto LABEL_23;
}
