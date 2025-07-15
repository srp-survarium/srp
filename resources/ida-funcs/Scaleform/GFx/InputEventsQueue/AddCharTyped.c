void __thiscall Scaleform::GFx::InputEventsQueue::AddCharTyped(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int wcharCode,
        char keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue::AddKeyEvent(this, 0, 0, wcharCode, 1u, (Scaleform::KeyModifiers)0x80, keyboardIndex);
}
