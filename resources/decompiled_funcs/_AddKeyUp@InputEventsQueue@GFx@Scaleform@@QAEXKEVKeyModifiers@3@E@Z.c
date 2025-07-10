void __thiscall Scaleform::GFx::InputEventsQueue::AddKeyUp(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int code,
        unsigned __int8 ascii,
        Scaleform::KeyModifiers specialKeysState,
        unsigned __int8 keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue::AddKeyEvent(this, code, ascii, 0, 0, specialKeysState, keyboardIndex);
}
