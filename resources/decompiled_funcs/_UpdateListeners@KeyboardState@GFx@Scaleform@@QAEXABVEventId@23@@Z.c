void __thiscall Scaleform::GFx::KeyboardState::UpdateListeners(
        Scaleform::GFx::KeyboardState *this,
        const Scaleform::GFx::EventId *evt)
{
  if ( this->pListener )
    this->pListener->Update(this->pListener, evt);
}
