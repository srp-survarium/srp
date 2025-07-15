void __thiscall Scaleform::GFx::StaticTextCharacter::AdvanceFrame(
        Scaleform::GFx::StaticTextCharacter *this,
        bool nextFrame,
        float framePos)
{
  if ( nextFrame )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
}
