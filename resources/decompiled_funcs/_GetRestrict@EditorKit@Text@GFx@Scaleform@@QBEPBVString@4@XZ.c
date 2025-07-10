Scaleform::StringLH *__thiscall Scaleform::GFx::Text::EditorKit::GetRestrict(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // eax

  pObject = this->pRestrict.pObject;
  if ( pObject )
    return &pObject->RestrictString;
  else
    return 0;
}
