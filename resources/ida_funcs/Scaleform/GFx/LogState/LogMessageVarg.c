void __thiscall Scaleform::GFx::LogState::LogMessageVarg(
        Scaleform::GFx::LogState *this,
        Scaleform::LogMessageId messageType,
        const char *fmt,
        char *argList)
{
  Scaleform::Log *pObject; // eax

  pObject = this->pLog.pObject;
  if ( pObject || (pObject = Scaleform::Log::GetGlobalLog()) != 0 )
    ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))pObject->LogMessageVarg)(
      pObject,
      messageType.Id,
      fmt,
      argList);
}
