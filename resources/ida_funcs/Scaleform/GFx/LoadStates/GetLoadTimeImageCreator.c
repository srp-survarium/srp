Scaleform::GFx::ImageCreator *__thiscall Scaleform::GFx::LoadStates::GetLoadTimeImageCreator(
        Scaleform::GFx::LoadStates *this,
        char loadConstants)
{
  Scaleform::GFx::ImageCreator *result; // eax
  Scaleform::GFx::ImageCreator *pObject; // ecx

  result = 0;
  if ( loadConstants >= 0 )
  {
    pObject = this->pBindStates.pObject->pImageCreator.pObject;
    if ( pObject )
      return pObject;
  }
  return result;
}
