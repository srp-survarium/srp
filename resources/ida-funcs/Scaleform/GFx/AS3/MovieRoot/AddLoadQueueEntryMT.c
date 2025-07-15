void __thiscall Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry::LoadType Type; // eax
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v4; // eax
  Scaleform::GFx::LoadQueueEntryMT *v5; // eax
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::GFx::LoadQueueEntryMT_LoadBinary *v7; // eax
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v8; // eax
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // ebp
  Scaleform::GFx::LoadQueueEntryMT *i; // esi
  Scaleform::GFx::LoadQueueEntry *v11; // ecx
  Scaleform::GFx::LoadQueueEntry_vtbl *v12; // edx
  Scaleform::GFx::LoadQueueEntry *pNext; // edx

  Type = pentry->Type;
  if ( (Type & 4) != 0 )
  {
    v4 = (Scaleform::GFx::LoadQueueEntryMT_LoadVars *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 28, 0);
    if ( v4 )
    {
      Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(
        v4,
        pentry,
        (Scaleform::String)this->pMovieImpl);
      goto LABEL_16;
    }
LABEL_17:
    ((void (__thiscall *)(Scaleform::GFx::AS3::LoadQueueEntry *, int))pentry->~Scaleform::GFx::AS3::LoadQueueEntry)(
      pentry,
      1);
    return;
  }
  Alloc = this->pMovieImpl->pHeap->Alloc;
  if ( (Type & 0x20) != 0 )
  {
    v7 = (Scaleform::GFx::LoadQueueEntryMT_LoadBinary *)((int (__stdcall *)(int, _DWORD))Alloc)(28, 0);
    if ( !v7 )
      goto LABEL_17;
    Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(
      v7,
      pentry,
      (Scaleform::String)this->pMovieImpl);
  }
  else
  {
    v8 = (Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *)((int (__stdcall *)(int, _DWORD))Alloc)(36, 0);
    if ( !v8 )
      goto LABEL_17;
    Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(v8, pentry, this->pMovieImpl);
    if ( !v5 )
      goto LABEL_17;
    pQueueEntry = v5->pQueueEntry;
    for ( i = this->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
    {
      v11 = i->pQueueEntry;
      v12 = v11[1].__vftable;
      if ( !v12 || v12 != pQueueEntry[1].__vftable )
      {
        pNext = v11[1].pNext;
        if ( !pNext || pNext != pQueueEntry[1].pNext )
          continue;
      }
      v11->Canceled = 1;
    }
  }
LABEL_16:
  if ( !v5 )
    goto LABEL_17;
  Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(this->pMovieImpl, v5);
}
