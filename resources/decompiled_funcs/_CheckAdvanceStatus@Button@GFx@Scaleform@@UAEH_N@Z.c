char __thiscall Scaleform::GFx::Button::CheckAdvanceStatus(Scaleform::GFx::Button *this, bool playingNow)
{
  char result; // al

  result = 0;
  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0xC) == 0
    && (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x40) == 0 )
  {
    return !playingNow;
  }
  if ( playingNow )
    return -1;
  return result;
}
