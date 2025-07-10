void __thiscall Scaleform::GFx::AS3::MovieRoot::GetMouseCursorType(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *result,
        unsigned int mouseIndex)
{
  if ( mouseIndex < 6 )
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(
      this,
      result,
      (Scaleform::GFx::ASStringNode *)this->pMovieImpl->mMouseState[mouseIndex].mPresetCursorType);
  else
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(this, result, MEMORY[0x28]);
}
