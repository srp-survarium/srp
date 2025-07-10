void __thiscall Scaleform::GFx::ZlibSupport::InflateWrapper(
        Scaleform::GFx::ZlibSupport *this,
        Scaleform::GFx::Stream *pinStream,
        void *buffer,
        unsigned int bufferBytes)
{
  int inited; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int8 buff[32]; // [esp+0h] [ebp-58h] BYREF
  z_stream_s D_stream; // [esp+20h] [ebp-38h] BYREF

  inited = Scaleform::GFx::ZLibFile::ZLib_InitStream(&D_stream, this, buffer, bufferBytes);
  if ( inited )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() inflateInit() returned %d",
      inited);
    return;
  }
  D_stream.next_in = buff;
  D_stream.avail_in = Scaleform::GFx::Stream::ReadToBuffer(pinStream, buff, 0x20u);
  v5 = inflate(&D_stream, 2);
  if ( v5 != 1 )
  {
    while ( !v5 )
    {
      D_stream.next_in = buff;
      D_stream.avail_in = Scaleform::GFx::Stream::ReadToBuffer(pinStream, buff, 0x20u);
      v5 = inflate(&D_stream, 2);
      if ( v5 == 1 )
        goto LABEL_9;
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() Inflate() returned %d",
      v5);
    if ( !D_stream.avail_in )
      goto LABEL_11;
    Scaleform::GFx::Stream::SetPosition(
      pinStream,
      pinStream->Pos + pinStream->FilePos - pinStream->DataSize - D_stream.avail_in);
  }
LABEL_9:
  if ( D_stream.avail_in )
    Scaleform::GFx::Stream::SetPosition(
      pinStream,
      pinStream->Pos + pinStream->FilePos - pinStream->DataSize - D_stream.avail_in);
LABEL_11:
  v6 = inflateEnd(&D_stream);
  if ( v6 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() InflateEnd() return %d",
      v6);
}
