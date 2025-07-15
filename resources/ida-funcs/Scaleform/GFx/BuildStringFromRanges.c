Scaleform::String *__usercall Scaleform::GFx::BuildStringFromRanges@<eax>(
        const Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *ranges@<esi>,
        Scaleform::String *a2)
{
  unsigned int Size; // eax
  int v3; // ebx
  unsigned __int16 start; // bp
  unsigned int v5; // edi
  Scaleform::GFx::Range *v6; // eax
  unsigned __int16 end; // dx
  int v8; // ebx
  Scaleform::String *v9; // ebp
  unsigned __int16 *p_end; // ebp
  char v12; // [esp+Fh] [ebp-521h]
  unsigned __int16 v[2]; // [esp+10h] [ebp-520h] BYREF
  int v14; // [esp+14h] [ebp-51Ch]
  Scaleform::MsgFormat::Sink r; // [esp+18h] [ebp-518h] BYREF
  Scaleform::MsgFormat::Sink v16; // [esp+24h] [ebp-50Ch] BYREF
  __m128i v17[32]; // [esp+30h] [ebp-500h] BYREF
  Scaleform::MsgFormat v18; // [esp+230h] [ebp-300h] BYREF

  Scaleform::String::String(a2);
  Size = ranges->Data.Size;
  v3 = 0;
  start = 0;
  v5 = 0;
  v14 = 0;
  v12 = 1;
  *(_DWORD *)v = 0;
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
          v3 = v14;
        }
        else
        {
          if ( start == end )
          {
            v16.Type = tDataPtr;
            v16.SinkData.pStr = (Scaleform::String *)v17;
            v16.SinkData.DataPtr.Size = 512;
            Scaleform::Format<unsigned short>(&v16, "0x{0:x}", v);
          }
          else
          {
            r.Type = tDataPtr;
            r.SinkData.pStr = (Scaleform::String *)v17;
            r.SinkData.DataPtr.Size = 512;
            Scaleform::Format<unsigned short,unsigned short>(&r, "0x{0:x}-0x{1:x}", v, &v6[-1].end);
          }
          v8 = v14;
          v9 = a2;
          if ( v14 )
            Scaleform::String::AppendString(a2, (const __m128i *)", ", 0xFFFFFFFF);
          Scaleform::String::AppendString(a2, v17, 0xFFFFFFFF);
          v3 = v8 + 1;
          v14 = v3;
          if ( v3 > 4 )
            goto LABEL_19;
          start = ranges->Data.Data[v5].start;
          *(_DWORD *)v = start;
          v12 = 0;
        }
      }
      else
      {
        start = ranges->Data.Data->start;
        *(_DWORD *)v = start;
        v12 = 0;
      }
      ++v5;
    }
    while ( v5 < ranges->Data.Size );
    if ( !v12 )
    {
      p_end = &ranges->Data.Data[ranges->Data.Size - 1].end;
      r.SinkData.pStr = (Scaleform::String *)v17;
      r.Type = tDataPtr;
      r.SinkData.DataPtr.Size = 512;
      Scaleform::MsgFormat::MsgFormat(&v18, &r);
      Scaleform::MsgFormat::Parse(&v18, "0x{0:x}-0x{1:x}");
      Scaleform::MsgFormat::FormatD1<unsigned short>(&v18, v);
      Scaleform::MsgFormat::FormatD1<unsigned short>(&v18, p_end);
      Scaleform::MsgFormat::FinishFormatD(&v18);
      Scaleform::MsgFormat::~MsgFormat(&v18);
      if ( v3 )
        Scaleform::String::AppendString(a2, (const __m128i *)", ", 0xFFFFFFFF);
      Scaleform::String::AppendString(a2, v17, 0xFFFFFFFF);
    }
  }
  v9 = a2;
LABEL_19:
  if ( v5 < ranges->Data.Size )
    Scaleform::String::AppendString(v9, (const __m128i *)" (truncated)", 0xFFFFFFFF);
  return v9;
}
