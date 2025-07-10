void __thiscall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry *v2; // ebp
  Scaleform::GFx::LoadQueueEntry::LoadType Type; // eax
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v5; // eax
  Scaleform::GFx::LoadQueueEntryMT *v6; // eax
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *v7; // eax
  Scaleform::GFx::LoadQueueEntryMT *v8; // eax
  Scaleform::GFx::AS2::Value *p_Method; // esi
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // esi
  Scaleform::GFx::AS2::Object *i; // ebp
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // edi
  char Method; // al
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS *v15; // eax
  Scaleform::GFx::LoadQueueEntryMT *v16; // eax
  Scaleform::GFx::AS2::Value *p_pNext; // esi
  Scaleform::GFx::AS2::Object *v18; // eax
  Scaleform::GFx::LoadQueueEntryMT *v19; // esi
  Scaleform::GFx::AS2::Object *j; // ebp
  Scaleform::GFx::LoadQueueEntry *v21; // edi
  char v22; // al
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *v23; // eax
  Scaleform::GFx::LoadQueueEntryMT *v24; // eax
  Scaleform::GFx::LoadQueueEntryMT *v25; // edx
  Scaleform::GFx::LoadQueueEntry *v26; // edi
  Scaleform::GFx::LoadQueueEntry *pNext; // ecx
  Scaleform::GFx::LoadQueueEntry *v28; // eax
  Scaleform::GFx::LoadQueueEntry *v29; // esi
  bool v30; // zf
  Scaleform::GFx::LoadQueueEntry_vtbl *v31; // ecx
  Scaleform::GFx::LoadQueueEntryMT *pentryMT; // [esp+10h] [ebp-4h]

  v2 = pentry;
  Type = pentry->Type;
  if ( (Type & 4) != 0 )
  {
    v5 = (Scaleform::GFx::LoadQueueEntryMT_LoadVars *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 28, 0);
    if ( v5 )
    {
      Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(
        v5,
        pentry,
        (Scaleform::String)this->pMovieImpl);
      pentryMT = v6;
      goto LABEL_17;
    }
LABEL_18:
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))v2->~Scaleform::GFx::LoadQueueEntry)(v2, 1);
    return;
  }
  if ( (Type & 8) != 0 )
  {
    if ( !Scaleform::String::GetLength(&pentry->URL) )
      goto LABEL_18;
    v7 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *)this->pMovieImpl->pHeap->Alloc(
                                                                  this->pMovieImpl->pHeap,
                                                                  32,
                                                                  0);
    if ( v7 )
    {
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::GFxAS2LoadQueueEntryMT_LoadXML(
        v7,
        pentry,
        (Scaleform::String)this);
      pentryMT = v8;
    }
    else
    {
      pentryMT = 0;
    }
    p_Method = (Scaleform::GFx::AS2::Value *)&pentryMT->pQueueEntry[2].Method;
    if ( Scaleform::GFx::AS2::Value::ToObject(p_Method, 0) )
    {
      v10 = Scaleform::GFx::AS2::Value::ToObject(p_Method, 0);
      pLoadQueueMTHead = this->pMovieImpl->pLoadQueueMTHead;
      for ( i = v10; pLoadQueueMTHead; pLoadQueueMTHead = pLoadQueueMTHead->pNext )
      {
        pQueueEntry = pLoadQueueMTHead->pQueueEntry;
        Method = pQueueEntry[2].Method;
        if ( Method
          && Method != 10
          && i == Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[2].Method, 0) )
        {
          pQueueEntry->Canceled = 1;
        }
      }
LABEL_16:
      v2 = pentry;
      goto LABEL_17;
    }
    goto LABEL_17;
  }
  if ( (Type & 0x10) == 0 )
  {
    v23 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *)this->pMovieImpl->pHeap->Alloc(
                                                                     this->pMovieImpl->pHeap,
                                                                     52,
                                                                     0);
    if ( !v23 )
      goto LABEL_18;
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::GFxAS2LoadQueueEntryMT_LoadMovie(
      v23,
      pentry,
      this->pMovieImpl);
    pentryMT = v24;
    if ( !v24 )
      goto LABEL_18;
    v25 = this->pMovieImpl->pLoadQueueMTHead;
    v26 = v24->pQueueEntry;
    if ( !v25 )
      goto LABEL_17;
    while ( 1 )
    {
      pNext = v26[1].pNext;
      v28 = v25->pQueueEntry;
      if ( pNext )
      {
        v29 = v28[1].pNext;
        if ( v29 )
        {
          v30 = v29->Method == pNext->Method;
          goto LABEL_40;
        }
      }
      else
      {
        v31 = v28[1].__vftable;
        if ( v31 != (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
        {
          v30 = v31 == v26[1].__vftable;
LABEL_40:
          if ( v30 )
            v28->Canceled = 1;
        }
      }
      v25 = v25->pNext;
      if ( !v25 )
        goto LABEL_17;
    }
  }
  if ( !Scaleform::String::GetLength(&pentry->URL) )
    goto LABEL_18;
  v15 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS *)this->pMovieImpl->pHeap->Alloc(
                                                                 this->pMovieImpl->pHeap,
                                                                 28,
                                                                 0);
  if ( v15 )
  {
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS::GFxAS2LoadQueueEntryMT_LoadCSS(
      v15,
      pentry,
      (Scaleform::String)this);
    pentryMT = v16;
  }
  else
  {
    pentryMT = 0;
  }
  p_pNext = (Scaleform::GFx::AS2::Value *)&pentryMT->pQueueEntry[3].pNext;
  if ( Scaleform::GFx::AS2::Value::ToObject(p_pNext, 0) )
  {
    v18 = Scaleform::GFx::AS2::Value::ToObject(p_pNext, 0);
    v19 = this->pMovieImpl->pLoadQueueMTHead;
    for ( j = v18; v19; v19 = v19->pNext )
    {
      v21 = v19->pQueueEntry;
      v22 = (char)v21[3].pNext;
      if ( v22 && v22 != 10 && j == Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v21[3].pNext, 0) )
        v21->Canceled = 1;
    }
    goto LABEL_16;
  }
LABEL_17:
  if ( !pentryMT )
    goto LABEL_18;
  Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(this->pMovieImpl, pentryMT);
}
