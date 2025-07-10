void __thiscall Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ActionBuffer *a,
        Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v5; // esi
  Scaleform::GFx::InteractiveObject *pDispObj; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v8; // ecx

  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
               prio);
  v5 = inserted;
  if ( inserted )
  {
    pDispObj = this->pDispObj;
    inserted->Type = Entry_Buffer;
    if ( pDispObj )
      ++pDispObj->RefCount;
    pObject = inserted->pCharacter.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    v5->pCharacter.pObject = pDispObj;
    if ( a )
      ++a->RefCount;
    v8 = v5->pActionBuffer.pObject;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    v5->pActionBuffer.pObject = a;
    v5->mEventId.Id = 0;
  }
}
