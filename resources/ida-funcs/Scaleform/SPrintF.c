unsigned int Scaleform::SPrintF(const Scaleform::MsgFormat::Sink *result, const char *fmt, ...)
{
  unsigned int StrSize; // esi
  Scaleform::StringDataPtr fmta; // [esp+0h] [ebp-308h] BYREF
  Scaleform::MsgFormat v5; // [esp+8h] [ebp-300h] BYREF
  va_list argList; // [esp+314h] [ebp+Ch] BYREF

  va_start(argList, fmt);
  Scaleform::MsgFormat::MsgFormat(&v5, result);
  fmta.pStr = fmt;
  if ( fmt )
    fmta.Size = strlen(fmt);
  else
    fmta.Size = 0;
  Scaleform::MsgFormat::FormatF(&v5, &fmta, argList);
  StrSize = v5.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v5);
  return StrSize;
}
