void Scaleform::GFx::AS2::ActionLogger::LogScriptError(Scaleform::GFx::AS2::ActionLogger *this, const char *pfmt, ...)
{
  unsigned int v2; // eax
  Scaleform::StringDataPtr v3; // [esp+8h] [ebp-114h] BYREF
  Scaleform::MsgFormat::Sink v4; // [esp+10h] [ebp-10Ch] BYREF
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
      v3.pStr = pfmt;
      v3.Size = v2;
      v4.SinkData.pStr = (Scaleform::String *)v5;
      v4.Type = tDataPtr;
      v4.SinkData.DataPtr.Size = 256;
      Scaleform::Format<Scaleform::StringDataPtr,char const *>(&v4, "{0} : {1}\n", &v3, &this->LogSuffix);
      ((void (__thiscall *)(Scaleform::Log *, int, _BYTE *, char *))this->pLog->LogMessageVarg)(
        this->pLog,
        212992,
        v5,
        va);
    }
    else
    {
      ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))this->pLog->LogMessageVarg)(
        this->pLog,
        212992,
        pfmt,
        va);
    }
  }
}
