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
