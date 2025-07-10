void Scaleform::GFx::AS2::Environment::LogScriptWarning(Scaleform::GFx::AS2::Environment *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::ActionLogger *pASLogger; // esi
  unsigned int v3; // eax
  Scaleform::Log *v4; // eax
  Scaleform::StringDataPtr v1; // [esp+8h] [ebp-114h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-10Ch] BYREF
  _BYTE v7[256]; // [esp+1Ch] [ebp-100h] BYREF
  va_list va; // [esp+128h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  pASLogger = this->pASLogger;
  if ( pASLogger )
  {
    if ( pASLogger->pLog )
    {
      if ( pASLogger->UseSuffix )
      {
        v3 = strlen(pfmt);
        if ( pfmt[v3 - 1] == 10 )
          --v3;
        v1.pStr = pfmt;
        v1.Size = v3;
        result.SinkData.pStr = (Scaleform::String *)v7;
        result.Type = tDataPtr;
        result.SinkData.DataPtr.Size = 256;
        Scaleform::Format<Scaleform::StringDataPtr,char const *>(&result, "{0} : {1}\n", &v1, &pASLogger->LogSuffix);
        ((void (__thiscall *)(Scaleform::Log *, int, _BYTE *, char *))pASLogger->pLog->LogMessageVarg)(
          pASLogger->pLog,
          147456,
          v7,
          va);
      }
      else
      {
        ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))pASLogger->pLog->LogMessageVarg)(
          pASLogger->pLog,
          147456,
          pfmt,
          va);
      }
    }
  }
  else if ( this->Target->GetLog(this->Target) )
  {
    v4 = this->Target->GetLog(this->Target);
    ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))v4->LogMessageVarg)(v4, 147456, pfmt, va);
  }
}
