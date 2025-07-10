void __thiscall Scaleform::GFx::MovieImpl::ProcessKeyboard(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Event::EventType qe,
        Scaleform::GFx::ProcessFocusKeyInfo *focusKeyInfo)
{
  unsigned int v3; // eax
  Scaleform::GFx::InputEventsQueueEntry::Entry *v4; // esi
  unsigned __int8 v6; // cl
  unsigned __int8 KeysState; // dl
  unsigned __int8 AsciiCode; // al
  char WheelScrollDelta; // cl
  unsigned int i; // ebp
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  unsigned int KeyboardIndex; // eax
  Scaleform::GFx::KeyboardState *v13; // ecx
  Scaleform::RefCountNTSImpl *v14; // edi
  int keyMask; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::EventId eventId; // [esp+Ch] [ebp-14h] BYREF

  v3 = *(_DWORD *)(qe + 8);
  v4 = (Scaleform::GFx::InputEventsQueueEntry::Entry *)(qe + 4);
  keyMask = 0;
  if ( v3 )
  {
    if ( *(_BYTE *)(qe + 15) )
    {
      v6 = 64;
      qe = KeyDown;
    }
    else
    {
      v6 = 0x80;
      qe = KeyUp;
    }
    eventId.WcharCode = v4->keyEntry.WcharCode;
    KeysState = v4->keyEntry.KeysState;
    eventId.KeyCode = v3;
    AsciiCode = v4->keyEntry.AsciiCode;
    eventId.Id = v6;
    WheelScrollDelta = v4->mouseEntry.WheelScrollDelta;
    eventId.AsciiCode = AsciiCode;
    eventId.RollOverCnt = 0;
    eventId.MouseWheelDelta = 0;
    eventId.ControllerIndex = WheelScrollDelta;
    eventId.KeysState.States = KeysState | 0x80;
    if ( !AsciiCode )
      eventId.AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(&eventId);
    for ( i = this->MovieLevels.Data.Size; i; --i )
    {
      pObject = this->MovieLevels.Data.Data[i - 1].pSprite.pObject;
      pObject->PropagateKeyEvent(pObject, &eventId, &keyMask);
    }
    KeyboardIndex = v4->keyEntry.KeyboardIndex;
    if ( KeyboardIndex >= 6 )
      v13 = 0;
    else
      v13 = &this->KeyboardStates[KeyboardIndex];
    Scaleform::GFx::KeyboardState::NotifyListeners(v13, this->pMainMovie, &eventId, keyMask);
    if ( this->Flags >> 30 != 1 )
      Scaleform::GFx::MovieImpl::ProcessFocusKey(
        this,
        qe,
        (const Scaleform::GFx::InputEventsQueueEntry::KeyEntry *)v4,
        focusKeyInfo);
  }
  else if ( v4->keyEntry.WcharCode )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[*(unsigned __int8 *)(qe + 14)]].LastFocused,
      (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&qe);
    v14 = (Scaleform::RefCountNTSImpl *)qe;
    if ( qe )
    {
      ++*(_DWORD *)(qe + 4);
      Scaleform::RefCountNTSImpl::Release(v14);
      ((void (__thiscall *)(Scaleform::RefCountNTSImpl *, unsigned int, _DWORD))v14->__vftable[95].~Scaleform::RefCountNTSImpl)(
        v14,
        v4->keyEntry.WcharCode,
        v4->keyEntry.KeyboardIndex);
      Scaleform::RefCountNTSImpl::Release(v14);
    }
  }
}
