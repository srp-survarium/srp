bool __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS::LoadFinished(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadCSS *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v4; // ecx
  Scaleform::GFx::AS2::Environment *v5; // eax
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // esi
  _DWORD *EntryTime; // ebp
  Scaleform::GFx::AS2::Environment *v8; // ebx
  void (__thiscall **v9)(_DWORD *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *); // edi
  Scaleform::GFx::AS2::Object *v10; // eax

  if ( this->pQueueEntry->Canceled )
    return this->pTask.pObject->Done == 1;
  if ( this->pTask.pObject->Done != 1 )
    return 0;
  pMainMovie = this->pMovieImpl->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  v4 = &pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
     + pMainMovie->AvmObjOffset;
  v5 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v4)->SetRotation)(v4);
  pQueueEntry = this->pQueueEntry;
  EntryTime = (_DWORD *)pQueueEntry[3].EntryTime;
  v8 = v5;
  v9 = (void (__thiscall **)(_DWORD *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))(*EntryTime + 8);
  v10 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[3].pNext, v5);
  (*v9)(EntryTime, v8, v10);
  return 1;
}
