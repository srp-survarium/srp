void __thiscall Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *cursor,
        unsigned int mouseIndex)
{
  unsigned int v4; // edi
  Scaleform::GFx::MouseState *v5; // esi

  v4 = -1;
  if ( !strcmp(cursor->pNode->pData, "arrow") )
  {
    v4 = 0;
  }
  else if ( !strcmp(cursor->pNode->pData, "button") )
  {
    v4 = 3;
  }
  else if ( !strcmp(cursor->pNode->pData, "hand") )
  {
    v4 = 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(cursor, "ibeam") )
  {
    v4 = 2;
  }
  if ( mouseIndex < 6 )
    v5 = &this->pMovieImpl->mMouseState[mouseIndex];
  else
    v5 = 0;
  this->ChangeMouseCursorType(this, mouseIndex, v4);
  v5->mPresetCursorType = v4;
  v5->CursorType = v4;
}
