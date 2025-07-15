Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::AvmCharacter::GetTopParent(
        Scaleform::GFx::AS2::AvmCharacter *this,
        BOOL ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *result; // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx

  result = this->pDispObj;
  pParent = result->pParent;
  if ( pParent )
  {
    if ( pParent->pASRoot->AVMVersion == 1 )
      return pParent->GetTopParent(pParent, ignoreLockRoot);
  }
  return result;
}
