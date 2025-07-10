unsigned int __cdecl Scaleform::Format<long>(const Scaleform::MsgFormat::Sink *result, const char *fmt, int *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v1);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}
