void __thiscall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ptargetChar,
        char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v4; // bl
  Scaleform::GFx::InteractiveObject *v5; // esi
  Scaleform::GFx::InteractiveObject *v7; // eax
  int v8; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v9; // edi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::LoadQueueEntry *v11; // eax
  Scaleform::GFx::LoadQueueEntry *v12; // esi
  void *v13; // edi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v14; // esi
  Scaleform::GFx::LoadQueueEntry *v15; // eax
  Scaleform::RefCountVImpl *v16; // eax
  Scaleform::String url; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  url.pData = 0;
  v5 = ptargetChar;
  if ( ptargetChar )
  {
    if ( ((ptargetChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
        ? (unsigned int)ptargetChar
        : 0) != 0
      && (v7 = (ptargetChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
             ? ptargetChar
             : 0,
          v8 = (*(int (__thiscall **)(int *))(*(&v7->Depth + v7->AvmObjOffset) + 120))(&v7->Depth + v7->AvmObjOffset),
          v8 != -1) )
    {
      v14 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v14 )
      {
        Scaleform::String::String(&url, purl);
        v4 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v14, v8, &url, method, 1, 0);
        v12 = v15;
      }
      else
      {
        v12 = 0;
      }
      if ( (v4 & 2) != 0 )
        Scaleform::String::~String(&url);
    }
    else
    {
      v9 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 108, 0);
      if ( v9 )
      {
        Scaleform::String::String((Scaleform::String *)&ptargetChar, purl);
        pObject = v5->pNameHandle.pObject;
        v4 = 1;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v5);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          v9,
          pObject,
          (const Scaleform::String *)&ptargetChar,
          method,
          1,
          0);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( (v4 & 1) != 0 )
      {
        v13 = (void *)((unsigned int)ptargetChar & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)ptargetChar & 0xFFFFFFFC) + 4), -1) == 1 )
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
