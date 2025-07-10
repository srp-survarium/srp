void __thiscall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this,
        Scaleform::GFx::AS3::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  int v6; // eax
  Scaleform::GFx::MoviePreloadTask *v7; // eax
  Scaleform::GFx::MoviePreloadTask *v8; // eax
  Scaleform::GFx::MoviePreloadTask *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v11; // edi
  bool stripped; // [esp+14h] [ebp+8h]

  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(this, pqueueEntry, pmovieRoot);
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie_vtbl *)&Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::`vftable';
  this->pPreloadTask.pObject = 0;
  pMovieImpl = this->pMovieImpl;
  this->CharSwitched = 0;
  this->FirstFrameLoaded = 0;
  this->BytesLoaded = 0;
  pMainMovie = pMovieImpl->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  stripped = 0;
  if ( pMainMovie )
  {
    v6 = (int)pMainMovie->GetResourceMovieDef(pMainMovie);
    stripped = ((*(int (__thiscall **)(int))(*(_DWORD *)v6 + 44))(v6) & 0x10) != 0;
  }
  v7 = (Scaleform::GFx::MoviePreloadTask *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 44, 0);
  if ( v7 )
  {
    Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
      v7,
      this->pMovieImpl,
      &pqueueEntry->URL,
      stripped,
      pqueueEntry->QuietOpen);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pPreloadTask.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pPreloadTask.pObject = v9;
  v11 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
  ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::MoviePreloadTask *))v11->AddRef)(
    v11,
    this->pPreloadTask.pObject);
  Scaleform::RefCountImpl::Release(v11);
}
