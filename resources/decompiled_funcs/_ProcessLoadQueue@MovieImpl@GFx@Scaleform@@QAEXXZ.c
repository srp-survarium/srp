void __thiscall Scaleform::GFx::MovieImpl::ProcessLoadQueue(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // esi
  Scaleform::GFx::LoadStates *v3; // eax
  Scaleform::GFx::StateBagImpl *pObject; // ecx
  Scaleform::GFx::StateBag *v5; // edx
  Scaleform::GFx::LoadStates *v6; // eax
  Scaleform::GFx::LoadStates *v7; // ebx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // esi
  Scaleform::GFx::LoadQueueEntryMT *v9; // esi
  Scaleform::GFx::LoadQueueEntryMT *pNext; // ebx
  Scaleform::GFx::LoadQueueEntryMT *pPrev; // eax

  while ( this->pLoadQueueHead )
  {
    pLoadQueueHead = this->pLoadQueueHead;
    this->pLoadQueueHead = pLoadQueueHead->pNext;
    v3 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
    if ( v3 )
    {
      pObject = this->pStateBag.pObject;
      if ( pObject )
        v5 = &pObject->Scaleform::GFx::StateBag;
      else
        v5 = 0;
      Scaleform::GFx::LoadStates::LoadStates(v3, this->pMainMovieDef.pObject->pLoaderImpl.pObject, v5, 0);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    this->pASMovieRoot.pObject->ProcessLoadQueueEntry(this->pASMovieRoot.pObject, pLoadQueueHead, v7);
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))pLoadQueueHead->~Scaleform::GFx::LoadQueueEntry)(
      pLoadQueueHead,
      1);
    if ( v7 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
  }
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  if ( pLoadQueueMTHead )
  {
    while ( pLoadQueueMTHead->IsPreloadingFinished(pLoadQueueMTHead) )
    {
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
      if ( !pLoadQueueMTHead )
        goto LABEL_14;
    }
  }
  else
  {
LABEL_14:
    v9 = this->pLoadQueueMTHead;
    while ( v9 )
    {
      if ( v9->LoadFinished(v9) )
      {
        pNext = v9->pNext;
        if ( pNext )
          pNext->pPrev = v9->pPrev;
        pPrev = v9->pPrev;
        if ( pPrev )
          pPrev->pNext = pNext;
        if ( this->pLoadQueueMTHead == v9 )
          this->pLoadQueueMTHead = pNext;
        ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntryMT *, int))v9->~Scaleform::GFx::LoadQueueEntryMT)(v9, 1);
        v9 = pNext;
      }
      else
      {
        v9 = v9->pNext;
      }
    }
  }
}
