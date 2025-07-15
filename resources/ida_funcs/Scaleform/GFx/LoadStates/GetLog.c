Scaleform::Log *__thiscall Scaleform::GFx::LoadStates::GetLog(Scaleform::GFx::LoadStates *this)
{
  Scaleform::GFx::LogState *pObject; // eax
  Scaleform::Log *result; // eax

  pObject = this->pLog.pObject;
  if ( !pObject )
    return 0;
  result = pObject->pLog.pObject;
  if ( !result )
    return Scaleform::Log::GetGlobalLog();
  return result;
}
