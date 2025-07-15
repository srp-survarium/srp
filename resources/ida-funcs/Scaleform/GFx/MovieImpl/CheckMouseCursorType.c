void __thiscall Scaleform::GFx::MovieImpl::CheckMouseCursorType(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIdx,
        Scaleform::GFx::InteractiveObject *ptopMouseCharacter)
{
  unsigned int v4; // eax

  if ( Scaleform::GFx::MouseState::IsTopmostEntityChanged(&this->mMouseState[mouseIdx]) )
  {
    v4 = 0;
    if ( ptopMouseCharacter )
      v4 = ptopMouseCharacter->GetCursorType(ptopMouseCharacter);
    Scaleform::GFx::MovieImpl::ChangeMouseCursorType(this, mouseIdx, v4);
  }
}
