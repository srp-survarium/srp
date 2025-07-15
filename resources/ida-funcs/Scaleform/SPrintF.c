unsigned int Scaleform::SPrintF(const Scaleform::MsgFormat::Sink *result, const char *fmt, ...)
{
  unsigned int StrSize; // esi
  Scaleform::StringDataPtr v4; // [esp+0h] [ebp-308h] BYREF
  Scaleform::MsgFormat parsed_format; // [esp+8h] [ebp-300h] BYREF
  va_list argList; // [esp+314h] [ebp+Ch] BYREF

  va_start(argList, fmt);
  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  v4.pStr = fmt;
  if ( fmt )
    v4.Size = strlen(fmt);
  else
    v4.Size = 0;
  Scaleform::MsgFormat::FormatF(&parsed_format, &v4, argList);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}
