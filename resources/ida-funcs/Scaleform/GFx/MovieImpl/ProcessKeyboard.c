void __thiscall Scaleform::GFx::MovieImpl::ProcessKeyboard(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> qe,
        Scaleform::GFx::ProcessFocusKeyInfo *focusKeyInfo)
{
  Scaleform::WeakPtrProxy *pWeakProxy; // eax
  const Scaleform::GFx::InputEventsQueueEntry::KeyEntry *p_RefCount; // esi
  unsigned __int8 v6; // cl
  Scaleform::GFx::Event::EventType v7; // ebx
  char v8; // dl
  unsigned __int8 v9; // al
  char v10; // cl
  unsigned int i; // ebp
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  unsigned int KeyboardIndex; // eax
  Scaleform::GFx::KeyboardState *v14; // ecx
  Scaleform::GFx::Sprite *v15; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  int keyMask; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::AmpFunctionTimer v20; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::EventId evt; // [esp+20h] [ebp-14h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v20,
    this->AdvanceStats.pObject,
    "MovieImpl::ProcessKeyboard",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  pWeakProxy = qe.pObject->pWeakProxy;
  p_RefCount = (const Scaleform::GFx::InputEventsQueueEntry::KeyEntry *)&qe.pObject->RefCount;
  keyMask = 0;
  if ( pWeakProxy )
  {
    if ( HIBYTE(qe.pObject->__vftable) )
    {
      v6 = 64;
      v7 = KeyDown;
    }
    else
    {
      v6 = 0x80;
      v7 = KeyUp;
    }
    evt.WcharCode = p_RefCount->WcharCode;
    v8 = BYTE1(qe.pObject->__vftable);
    evt.KeyCode = (unsigned int)pWeakProxy;
    v9 = (unsigned __int8)qe.pObject->__vftable;
    evt.Id = v6;
    v10 = BYTE2(qe.pObject->__vftable);
    evt.AsciiCode = v9;
    evt.RollOverCnt = 0;
    evt.MouseWheelDelta = 0;
    evt.ControllerIndex = v10;
    evt.KeysState.States = v8 | 0x80;
    if ( !v9 )
      evt.AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(&evt);
    for ( i = this->MovieLevels.Data.Size; i; --i )
    {
      pObject = this->MovieLevels.Data.Data[i - 1].pSprite.pObject;
      pObject->PropagateKeyEvent(pObject, &evt, &keyMask);
    }
    KeyboardIndex = p_RefCount->KeyboardIndex;
    if ( KeyboardIndex >= 6 )
      v14 = 0;
    else
      v14 = &this->KeyboardStates[KeyboardIndex];
    Scaleform::GFx::KeyboardState::NotifyListeners(v14, this->pMainMovie, &evt, keyMask);
    if ( this->Flags >> 30 != 1 )
      Scaleform::GFx::MovieImpl::ProcessFocusKey(this, v7, p_RefCount, focusKeyInfo);
  }
  else if ( p_RefCount->WcharCode )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[BYTE2(qe.pObject->__vftable)]].LastFocused,
      &qe);
    v15 = qe.pObject;
    if ( qe.pObject )
    {
      ++qe.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(v15);
      v15->OnCharEvent(v15, p_RefCount->WcharCode, p_RefCount->KeyboardIndex);
      Scaleform::RefCountNTSImpl::Release(v15);
    }
  }
  Stats = v20.Stats;
  if ( v20.Stats )
  {
    p_NativePopCallstack = &v20.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v20.StartTicks),
      (ProfileTicks - v20.StartTicks) >> 32);
  }
}
