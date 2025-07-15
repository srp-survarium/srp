unsigned int __cdecl Scaleform::Format<unsigned short>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        unsigned __int16 *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v5; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v5, result);
  Scaleform::MsgFormat::Parse(&v5, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned short>(&v5, v1);
  Scaleform::MsgFormat::FinishFormatD(&v5);
  StrSize = v5.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v5);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<unsigned short,unsigned short>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        unsigned __int16 *v1,
        unsigned __int16 *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v6; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v6, result);
  Scaleform::MsgFormat::Parse(&v6, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned short>(&v6, v1);
  Scaleform::MsgFormat::FormatD1<unsigned short>(&v6, v2);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  StrSize = v6.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<int,int>(const Scaleform::MsgFormat::Sink *result, char *fmt, int *v1, int *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<int,int,int,int>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        int *v1,
        int *v2,
        int *v3,
        int *v4)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v8; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v8, result);
  Scaleform::MsgFormat::Parse(&v8, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&v8, v1);
  Scaleform::MsgFormat::FormatD1<int>(&v8, v2);
  Scaleform::MsgFormat::FormatD1<int>(&v8, v3);
  Scaleform::MsgFormat::FormatD1<int>(&v8, v4);
  Scaleform::MsgFormat::FinishFormatD(&v8);
  StrSize = v8.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v8);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<int,int,int,char const *,int>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        int *v1,
        int *v2,
        int *v3,
        const char **v4,
        int *v5)
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


unsigned int __cdecl Scaleform::Format<int,char const *>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        int *v1,
        const char **v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<int,Scaleform::String>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        int *v1,
        const Scaleform::StringLH *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<long>(const Scaleform::MsgFormat::Sink *result, char *fmt, int *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v5; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v5, result);
  Scaleform::MsgFormat::Parse(&v5, fmt);
  Scaleform::MsgFormat::FormatD1<int>(&v5, v1);
  Scaleform::MsgFormat::FinishFormatD(&v5);
  StrSize = v5.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v5);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<unsigned long>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        unsigned int *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v5; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v5, result);
  Scaleform::MsgFormat::Parse(&v5, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v5, v1);
  Scaleform::MsgFormat::FinishFormatD(&v5);
  StrSize = v5.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v5);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<unsigned long,int>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        unsigned int *v1,
        int *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v6; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v6, result);
  Scaleform::MsgFormat::Parse(&v6, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v6, v1);
  Scaleform::MsgFormat::FormatD1<int>(&v6, v2);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  StrSize = v6.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<unsigned long,unsigned long>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        unsigned int *v1,
        unsigned int *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v6; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v6, result);
  Scaleform::MsgFormat::Parse(&v6, fmt);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v6, v1);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v6, v2);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  StrSize = v6.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<float,float,float,float,float,float>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        float *v1,
        float *v2,
        float *v3,
        float *v4,
        float *v5,
        float *v6)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v10; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v10, result);
  Scaleform::MsgFormat::Parse(&v10, fmt);
  Scaleform::MsgFormat::FormatD1<float>(&v10, v1);
  Scaleform::MsgFormat::FormatD1<float>(&v10, v2);
  Scaleform::MsgFormat::FormatD1<float>(&v10, v3);
  Scaleform::MsgFormat::FormatD1<float>(&v10, v4);
  Scaleform::MsgFormat::FormatD1<float>(&v10, v5);
  Scaleform::MsgFormat::FormatD1<float>(&v10, v6);
  Scaleform::MsgFormat::FinishFormatD(&v10);
  StrSize = v10.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v10);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<float,float,float,float,float,float,float,float>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        float *v1,
        float *v2,
        float *v3,
        float *v4,
        float *v5,
        float *v6,
        float *v7,
        float *v8)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v12; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v12, result);
  Scaleform::MsgFormat::Parse(&v12, fmt);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v1);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v2);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v3);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v4);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v5);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v6);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v7);
  Scaleform::MsgFormat::FormatD1<float>(&v12, v8);
  Scaleform::MsgFormat::FinishFormatD(&v12);
  StrSize = v12.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v12);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v5; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v5, result);
  Scaleform::MsgFormat::Parse(&v5, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&v5, v1);
  Scaleform::MsgFormat::FinishFormatD(&v5);
  StrSize = v5.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v5);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,unsigned long,unsigned long,Scaleform::String>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1,
        unsigned int *v2,
        unsigned int *v3,
        Scaleform::StringLH *v4)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v8; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v8, result);
  Scaleform::MsgFormat::Parse(&v8, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&v8, v1);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v8, v2);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v8, v3);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v8, v4);
  Scaleform::MsgFormat::FinishFormatD(&v8);
  StrSize = v8.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v8);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,char const *>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1,
        const char **v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v6; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v6, result);
  Scaleform::MsgFormat::Parse(&v6, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&v6, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&v6, v2);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  StrSize = v6.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,char const *,int>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1,
        const char **v2,
        int *v3)
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
        char *fmt,
        const char **v1,
        const char **v2,
        int *v3,
        int *v4,
        int *v5,
        int *v6,
        int *v7,
        int *v8,
        int *v9)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v13; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v13, result);
  Scaleform::MsgFormat::Parse(&v13, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&v13, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&v13, v2);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v3);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v4);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v5);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v6);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v7);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v8);
  Scaleform::MsgFormat::FormatD1<int>(&v13, v9);
  Scaleform::MsgFormat::FinishFormatD(&v13);
  StrSize = v13.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v13);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,char const *,Scaleform::String>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1,
        const char **v2,
        Scaleform::StringLH *v3)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v7; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v7, result);
  Scaleform::MsgFormat::Parse(&v7, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&v7, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&v7, v2);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v7, v3);
  Scaleform::MsgFormat::FinishFormatD(&v7);
  StrSize = v7.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v7);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,Scaleform::StringDataPtr>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1,
        const Scaleform::StringDataPtr *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<char const *,unsigned __int64,unsigned long>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const char **v1,
        unsigned __int64 *v2,
        unsigned int *v3)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v7; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v7, result);
  Scaleform::MsgFormat::Parse(&v7, fmt);
  Scaleform::MsgFormat::FormatD1<char const *>(&v7, v1);
  Scaleform::MsgFormat::FormatD1<unsigned __int64>(&v7, v2);
  Scaleform::MsgFormat::FormatD1<unsigned int>(&v7, v3);
  Scaleform::MsgFormat::FinishFormatD(&v7);
  StrSize = v7.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v7);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::String>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        Scaleform::StringLH *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v5; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v5, result);
  Scaleform::MsgFormat::Parse(&v5, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v5, v1);
  Scaleform::MsgFormat::FinishFormatD(&v5);
  StrSize = v5.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v5);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::StringDataPtr>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const Scaleform::StringDataPtr *v1)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&parsed_format, v1);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::StringDataPtr,int,int,int>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const Scaleform::StringDataPtr *v1,
        int *v2,
        int *v3,
        int *v4)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v2);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v3);
  Scaleform::MsgFormat::FormatD1<int>(&parsed_format, v4);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::StringDataPtr,char const *>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const Scaleform::StringDataPtr *v1,
        const char **v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat v6; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v6, result);
  Scaleform::MsgFormat::Parse(&v6, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v6, v1);
  Scaleform::MsgFormat::FormatD1<char const *>(&v6, v2);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  StrSize = v6.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return StrSize;
}


unsigned int __cdecl Scaleform::Format<Scaleform::StringDataPtr,Scaleform::StringDataPtr>(
        const Scaleform::MsgFormat::Sink *result,
        char *fmt,
        const Scaleform::StringDataPtr *v1,
        const Scaleform::StringDataPtr *v2)
{
  unsigned int StrSize; // esi
  Scaleform::MsgFormat parsed_format; // [esp+4h] [ebp-300h] BYREF

  Scaleform::MsgFormat::MsgFormat(&parsed_format, result);
  Scaleform::MsgFormat::Parse(&parsed_format, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&parsed_format, v1);
  Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&parsed_format, v2);
  Scaleform::MsgFormat::FinishFormatD(&parsed_format);
  StrSize = parsed_format.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&parsed_format);
  return StrSize;
}
