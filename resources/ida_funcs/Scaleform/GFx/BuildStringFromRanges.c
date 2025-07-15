Scaleform::String *__usercall Scaleform::GFx::BuildStringFromRanges@<eax>(
        const Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *ranges@<esi>,
        Scaleform::String *a2)
{
  unsigned int Size; // eax
  int v3; // ebx
  unsigned __int16 v4; // bp
  unsigned int v5; // edi
  Scaleform::GFx::Range *v6; // eax
  unsigned __int16 end; // dx
  int v8; // ebx
  Scaleform::String *v9; // ebp
  unsigned __int16 *p_end; // ebp
  bool lastPrinted; // [esp+Fh] [ebp-521h]
  int start; // [esp+10h] [ebp-520h] BYREF
  int countPrinted; // [esp+14h] [ebp-51Ch]
  Scaleform::MsgFormat::Sink r; // [esp+18h] [ebp-518h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+24h] [ebp-50Ch] BYREF
  char buff[512]; // [esp+30h] [ebp-500h] BYREF
  Scaleform::MsgFormat v18; // [esp+230h] [ebp-300h] BYREF

  Scaleform::String::String(a2);
  Size = ranges->Data.Size;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  countPrinted = 0;
  lastPrinted = 1;
  start = 0;
  if ( Size )
  {
    do
    {
      if ( v5 )
      {
        v6 = &ranges->Data.Data[v5];
        end = v6[-1].end;
        if ( v6->start <= end + 1 )
        {
          v3 = countPrinted;
        }
        else
        {
          if ( v4 == end )
          {
            result.Type = tDataPtr;
            result.SinkData.pStr = (Scaleform::String *)buff;
            result.SinkData.DataPtr.Size = 512;
            Scaleform::Format<unsigned short>(&result, "0x{0:x}", (const unsigned __int16 *)&start);
          }
          else
          {
            r.Type = tDataPtr;
            r.SinkData.pStr = (Scaleform::String *)buff;
            r.SinkData.DataPtr.Size = 512;
            Scaleform::Format<unsigned short,unsigned short>(
              &r,
              "0x{0:x}-0x{1:x}",
              (const unsigned __int16 *)&start,
              &v6[-1].end);
          }
          v8 = countPrinted;
          v9 = a2;
          if ( countPrinted )
            Scaleform::String::AppendString(a2, (char *)&stru_95AF78.m_key_bindings[32], 0xFFFFFFFF);
          Scaleform::String::AppendString(a2, buff, 0xFFFFFFFF);
          v3 = v8 + 1;
          countPrinted = v3;
          if ( v3 > 4 )
            goto LABEL_19;
          v4 = ranges->Data.Data[v5].start;
          start = v4;
          lastPrinted = 0;
        }
      }
      else
      {
        v4 = ranges->Data.Data->start;
        start = v4;
        lastPrinted = 0;
      }
      ++v5;
    }
    while ( v5 < ranges->Data.Size );
    if ( !lastPrinted )
    {
      p_end = &ranges->Data.Data[ranges->Data.Size - 1].end;
      r.SinkData.pStr = (Scaleform::String *)buff;
      r.Type = tDataPtr;
      r.SinkData.DataPtr.Size = 512;
      Scaleform::MsgFormat::MsgFormat(&v18, &r);
      Scaleform::MsgFormat::Parse(&v18, "0x{0:x}-0x{1:x}");
      Scaleform::MsgFormat::FormatD1<unsigned short>(&v18, (const unsigned __int16 *)&start);
      Scaleform::MsgFormat::FormatD1<unsigned short>(&v18, p_end);
      Scaleform::MsgFormat::FinishFormatD(&v18);
      Scaleform::MsgFormat::~MsgFormat(&v18);
      if ( v3 )
        Scaleform::String::AppendString(a2, (char *)&stru_95AF78.m_key_bindings[32], 0xFFFFFFFF);
      Scaleform::String::AppendString(a2, buff, 0xFFFFFFFF);
    }
  }
  v9 = a2;
LABEL_19:
  if ( v5 < ranges->Data.Size )
    Scaleform::String::AppendString(v9, " (truncated)", 0xFFFFFFFF);
  return v9;
}
