unsigned int __cdecl Scaleform::Format<char const *,char const *>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const char **v1,
        const char **v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}
