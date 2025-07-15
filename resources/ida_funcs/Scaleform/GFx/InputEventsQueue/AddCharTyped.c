void __thiscall Scaleform::GFx::InputEventsQueue::AddCharTyped(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int wcharCode,
        unsigned __int8 keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue::AddKeyEvent(this, 0, 0, wcharCode, 1, (Scaleform::KeyModifiers)0x80, keyboardIndex);
}
