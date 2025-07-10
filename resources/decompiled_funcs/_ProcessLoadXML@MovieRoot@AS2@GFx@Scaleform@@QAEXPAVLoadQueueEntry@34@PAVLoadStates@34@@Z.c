void __thiscall Scaleform::GFx::AS2::MovieRoot::ProcessLoadXML(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String pentry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadQueueEntry *pData; // ebp
  Scaleform::String *p_RefCount; // esi
  Scaleform::GFx::LoadStates *v6; // esi
  void *v7; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  unsigned int v10; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::AS2::Environment *v14; // eax
  Scaleform::GFx::LoadQueueEntry_vtbl *v15; // ebx
  Scaleform::GFx::AS2::Environment *v16; // edi
  void (__thiscall **v17)(Scaleform::GFx::LoadQueueEntry_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *); // esi
  Scaleform::GFx::AS2::Object *v18; // eax
  void *v19; // esi
  void *v20; // esi
  Scaleform::String level0Path; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+1Ch] [ebp-Ch] BYREF

  Scaleform::String::String(&level0Path);
  Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(this, &level0Path);
  pData = (Scaleform::GFx::LoadQueueEntry *)pentry.pData;
  p_RefCount = (Scaleform::String *)&pentry.pData[1].RefCount;
  if ( Scaleform::String::GetLength((Scaleform::String *)&pentry.pData[1].RefCount) )
  {
    loc.Use = File_LoadXML;
    Scaleform::String::String(&loc.FileName, p_RefCount);
    Scaleform::String::String(&loc.ParentPath, &level0Path);
    Scaleform::String::String(&pentry);
    v6 = pls;
    Scaleform::GFx::LoadStates::BuildURL(pls, &pentry, &loc);
    Scaleform::String::String((Scaleform::String *)&pls, (char *)((pentry.HeapTypeBits & 0xFFFFFFFC) + 8));
    (*((void (__thiscall **)(Scaleform::GFx::LoadQueueEntry_vtbl *, Scaleform::GFx::LoadStates **, Scaleform::GFx::FileOpener *))pData[3].~Scaleform::GFx::LoadQueueEntry
     + 1))(
      pData[3].__vftable,
      &pls,
      v6->pBindStates.pObject->pFileOpener.pObject);
    v7 = (void *)((unsigned int)pls & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pls & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    pMovieImpl = this->pMovieImpl;
    Size = pMovieImpl->MovieLevels.Data.Size;
    v10 = 0;
    if ( Size )
    {
      Data = pMovieImpl->MovieLevels.Data.Data;
      v12 = Data;
      while ( v12->Level )
      {
        ++v10;
        ++v12;
        if ( v10 >= Size )
          goto LABEL_8;
      }
      pObject = Data[v10].pSprite.pObject;
    }
    else
    {
LABEL_8:
      pObject = 0;
    }
    v14 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                           + pObject->AvmObjOffset)
                                                                         + 124))((int)pObject + 4
                                                                                              * pObject->AvmObjOffset);
    v15 = pData[3].__vftable;
    v16 = v14;
    v17 = (void (__thiscall **)(Scaleform::GFx::LoadQueueEntry_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))((char *)v15->~Scaleform::GFx::LoadQueueEntry + 8);
    v18 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pData[2].Method, v14);
    (*v17)(v15, v16, v18);
    v19 = (void *)(pentry.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((pentry.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
  }
  v20 = (void *)(level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((level0Path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
}
