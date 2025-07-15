void __thiscall Scaleform::GFx::InputEventsQueue::AddKeyDown(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int code,
        unsigned __int8 ascii,
        Scaleform::KeyModifiers specialKeysState,
        char keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue::AddKeyEvent(this, code, ascii, 0, 1u, specialKeysState, keyboardIndex);
}
