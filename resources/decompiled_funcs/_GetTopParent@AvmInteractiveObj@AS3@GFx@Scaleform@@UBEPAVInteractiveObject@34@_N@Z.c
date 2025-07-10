Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS3::AvmInteractiveObj::GetTopParent(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        BOOL ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *result; // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx

  result = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  pParent = result->pParent;
  if ( pParent )
  {
    if ( pParent->pASRoot->AVMVersion == 2 )
      return pParent->GetTopParent(pParent, ignoreLockRoot);
  }
  return result;
}
