void __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::GFxAS2LoadQueueEntryMT_LoadMovie(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::LoadQueueEntry *v4; // eax
  Scaleform::GFx::CharacterHandle *pNext; // ecx
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::RefCountNTSImpl *v7; // edi
  int v8; // eax
  int v9; // ebp
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  Scaleform::GFx::Sprite *LevelMovie; // eax
  int v12; // eax
  Scaleform::GFx::MoviePreloadTask *v13; // eax
  Scaleform::GFx::MoviePreloadTask *v14; // eax
  Scaleform::GFx::MoviePreloadTask *v15; // edi
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::RefCountVImpl *v17; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *qe; // [esp+Ch] [ebp-4h]
  bool stripped; // [esp+18h] [ebp+8h]

  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(this, pqueueEntry, pmovieRoot);
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::`vftable';
  this->pPreloadTask.pObject = 0;
  this->pNewChar.pObject = 0;
  this->pOldChar.pObject = 0;
  this->NewCharId.Id = 65537;
  v4 = this->pQueueEntry;
  this->CharSwitched = 0;
  this->BytesLoaded = 0;
  this->FirstFrameLoaded = 0;
  pNext = (Scaleform::GFx::CharacterHandle *)v4[1].pNext;
  stripped = 0;
  qe = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v4;
  if ( pNext )
  {
    v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pNext, this->pMovieImpl);
    v7 = v6;
    if ( v6 )
    {
      ++v6->RefCount;
      v8 = (int)v6->GetResourceMovieDef(v6);
      stripped = ((*(int (__thiscall **)(int))(*(_DWORD *)v8 + 44))(v8) & 0x10) != 0;
      Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
  else
  {
    v9 = (int)v4[1].__vftable;
    if ( v9 == -1 )
      goto LABEL_10;
    pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieImpl->pASMovieRoot.pObject;
    if ( Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, (int)v4[1].__vftable) )
    {
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, v9);
    }
    else
    {
      if ( !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0) )
        goto LABEL_10;
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
    }
    v12 = (int)LevelMovie->GetResourceMovieDef(LevelMovie);
    stripped = ((*(int (__thiscall **)(int))(*(_DWORD *)v12 + 44))(v12) & 0x10) != 0;
  }
LABEL_10:
  v13 = (Scaleform::GFx::MoviePreloadTask *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 44, 0);
  if ( v13 )
  {
    Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
      v13,
      this->pMovieImpl,
      &qe->URL,
      stripped,
      pqueueEntry->QuietOpen);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  v16 = (Scaleform::RefCountVImpl *)this->pPreloadTask.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->pPreloadTask.pObject = v15;
  v17 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
  ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::MoviePreloadTask *))v17->AddRef)(
    v17,
    this->pPreloadTask.pObject);
  Scaleform::RefCountImpl::Release(v17);
}
