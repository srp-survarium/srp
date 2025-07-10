void Scaleform::GFx::AS2::ActionLogger::LogScriptWarning(
        Scaleform::GFx::AS2::ActionLogger *this,
        const char *pfmt,
        ...)
{
  unsigned int v2; // eax
  Scaleform::StringDataPtr v1; // [esp+8h] [ebp-114h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-10Ch] BYREF
  _BYTE v5[256]; // [esp+1Ch] [ebp-100h] BYREF
  va_list va; // [esp+128h] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this->pLog )
  {
    if ( this->UseSuffix )
    {
      v2 = strlen(pfmt);
      if ( pfmt[v2 - 1] == 10 )
        --v2;
      v1.pStr = pfmt;
      v1.Size = v2;
      result.SinkData.pStr = (Scaleform::String *)v5;
      result.Type = tDataPtr;
      result.SinkData.DataPtr.Size = 256;
      Scaleform::Format<Scaleform::StringDataPtr,char const *>(&result, "{0} : {1}\n", &v1, &this->LogSuffix);
      ((void (__thiscall *)(Scaleform::Log *, int, _BYTE *, char *))this->pLog->LogMessageVarg)(
        this->pLog,
        147456,
        v5,
        va);
    }
    else
    {
      ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))this->pLog->LogMessageVarg)(
        this->pLog,
        147456,
        pfmt,
        va);
    }
  }
}
