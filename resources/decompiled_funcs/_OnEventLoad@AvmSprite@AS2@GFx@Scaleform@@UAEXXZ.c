void __thiscall Scaleform::GFx::AS2::AvmSprite::OnEventLoad(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // ebp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v4; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::GFx::ASMovieRootBase_vtbl *v7; // ebp
  unsigned int v8; // esi
  Scaleform::GFx::InteractiveObject *v9; // ebx
  int v10; // ecx
  Scaleform::GFx::EventId id; // [esp+10h] [ebp-14h] BYREF

  id.Id = 1;
  memset(&id.WcharCode, 0, 9);
  id.RollOverCnt = 0;
  id.KeysState.States = 0;
  id.MouseWheelDelta = 0;
  id.ControllerIndex = -1;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, &id) )
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
                 AP_Frame);
  else
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
                 AP_Load);
  pDispObj = this->pDispObj;
  v4 = inserted;
  inserted->Type = Entry_Event;
  if ( pDispObj )
    ++pDispObj->RefCount;
  pObject = inserted->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4->pCharacter.pObject = pDispObj;
  v6 = v4->pActionBuffer.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v4->pActionBuffer.pObject = 0;
  v4->mEventId.Id = 1;
  v4->mEventId.WcharCode = 0;
  v4->mEventId.KeyCode = 0;
  v4->mEventId.AsciiCode = 0;
  v4->mEventId.RollOverCnt = 0;
  v4->mEventId.ControllerIndex = -1;
  v4->mEventId.KeysState.States = 0;
  v4->mEventId.MouseWheelDelta = 0;
  this->pDispObj->Flags |= 0x20u;
  Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags(
    (Scaleform::GFx::AS2::AvmSprite *)&this->Scaleform::GFx::AvmSpriteBase,
    0);
  Scaleform::GFx::Sprite::DefaultOnEventLoad((Scaleform::GFx::Sprite *)this->pDispObj);
  v7 = this->pDispObj->pASRoot[40].__vftable;
  v8 = 0;
  if ( v7 )
  {
    do
    {
      v9 = this->pDispObj;
      v10 = *(_DWORD *)(*(_DWORD *)&v9->pASRoot[39].AVMVersion + 4 * v8);
      if ( v9 == (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 484))(v10) )
        Scaleform::GFx::Sprite::SetHitArea(
          *(Scaleform::GFx::Sprite **)(*(_DWORD *)&this->pDispObj->pASRoot[39].AVMVersion + 4 * v8),
          (Scaleform::GFx::Sprite *)this->pDispObj);
      ++v8;
    }
    while ( v8 < (unsigned int)v7 );
  }
}
