unsigned int __cdecl Scaleform::Format<unsigned short>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const unsigned __int16 *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned short>(&parsed_format, v1);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<unsigned short,unsigned short>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const unsigned __int16 *v1,
        const unsigned __int16 *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned short>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<unsigned short>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


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


unsigned int __cdecl Scaleform::Format<unsigned long>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const unsigned int *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&parsed_format, v1);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const char **v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v1);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


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


unsigned int __cdecl Scaleform::Format<char const *,char const *,int>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const char **v1,
        const char **v2,
        const int *v3)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v2);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v3);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,char const *,int,int,int,int,int,int,int>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const char **v1,
        const char **v2,
        const int *v3,
        const int *v4,
        const int *v5,
        const int *v6,
        const int *v7,
        const int *v8,
        const int *v9)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v2);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v3);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v4);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v5);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v6);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v7);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v8);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v9);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,char const *,Scaleform::String>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const char **v1,
        const char **v2,
        const Scaleform::StringLH *v3)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v2);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&parsed_format, v3);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::String>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const Scaleform::StringLH *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&parsed_format, v1);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::StringDataPtr,char const *>(
        const Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        const Scaleform::StringDataPtr *v1,
        const char **v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}
