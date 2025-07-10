unsigned int __cdecl Scaleform::Format<int,int,int,char const *,int>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const int *v1,
        const int *v2,
        const int *v3,
        const char **v4,
        const int *v5)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v2);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v3);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v4);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v5);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}
