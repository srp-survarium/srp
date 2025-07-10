bool __thiscall Scaleform::GFx::AS2::AvmSprite::OnUnloading(Scaleform::GFx::AS2::AvmSprite *this, bool mayRemove)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v4; // edx
  signed int v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::GFx::InteractiveObject **v7; // ecx
  bool (__thiscall *HasEventHandler)(Scaleform::GFx::AvmDisplayObjBase *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::InteractiveObject *v9; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v11; // esi
  Scaleform::GFx::InteractiveObject *v12; // ebp
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v14; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v15; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v16; // esi
  Scaleform::GFx::InteractiveObject *v17; // ebp
  Scaleform::RefCountNTSImpl *v18; // ecx
  Scaleform::RefCountNTSImpl *v19; // ecx
  _DWORD v21[3]; // [esp+Ch] [ebp-14h] BYREF
  char v22; // [esp+18h] [ebp-8h]
  char v23; // [esp+1Ch] [ebp-4h]
  char v24; // [esp+1Dh] [ebp-3h]
  char v25; // [esp+1Eh] [ebp-2h]
  char v26; // [esp+1Fh] [ebp-1h]

  pDispObj = this->pDispObj;
  v4 = pDispObj->pASRoot[40].__vftable;
  if ( pDispObj[1].pGeomData )
  {
    v5 = 0;
    if ( v4 )
    {
      v6 = this->pDispObj;
      v7 = *(Scaleform::GFx::InteractiveObject ***)&v6->pASRoot[39].AVMVersion;
      while ( *v7 != v6 )
      {
        ++v5;
        ++v7;
        if ( v5 >= (unsigned int)v4 )
          goto LABEL_9;
      }
      if ( v5 > -1 )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *)&v6->pASRoot[39].AVMVersion,
          v5);
    }
  }
LABEL_9:
  if ( mayRemove )
  {
    HasEventHandler = this->HasEventHandler;
    v21[0] = 4;
    v21[1] = 0;
    v21[2] = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
    v26 = 0;
    v24 = -1;
    if ( !HasEventHandler(this, (const Scaleform::GFx::EventId *)v21) )
      goto LABEL_30;
    mayRemove = 0;
  }
  v9 = this->pDispObj;
  if ( (v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x20) != 0
    && (v9->Scaleform::GFx::DisplayObject::Flags & 8) == 0 )
  {
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v9->pASRoot[3].pMovieImpl,
                 AP_Frame);
    v11 = inserted;
    if ( inserted )
    {
      v12 = this->pDispObj;
      inserted->Type = Entry_Event;
      if ( v12 )
        ++v12->RefCount;
      pObject = inserted->pCharacter.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      v11->pCharacter.pObject = v12;
      v14 = v11->pActionBuffer.pObject;
      if ( v14 )
        Scaleform::RefCountNTSImpl::Release(v14);
      v11->pActionBuffer.pObject = 0;
      v11->mEventId.Id = 1;
      v11->mEventId.WcharCode = 0;
      v11->mEventId.KeyCode = 0;
      v11->mEventId.AsciiCode = 0;
      v11->mEventId.RollOverCnt = 0;
      v11->mEventId.ControllerIndex = -1;
      v11->mEventId.KeysState.States = 0;
      v11->mEventId.MouseWheelDelta = 0;
    }
  }
  v15 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
          (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
          AP_Frame);
  v16 = v15;
  if ( v15 )
  {
    v17 = this->pDispObj;
    v15->Type = Entry_Event;
    if ( v17 )
      ++v17->RefCount;
    v18 = v15->pCharacter.pObject;
    if ( v18 )
      Scaleform::RefCountNTSImpl::Release(v18);
    v16->pCharacter.pObject = v17;
    v19 = v16->pActionBuffer.pObject;
    if ( v19 )
      Scaleform::RefCountNTSImpl::Release(v19);
    v16->pActionBuffer.pObject = 0;
    v16->mEventId.Id = 4;
    v16->mEventId.WcharCode = 0;
    v16->mEventId.KeyCode = 0;
    v16->mEventId.AsciiCode = 0;
    v16->mEventId.RollOverCnt = 0;
    v16->mEventId.ControllerIndex = -1;
    v16->mEventId.KeysState.States = 0;
    v16->mEventId.MouseWheelDelta = 0;
  }
LABEL_30:
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->pDispObj);
  return mayRemove;
}
