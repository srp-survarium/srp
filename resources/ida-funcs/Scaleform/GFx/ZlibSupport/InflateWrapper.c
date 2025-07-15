void __thiscall Scaleform::GFx::ZlibSupport::InflateWrapper(
        Scaleform::GFx::ZlibSupport *this,
        Scaleform::GFx::Stream *pinStream,
        unsigned __int8 *buffer,
        unsigned int bufferBytes)
{
  int inited; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int8 pdestBuf[32]; // [esp+0h] [ebp-58h] BYREF
  z_stream_s pstream; // [esp+20h] [ebp-38h] BYREF

  inited = Scaleform::GFx::ZLibFile::ZLib_InitStream(&pstream, this, buffer, bufferBytes);
  if ( inited )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() inflateInit() returned %d",
      inited);
    return;
  }
  pstream.next_in = pdestBuf;
  pstream.avail_in = Scaleform::GFx::Stream::ReadToBuffer(pinStream, pdestBuf, 0x20u);
  v5 = inflate(&pstream, 2);
  if ( v5 != 1 )
  {
    while ( !v5 )
    {
      pstream.next_in = pdestBuf;
      pstream.avail_in = Scaleform::GFx::Stream::ReadToBuffer(pinStream, pdestBuf, 0x20u);
      v5 = inflate(&pstream, 2);
      if ( v5 == 1 )
        goto LABEL_9;
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() Inflate() returned %d",
      v5);
    if ( !pstream.avail_in )
      goto LABEL_11;
    Scaleform::GFx::Stream::SetPosition(
      pinStream,
      pinStream->Pos + pinStream->FilePos - pinStream->DataSize - pstream.avail_in);
  }
LABEL_9:
  if ( pstream.avail_in )
    Scaleform::GFx::Stream::SetPosition(
      pinStream,
      pinStream->Pos + pinStream->FilePos - pinStream->DataSize - pstream.avail_in);
LABEL_11:
  v6 = inflateEnd(&pstream);
  if ( v6 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() InflateEnd() return %d",
      v6);
}
