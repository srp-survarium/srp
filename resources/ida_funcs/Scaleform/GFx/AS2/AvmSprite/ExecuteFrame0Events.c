void __thiscall Scaleform::GFx::AS2::AvmSprite::ExecuteFrame0Events(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  unsigned int Capacity; // edi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v4; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v6; // ecx

  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_DWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity
                                                                             + 16)
                                                                 + 68),
               AP_Load);
  Capacity = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v4 = inserted;
  inserted->Type = Entry_Event;
  if ( Capacity )
    ++*(_DWORD *)(Capacity + 4);
  pObject = inserted->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)Capacity;
  v6 = v4->pActionBuffer.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v4->pActionBuffer.pObject = 0;
  v4->mEventId.WcharCode = 0;
  v4->mEventId.KeyCode = 0;
  v4->mEventId.AsciiCode = 0;
  v4->mEventId.RollOverCnt = 0;
  v4->mEventId.KeysState.States = 0;
  v4->mEventId.MouseWheelDelta = 0;
  v4->mEventId.Id = 1;
  v4->mEventId.ControllerIndex = -1;
}
