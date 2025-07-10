void __thiscall Scaleform::GFx::InputEventsQueue::AddKeyEvent(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int code,
        unsigned __int8 ascii,
        unsigned int wcharCode,
        unsigned __int8 isKeyDown,
        Scaleform::KeyModifiers specialKeysState,
        char keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue *v7; // eax

  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->Queue[0].t = QE_Key;
  v7->Queue[0].u.keyEntry.Code = code;
  v7->Queue[0].u.keyEntry.AsciiCode = ascii;
  v7->Queue[0].u.keyEntry.WcharCode = wcharCode;
  BYTE1(v7->Queue[0].u.gamepadAnalogEntry.AnalogY) = specialKeysState;
  v7->Queue[0].u.mouseEntry.WheelScrollDelta = keyboardIndex;
  v7->Queue[0].u.mouseEntry.Flags = isKeyDown;
}
