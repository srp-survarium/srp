void __thiscall Scaleform::GFx::KeyboardState::NotifyListeners(
        Scaleform::GFx::KeyboardState *this,
        Scaleform::GFx::InteractiveObject *pmovie,
        const Scaleform::GFx::EventId *evt,
        int keyMask)
{
  if ( this->pListener )
  {
    if ( evt->Id == 64 )
    {
      this->pListener->OnKeyDown(this->pListener, pmovie, evt, keyMask);
    }
    else if ( evt->Id == 128 )
    {
      this->pListener->OnKeyUp(this->pListener, pmovie, evt, keyMask);
    }
  }
}
