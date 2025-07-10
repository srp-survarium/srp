bool __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::LoadFinished(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this)
{
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v7; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::AS2::Environment *v9; // eax
  Scaleform::GFx::LoadQueueEntry_vtbl *v10; // ebx
  Scaleform::GFx::AS2::Environment *v11; // edi
  void (__thiscall **v12)(Scaleform::GFx::LoadQueueEntry_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *); // esi
  Scaleform::GFx::AS2::Object *v13; // eax

  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
    return this->pTask.pObject->Done == 1;
  if ( this->pTask.pObject->Done != 1 )
    return 0;
  pMovieImpl = this->pASMovieRoot->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v5 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v7 = Data;
    while ( v7->Level )
    {
      ++v5;
      ++v7;
      if ( v5 >= Size )
        goto LABEL_10;
    }
    pObject = Data[v5].pSprite.pObject;
  }
  else
  {
LABEL_10:
    pObject = 0;
  }
  v9 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                        + pObject->AvmObjOffset)
                                                                      + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  v10 = pQueueEntry[3].__vftable;
  v11 = v9;
  v12 = (void (__thiscall **)(Scaleform::GFx::LoadQueueEntry_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))((char *)v10->~Scaleform::GFx::LoadQueueEntry + 8);
  v13 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[2].Method, v9);
  (*v12)(v10, v11, v13);
  return 1;
}
