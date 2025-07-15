Scaleform::GFx::AS2::AvmCharacter *__thiscall Scaleform::GFx::AS2::AvmCharacter::GetAvmTopParent(
        Scaleform::GFx::AS2::AvmCharacter *this,
        BOOL ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  int v4; // eax

  pParent = this->pDispObj->pParent;
  if ( pParent->pASRoot->AVMVersion != 1 )
    return 0;
  v4 = (int)pParent->GetTopParent(pParent, ignoreLockRoot);
  return (Scaleform::GFx::AS2::AvmCharacter *)(v4 + 4 * *(unsigned __int8 *)(v4 + 65));
}
